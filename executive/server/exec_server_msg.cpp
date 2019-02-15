// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <executive.pb.h>
#include "exec_server_msg.h"
#include "exec_server_msg_version.h"
#include "exec_server_msg_watchdog.h"

exec_server_msg::exec_server_msg( const ProtoExecutive::Exec_Inbound_Message msg ) :
   _messageFromClient( msg )
{
   // do nothing
}

std::shared_ptr<exec_server_msg> exec_server_msg::build( const std::string data )
{
   ProtoExecutive::Exec_Inbound_Message msg;
   msg.ParseFromString( data );

   switch ( msg.message_type() )
   {
      case ProtoExecutive::VERSION:
      {
         return std::make_shared<exec_server_msg_version>( msg );
      }

      case ProtoExecutive::WATCHDOG:
      {
         return std::make_shared<exec_server_msg_watchdog>( msg );
      }

      case ProtoExecutive::INVALID_TYPE:
      default:
      {
         break;
      }
   }

   return nullptr;
}

ProtoExecutive::Exec_Inbound_Message exec_server_msg::getMessageFromClient() const
{
   return _messageFromClient;
}
