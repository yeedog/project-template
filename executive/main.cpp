// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <iostream>
#include <csignal>
#include <thread>
#include <cstring>

#include "executive.h"

namespace
{
   volatile std::sig_atomic_t g_SignalStatus = 0;
}

void signal_handler( int32_t signal )
{
   if ( g_SignalStatus == 0 )
   {
      g_SignalStatus = signal;

      std::cout << "Executive Caught Signal: " << std::endl;
      std::cout << "\tSignal Number: (" << g_SignalStatus << ")" << std::endl;
      std::cout << "\tSignal String: (" << strsignal( g_SignalStatus ) << ")" << std::endl;
   }
}

void installSignals()
{
   std::signal( SIGABRT, signal_handler );
   std::signal( SIGALRM, signal_handler );
   std::signal( SIGBUS, signal_handler );
   std::signal( SIGCHLD, signal_handler );
   std::signal( SIGCONT, signal_handler );
   std::signal( SIGFPE, signal_handler );
   std::signal( SIGHUP, signal_handler );
   std::signal( SIGILL, signal_handler );
   std::signal( SIGINT, signal_handler );
   std::signal( SIGIO, signal_handler );
   std::signal( SIGKILL, signal_handler );
   std::signal( SIGPIPE, signal_handler );
   std::signal( SIGPROF, signal_handler );
   std::signal( SIGPWR, signal_handler );
   std::signal( SIGQUIT, signal_handler );
   std::signal( SIGSEGV, signal_handler );
   std::signal( SIGSTKFLT, signal_handler );
   std::signal( SIGSTOP, signal_handler );
   std::signal( SIGSYS, signal_handler );
   std::signal( SIGTERM, signal_handler );
   std::signal( SIGTRAP, signal_handler );
   std::signal( SIGTSTP, signal_handler );
   std::signal( SIGTTIN, signal_handler );
   std::signal( SIGTTOU, signal_handler );
   std::signal( SIGURG, signal_handler );
   std::signal( SIGVTALRM, signal_handler );
   std::signal( SIGWINCH, signal_handler );
   std::signal( SIGXCPU, signal_handler );
   std::signal( SIGXFSZ, signal_handler );
}

int main()
{
   std::cout << "Executive: Starting" << std::endl;

   installSignals();

   executive exec;
   exec.init();
   exec.start();

   std::cout << "Executive: Entering Main Loop" << std::endl;
   while ( g_SignalStatus == 0 )
   {
      exec.run();

      std::this_thread::sleep_for( std::chrono::milliseconds( 5 ) );
   }

   std::cout << "Executive: Exiting Imminent" << std::endl;
   exec.stop( exec_process::status::STARTED );
   exec.stop( exec_process::status::RUNNING );

   std::cout << "Executive: Exiting" << std::endl;
   return 0;
}
