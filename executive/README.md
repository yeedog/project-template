# Introduction
The Executive process is responsible for managing processes in the system.  The Executive process is the only executable started at boot and it is responsible for starting and stopping processes along with managing data associated with each process.  This data includes watchdog information and software versions.

# Requirements

## General
- [ ] The Executive shall take no more than 100ms to complete its main loop.

## Interface
- [x] The Executive shall provide an interface for synchronous communications with child process.
- [x] The Executive shall respond with an Accept message when data is successfully processed.
- [ ] The Executive shall use a SHA-256 checksum to verify data integrity at runtime.

#### Message: Version
- [x] The Executive shall store the software Version during runtime.
- [x] The Executive shall support a message to accept Version information.
- [ ] The Executive shall support a message to request Version information.

#### Message: Watchdog
- [x] The Executive shall manage Watchdog messages on a per process basis.
- [x] The Executive shall store the time of the last Watchdog message during runtime.
- [x] The Executive shall support a message to accept Watchdog information.

## Process Management: Start
- [x] The Executive shall provide a list of process to Start.
- [x] The Executive shall Start process as a child of the Executive process.

## Process Management: Stop
- [x] The Executive shall Stop all running processes on Shutdown.
- [ ] The Executive shall Stop all running processes when a Watchdog fails to be kicked within 5 seconds.

# Design
* TODO

# Test Methodology
* TODO
