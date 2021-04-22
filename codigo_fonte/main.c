#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

int resistorPin = 25;
int buzzerPin = 24;
int onoffPin = 28;

void* detection(void* dummy_ptr)
{
	printf("Sensor acionado\n");
        digitalWrite(buzzerPin, HIGH);
        system("python3 face_detection.py");
        sleep(1);
	return NULL;
}

int rc_time(int pin_to_circuit)
{	
    int count = 0;
    pinMode(pin_to_circuit, OUTPUT);
    digitalWrite(pin_to_circuit, LOW);
    sleep(0.1);
    
    pinMode(pin_to_circuit, INPUT);
    
    while(digitalRead(resistorPin) == 0)
    {
        count++;
    }
    return count/1000;
}

int main(void){
    
    pthread_t thread1_id;
    wiringPiSetup();
    while(1)
    {
        int sensor = rc_time(resistorPin);
        //printf("%d\n",sensor);
        if(digitalRead(onoffPin)==LOW)
        {            
            digitalWrite(buzzerPin, LOW);
        }
        if(sensor > 100){
            if(digitalRead(onoffPin)==HIGH)
            {
            	pthread_create(&thread1_id,NULL,&detection,NULL);
            	pthread_join(thread1_id, NULL);
            }
            if(digitalRead(onoffPin)==LOW)
            {
                digitalWrite(buzzerPin, LOW);
            }
        }
        sleep(0.001);
    }
    
    return 0;
}
