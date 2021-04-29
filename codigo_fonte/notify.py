#!/usr/bin/env python3
import os
import blynklib
from time import sleep
import sys
import socket

#Bibliotecas necessarias para o envio do email
import smtplib
import email
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

#Código de autenticação do aplicativo
BLYNK_AUTH = '9BXDsuxldXNjj6q7VRpAZKmR8UypTGjv'

#Guardar IP address em uma variável
gw = os.popen("ip -4 route show default").read().split()
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.connect((gw[2], 0))
ipaddr = s.getsockname()[0]

#Inicia a comunicação com o aplicativo
blynk = blynklib.Blynk(BLYNK_AUTH)
blynk.run()

#Atualiza as imagens no aplicativo
blynk.set_property(1,"urls","http://"+ipaddr+":8081/default.png","http://"+ipaddr+":8081/imagem.jpg")
blynk.virtual_write(1,1)
sleep(1)

#Identifica pelo argumento de entrada se houve ou não uma pessoa detectada na foto
if(sys.argv[1]=='y'):
    blynk.notify('ALARME ACIONADO - Pessoa detectada')
if(sys.argv[1]=='n'):
    blynk.notify('ALARME ACIONADO - Nenhuma pessoa detectada')
    
#Mostra a foto no aplicativo
blynk.virtual_write(1,2)
sleep(1)

#Envio do email com a foto em anexo
fromaddr = "email@gmail.com"
toaddr = "@gmail.com"
passwd = "password"

msg = MIMEMultipart()
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = "ALARME ACIONADO!!!"

body = "O alarme de sua residencia foi acionado!\nFoi detectada uma pessoa nas cameras!"
msg.attach(MIMEText(body, 'plain'))
filename = "imagem.jpg"
attachment = open(filename, "rb")
part = MIMEBase('application','octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition',"attachment; filename= %s" % filename)
msg.attach(part)

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr,passwd)
text = msg.as_string()
server.sendmail(fromaddr,msg['To'].split(","),text)
server.quit()

