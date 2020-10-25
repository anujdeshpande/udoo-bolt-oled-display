import time
import serial
import psutil

ser = serial.Serial('/dev/ttyACM0')
ser.baudrate = 9600
ser.flushInput()

cpu = 0
ram = 0
temp = 0

while (1):
    cpu = psutil.cpu_percent()
    ram = psutil.virtual_memory().percent
    temp = psutil.sensors_temperatures()["acpitz"][0][1]
    string_to_send = str(int(cpu))+","+str(int(ram))+","+str(int(temp))+"\n"
    print(string_to_send)
    ser.write(bytes(string_to_send, encoding='utf8'))
    time.sleep(3)
