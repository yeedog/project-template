// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_SERVER_MSG_H
#define EXEC_SERVER_MSG_H

#include <string>
#include <memory>

class exec_server_msg
{
   public:

      static std::shared_ptr<exec_server_msg> build( std::string );
      virtual ~exec_server_msg() = default;

      virtual void process() = 0;
      virtual std::string reply() = 0;

   protected:

      explicit exec_server_msg( ProtoExecutive::Exec_Inbound_Message );
      ProtoExecutive::Exec_Inbound_Message getMessageFromClient() const;

   private:

      ProtoExecutive::Exec_Inbound_Message _messageFromClient;
};

#endif //EXEC_SERVER_MSG_H
