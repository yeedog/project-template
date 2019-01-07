// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef MODEL_EXEC_CLIENT_MESSAGE_VERSION_H
#define MODEL_EXEC_CLIENT_MESSAGE_VERSION_H

#include "model.pb.h"
#include "model_exec_client_msg.h"

class model_exec_client_msg_version : public model_exec_client_msg
{
   public:

      model_exec_client_msg_version();
      explicit model_exec_client_msg_version( ProtoModel::Model_Message );

      std::string create() override;
      void process() override;

   protected:
   private:

      ProtoModel::Model_Message _messageFromServer;
};

#endif //MODEL_EXEC_CLIENT_MESSAGE_VERSION_H
