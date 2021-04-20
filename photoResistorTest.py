import RPi.GPIO as GPIO
import time
import os

GPIO.setmode(GPIO.BOARD)

resistorPin = 37

while True:
        GPIO.setup(resistorPin, GPIO.OUT)
        GPIO.output(resistorPin, GPIO.LOW)
        time.sleep(0.1)
        
        GPIO.setup(resistorPin, GPIO.IN)
        currentTime = time.time()
        diff = 0
        
        while(GPIO.input(resistorPin) == GPIO.LOW):
            diff = time.time() - currentTime
            
        print(diff * 1000)
        if ((diff*1000) > 15.00):
            print("Sensor acionado")
            os.system("python3 face_detection.py")
        time.sleep(0.001)