from send_keys import *
import time
import os

print(os.listdir())
print(os.getcwd())

time.sleep(3)
keys = Keys()


def execute_line(line):
    print(line)
    for char in line:
        print(char)
        if char == " ":
            keys.directKey("SPACE")
        else:
            print(char)
            keys.directKey("SHIFT")
            keys.directKey(char)
        time.sleep(0.005)

def program_key(data):
    print("Programing is yet to be implemented")
    pass


programing_flag = 0

def execute_file(file_name):
    file = open(file_name, "r")
    print(file.line)

execute_file("a.txt")