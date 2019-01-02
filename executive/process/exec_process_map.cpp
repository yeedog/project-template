// Copyright 2018 - 2019
// The "project-template" Authors. All rights reserved.
// Use of this source code is governed by the MIT License that can be found in the LICENSE file.

#include <algorithm>

#include "exec_process_map.h"

exec_process_map &exec_process_map::getInstance()
{
   static auto client = exec_process_map();
   return client;
}

void exec_process_map::init( const std::vector<executive_process_data::process_data> data )
{
   auto lambda = [this]( const auto it )
   {
      exec_process proc( it.path, it.name );
      insert( it.id, proc );
   };

   std::for_each( data.begin(), data.end(), lambda );
}

void exec_process_map::update( const ProtoExecutive::Process_Id id, const exec_process proc )
{
   remove( id );
   insert( id, proc );
}

exec_process exec_process_map::find( const ProtoExecutive::Process_Id id ) const
{
   auto it = _process_map.find( id );
   return it->second;
}

std::tuple<ProtoExecutive::Process_Id, exec_process> exec_process_map::find ( const exec_process::status status ) const
{
   auto lambda = [status]( auto proc )
   {
      return ( proc.second.getStatus() == status );
   };

   auto process = std::find_if( _process_map.begin(), _process_map.end(), lambda );
   if ( process == _process_map.end() )
   {
      exec_process proc( "", "" );
      return std::make_tuple( ProtoExecutive::INVALID_PROCESS, proc );
   }

   return std::make_tuple( process->first, process->second );
}

void exec_process_map::insert( const ProtoExecutive::Process_Id id, const exec_process proc )
{
   std::pair<ProtoExecutive::Process_Id, exec_process> pair = std::make_pair( id, std::move( proc ) );
   _process_map.insert( std::move( pair ) );
}

void exec_process_map::remove( const ProtoExecutive::Process_Id id )
{
   auto it = _process_map.find( id );
   _process_map.erase( it );
}
