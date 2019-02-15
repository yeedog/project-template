// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <executive.pb.h>

#include "exec_client_msg.h"
#include "exec_client_msg_version.h"
#include "exec_client_msg_watchdog.h"

exec_client_msg::exec_client_msg( const ProtoExecutive::Exec_Outbound_Message msg ) :
   _messageFromServer( msg )
{
   // do nothing
}

std::shared_ptr<exec_client_msg> exec_client_msg::build( const ProtoExecutive::Message_Type type )
{
   switch ( type )
   {
      case ProtoExecutive::VERSION:
      {
         return std::make_shared<exec_client_msg_version>();
      }

      case ProtoExecutive::WATCHDOG:
      {
         return std::make_shared<exec_client_msg_watchdog>();
      }

      case ProtoExecutive::INVALID_TYPE:
      default:
      {
         break;
      }
   }

   return nullptr;
}

std::shared_ptr<exec_client_msg> exec_client_msg::build( const std::string data )
{
   ProtoExecutive::Exec_Outbound_Message msg;
   msg.ParseFromString( data );

   switch ( msg.message_type() )
   {
      case ProtoExecutive::VERSION:
      {
         return std::make_shared<exec_client_msg_version>( msg );
      }

      case ProtoExecutive::WATCHDOG:
      {
         return std::make_shared<exec_client_msg_watchdog>( msg );
      }

      case ProtoExecutive::INVALID_TYPE:
      default:
      {
         break;
      }
   }

   return nullptr;
}

ProtoExecutive::Exec_Outbound_Message exec_client_msg::getMessageFromServer() const
{
   return _messageFromServer;
}
