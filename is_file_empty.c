#include "libft.h"

/*
 * \fn int	is_file_empty( const char * )
 * \brief Cette fonction vérifie si le fichier est vide. La valeur 1 est renvoyée si le fichier est vide et 0 si le fichier n'est pas vide.
 */
int	is_file_empty( const char *filename )
{
	struct stat	sb = { 0X00 };
	if ( stat( filename, &sb )  == -1 )
		return ( -1 );
	if ( sb.st_size == 0X00 )
		return ( 1 );
	return ( 0x00 );
}
