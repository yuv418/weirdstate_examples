#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

struct login {
  char username[8]; 
  uint64_t authenticated; 
};

uint64_t sum(uint64_t* cookie) {
  uint64_t sum = 0;
  // Work on cookie
  for (uint64_t i = 0; i < 8; i++) {
    sum += (*cookie >> (i * 8)) & 255;
  }
  return sum;
}

struct login* compute_cookie(uint64_t user_cookie) {
  // Initial cookie
  uint64_t* cookie = malloc(sizeof(uint64_t));
  // Do something with cookie
  // Done with cookie
  free(cookie);

  struct login* login_s = malloc(sizeof(struct login));

  strcpy(login_s->username, "janedoe");

  *cookie = user_cookie;
  login_s->authenticated = sum(cookie);

  return login_s;
}

int main(int argc, char** argv) {
  if (argc != 2) { return 1; }
  uint64_t user_cookie = strtoul(argv[1], NULL, 0);
  if (errno == ERANGE) { return 1; }

  struct login* login_s = compute_cookie(user_cookie);
  printf("USER: %s, login granted %d.\n", login_s->username, login_s->authenticated != 0);

}
