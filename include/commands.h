#ifndef COMMANDS_H
#define COMMANDS_H

void handle_get_info(int client_socket);
void handle_get_number_of_partitions(int client_socket);
void handle_get_current_kernel_version(int client_socket);
void handle_sshd_running(int client_socket);

#endif
