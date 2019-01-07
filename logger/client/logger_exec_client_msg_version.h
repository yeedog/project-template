// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef LOGGER_EXEC_CLIENT_MESSAGE_VERSION_H
#define LOGGER_EXEC_CLIENT_MESSAGE_VERSION_H

#include "logger.pb.h"
#include "logger_exec_client_msg.h"

class logger_exec_client_msg_version : public logger_exec_client_msg
{
   public:

      logger_exec_client_msg_version();
      explicit logger_exec_client_msg_version( ProtoLogger::Logger_Message );

      std::string create() override;
      void process() override;

   protected:
   private:

      ProtoLogger::Logger_Message _messageFromServer;
};

#endif //LOGGER_EXEC_CLIENT_MESSAGE_VERSION_H
