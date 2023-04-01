#include "libft.h"

/*
 * \fn uint8_t	initialize_lib_magiclib
 * \brief Cette fonction est utilisée pour initialiser la bibliothèque libmagic 
 */
magic_t	initialize_lib_magiclib( void )
{
	magic_t magic_cookie = magic_open(MAGIC_MIME_TYPE); // Initialise la bibliothèque libmagic
	if ( magic_cookie == NULL )
		return NULL;
	if ( magic_load(magic_cookie, NULL ) < 0 )
	{
        	magic_close( magic_cookie );
		return NULL;
	}
	return ( magic_cookie );
}
