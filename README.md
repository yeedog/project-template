# Purpose
The purpose of this code was for me to experiment with the C++17 standard and learn the basics of using the following open source libraries:
* [ZMQ](http://zeromq.org/)
* [Protocal Buffers](https://developers.google.com/protocol-buffers/)

# Enviorment
The enviorment used for delvelopment is Ubuntu 18.04.1 LTS.  This was done through WSL on a Windows 10 machine. CLion is used as the IDE and requires so additional setup to work with WSL. 

The following shell scripts can be used to set up WSL for this software:

* TODO: ZMQ setup on WSL
* TODO: Protcol Buffer setup on WSL
* TODO: CLion setup on WSL

# Design
The current design uses ZMQ is a client-server pattern to communicated between two Linux process.  Protocol Buffers are used to define an interface between the client and server that is language agnostic.

## Executive
The Executive process is the server in the system and it's main resoponsibily is to start, stop and watchdog other process.  The watchdog provides a way to verify processes are still running with the goal of taking the system down upon the loss of any other process.

The Executive process makes use of Linux commands such as fork(), thus this software will only execute on Linux.

Executive Requirements:
* TODO

## Logger
The Logger process is the client in the system.  Currently it doesn't do anyting but connect to the Executive process and send and watchdog command in the main loop.

Logger Requirements:
* TODO

# License
This software is governed by the MIT License.

