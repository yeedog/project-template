# Purpose
The purpose of this code is for me to experiment with the C++17 standard and learn the basics of using the following open source libraries:
* [ZMQ](http://zeromq.org/)
* [Protocol Buffers](https://developers.google.com/protocol-buffers/)

# Environment
The environment used for development is Ubuntu 18.04.1 LTS.  This was done through WSL on a Windows 10 machine. CLion is used as the IDE and requires so additional setup to work with WSL.

The following shell scripts can be used to set up WSL for my development environment:

* [CLion setup on WSL](https://github.com/yeedog/shell-scripts/blob/master/scripts/setup_clion_wsl.sh)
* [ZMQ setup on WSL](https://github.com/yeedog/shell-scripts/blob/master/scripts/setup_zmq.sh)

The Protocol Buffer project provides instructions for building and installing 

* [Protocol Buffer Setup](https://github.com/protocolbuffers/protobuf/blob/master/src/README.md)

# Design
The project uses ZMQ in a synchronous client-server pattern to communicated between two Linux process.  Protocol Buffers are used to define a language agnostic interface between the client and server.

* TODO: Create a picture of the architecture

# License
This software is governed by the MIT License.

