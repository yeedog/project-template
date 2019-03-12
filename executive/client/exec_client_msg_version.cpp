// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <iostream>
#include <executive.pb.h>

#include "exec_client_msg_version.h"

exec_client_msg_version::exec_client_msg_version( const ProtoExecutive::Exec_Outbound_Message msg ) :
   exec_client_msg( msg )
{
   // do nothing
}

void exec_client_msg_version::process()
{
   //std::cout << "Executive MQ Client Receive: ";
   //std::cout << exec_client_msg::getMessageFromServer().ShortDebugString()<< std::endl;
}

std::string exec_client_msg_version::create( const ProtoExecutive::Process_Id procId )
{
   auto messageToServer = std::make_shared<ProtoExecutive::Exec_Inbound_Message>();
   messageToServer->set_proc_id( procId );
   messageToServer->set_message_type( ProtoExecutive::VERSION );
   messageToServer->mutable_version()->set_software_version( "1.2.3" );

  // std::cout << "Executive MQ Client Send: " << messageToServer->ShortDebugString() << std::endl;

   return messageToServer->SerializeAsString();
}
