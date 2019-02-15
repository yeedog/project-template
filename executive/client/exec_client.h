// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_CLIENT_H
#define EXEC_CLIENT_H

#include <message_queue_client.h>
#include <executive.pb.h>

class exec_client
{
   public:

      static exec_client &getInstance();

      void process( ProtoExecutive::Process_Id, ProtoExecutive::Message_Type );

   protected:
   private:

      message_queue_client _mq_exec_client;

      exec_client();
      ~exec_client();

      std::string create( ProtoExecutive::Process_Id, ProtoExecutive::Message_Type );

      void send( std::string );
      void receive();
};

#endif //EXEC_CLIENT_H
