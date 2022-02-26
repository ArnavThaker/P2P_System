#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys.socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <err.h>
#include <arpa/inet.h>


int cli_sd = -1;

/*
Need method for socket connection
 */
bool connected(const char *ip, uint16_t port) {
  cli_sd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in binAddr;

  binAddr.sin_family = AF_INET;
  binAddr.sin_port = htons(JBOD_PORT);

  if (inet_aton(ip, &binAddr.sin_addr) == 0) {
    return false;
  } else if (cli_sd == -1) {
    return false;
  } else if (connect(cli_sd, (const struct sockaddr *) &binAddr, sizeof(binAddr)) == -1) {
    return false;
  } else {
    return true;
  }
}

/*
Need method for socket disconnection
 */

void disconnected(void) {
  close(cli_sd);
  cli_sd = -1;
}

/*
Need method for socket connection
 */

/*
Need method for socket connection
 */

/*
Need method for socket connection
 */
