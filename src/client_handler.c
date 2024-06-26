#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/socket.h>

#include "commands.h"

#define BUFFER_SIZE 1024

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    free(arg);

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client_socket, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received: %s\n", buffer);

        if (strcmp(buffer, "getInfo") == 0) {
            handle_get_info(client_socket);
        } else if (strcmp(buffer, "getNumberOfPartitions") == 0) {
            handle_get_number_of_partitions(client_socket);
        } else if (strcmp(buffer, "getCurrentKernelVersion") == 0) {
            handle_get_current_kernel_version(client_socket);
        } else if (strcmp(buffer, "sshdRunning") == 0) {
            handle_sshd_running(client_socket);
        } else {
            const char* response = "Invalid command\n";
            write(client_socket, response, strlen(response));
        }
    }

    close(client_socket);
    
    return NULL;
}
