// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXEC_PROCESS_DATA_H
#define EXEC_PROCESS_DATA_H

#include <string>
#include <vector>
#include <executive.pb.h>

namespace executive_process_data
{
   typedef struct
   {
      ProtoExecutive::Process_Id id;

      std::string path;
      std::string name;
   } process_data;

   const std::vector<executive_process_data::process_data> process_data_map =
      {
         {ProtoExecutive::LOGGER, "/mnt/c/Users/Brian/CLionProjects/NewProjectTemplate/cmake-build-debug/logger", "logger"},
      };
};

#endif //EXEC_PROCESS_DATA_H
