// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_CLIENT_MSG_H
#define EXEC_CLIENT_MSG_H

#include <string>
#include <memory>

class exec_client_msg
{
   public:

      static std::shared_ptr<exec_client_msg> build( ProtoExecutive::Message_Type );
      static std::shared_ptr<exec_client_msg> build( std::string );

      virtual ~exec_client_msg() = default;

      virtual void process() = 0;
      virtual std::string create( ProtoExecutive::Process_Id ) = 0;

   protected:

      exec_client_msg() = default;
      explicit exec_client_msg( ProtoExecutive::Exec_Outbound_Message );

      ProtoExecutive::Exec_Outbound_Message getMessageFromServer() const;

   private:

      ProtoExecutive::Exec_Outbound_Message _messageFromServer;
};

#endif //EXEC_CLIENT_MSG_H
