// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef LOGGER_EXEC_CLIENT_MSG_H
#define LOGGER_EXEC_CLIENT_MSG_H

#include <string>
#include <memory>

class logger_exec_client_msg
{
   public:

      static std::shared_ptr<logger_exec_client_msg> build( ProtoExecutive::Message_Type );
      static std::shared_ptr<logger_exec_client_msg> build( std::string );

      virtual ~logger_exec_client_msg() = default;

      virtual std::string create() = 0;
      virtual void process() = 0;

   protected:
   private:

};

#endif //LOGGER_EXEC_CLIENT_MSG_H
