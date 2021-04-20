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
camera.resolution = (500,500)

camera.capture('foto.jpg')
camera.close()

blynk.virtual_write(1,1)
    
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
upper_cascade = cv2.CascadeClassifier('haarcascade_upperbody.xml')
profile_cascade = cv2.CascadeClassifier('haarcascade_profileface.xml')

img = cv2.imread('foto.jpg')

gray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

faces = face_cascade.detectMultiScale(gray, 1.3, 5)
profile = profile_cascade.detectMultiScale(gray, 1.1, 5)
upper = upper_cascade.detectMultiScale(gray, 1.03, 5)

i = 0

for (x,y,w,h) in faces:
    cv2.rectangle(img, (x, y), (x+w, y+h), (255, 0, 0), 2)
    cv2.putText(img, "Rosto Detectado",(x+5,y-10),cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,0,0),2)
for (x,y,w,h) in profile:
    cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 1)
for (x,y,w,h) in upper:
    cv2.rectangle(img, (x, y), (x+w, y+h), (0, 0, 255), 1)

if len(faces)>0 or len(profile)>0 or len(upper)>0:
    print("\n")
    print("\n")
    print("\n")
    print("-----------------------------------------------\n")
    print("-----------------------------------------------\n")
    print("-----------!!! PESSOA  DETECTADO !!!-----------\n")
    print("-----------------------------------------------\n")
    print("-----------------------------------------------\n")
    print("\n")
    print("\n")
    print("\n")
    blynk.notify('ALARME ACIONADO - Pessoa detectada')
    i = 1
    os.system("python3 send_email.py")
if i==0:
    blynk.notify('ALARME ACIONADO - Nenhuma pessoa detectada')

    
cv2.imwrite('imagem.jpg',img)
blynk.set_property(1,"url",2,"http://192.168.0.18:8081/imagem.jpg")
blynk.virtual_write(1,2)

