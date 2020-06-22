

names = "abcedfghijklmopqst"

for char in names:
    file_name = char + ".txt"
    file = open(file_name, "w")
    file.write(f"This is key {char}")
    file.close()