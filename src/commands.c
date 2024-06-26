#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void handle_get_info(int client_socket) {
    const char* response = "Data Collection Service of Jose Luis\n";

    write(client_socket, response, strlen(response));
}

void handle_get_number_of_partitions(int client_socket) {
    FILE* fp = popen("./scripts/get_number_of_partitions.sh", "r");

    if (fp == NULL) {
        perror("popen");
        close(client_socket);
        return;
    }

    char result[BUFFER_SIZE];
    fgets(result, sizeof(result), fp);
    pclose(fp);

    write(client_socket, result, strlen(result));
}

void handle_get_current_kernel_version(int client_socket) {
    FILE* fp = popen("./scripts/get_current_kernel_version.sh", "r");

    if (fp == NULL) {
        perror("popen");
        close(client_socket);
        return;
    }

    char result[BUFFER_SIZE];
    fgets(result, sizeof(result), fp);
    pclose(fp);

    write(client_socket, result, strlen(result));
}

void handle_sshd_running(int client_socket) {
    FILE* fp = popen("ps ax | grep [s]shd", "r");

    if (fp == NULL) {
        perror("popen");
        close(client_socket);
        return;
    }

    char result[BUFFER_SIZE];

    if (fgets(result, sizeof(result), fp) != NULL) {
        write(client_socket, "true\n", 5);
    } else {
        write(client_socket, "false\n", 6);
    }

    pclose(fp);
}
