// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef MESSAGE_QUEUE_CLIENT_H
#define MESSAGE_QUEUE_CLIENT_H

#include <string>
#include <vector>
#include <zmq.h>
#include "message_queue.h"

class message_queue_client : public message_queue
{
   public:

      message_queue_client();

      void connect( std::string );
      void disconnect( std::string);

   protected:
   private:

      std::tuple<int32_t, std::string> read( int32_t ) override;

};

#endif //MESSAGE_QUEUE_CLIENT_H
