# Copyright 2018 - 2019
# The "project-template" Authors. All rights reserved.
# Use of this source code is governed by the MIT License that can be found in the LICENSE file.

cmake_minimum_required( VERSION 3.5 )
project( project-template )

set( CMAKE_CXX_STANDARD 17 )

set( PROTO_SRC_FILES
     executive.proto )

find_package( Protobuf REQUIRED )
include_directories( $(PROTOBUF_INCLUDE_DIR))
include_directories(${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp( PROTO_SRC PROTO_HEADER ${PROTO_SRC_FILES} )

add_library( proto ${PROTO_SRC} ${PROTO_HEADER} )
target_link_libraries( proto ${PROTOBUF_LIBRARY} )
