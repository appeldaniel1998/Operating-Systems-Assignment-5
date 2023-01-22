# Operating-Systems-Assignment-5

The only resource on the internet used was:
https://chat.openai.com/

A sample run (using "script" command):

Server:

Script started on 2023-01-22 11:31:40+02:00 [TERM="xterm-256color" TTY="/dev/pts/1" COLUMNS="86" LINES="24"]
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5[00m$ cd server/
[?2004l
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5/server[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5/server[00m$ make clean
[?2004l
rm -f *.o server
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5/server[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5/server[00m$ make all
[?2004l
clang++ -c -Wall ActiveObject.cpp -o ActiveObject.o
clang++ -c -Wall main.cpp -o main.o
clang++ -c -Wall Pipeline.cpp -o Pipeline.o
clang++ -c -Wall Reactor.cpp -o Reactor.o
clang++ ActiveObject.o main.o Pipeline.o Reactor.o -o server
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5/server[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5/server[00m$ ./server 2
[?2004l
Listening...
Incoming connection from 127.0.0.1:48976
Received message: hi
original: hi
polyndrom: NO
Received message: ada
original: ada
polyndrom: YES
Received message: ada ada
original: ada ada
polyndrom: YES
Received message: hi ih
original: hi ih
polyndrom: YES
Received message: goodbye
Server has finished with current client!
^C
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5/server[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5/server[00m$ [?2004l
exit
Script done on 2023-01-22 11:32:47+02:00 [COMMAND_EXIT_CODE="130"]




Client:

Script started on 2023-01-22 11:32:05+02:00 [TERM="xterm-256color" TTY="/dev/pts/0" COLUMNS="80" LINES="24"]
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5[00m$ cd client/
[?2004l
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5/client[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5/client[00m$ make clean
[?2004l
rm -f *.o client
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5/client[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5/client[00m$ make all
[?2004l
clang++ -c -Wall mainClient.cpp -o mainClient.o
clang++ -c -Wall TCPClient.cpp -o TCPClient.o
clang++ mainClient.o TCPClient.o -o client
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5/client[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5/client[00m$ ./client 
[?2004l
Enter message to send to server: hi
Message sent to server: hi
Enter message to send to server: ada
Message sent to server: ada
Enter message to send to server: ada ada
Message sent to server: ada ada
Enter message to send to server: hi ih
Message sent to server: hi ih
Enter message to send to server: quit
goodbye sent to server, closing connection
[?2004h]0;appeldaniel@appeldaniel-virtual-machine: ~/CLionProjects/Operating-Systems-Assignment-5/client[01;32mappeldaniel@appeldaniel-virtual-machine[00m:[01;34m~/CLionProjects/Operating-Systems-Assignment-5/client[00m$ [?2004l
exit
Script done on 2023-01-22 11:32:45+02:00 [COMMAND_EXIT_CODE="0"]
