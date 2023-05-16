# include "libft.h"

/*
 * \fn void	xor( uint8_t *, uint32_t, uint8_t )
 * \brief
 */
void 	xor(uint8_t *str_in, uint32_t length, uint8_t *key ) {

	for( uint32_t i = 0X00; i < length; i++ )
	{
		str_in[i] = ( str_in[i] ^ key[ i % (sizeof( key )/ sizeof( char )) ] );
	}
}
