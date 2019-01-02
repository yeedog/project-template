// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_CLIENT_MSG_WATCHDOG_H
#define EXEC_CLIENT_MSG_WATCHDOG_H

#include <logger.pb.h>
#include "exec_client_msg.h"

class exec_client_msg_watchdog : public exec_client_msg
{
   public:

      exec_client_msg_watchdog();
      explicit exec_client_msg_watchdog( ProtoLogger::Logger_Message );

      std::string create() override;
      void process() override;

   protected:
   private:

      ProtoLogger::Logger_Message _messageFromServer;
};

#endif //EXEC_CLIENT_MSG_WATCHDOG_H
