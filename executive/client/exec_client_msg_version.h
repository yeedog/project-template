// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_CLIENT_MSG_VERSION_H
#define EXEC_CLIENT_MSG_VERSION_H

#include "exec_client_msg.h"

class exec_client_msg_version : public exec_client_msg
{
   public:

      exec_client_msg_version() = default;
      explicit exec_client_msg_version( ProtoExecutive::Exec_Outbound_Message );

      void process() override;
      std::string create( ProtoExecutive::Process_Id ) override;

   protected:

   private:
};

#endif //EXEC_CLIENT_MSG_VERSION_H
