// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_SERVER_MSG_WATCHDOG_H
#define EXEC_SERVER_MSG_WATCHDOG_H

#include <executive.pb.h>
#include "exec_server_msg.h"

class exec_server_msg_watchdog : public exec_server_msg
{
   public:

      explicit exec_server_msg_watchdog( ProtoExecutive::Exec_Message );

      void process() override;
      std::string reply() override;

   protected:
   private:

      ProtoExecutive::Exec_Message _messageFromClient;
};

#endif //EXEC_SERVER_MSG_WATCHDOG_H
