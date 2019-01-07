// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include "executive.h"
#include "exec_server.h"

#include "exec_process_data.h"
#include "exec_process_map.h"

void executive::init()
{
   exec_process_map::getInstance().init( executive_process_data::process_data_map );
}

void executive::start()
{
   auto loop = true;
   do
   {
      auto[id, proc] = exec_process_map::getInstance().find( exec_process::status::STOPPED );

      loop = ( id != ProtoExecutive::INVALID_PROCESS );
      if ( loop )
      {
         proc.start();
         exec_process_map::getInstance().update( id, proc );
      }

   } while ( loop );
}

void executive::stop( const exec_process::status status )
{
   auto loop = true;
   do
   {
      auto[id, proc] = exec_process_map::getInstance().find( status );

      loop = ( id != ProtoExecutive::INVALID_PROCESS );
      if ( loop )
      {
         proc.stop();
         exec_process_map::getInstance().update( id, proc );
      }

   } while ( loop );
}

void executive::run()
{
   exec_server::getInstance().process();
}
