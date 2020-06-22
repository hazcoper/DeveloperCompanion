import socket

esp_name = "ESP-0079EB"

def find_esp():
    for counter in range(255):
        ip = f"192.168.1.{counter}"
        try:
            name = socket.gethostbyaddr(ip)
            if esp_name == name[0].split(".")[0]:
                break
        except:
            pass
    return ip

print(find_esp())