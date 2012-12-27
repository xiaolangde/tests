# touch *.c
# make all
# result:
# build a.o
# build b.o
# build all
#

all: a.o b.o
	@echo build all
	@touch all

a.o: fa.c
	@echo build a.o
	@touch a.o

b.o: fb.c
	@echo build b.o
	@touch b.o

c.o: fc.c
	@echo build c.o
	@touch c.o