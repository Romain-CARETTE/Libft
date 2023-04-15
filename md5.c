# include "libft.h"

/*
 * \fn uint8_t ft_md5( const char *, unsigned char * )
 * \brief La fonction ft_md5 est un wrapper utilisant la fonction MD5 pour générer un condensat de 128 bits.
 */
uint8_t ft_md5( const char *pathname, unsigned char *output )
{
	int 	fd = open( pathname, O_RDONLY );
	if ( fd == -1 )
		return ( 1 );
	struct stat	info = { 0 };
	if ( stat( pathname, &info ) == -1 )
	{
		close( fd );
		return ( 1 );
	}
	char	*ptr = calloc( sizeof(char), info.st_size );
	if ( ptr == NULL )
	{
		close ( fd );
		return ( 1 );
	}

	if ( read( fd, ptr, info.st_size ) != info.st_size )
	{
		close ( fd );
		free( ptr );
		return ( 1 );
	}
	close ( fd );
	MD5( (unsigned char *)ptr, info.st_size, output );
	free( ptr );
	return ( 0x00 );
}
