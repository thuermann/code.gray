/*
 * $Id: gray.c,v 1.2 2003/12/05 12:55:35 urs Exp $
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int N = 16;
    int n;

    if (argc > 1)
	N = atoi(argv[1]);

    for (n = 0; n < N; n++)
	printf("%2x: %2x\n", n, n ^ (n >> 1));

    return 0;
}
