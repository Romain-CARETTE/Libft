#include "libft.h"


uint32_t	RLE_compress( const uint8_t *src, uint8_t *dst, uint32_t *size_input )
{
	uint8_t		tmp[ 129 ] = { 0x00 };
	uint32_t	index_in = 0X00, size_compressed = 0X00, keep = 0X00, i = 0X00;

	tmp[ 0X00 ] = src[ index_in++ ];
	while ( index_in < *size_input )
	{
		tmp[ 0X01 ] = src[ index_in++ ];
		if ( tmp[ 0X00 ] != tmp[ 0X01 ] )
		{
			i = 0X01;
			do
			{
				tmp[ ++i ] = src[ index_in ];
				printf("%x %x\n", tmp[i], tmp[i-1]);
			}while( ++index_in < *size_input && i < 128 && tmp[ i ] != tmp[ i - 1]);
			if ( ( keep = tmp[ i ] == tmp[i - 1]))
				i = ( i - 1 );
			dst[ size_compressed ] = i - 1;
			++size_compressed;
			memcpy( dst+size_compressed, tmp, i );
			size_compressed += i;
			tmp[ 0X00 ] = tmp[ i ];
			if ( !keep )
				continue;
		}
		i = 0X02;
		do
		{
			tmp[ 1 ] = src[ index_in ];
		}while( ++index_in < *size_input && ++i < 130 && tmp[ 0 ] == tmp[ 1 ]);
		dst[ size_compressed ] = i + 125;
		++size_compressed;
		dst[ size_compressed ] = tmp[ 0X0 ];
		++size_compressed;
		tmp[ 0X00 ] = tmp[ 0X01 ];
	}
	printf("Compressed: %ld\n", size_compressed );
	return ( size_compressed );
	/*int fd = open("/home/ssokar/testing/test", O_CREAT | O_WRONLY );
	write( fd, dst, index_out );
	close( fd );*/
}

uint32_t	RLE_uncompress( const uint8_t *dst, const uint8_t *src, uint32_t *size_compressed )
{

}
