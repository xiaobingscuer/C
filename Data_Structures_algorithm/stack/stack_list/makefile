test:stack.o teststack.o
	gcc stack.o teststack.o -o test
stack.o:
	gcc -c stack.c -o stack.o
teststack.o:
	gcc -c teststack.c -o teststack.o
clean:
	rm -f *.o test