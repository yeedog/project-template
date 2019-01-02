// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <zmq.h>
#include <iostream>
#include <cstring>
#include <tuple>
#include "message_queue_server.h"

message_queue_server::message_queue_server() :
   message_queue( ZMQ_REP )
{
   // do nothing
}

void message_queue_server::create( std::string address )
{
   int32_t status = zmq_bind(_socket, address.c_str());

   if( status != 0 )
   {
      std::cout << "Server Create Failed with Errno (" << errno << "): " << strerror(errno) << std::endl;
   }
}

void message_queue_server::destroy( std::string address )
{
   int32_t status = zmq_unbind(_socket, address.c_str());

   if( status != 0 )
   {
      std::cout << "Server Destroy Failed with Errno (" << errno << "): " << strerror(errno) << std::endl;
   }
}

std::tuple<int32_t, std::string> message_queue_server::read( const int32_t size )
{
   auto[total_bytes, message] = message_queue::read( size, ZMQ_DONTWAIT );
   return std::make_tuple( total_bytes, message );
}
