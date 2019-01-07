# Copyright 2018 - 2019
# The "project-template" Authors. All rights reserved.
# Use of this source code is governed by the MIT License that can be found in the LICENSE file.

cmake_minimum_required( VERSION 3.5 )
project( project-template )

set( CMAKE_CXX_STANDARD 17 )

include_directories( ../message_queues )
include_directories( ../cmake-build-debug/proto_buffers/ )

include_directories( client )

set( LOGGER_SRC_FILES
     client/logger_exec_client.cpp
     client/logger_exec_client.h
     client/logger_exec_client_msg.cpp
     client/logger_exec_client_msg.h
     client/logger_exec_client_msg_version.cpp
     client/logger_exec_client_msg_version.h
     client/logger_exec_client_msg_watchdog.cpp
     client/logger_exec_client_msg_watchdog.h
     logger.cpp
     logger.h
     main.cpp )

add_executable( logger ${LOGGER_SRC_FILES} )
target_link_libraries( logger message_queues proto )
