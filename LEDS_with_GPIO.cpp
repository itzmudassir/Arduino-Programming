import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
led1 = 2
led2 = 3
led3 = 22
led4 = 17
led5 = 27
GPIO.setup(led1, GPIO.OUT)
GPIO.setup(led2, GPIO.OUT)
GPIO.setup(led3, GPIO.OUT)
GPIO.setup(led4, GPIO.OUT)
GPIO.setup(led5, GPIO.OUT)
while(True):
    print("Leds are ON")
    GPIO.output(led1, GPIO.HIGH)
    GPIO.output(led2, GPIO.HIGH)
    GPIO.output(led3, GPIO.HIGH)
    GPIO.output(led4, GPIO.HIGH)
    GPIO.output(led5, GPIO.HIGH)
    time.sleep(1)
    print("Leds are OFF")
    GPIO.output(led1, GPIO.LOW)
    GPIO.output(led2, GPIO.LOW)
    GPIO.output(led3, GPIO.LOW)
    GPIO.output(led4, GPIO.LOW)
    GPIO.output(led5, GPIO.LOW)
    time.sleep(1)
