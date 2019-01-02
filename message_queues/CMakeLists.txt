# Copyright 2018 - 2019
# The "project-template" Authors. All rights reserved.
# Use of this source code is governed by the MIT License that can be found in the LICENSE file.

cmake_minimum_required( VERSION 3.5 )
project( project-template )

set( CMAKE_CXX_STANDARD 17 )

set( MESSAGE_QUEUES_SRC_FILES
     message_queue_client.cpp
     message_queue_client.h
     message_queue_server.cpp
     message_queue_server.h
     message_queue.cpp
     message_queue.h )

add_library( message_queues ${MESSAGE_QUEUES_SRC_FILES} )
target_link_libraries( message_queues zmq)
