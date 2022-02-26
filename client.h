#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdbool.h>
#include <stdint.h>


/* add description */
bool connected(const char *ip, uint16_t port);

/* add description */
void disconnected(void);

#endif
