// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <executive.pb.h>

#include "model_exec_client_msg.h"
#include "model_exec_client_msg_version.h"
#include "model_exec_client_msg_watchdog.h"

std::shared_ptr<model_exec_client_msg> model_exec_client_msg::build( const ProtoExecutive::Message_Type message_type )
{
   switch ( message_type )
   {
      case ProtoExecutive::VERSION_INTERFACE:
      {
         return std::make_shared<model_exec_client_msg_version>();
      }

      case ProtoExecutive::WATCHDOG_KICK:
      {
         return std::make_shared<model_exec_client_msg_watchdog>();
      }

      case ProtoExecutive::INVALID_TYPE:
      default:
      {
         break;
      }
   }

   return nullptr;
}

std::shared_ptr<model_exec_client_msg> model_exec_client_msg::build( const std::string data )
{
   ProtoModel::Model_Message msg;
   msg.ParseFromString( data );

   switch ( msg.message_type() )
   {
      case ProtoModel::VERSION_INTERFACE:
      {
         return std::make_shared<model_exec_client_msg_version>( msg );
      }

      case ProtoModel::WATCHDOG_KICK:
      {
         return std::make_shared<model_exec_client_msg_watchdog>( msg );
      }

      case ProtoModel::INVALID_TYPE:
      default:
      {
         break;
      }
   }

   return nullptr;
}
