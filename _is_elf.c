#include "libft.h"

uint8_t	_is_elf( const char *buf )
{
	Elf64_Ehdr	*hdr = (Elf64_Ehdr *)buf;
	if ( memcmp( hdr->e_ident, ELFMAG, SELFMAG ) != 0)
		goto out;
	if ( hdr->e_type != ET_EXEC && hdr->e_type != ET_DYN )
		goto out;
	/* Now read in all of the header information */
	if ( hdr->e_phentsize != sizeof( Elf64_Phdr ) )
		goto out;
	if (hdr->e_phnum < 1 || hdr->e_phnum > 65536U / sizeof( Elf64_Phdr ))
		goto out;
	return ( 0X00 );
	out:
		return ( 1 );
}
