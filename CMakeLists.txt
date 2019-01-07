# Copyright 2018 - 2019
# The "project-template" Authors. All rights reserved.
# Use of this source code is governed by the MIT License that can be found in the LICENSE file.

cmake_minimum_required( VERSION 3.5 )
project( project-template )

set( CMAKE_CXX_STANDARD 17 )

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

add_subdirectory( executive )
add_subdirectory( logger )
add_subdirectory( message_queues )
add_subdirectory( model )
add_subdirectory( proto_buffers )
