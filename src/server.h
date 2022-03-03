#ifndef SERVER_H_
#define SERVER_H_

#include <stdbool.h>
#include <stdint.h>


/* This function creates the central server of the 
peer-to-peer system. It initializes some global 
state variables, creates a socket, and binds the socket.  */
bool create_server(const char *ip, uint16_t port);

/* This function wraps the listen and accept procedures
of the server in the peer-to-peer system. In addition, it
updates the global state maintained by the server. */
void listen_and_accept(int serv_sd, struct sockaddr_in client);

/* This function destroys the central server of the
peer-to-peer system by closing the server's socket. It also 
reinitializes the socket and other global state
variables to the original empty state. */
void destroy_server();

#endif
