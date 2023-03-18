#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdint.h>
#include "libft.h"
int	main( int ac, char **av )
{
	int fd = open( av[1], O_RDONLY );
	struct stat sb;
	fstat( fd, &sb );
	uint32_t size_input = sb.st_size;
	char *ptr = malloc( sizeof(char)*size_input+1000 );
	char *ptr2 = malloc( sizeof(char)*size_input+1000 );
	read( fd, ptr, sb.st_size );
	close ( fd );

	uint32_t size_output = 0x00;
	RLE_compress( ptr, ptr2, &size_input );
	return ( 0x00 );
}
