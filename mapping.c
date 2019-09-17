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
	int count = 0, count2 = 0;
	struct stat mystat;
	void *pmaping;
	char *extra;

	fd =open(arr, O_RDWR);		//file open command
	
	if (fd == -1)
	{
		perror("Failed...!!! File is not opened.\n");
		exit(1);
	}
	
	if (fstat(fd, &mystat) < 0)		// to get mystat
	{
		perror("Failed...!!! fstat is failed\n");
		
		close(fd);		// close the fd
		exit(1);
	}
	

	/* **********************************************************************
								Mmaping
	*********************************************************************** */

	pmaping = mmap (0, mystat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	if (pmaping == MAP_FAILED)
	{
		perror("Failed..!!! Mmaping Failed\n");		// if failed
		
		close(fd);
		exit(1);
		
	}
	
	extra = (char *)pmaping;		// initializing extra as pmaping;
	

	for (;extra[count2] != '\0';)	// Check the file untill end (\0)
	
	{
		if (extra[count2] == 10)
		{
			count++;
		}
		count2++;
	}
	close(fd);
	
	return count;				// return the count value
	
	
}
