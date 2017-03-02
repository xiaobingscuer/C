test:queue.o testqueue.o
	gcc queue.o testqueue.o -o test
queue.o:
	gcc -c queue.c -o queue.o
testqueue.o:
	gcc -c testqueue.c -o testqueue.o
clean:
	rm -f *.o test