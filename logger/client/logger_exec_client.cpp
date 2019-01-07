// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include "logger_exec_client.h"
#include "logger_exec_client_msg.h"

logger_exec_client::logger_exec_client() :
   _mq_exec_client()
{
   _mq_exec_client.connect( "ipc:///tmp/executive" );
}

logger_exec_client::~logger_exec_client()
{
   _mq_exec_client.disconnect( "ipc:///tmp/executive" );
}

logger_exec_client &logger_exec_client::getInstance()
{
   static logger_exec_client client = logger_exec_client();
   return client;
}

void logger_exec_client::process( const ProtoExecutive::Message_Type message_type )
{
   auto message = create( message_type);
   send( message );
   receive();
}

std::string logger_exec_client::create( const ProtoExecutive::Message_Type message_type )
{
   auto msgHandler = logger_exec_client_msg::build( message_type );
   std::string message = msgHandler->create();

   return message;
}

void logger_exec_client::send( const std::string message )
{
   message_queue::message_queue_status status = message_queue::message_queue_status::MESSAGE_QUEUE_INVALID;
   while ( status != message_queue::message_queue_status::MESSAGE_QUEUE_COMPLETE )
   {
      status = _mq_exec_client.send( message );
   }
}

void logger_exec_client::receive()
{
   std::string receivedData = _mq_exec_client.receive();
   if ( !receivedData.empty() )
   {
      auto msgHandler = logger_exec_client_msg::build( receivedData );
      msgHandler->process();
   }
//   else
//   {
//      std::cout << "Client Receive: " << std::endl;
//      std::cout << "\t" << "No Data" << std::endl;
//   }
}

