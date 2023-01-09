# include "libft.h"

int	get_arr_size( char **arr )
{
	assert( arr != 0X00 );
	int	i = 0X00;
	while ( arr[ i ] != 0X00 )
		i = ( i + 1 );
	return ( i );
}
