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


int my_cnt(const char *arr)
{

	
	int fd;
	int count = 0; 
	int i = 0;
	int reading_byte, pages;
	
	
	fd = open(arr, O_RDWR);		//file open command
	
	if (fd == -1)
	{
		perror("Failed...!!! File is not opened.\n");
		exit(1);
	}

	pages = getpagesize();		//  getting pagesize
	
	char buffer[pages];
	
	
	/* **********************************************************************
						Reading using buffer and pagesize
	*********************************************************************** */

	
	reading_byte = read(fd, buffer, pages);
	for (; reading_byte > 0 && reading_byte != 0 ;)
	{

		for(i=0; i<reading_byte; i++)	//read untill less than reading bytes
		{
			
			if(buffer[i]=='\n')			// if there is next line. count the line number
			{
				count++;
			}
		}
		if (reading_byte == 0 )			// no byte, break;
		{
			break;	
		}
		reading_byte = read(fd, buffer, pages);		//putting into reading
	}
	
	
	return count;
	
}
