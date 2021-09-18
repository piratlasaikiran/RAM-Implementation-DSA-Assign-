all:program
	./a.out

program:assignment driver
	gcc assignment driver

assignment:assignment.c assignment.h
	gcc -c assignment.c -o assignment
	
driver:driver.c assignment.h
	gcc -c driver.c -o driver

clean:
	rm -f ./a.out
	rm -f ./assignment
	rm -f ./driver
