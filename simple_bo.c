#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define LEN 5

void copy(uint64_t* data, uint64_t val, uint64_t number) {
  for (uint64_t i = 0; i < number; i++) {
    data[i] = val;
  }
}

int main(int argc, char **argv) { 
    // first argument is data to fill, second argument is number of 
    //  elements
    if (argc != 3) { return 1; }

    uint64_t val = strtoul(argv[1], NULL, 0);
    if (errno == ERANGE) { return 1; }

    uint64_t number = strtoul(argv[2], NULL, 0);
    if (errno == ERANGE) { return 1; }

    uint64_t* data = malloc(number * sizeof(uint32_t));

    copy(data, val, number);

    return 0;
}
