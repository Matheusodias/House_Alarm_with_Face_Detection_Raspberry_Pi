//Bibliotecas para o OpenCV
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

//Bibliotecas para tirar e salvar a foto
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <raspicam/raspicam.h>
#include <raspicam/raspicam_cv.h>

using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame );

//Variáveis globais
CascadeClassifier face_cascade;
CascadeClassifier upper_cascade;
CascadeClassifier profile_cascade;

//Função main
int main( int argc, const char** argv )
{
    //Inicia a camera e tira uma foto
    raspicam::RaspiCam camera;
    camera.open();
    sleep(1);
    camera.grab();
 
    //Define alguns parametros da foto e salva em 'foto.jpg'
    std::vector<unsigned char> buf;
    buf.resize(camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB));
    camera.retrieve(buf.data(), raspicam::RASPICAM_FORMAT_RGB);
    std::ofstream outFile("foto.jpg", std::ios::binary);
    outFile << "P6\n" << camera.getWidth() << " " << camera.getHeight() << " 255\n";
    outFile.write((char*)buf.data(), buf.size());
    //Libera a camera
    camera.release();
    
    //Define os arquivos e chama a função para detecção
    face_cascade.load("haarcascade_frontalface_default.xml");	//Rosto frontal
    upper_cascade.load("haarcascade_upperbody.xml");		//Parte superior do corpo humano
    profile_cascade.load("haarcascade_profileface.xml");	//Rosto de perfil
    detectAndDisplay(imread("foto.jpg"));
    return 0;
}

//Função para detecção e desenho dos retângulos na parte do corpo detectada
void detectAndDisplay( Mat frame )
{
	//Converte a imagem para tons de cinza
	Mat frame_gray;
	cvtColor(frame,frame_gray,COLOR_BGR2GRAY);
	equalizeHist(frame_gray,frame_gray);

	//Detecção
	std::vector<Rect> faces;
	face_cascade.detectMultiScale(frame_gray,faces,1.3,5);
	std::vector<Rect> upperbd;
	face_cascade.detectMultiScale(frame_gray,upperbd,1.3,3);
	std::vector<Rect> profileface;
	face_cascade.detectMultiScale(frame_gray,profileface,1.03,5);

	//Desenho dos retângulos, caso haja detecção
	for ( size_t i = 0; i < faces.size(); i++ )		//Retângulo no rosto
	{
		rectangle(frame,Point(faces[i].x,faces[i].y),Point(faces[i].x+faces[i].width,faces[i].y+faces[i].height),Scalar(255,0,0),2);
		putText(frame,"Rosto Detectado",Point(faces[i].x+5,faces[i].y-10),FONT_HERSHEY_SIMPLEX,0.5,Scalar(255,0,0),2);
		Mat faceROI = frame_gray(faces[i]);
	}
	for ( size_t i = 0; i < upperbd.size(); i++ )		//Retângulo na parte superior do corpo
	{
		rectangle(frame,Point(upperbd[i].x,upperbd[i].y),Point(upperbd[i].x+upperbd[i].width,upperbd[i].y+upperbd[i].height),Scalar(0,255,0),2);
		Mat faceROI = frame_gray(upperbd[i]);
	}	
	for ( size_t i = 0; i < profileface.size(); i++ )	//Retângulo no rosto de perfil
	{
		rectangle(frame,Point(profileface[i].x,profileface[i].y),Point(profileface[i].x+profileface[i].width,profileface[i].y+profileface[i].height),Scalar(0,0,255),2);
		Mat faceROI = frame_gray(profileface[i]);
	}
	
	//Salva a imagem após a detecção
	imwrite("imagem.jpg",frame);
	
	//Chamada do código em python para a notificação via app e email
	if(faces.size()>0||upperbd.size()>0||profileface.size()>0)
	{
		system("./notify.py y");	//Passa o parâmetro 'y' caso uma pessoa seja detectada
	} else {
		system("./notify.py n");	//Passa o parâmetro 'n' caso nenhuma pessoa seja detectada
	}
}
