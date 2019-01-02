// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "exec_process.h"

class executive
{
   public:

      void init();
      void run();

      void start();
      void stop( exec_process::status );

   protected:
   private:


};

#endif //EXECUTIVE_H
