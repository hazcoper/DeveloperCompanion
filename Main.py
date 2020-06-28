"""
Only missing programing mode
It already has the discovery mode to find the esp ip in the network
"""

import socket
from find_esp import *
from execute_file import *
import time



TCP_IP = find_esp()
TCP_PORT = 23034
BUFFER_SIZE = 1024
should_connect = 0

time.sleep(2)


#Connect to esp8266
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
print("Connected to client")


def program_key(data):
    print("Programing is yet to be implemented")
    pass


programing_flag = 0


while True:
    data = s.recv(BUFFER_SIZE)
    print("This is the data: ",data)
    if programing_flag:
        programing_flag = 0
        program_key(data)
    elif data.decode() == 'R':
        programing_flag = 1
        print("Entering program mode, please choose key")
    else:
        file_name = f"{data.decode()}.txt"
        run_file(file_name)

s.close()