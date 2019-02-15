// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <executive.pb.h>
#include <logger.pb.h>

#include "exec_server_msg_version.h"

exec_server_msg_version::exec_server_msg_version( ProtoExecutive::Exec_Inbound_Message msg ) :
   exec_server_msg( msg )
{
   // do nothing
}

void exec_server_msg_version::process()
{
   std::cout << "Executive MQ Server Receive: " << exec_server_msg::getMessageFromClient().ShortDebugString() << std::endl;

   std::cout << "Software Version for: (" << exec_server_msg::getMessageFromClient().proc_id() << ")" << std::endl;
   std::cout << "\t" << "Version: (" << exec_server_msg::getMessageFromClient().version().software_version() << ")" << std::endl;
}

std::string exec_server_msg_version::reply()
{
   ProtoExecutive::Version_Outbound_Message reply;
   reply.set_status( ProtoExecutive::ACCEPT );

   auto messageToClient = std::make_shared<ProtoExecutive::Exec_Outbound_Message>();
   messageToClient->set_message_type( ProtoExecutive::VERSION );
   messageToClient->mutable_version()->CopyFrom( reply );

   std::cout << "Executive MQ Server Send: " << messageToClient->ShortDebugString() << std::endl;

   return messageToClient->SerializeAsString();
}
