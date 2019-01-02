// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_PROCESS_MAP_H
#define EXEC_PROCESS_MAP_H

#include <map>
#include <executive.pb.h>


#include "exec_process.h"
#include "exec_process_data.h"

class exec_process_map
{
   public:

      static exec_process_map &getInstance();

      void init( std::vector<executive_process_data::process_data> );
      void update( ProtoExecutive::Process_Id, exec_process );

      exec_process find( ProtoExecutive::Process_Id ) const;
      std::tuple<ProtoExecutive::Process_Id, exec_process> find ( exec_process::status ) const;

   protected:
   private:

      exec_process_map() = default;
      ~exec_process_map() = default;

      std::map<ProtoExecutive::Process_Id, exec_process> _process_map;

      void insert( ProtoExecutive::Process_Id, exec_process );
      void remove( ProtoExecutive::Process_Id );
};

#endif //EXEC_PROCESS_MAP_H
