/*
 * $Id: gray.c,v 1.1 1998/01/26 18:01:23 urs Exp $
 */

#include <stdio.h>

int main(void)
{
    int n;

    for (n = 0 ; n < 16; n++)
	printf("%2x: %2x\n", n, n ^ (n >> 1));

    return 0;
}
