#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"  // Change ip
#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at %s:%d\n", SERVER_IP, PORT);

    while (1) {
        printf("Client> ");
        fgets(command, BUFFER_SIZE, stdin);

        if (strncmp(command, "exit", 4) == 0) break;

        send(sock, command, strlen(command), 0);

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0 || strstr(buffer, "__END__") != NULL) break;
            printf("%s", buffer);
        }
    }

    close(sock);
    return 0;
}

