// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <executive.pb.h>
#include <logger.pb.h>

#include "exec_server_msg_version.h"

exec_server_msg_version::exec_server_msg_version(ProtoExecutive::Exec_Message msg) :
   _messageFromClient(msg),
   _interfaceAccepted( false )
{
   // do nothing
}

void exec_server_msg_version::process()
{
   std::cout << "Executive MQ Server Receive: " << _messageFromClient.ShortDebugString() << std::endl;

   _interfaceAccepted = ( _messageFromClient.version().version() == _interfaceVersion );
   if( !_interfaceAccepted )
   {
      std::cout << "Bad Interface Version: (" << _messageFromClient.version().version() << ") Expected: (" << _interfaceVersion << ")" << std::endl;
   }
}

std::string exec_server_msg_version::reply()
{
   auto version = std::make_shared<ProtoLogger::Version_Interface>();
   version->set_status( _interfaceAccepted ? ProtoLogger::ACCEPT : ProtoLogger::REJECT );

   ProtoLogger::Logger_Message msg;
   msg.set_message_type( ProtoLogger::VERSION_INTERFACE );
   msg.mutable_version()->CopyFrom(*version);

   std::cout << "Executive MQ Server Send: " << msg.ShortDebugString() << std::endl;

   return msg.SerializeAsString();
}
