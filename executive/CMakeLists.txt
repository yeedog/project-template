# Copyright 2018 - 2019
# The "project-template" Authors. All rights reserved.
# Use of this source code is governed by the MIT License that can be found in the LICENSE file.

cmake_minimum_required( VERSION 3.5 )
project( project-template )

set( CMAKE_CXX_STANDARD 17 )

include_directories( ../message_queues )
include_directories( ../cmake-build-debug/proto_buffers/ )

include_directories( client )
include_directories( process )
include_directories( server )

set( EXECUTIVE_SRC_FILES
     executive.cpp
     executive.h
     main.cpp
     process/exec_process.cpp
     process/exec_process.h
     process/exec_process_data.h
     process/exec_process_map.cpp
     process/exec_process_map.h
     server/exec_server.cpp
     server/exec_server.h
     server/exec_server_msg.cpp
     server/exec_server_msg.h
     server/exec_server_msg_version.cpp
     server/exec_server_msg_version.h
     server/exec_server_msg_watchdog.cpp
     server/exec_server_msg_watchdog.h  )

add_executable( executive ${EXECUTIVE_SRC_FILES} )
target_link_libraries( executive message_queues proto )

set( EXECUTIVE_CLIENT_SRC_FILES
     client/exec_client.cpp
     client/exec_client.h
     client/exec_client_msg.cpp
     client/exec_client_msg.h
     client/exec_client_msg_version.cpp
     client/exec_client_msg_version.h
     client/exec_client_msg_watchdog.cpp
     client/exec_client_msg_watchdog.h )

add_library( exec_client ${EXECUTIVE_CLIENT_SRC_FILES} )
target_link_libraries( exec_client message_queues proto )

#add_custom_command( TARGET executive
#                    POST_BUILD
#                    COMMAND /bin/sh /path/to/my_script )
