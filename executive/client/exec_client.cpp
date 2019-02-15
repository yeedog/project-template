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

void exec_client::process( const ProtoExecutive::Process_Id procId,
                           const ProtoExecutive::Message_Type message_type )
{
   auto message = create( procId, message_type );
   send( message );
   receive();
}

std::string exec_client::create( const ProtoExecutive::Process_Id procId,
                                 const ProtoExecutive::Message_Type messageType )
{
   auto msgHandler = exec_client_msg::build( messageType );
   std::string message = msgHandler->create( procId );
   return message;
}

void exec_client::send( const std::string message )
{
   message_queue::message_queue_status status = message_queue::message_queue_status::MESSAGE_QUEUE_INVALID;
   while ( status != message_queue::message_queue_status::MESSAGE_QUEUE_COMPLETE )
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
}

