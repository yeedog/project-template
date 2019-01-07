// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include "logger.pb.h"
#include "executive.pb.h"

#include "exec_server.h"
#include "exec_server_msg.h"

exec_server::exec_server() :
   _mq_exec_server()
{
   _mq_exec_server.create( "ipc:///tmp/executive" );
}

exec_server::~exec_server()
{
   _mq_exec_server.destroy( "ipc:///tmp/executive" );
}

exec_server &exec_server::getInstance()
{
   static auto client = exec_server();
   return client;
}

void exec_server::process()
{
   std::string receivedData = receive();
   if ( !receivedData.empty() )
   {
      auto msgHandler = exec_server_msg::build( receivedData );
      msgHandler->process();
      send( msgHandler->reply() );
   }
   //else
   //{
   //   std::cout << "Server Receive: " << std::endl;
   //   std::cout << "\t" << "No Data" << std::endl;
   //}
}

void exec_server::send( const std::string message )
{
   message_queue::message_queue_status status = message_queue::message_queue_status::MESSAGE_QUEUE_INVALID;
   while ( status != message_queue::message_queue_status::MESSAGE_QUEUE_COMPLETE )
   {
      status = _mq_exec_server.send( message );
   }
}

std::string exec_server::receive()
{
   return _mq_exec_server.receive();
}
