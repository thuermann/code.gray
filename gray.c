/*
 * $Id: gray.c,v 1.4 2014/06/30 11:00:56 urs Exp $
 */

#include <stdlib.h>
#include <stdio.h>

static void usage(const char *name)
{
    fprintf(stderr, "Usage: %s [min] max\n", name);
}

int main(int argc, char **argv)
{
    unsigned long n, m, min, max;
    int i;
    char bits[32 + 1];

    if (argc != 2 && argc != 3) {
	usage(argv[0]);
	exit(1);
    }

    min = 0;
    max = strtoul(argv[1], NULL, 0);
    if (argc == 3) {
	min = max;
	max = strtoul(argv[2], NULL, 0);
    }

    for (n = min; n < max; n++) {
	m = n ^ (n >> 1);
	for (i = 0; i < 8; i++)
	    bits[i] = '0' + ((m & (1 << (7 - i))) != 0);
	bits[i] = 0;
	printf("%2lx: %2lx %s\n", n, m, bits);
    }

    return 0;
}
