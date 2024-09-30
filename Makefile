CC=gcc
all:
	$(CC) -Werror -Wall -Og -g -o $(CC)-simple_underflow simple_underflow.c -fno-stack-protector
	$(CC) -Werror -Wall -Og -g -o $(CC)-simple_bo simple_bo.c -fno-stack-protector
	$(CC) -Wall -Og -g -o $(CC)-simple_uaf simple_uaf.c -fno-stack-protector
