/*
 * $Id: gray.c,v 1.3 2003/12/05 12:55:45 urs Exp $
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int N = 16;
    int n, m, i;
    char bits[32 + 1];

    if (argc > 1)
	N = atoi(argv[1]);

    for (n = 0; n < N; n++) {
	m = n ^ (n >> 1);
	for (i = 0; i < 8; i++)
	    bits[i] = '0' + ((m & (1 << (7 - i))) != 0);
	bits[i] = 0;
	printf("%2x: %2x %s\n", n, m, bits);
    }

    return 0;
}
