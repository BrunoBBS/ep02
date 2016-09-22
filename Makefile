CC:=gcc
FLAGS:=-Wall -ansi -pedantic -O2

ep2: ep2.o matriz.o pilha.o
	$(CC) $(FLAGS) -o $@ $^

# General formulas ()
%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

%.o: %.c %.h
	$(CC) $(FLAGS) -c -o $@ $<

upload:
	git add *.c
	git add *.h
	git commit
	git push

