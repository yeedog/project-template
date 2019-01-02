// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <logger.pb.h>
#include "exec_server_msg_watchdog.h"
#include "exec_process_map.h"

exec_server_msg_watchdog::exec_server_msg_watchdog( ProtoExecutive::Exec_Message msg ) :
   _messageFromClient( msg )
{
   // do nothing
}

void exec_server_msg_watchdog::process()
{
   std::cout << "Executive MQ Server Receive: " << _messageFromClient.ShortDebugString() << std::endl;

   ProtoExecutive::Process_Id id = _messageFromClient.watchdog().id();
   auto proc = exec_process_map::getInstance().find( id );
   proc.kick_watchdog();

   exec_process_map::getInstance().update( id, proc );
}

std::string exec_server_msg_watchdog::reply()
{
   auto watchdog = std::make_shared<ProtoLogger::Watchdog_Kick>();
   watchdog->set_status( ProtoLogger::ACCEPT );

   ProtoLogger::Logger_Message msg;
   msg.set_message_type( ProtoLogger::WATCHDOG_KICK );
   msg.mutable_watchdog()->CopyFrom( *watchdog );

   std::cout << "Executive MQ Server Send: " << msg.ShortDebugString() << std::endl;

   return msg.SerializeAsString();
}
