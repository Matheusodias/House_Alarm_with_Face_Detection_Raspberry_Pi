import cv2
import os
import blynklib
from picamera import PiCamera
from time import sleep

BLYNK_AUTH = '9BXDsuxldXNjj6q7VRpAZKmR8UypTGjv'
date = "foto"

blynk = blynklib.Blynk(BLYNK_AUTH)
blynk.run()
camera = PiCamera()
camera.resolution = (640,480)

#os.system("raspistill -o foto.jpg")
camera.capture('foto.jpg')
camera.close()

blynk.virtual_write(1,1)
    
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

img = cv2.imread('foto.jpg')

gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

faces = face_cascade.detectMultiScale(gray, 1.3, 5)
i = 0

for (x,y,w,h) in faces:
    cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)

for (a,b,c,d) in faces:
    if a>0:
        print("\n")
        print("\n")
        print("\n")
        print("-----------------------------------------------\n")
        print("-----------------------------------------------\n")
        print("-----------!!! ROSTO  DETECTADO !!!------------\n")
        print("-----------------------------------------------\n")
        print("-----------------------------------------------\n")
        print("\n")
        print("\n")
        print("\n")
        blynk.notify('ALARME ACIONADO - Rosto detectado')
        i = 1
        #os.system("python3 send_email.py")
        break

if i==0:
    blynk.notify('ALARME ACIONADO - Nenhum rosto detectado')

    
#cv2.imshow('img', img)
cv2.imwrite('imagem.jpg',img)
blynk.set_property(1,"url",2,"http://192.168.0.18:8081/imagem.jpg")
blynk.virtual_write(1,2)
#cv2.waitKey()

