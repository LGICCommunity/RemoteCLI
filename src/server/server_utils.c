#include "../common/config.h"
#include "server_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

void execute_and_respond(int client_fd) {
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_read <= 0) break;

        FILE *fp = popen(buffer, "r");
        if (!fp) {
            char *msg = "Failed to execute command.\n";
            send(client_fd, msg, strlen(msg), 0);
            continue;
        }

        while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
            send(client_fd, buffer, strlen(buffer), 0);
        }
        pclose(fp);

        send(client_fd, "__END__", strlen("__END__"), 0);
    }
}
