// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include "exec_client.h"
#include "exec_client_msg.h"

exec_client::exec_client() :
   _mq_exec_client()
{
   _mq_exec_client.connect( "ipc:///tmp/executive" );
}

exec_client::~exec_client()
{
   _mq_exec_client.disconnect( "ipc:///tmp/executive" );
}

exec_client &exec_client::getInstance()
{
   static exec_client client = exec_client();
   return client;
}

void exec_client::process( const ProtoExecutive::Message_Type message_type )
{
   auto message = create( message_type);
   send( message );
   receive();
}

std::string exec_client::create( const ProtoExecutive::Message_Type message_type )
{
   auto msgHandler = exec_client_msg::build( message_type );
   std::string message = msgHandler->create();

   return message;
}

void exec_client::send( const std::string message )
{
   message_queue::MESSAGE_QUEUE_STATUS status = message_queue::INVALID_QUEUE_STATUS;
   while ( status != message_queue::MESSAGE_QUEUE_COMPLETE )
   {
      status = _mq_exec_client.send( message );
   }
}

void exec_client::receive()
{
   std::string receivedData = _mq_exec_client.receive();
   if ( !receivedData.empty() )
   {
      auto msgHandler = exec_client_msg::build( receivedData );
      msgHandler->process();
   }
//   else
//   {
//      std::cout << "Client Receive: " << std::endl;
//      std::cout << "\t" << "No Data" << std::endl;
//   }
}

