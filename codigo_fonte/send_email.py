#!/usr/bin/python3

import smtplib
import email
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

fromaddr = "matchulaod@gmail.com"
toaddr = "@gmail.com"
passwd = "matwermdias96"

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
print("Email enviado\n")
server.quit()
