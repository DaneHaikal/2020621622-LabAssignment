import socket

ClientSocket = socket.socket()
host = '192.168.56.109'
port = 8889

print('Waiting for connection')
try:
    ClientSocket.connect((host, port))
except socket.error as e:
    print(str(e))

while True:
    filename = input(str('Please enter the filename to transfer: '))
    file = open(filename, "rb")
    file_data = file.read(1024)
    ClientSocket.send(file_data)
    print("File has been transferred successfully")

ClientSocket.close()

