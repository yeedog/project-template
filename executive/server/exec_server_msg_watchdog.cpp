// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <logger.pb.h>
#include "exec_server_msg_watchdog.h"
#include "exec_process_map.h"

exec_server_msg_watchdog::exec_server_msg_watchdog( ProtoExecutive::Exec_Inbound_Message msg ) :
   exec_server_msg( msg )
{
   // do nothing
}

void exec_server_msg_watchdog::process()
{
   //std::cout << "Executive MQ Server Receive: ";
   //std::cout << exec_server_msg::getMessageFromClient().ShortDebugString() << std::endl;

   ProtoExecutive::Process_Id id = exec_server_msg::getMessageFromClient().proc_id();

   auto proc = exec_process_map::getInstance().find( id );
   proc.kick_watchdog();

   exec_process_map::getInstance().update( id, proc );
}

std::string exec_server_msg_watchdog::reply()
{
   ProtoExecutive::Version_Outbound_Message reply;
   reply.set_status( ProtoExecutive::ACCEPT );

   auto messageToClient = std::make_shared<ProtoExecutive::Exec_Outbound_Message>();
   messageToClient->set_message_type( ProtoExecutive::WATCHDOG );
   messageToClient->mutable_version()->CopyFrom( reply );

   //std::cout << "Executive MQ Server Send: " << messageToClient->ShortDebugString() << std::endl;

   return messageToClient->SerializeAsString();
}
