#include "libft.h"

/*
 * \fn void	display_md5( const char *)
 * \brief Cette fonction prend en entrée le chemin d'un fichier, calcule le hash MD5 de son contenu et affiche le résultat du hash MD5 à l'écran.
 */
void	display_md5( const char *filename )
{
	unsigned char	hash[ MD5_DIGEST_LENGTH ] = { 0x00 };
	ft_md5( filename, hash );
	fprintf( stderr, "\t%s[+] (%s): The file %s has been created successfully. hash(md5): ", ANSI_COLOR_GREEN, __func__, filename );
	for( int i = 0; i < MD5_DIGEST_LENGTH; i++ )
		fprintf( stdout, "%02X", hash[ i ] );
	fprintf( stdout, "%s\n", ANSI_COLOR_RESET );
}
