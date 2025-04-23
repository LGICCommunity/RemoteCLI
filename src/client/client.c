#include "client_utils.h"
#include "../common/config.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    int sock;
    char command[BUFFER_SIZE];

    connect_to_server(&sock, "127.0.0.1");
    printf("Connected to server. Type commands (type 'exit' to quit)\n");

    while (1) {
        printf("Client> ");
        fgets(command, BUFFER_SIZE, stdin);

        if (strncmp(command, "exit", 4) == 0) break;

        send_command(sock, command);
        receive_response(sock);
    }

    close(sock);
    return 0;
}
