/*
 * $Id: gray.c,v 1.5 2014/06/30 11:01:06 urs Exp $
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static void usage(const char *name)
{
    fprintf(stderr, "Usage: %s [min] max\n", name);
}

static unsigned long gray(unsigned long n);
static int length(unsigned long n, int base);
static char *bin(unsigned long n, size_t len);

int main(int argc, char **argv)
{
    unsigned long n, min, max;
    int wd, wb;

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

    wd = length(max - 1, 10);
    wb = length(max - 1, 2);

    for (n = min; n < max; n++)
	printf("%*lu %*lu %s\n", wd, n, wd, gray(n), bin(gray(n), wb));

    return 0;
}

static unsigned long gray(unsigned long n)
{
    return n ^ (n >> 1);
}

static int length(unsigned long n, int base)
{
    int len = 0;

    do {
	n /= base;
	len++;
    } while (n > 0);

    return len;
}

#define MAXLEN (sizeof(unsigned long) * CHAR_BIT)

static char *bin(unsigned long n, size_t len)
{
    static char s[MAXLEN + 1];
    int i = MAXLEN;

    do {
	s[--i] = n & 1 ? '1' : '0';
	n >>= 1;
    } while (n || MAXLEN - i < len);

    return s + i;
}
