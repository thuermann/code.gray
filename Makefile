#
# $Id: Makefile,v 1.1 2003/12/05 12:55:25 urs Exp $
#

RM = rm -f

.PHONY: all
all: gray

.PHONY: clean
clean:
	$(RM) *.o gray code
