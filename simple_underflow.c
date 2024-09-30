#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define LEN 5

uint64_t tot(uint64_t data[LEN]) {

  uint64_t total = 0;

  for (uint64_t i = 0; i < LEN; i++) {
    if (data[i] <= 30) {
      total -= data[i];
    } else {
      total += data[i];
    }
  }
  return total;
}

int main(int argc, char **argv) { 
	uint64_t data[LEN] = {};
	if (argc != 6) { return 1; }
	for (int i = 0; i < LEN; i++) {
		data[i] = strtoul(argv[i+1], NULL, 0);
		if (errno == ERANGE) { return 1; }
	}
	uint64_t total = tot(data);
	int* alloc = malloc(total);
        printf("%lu\n", total);
        printf("%p\n", alloc);
        free(alloc);
}
