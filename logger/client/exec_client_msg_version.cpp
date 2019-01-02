// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include "logger.pb.h"
#include "executive.pb.h"

#include "exec_client.h"
#include "exec_client_msg_version.h"

exec_client_msg_version::exec_client_msg_version() :
   _messageFromServer()
{
   // do nothing
}

exec_client_msg_version::exec_client_msg_version( const ProtoLogger::Logger_Message msg ) :
   _messageFromServer( msg )
{
   // do nothing
}

std::string exec_client_msg_version::create()
{
   auto version = std::make_shared<ProtoExecutive::Version_Interface>();
   version.get()->set_version( 1 );

   ProtoExecutive::Exec_Message msg;
   msg.set_message_type( ProtoExecutive::VERSION_INTERFACE );
   msg.mutable_version()->CopyFrom( *version );

   std::cout << "Logger MQ Client Create: " << msg.ShortDebugString() << std::endl;
   return msg.SerializeAsString();
}

void exec_client_msg_version::process()
{
   std::cout << "Logger MQ Client Process: " << _messageFromServer.ShortDebugString() << std::endl;

   if ( _messageFromServer.version().status() != ProtoLogger::ACCEPT )
   {
      std::cout << "Message Failed: Version" << std::endl;
   }
}
