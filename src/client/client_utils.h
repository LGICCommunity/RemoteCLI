#ifndef CLIENT_UTILS_H
#define CLIENT_UTILS_H

void connect_to_server(int *sock, const char *ip);
void send_command(int sock, const char *command);
void receive_response(int sock);

#endif
