#include "libft.h"

/*
 * \fn void	get_last_part( const char *, char * )
 * \brief elle est utilisée pour récupérer la dernière partie d'une chaîne de caractères ou d'un chemin d'accès.
 */
void	get_last_part( const char *str, char *output )
{
	char	*t = strrchr( str, '/' );
	if ( t == NULL )
		t = ( char *)str;
	else
		t = ( t + 1 );
	sprintf( output, "%s%c", t, 0 );
}
