// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>

#include "message_queue.h"

message_queue::message_queue( const int32_t Type )
{
   _context = zmq_ctx_new();
   _socket = zmq_socket( _context, Type );
}

message_queue::~message_queue()
{
   zmq_close( _socket );
   zmq_ctx_destroy( _context );
}

message_queue::message_queue_status message_queue::send( const std::string message )
{
   const int32_t sent_bytes = zmq_send( _socket, message.c_str(), message.size(), ZMQ_DONTWAIT );
   if ( sent_bytes != static_cast<int32_t >( message.size() ) )
   {
      std::cout << "Send Failed with Errno (" << errno << "): " << strerror( errno ) << std::endl;
      return message_queue_status::MESSAGE_QUEUE_FAIL;
   }

   return message_queue_status::MESSAGE_QUEUE_COMPLETE;
}

std::string message_queue::receive()
{
   const int32_t max_bytes = 1000;
   auto[total_bytes, message] = read( max_bytes );

   const bool received_failed = ( total_bytes == -1 );
   if ( received_failed )
   {
      //std::cout << "Receive Failed: " << std::endl;
      //std::cout << '\t' << "Errno (" << errno << "): " << strerror( errno ) << std::endl;

      message.clear();
   }

   const bool received_truncated = ( total_bytes != static_cast<int32_t >( message.size() ) );
   if ( !received_failed && received_truncated )
   {
      std::cout << "Receive Failed: Message Truncated" << std::endl;
      std::cout << '\t' << "Expected: (" << total_bytes << ") bytes" << std::endl;
      std::cout << '\t' << "Actual: (" << message.size() << ") bytes" << std::endl;
      std::cout << '\t' << "Max: (" << max_bytes << ") bytes" << std::endl;

      message.clear();
   }

   return message;
}

std::tuple<int32_t, std::string> message_queue::read( const int32_t max_bytes, const int32_t flags )
{
   char buffer[max_bytes];
   memset( &buffer, '\0', static_cast<size_t>( max_bytes ) );

   const int32_t total_bytes = zmq_recv( _socket, buffer, max_bytes, flags );
   std::string message = ( ( total_bytes > 0 ) ? std::string( buffer ) : std::string() );

   return std::make_tuple( total_bytes, message );
}
