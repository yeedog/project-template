// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <zmq.h>

class message_queue
{
   public:

      enum MESSAGE_QUEUE_STATUS
      {
         INVALID_QUEUE_STATUS,

         MESSAGE_QUEUE_FAIL,
         MESSAGE_QUEUE_COMPLETE
      };

      MESSAGE_QUEUE_STATUS send( std::string );
      std::string receive();

   protected:

      explicit message_queue( int32_t );
      ~message_queue();

      std::tuple<int32_t, std::string> read( int32_t, int32_t );

      void *_context;
      void *_socket;

   private:

      virtual std::tuple<int32_t, std::string> read( int32_t ) = 0;

};

#endif //MESSAGE_QUEUE_H
