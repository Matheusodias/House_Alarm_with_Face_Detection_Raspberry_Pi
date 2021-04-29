#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>
#include <pthread.h>

//Definição dos pinos - WiringPi
int resistorPin = 25;
int buzzerPin = 24;
int onoffPin = 28;

//Função para tratar o acionamento do alarme
void* detection(void* dummy_ptr)
{
    digitalWrite(buzzerPin, HIGH);
    system("./Faces");              //Chama o executável do código de captura da foto e detecção facial "Faces.cpp"
    sleep(1);                       //Aguarda um tempo de instabilidade no sensor 
	return NULL;
}

//Função que incrementa uma variável em função do tempo
//  de carga do capacitor, para a leitura do sensor LDR
int rc_time(int pin_to_circuit)
{	
    int count = 0;
    pinMode(pin_to_circuit, OUTPUT);            //Define o pino como saída
    digitalWrite(pin_to_circuit, LOW);          //Define nível lógico baixo nesse pino
    sleep(0.1);
    pinMode(pin_to_circuit, INPUT);             //Define o pino como entrada
    while(digitalRead(resistorPin) == 0)        //Incrementa a variável enquato o pino estiver em LOW
    {
        count++;
    }
    return count/1000;
}

//Função main
int main(void){
    while(1)
    {
        pthread_t thread1_id;                   //Define a thread
        wiringPiSetup();                        //Inicia WiringPi
        int sensor = rc_time(resistorPin);      //Recebe uma leitura do sensor
        if(digitalRead(onoffPin)==LOW)          //Caso o alarme esteja desativado pelo app, desliga o buzzer
        {            
            digitalWrite(buzzerPin, LOW);
        }
        if(sensor > 100){                       //Se o valor do sensor indicar uma interrupção do feixe de luz do laser...
            if(digitalRead(onoffPin)==HIGH)     //Se o alarme estiver ligado pelo app...
            {
                pthread_create(&thread1_id,NULL,&detection,NULL);   //Executa a thread caso o alarme seja acionado
            	pthread_join(thread1_id, NULL);                     //Aguarda até o fim da execução da thread
            }
            if(digitalRead(onoffPin)==LOW)      //Caso o alarme esteja desativado pelo app, desliga o buzzer
            {
                digitalWrite(buzzerPin, LOW);
            }
        }
        sleep(0.001);                           //Período do loop
    }
    return 0;
}
