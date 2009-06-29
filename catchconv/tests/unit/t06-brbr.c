#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char buf[80], *p = NULL;
	FILE *f = fopen(argv[1], "r");
	fgets(buf, sizeof buf, f);
	if (buf[8] == 'P')
		if (buf[9] == 'U')
			*p = 5;
	return 0;
}
