# Introduction
THe Logger process is responsible for all logging activities within the system.  This allows one process to have control of all reading and writing to files on the disk.  The Logger process guarantees that all data logged within the last second will make it to disk.

# Requirements

## General
- [ ] The Logger shall take no more than 100ms to complete its main loop.

## Interface: Executive
- [ ] The Logger shall create a synchronous connection with the Executive process on startup.
- [ ] The Logger shall send a Version message to Executive on startup.
- [ ] The Logger shall send a Watchdog message to Executive on each iteration of the main loop.

## Interface: General
- [ ] The Logger shall provide an interface for asynchronous communications with process.
- [ ] The Logger shall use a SHA-256 checksum to verify data integrity.

## Logs
- [ ] The Logger shall create a unique timestamp for all entries a Log.

#### System Logs
- [ ] The Logger shall create the System Log File at startup.
- [ ] The Logger shall close the System Log File at shutdown 
- [ ] The Logger shall allow all processes to direct data to the System Log File.

#### Process Logging
- [ ] The Logger shall allow processes to create a dedicated log file for the requesting process.
- [ ] The Logger shall allow processes to close a dedicated log file.

# Design
* TODO

# Test Methodology
* TODO
