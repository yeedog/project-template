// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <iostream>
#include <cstring>
#include <tuple>
#include "message_queue_client.h"

message_queue_client::message_queue_client() :
   message_queue( ZMQ_REQ )
{
   // do nothing
}

void message_queue_client::connect( const std::string address)
{
   int32_t status = zmq_connect(_socket, address.c_str());

   if( status != 0 )
   {
      std::cout << "Server Create Failed with Errno (" << errno << "): " << strerror(errno) << std::endl;
   }
}

void message_queue_client::disconnect( const std::string address )
{
   int32_t status = zmq_disconnect(_socket, address.c_str());

   if( status != 0 )
   {
      std::cout << "Server Create Failed with Errno (" << errno << "): " << strerror(errno) << std::endl;
   }
}
std::tuple<int32_t, std::string> message_queue_client::read( const int32_t size )
{
   auto[total_bytes, message] = message_queue::read( size, 0 );
   return std::make_tuple( total_bytes, message );
}
