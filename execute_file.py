"""
| - activate the special command flag, between the | | everything inside will always be pressed
    A - alt
    C - ctrl
    S - shift
    E - enter
    T - tab
    W - win
    With this things like win + r are possible by doing |Wr|
¬ - Delay of 0.1 seconds used when multi key combination is necessary
To send space key, put " "
"""
from Keyboard_emulator import *
import time
import os

extra_chars = [".", "-"]

def execute_line(line):
    special_char_flag = 0
    special_char = []


    for char in line:
        if char == '¬':
            time.sleep(0.1)
            pass
        if char == '|':   #Toggle special char
            if special_char_flag == 1: #execute special flag
                pressHoldRelease(*special_char)
                special_char = []
            special_char_flag = int(not(special_char_flag))

        if special_char_flag:   #Read special char and build it
            if 64 < ord(char) < 91:
                if char == "A":
                    special_char.append("alt")
                if char == "C":
                    special_char.append("ctrl")
                if char == "S":
                    special_char.append("shift")
                if char == "E":
                    special_char.append("enter")
                if char == "T":
                    special_char.append("tab")
                if char == "W":
                    special_char.append("win")
            else:
                if char != '|':
                    special_char.append(char)

        if char == " ":
            press('spacebar')
        if char == "<":
            typer("<")
        if char == "*":
            typer("*")
        if char in extra_chars:
            press(char)

        #Means its a character
        if (64 < ord(char) < 91 or 96 < ord(char) < 123 or char == "/") and not(special_char_flag):
            if char.isupper():
                capital_press(chr(ord(char)+32))
            else:
                press(char)
        

def run_file(file_name):
    
    file = open(file_name, "r")
    line = file.readline()
    execute_line(line)

    file.close()


