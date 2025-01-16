# winTools - C++ Utility Library for Windows

Welcome to **winTools**, a C++ library designed to provide a set of utilities for Windows application development. Whether you're looking to manage files, system resources, or automate repetitive tasks, **winTools** has something to offer.

---

## Features
![alt text](screenshot/wetchat.png)

- **File System Utilities**: Tools for file creation, manipulation, and management.
- **Registry Access**: Functions to interact with the Windows registry for configuration management.
- **Process Management**: Handle processes, including starting, stopping, and querying processes.
- **System Info**: Retrieve detailed system information like CPU, memory, and OS details.
- **Window Management**: Functions to interact with system windows, including manipulation and query.

---

## Installation and Building

### Prerequisites

Before you can build the project, make sure you have the following installed:

- **CMake** (version 3.10 or later)
- A **C++ compiler** (such as GCC, Clang, or MSVC)
- **Make** tool (e.g., `make` on Unix-like systems, or `nmake` on Windows with MSVC)

### Build the Project

To build the project from source, follow these steps:
```
mkdir build

cd build

cmake .. -G"Unix Makefiles"

make 
