// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cassert>

#include "exec_process.h"

exec_process::exec_process( const std::string path, const std::string name ) :
   _path( path ),
   _name( name ),
   _full_name( _path + "/" + _name ),
   _pid( -1 ),
   _status( status::STOPPED ),
   _system_time_sec()
{
   //do nothing
}

void exec_process::start()
{
   assert( _status == status::STOPPED );

   _pid = fork();
   if ( _pid < 0 )
   {
      std::cout << "Process Failed To Start due to fork(): " << _full_name << std::endl;

   }
   else if ( _pid == 0 )
   {
      if ( execl( _full_name.c_str(), _full_name.c_str(), NULL ) == -1 )
      {
         std::cout << "Child Process Failed To Start due to execl(): " << _full_name << std::endl;
      }
   }
   else
   {
      _status = status::STARTED;
   }
}

void exec_process::stop()
{
   std::cout << "Stopping Process: " << _name << std::endl;

   if ( _pid > 0 )
   {
      kill( _pid, SIGTERM );

      int32_t status;
      waitpid( _pid, &status, WNOHANG );

      if ( status == _pid )
      {
         std::cout << "Stopped Process Failed: " << std::endl;
         std::cout << "\tName: (" << _name << ")" << std::endl;
         std::cout << "\tPid: (" << _pid << ")" << std::endl;
         std::cout << "\tStatus: (" << status << ")" << std::endl;
      }
      else
      {
         std::cout << "Stopped Process Passed: " << std::endl;
         std::cout << "\tName: (" << _name << ")" << std::endl;
         std::cout << "\tPid: (" << _pid << ")" << std::endl;
         std::cout << "\tStatus: (" << status << ")" << std::endl;

         _pid = -1;
         _status = status::STOPPED;
      }
   }
}

void exec_process::kick_watchdog()
{
   //std::cout << "Kicking Watchdog For Process: " << _name << std::endl;

   _system_time_sec = std::chrono::system_clock::now();
   _status = status::RUNNING;

   //auto time_t = std::chrono::system_clock::to_time_t( _system_time_sec );
   //std::cout << "Kicking Watchdog For Process: " << std::to_string( time_t ) << std::endl;
}

exec_process::status exec_process::getStatus() const
{
   return _status;
}
