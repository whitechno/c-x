
hellogcc : hellogcc.c
	gcc -o hellogcc hellogcc.c

hellogcc.o : hellogcc.c
	gcc -c hellogcc.c

.PHONY : run
run :
	./hellogcc

.PHONY : clean
clean :
	rm hellogcc hellogcc.o hellogcc.s hellogcc.i hellogcc.bc
