#include "libft.h"


/*
 * \fn uint8_t	create_file_with_content( const char *, int, mode_t, const uint8_t *, uint64_t )
 * \brief La fonction create_file_with_content permet de créer un nouveau fichier avec un contenu spécifié. La fonction prend deux paramètres en entrée : le nom du fichier à créer et le contenu du fichier à écrire. 
 * La fonction commence par ouvrir le fichier en utilisant la fonction open() en mode de création (O_CREAT) avec les indicateurs appropriés pour définir les droits d'accès pour le fichier.
 * Ensuite, la fonction utilise la fonction write() pour écrire le contenu spécifié dans le fichier nouvellement créé. Si l'écriture est réussie, la fonction retourne un code de succès.
 * Si une erreur se produit lors de l'écriture du contenu dans le fichier, la fonction retourne un code d'erreur approprié.
 *
 * En résumé, la fonction create_file_with_content simplifie la création d'un nouveau fichier avec un contenu spécifié en prenant en charge les opérations d'ouverture et d'écriture de fichiers pour vous.
 */
uint8_t	create_file_with_content( const char *pathname, int flags, mode_t mode, const uint8_t *content, uint64_t size_content )
{
	int	fd = open( pathname, flags, mode );
	if ( fd == -1 )
		return ( 1 );
	if ( write( fd, content, size_content ) -1 )
	{
		close ( fd );
		return ( 1 );
	}
	close ( fd );
	return ( 0x00 );
}
