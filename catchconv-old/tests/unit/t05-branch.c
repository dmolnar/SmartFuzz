#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char buf[80], *p = malloc(128);
	FILE *f = fopen(argv[1], "r");
	fgets(buf, sizeof buf, f);
	free(p);
	if (buf[8] == 'P')
		*p = 5;
	return 0;
}
