// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <executive.pb.h>
#include "exec_client_msg_watchdog.h"

exec_client_msg_watchdog::exec_client_msg_watchdog() :
   _messageFromServer()
{
   // do nothing
}

exec_client_msg_watchdog::exec_client_msg_watchdog( const ProtoLogger::Logger_Message msg ) :
   _messageFromServer( msg )
{
   // do nothing
}

std::string exec_client_msg_watchdog::create()
{
   auto watchdog = std::make_shared<ProtoExecutive::Watchdog_Kick>();
   watchdog.get()->set_id( ProtoExecutive::LOGGER );

   ProtoExecutive::Exec_Message msg;
   msg.set_message_type( ProtoExecutive::WATCHDOG_KICK );
   msg.mutable_watchdog()->CopyFrom( *watchdog );

   std::cout << "Logger MQ Client Create: " << msg.ShortDebugString() << std::endl;
   return msg.SerializeAsString();
}

void exec_client_msg_watchdog::process()
{
   std::cout << "Logger MQ Client Process: " << _messageFromServer.ShortDebugString() << std::endl;

   if ( _messageFromServer.watchdog().status() != ProtoLogger::ACCEPT )
   {
      std::cout << "Message Failed: Watchdog" << std::endl;
      std::cout << "\t" << "Received: (" << _messageFromServer.version().status();
      std::cout << ") Expected: (" << ProtoLogger::ACCEPT << ")" << std::endl;
   }
}
