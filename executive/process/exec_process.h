// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_PROCESS_H
#define EXEC_PROCESS_H

#include <string>
#include <chrono>

class exec_process
{
   public:

      enum class status
      {
         STARTED,
         RUNNING,
         STOPPED
      };

      explicit exec_process( std::string, std::string );

      void start();
      void stop();

      void kick_watchdog();

      exec_process::status getStatus() const;

   protected:

   private:

      std::string _path;
      std::string _name;
      std::string _full_name;

      pid_t _pid;

      status _status;

      std::chrono::time_point<std::chrono::system_clock> _system_time_sec;

};

#endif //EXEC_PROCESS_H
