#include <stdio.h>
#include <stdlib.h>

#include "server.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Running on: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    start_server(port);

    return 0;
}
