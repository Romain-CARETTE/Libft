#include "libft.h"

void	clear_arr( char **arr )
{
	assert( arr != NULL );

	for( int i = 0; arr[i] != 0X00; i++ )
		free( arr[ i ] );
	free( arr );
	arr = NULL;
}
