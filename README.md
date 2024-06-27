# Data Collection Service

This project implements a server application in `C` language that handles client connections and responds to specific commands.

The server supports functionalities such as recovering server information, querying system partitions, checking the current kernel version, and verifying if SSH daemon is running.

## Team:

- José Luis Terán

## Directory Structure

This is the directory structure that Data Collection Service project uses:

```bash
.
├── include
│ ├── client_handler.h
│ ├── commands.h
│ └── server.h
├── scripts
│ ├── get_current_kernel_version.sh
│ └── get_number_of_partitions.sh
├── src
│ ├── client_handler.c
│ ├── commands.c
│ ├── main.c
│ └── server.c
├── test
│ └── test_client.c
└── .gitignore
└── LICENSE
└── README.md
```

You can visit this [link](https://www.lucavall.in/blog/how-to-structure-c-projects-my-experience-best-practices) if you want to know more about **How to Structure C Projects.**

## Dependencies

- `gcc` (GNU Compiler Collection)
- `pthread` library (for POSIX threads)

## Building

To build the server application, navigate to the `src` directory and use the following command:

```bash
gcc -o server main.c client_handler.c commands.c server.c -I../include -pthread
```

## Running

Once compiled, you can run the server with the following command:

```bash
./server <port>
```

### Testing

A test client (`test/test_client.c`) is provided to validate server functionality. 

Compile it using:

```bash
gcc -o test_client test/test_client.c
```

Run the test client with:

```bash
./test_client <server_ip> <port>
```
