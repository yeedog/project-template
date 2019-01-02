// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef MESSAGE_QUEUE_SERVER_H
#define MESSAGE_QUEUE_SERVER_H

#include <string>
#include <zmq.h>
#include "message_queue.h"

class message_queue_server : public message_queue
{
   public:

      message_queue_server();

      void create( std::string );
      void destroy( std::string );

   protected:
   private:

      std::tuple<int32_t, std::string> read( int32_t ) override;

};

#endif //MESSAGE_QUEUE_SERVER_H
