// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <model.pb.h>
#include <executive.pb.h>

#include "model_exec_client.h"
#include "model_exec_client_msg_version.h"

model_exec_client_msg_version::model_exec_client_msg_version() :
   _messageFromServer()
{
   // do nothing
}

model_exec_client_msg_version::model_exec_client_msg_version( const ProtoModel::Model_Message msg ) :
   _messageFromServer( msg )
{
   // do nothing
}

std::string model_exec_client_msg_version::create()
{
   auto version = std::make_shared<ProtoExecutive::Version_Interface>();
   version.get()->set_version( 1 );

   ProtoExecutive::Exec_Message msg;
   msg.set_message_type( ProtoExecutive::VERSION_INTERFACE );
   msg.mutable_version()->CopyFrom( *version );

   std::cout << "Model MQ Client Create: " << msg.ShortDebugString() << std::endl;
   return msg.SerializeAsString();
}

void model_exec_client_msg_version::process()
{
   std::cout << "Model MQ Client Process: " << _messageFromServer.ShortDebugString() << std::endl;

   if ( _messageFromServer.version().status() != ProtoModel::ACCEPT )
   {
      std::cout << "Model Message Failed: Version" << std::endl;
   }
}
