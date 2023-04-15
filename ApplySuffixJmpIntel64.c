#include "libft.h"

/*
 * \fn void	ApplySuffixJmpIntel64( uint32_t, uint32_t, uint32_t, uint8_t * )
 * \brief Cette fonction permet de créer une instruction de saut (jmp) qui permet de retourner au point d'entrée d'origine du binaire.
 *        Elle ne modifie pas directement le binaire, mais génère simplement l'instruction de saut correspondante.
 */
void	ApplySuffixJmpIntel64( uint32_t Vaddr, uint32_t size_shellcode, uint32_t entrypoint, uint8_t *buf )
{
	uint32_t entryJump = entrypoint - ( Vaddr + 5 ) - size_shellcode;
	buf[ 0x00 ] = 0XE9;
	memmove( &buf[ 1 ], &entryJump, sizeof( uint32_t ));
}
