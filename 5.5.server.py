import socket
import os
from _thread import *

ServerSocket = socket.socket()
host = ''
port = 8889
ThreadCount = 0
try:
    ServerSocket.bind((host, port))
except socket.error as e:
    print(str(e))

print('Waiting for a Connection..')
ServerSocket.listen(5)

def threaded_client(connection):
    connection.send(str.encode("Welcome to the Server"))
    while True:

        filename = input(str("Please enter the filename for incoming file: "))
        file = open(filename, "wb")
        file_data = ServerSocket.recv(1024)
        file.write(file_data)
        file.close()

        if not file_data:
            break
        connection.sendall(str.encode(reply))
    connection.close()

while True:
    Client, address = ServerSocket.accept()
    print('Connected to: ' + address[0] + ':' + str(address[1]))
    start_new_thread(threaded_client, (Client, ))
    ThreadCount += 1
    print('Thread Number: ' + str(ThreadCount))
ServerSocket.close()

