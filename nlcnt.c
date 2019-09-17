#include <stdio.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <limits.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>


typedef void* (*arbitrary)(char *);


int main(int argc, char *argv[])
{
	void *handler;				// handler
	const char *error_check;	// error checker
	arbitrary func;
	int process_type;		// mapping is 0 and reading is 1
	
	//printf("%c", argv[1]);
	
	/* **********************************************************************
							For Mapping
	************************************************************************* */
	
	//if ((strcmp(argv[1], "m") || strcmp(argv[1], "-m") || strcmp(argv[1], "mapping"))== 0) 
	//switch()
	
	if ((strcmp(argv[1], "m"))== 0)
	{
		process_type = 0;	
	}
	
	else if ((strcmp(argv[1], "-m"))== 0)
	{
		process_type = 0;	
	}
	
	else if ((strcmp(argv[1], "mapping"))== 0)
	{
		process_type = 0;	
	}
	
	else if ((strcmp(argv[1], "M"))== 0)
	{
		process_type = 0;	
	}
	
	else if ((strcmp(argv[1], "-M"))== 0)
	{
		process_type = 0;	
	}
	
	else if ((strcmp(argv[1], "Mapping"))== 0)
	{
		process_type = 0;	
	}
	

	/* **********************************************************************
							For Reading
	************************************************************************* */
	

	
	else if ((strcmp(argv[1], "r"))== 0)
	{
		process_type = 1;	
	}
	
	else if ((strcmp(argv[1], "-r"))== 0)
	{
		process_type = 1;	
	}
	
	else if ((strcmp(argv[1], "reading"))== 0)
	{
		process_type = 1;	
	}
	
	else if ((strcmp(argv[1], "R"))== 0)
	{
		process_type = 1;	
	}
	
	else if ((strcmp(argv[1], "-R"))== 0)
	{
		process_type = 1;	
	}
	
	else if ((strcmp(argv[1], "Reading"))== 0)
	{
		process_type = 1;	
	}
	
	else
	{
		printf("Incorrect input command...!!! \nPlease enter correct input.\n");
		
		return 0;		// for return only the statement
	}
	
	
	
	/* **********************************************************************
							Library - Mapping 
	************************************************************************* */	
	
	if (process_type == 0)
	{
		handler = dlopen("./mapping.so", RTLD_LAZY);
		if(!handler)
		{
			printf("library cannot be opened %s\n", dlerror()); 	// error statement for not fiding library
			exit(1);
		}
	
		dlerror();
	
		func = (dlsym(handler, "my_cnt"));
		
			if((error_check = dlerror()))
			{
				fprintf(stderr, "function is not found..!!! %s\n", error_check);
				
				exit(1);
			}
			
		dlerror();
			
		/* Mapping of DL call function */
		
		long map = ((long)(*func)(argv[2]));

		printf("Number of line : %ld. \nMapping done..!!\n" ,map);
		
		return 0;
	
	}

	

	/* **********************************************************************
							Library - Reading 
	************************************************************************* */	
	
	
	if (process_type == 1)
	{
		handler = dlopen("./reading.so", RTLD_LAZY);
		
		if(!handler)
		{
			printf("library cannot be opened %s\n", dlerror());	// error statement for not fiding library
			
			exit(1);
		}
	
		dlerror();
	
		func = (dlsym(handler, "my_cnt"));
		
			if((error_check = dlerror()))
				
			{
				fprintf(stderr, "function is not found..!!! %s\n", error_check);
				exit(1);
			}
			
		dlerror();

	/* Reading of DL call function */
	
	long read = ((long)(*func)(argv[2]));
	
		printf("Number of line : %ld. \nReading done..!!\n",read);
	}
	
	dlclose(handler);
	
	return 0;
}


