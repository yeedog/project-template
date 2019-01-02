// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_SERVER_H
#define EXEC_SERVER_H

#include <message_queue_server.h>

class exec_server
{
   public:

      static exec_server &getInstance();

      void process();

   protected:
   private:

      message_queue_server _mq_exec_server;

      exec_server();
      ~exec_server();

      void send( std::string );
      std::string receive();
};

#endif //EXEC_SERVER_H
