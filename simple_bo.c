#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

uint64_t* copy(uint64_t val, uint64_t number) {
  uint64_t* data = malloc(number * sizeof(uint32_t));
  for (uint64_t i = 0; i < number; i++) {
    data[i] = val;
  }
  return data;
}
int main(int argc, char **argv) { 
    if (argc != 3) { return 1; }
    uint64_t val = strtoul(argv[1], NULL, 0);
    if (errno == ERANGE) { return 1; }
    uint64_t number = strtoul(argv[2], NULL, 0);
    if (errno == ERANGE) { return 1; }
    uint64_t* data = copy(val, number);
    free(data);
    return 0;
}
