// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef LOGGER_EXEC_CLIENT_H
#define LOGGER_EXEC_CLIENT_H

#include <message_queue_client.h>
#include <executive.pb.h>

class logger_exec_client
{
   public:

      static logger_exec_client &getInstance();

      void process( ProtoExecutive::Message_Type );

   protected:
   private:

      message_queue_client _mq_exec_client;

      logger_exec_client();
      ~logger_exec_client();

      std::string create( ProtoExecutive::Message_Type );
      void send( std::string );
      void receive();
};

#endif //LOGGER_EXEC_CLIENT_H
