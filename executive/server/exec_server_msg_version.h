// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_SERVER_MSG_VERSION_H
#define EXEC_SERVER_MSG_VERSION_H

#include <string>
#include "exec_server_msg.h"

class exec_server_msg_version : public exec_server_msg
{
   public:

      explicit exec_server_msg_version( ProtoExecutive::Exec_Inbound_Message );

      void process() override;
      std::string reply() override;

   protected:
   private:
};

#endif //EXEC_SERVER_MSG_VERSION_H
