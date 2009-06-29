#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char buf[80];
	FILE *f = fopen(argv[1], "r");
	fgets(buf, sizeof buf, f);
	if (buf[8] == 'P')
		abort();
	return 0;
}
