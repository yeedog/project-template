// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <executive.pb.h>
#include "model_exec_client_msg_watchdog.h"

model_exec_client_msg_watchdog::model_exec_client_msg_watchdog() :
   _messageFromServer()
{
   // do nothing
}

model_exec_client_msg_watchdog::model_exec_client_msg_watchdog( const ProtoModel::Model_Message msg ) :
   _messageFromServer( msg )
{
   // do nothing
}

std::string model_exec_client_msg_watchdog::create()
{
   auto watchdog = std::make_shared<ProtoExecutive::Watchdog_Kick>();
   watchdog.get()->set_id( ProtoExecutive::MODEL );

   ProtoExecutive::Exec_Message msg;
   msg.set_message_type( ProtoExecutive::WATCHDOG_KICK );
   msg.mutable_watchdog()->CopyFrom( *watchdog );

   std::cout << "Model MQ Client Create: " << msg.ShortDebugString() << std::endl;
   return msg.SerializeAsString();
}

void model_exec_client_msg_watchdog::process()
{
   std::cout << "Model MQ Client Process: " << _messageFromServer.ShortDebugString() << std::endl;

   if ( _messageFromServer.watchdog().status() != ProtoModel::ACCEPT )
   {
      std::cout << "Message Failed: Watchdog" << std::endl;
      std::cout << "\t" << "Received: (" << _messageFromServer.version().status();
      std::cout << ") Expected: (" << ProtoModel::ACCEPT << ")" << std::endl;
   }
}
