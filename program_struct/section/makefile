exe: section4.c
	gcc -o $(patsubst %.c, %.o,$^) $^

section: section4.c
	@gcc -g -c $^
	@strip $(patsubst %.c, %.o,$^)
	@objdump -h $(patsubst %.c, %.o,$^)
clean:
	-rm -f *.o *.exe *~
ls:
	ls -l