SRC = mapping.c reading.c nlcnt.c
OBJ = mapping.so reading.so
FLAGS = -fPIC -Wall -g -rdynamic -shared -o


all: 
	gcc $(FLAGS) reading.so reading.c
	gcc $(FLAGS) mapping.so mapping.c
	gcc -ldl -Wall -lm -g ./reading.so ./mapping.so -o nlcnt nlcnt.c
	
nlcnt:
		gcc -ldl -Wall -lm -g ./reading.so ./mapping.so -o nlcnt nlcnt.c 
		
	
mapping: 
		gcc $(FLAGS) mapping.so mapping.c	
	
	
reading: 
		gcc $(FLAGS) reading.so reading.c
	
clean:
		/bin/rm -f ${OBJ} 
		
tar:
	tar cf Assignment3.tar $(SRC) $ makefile
	


