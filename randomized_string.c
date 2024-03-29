#include "libft.h"

char	*randomized_string( char *str, int n ) {
	
	static const int a = 33, z = 126;
	int	seed = ( unsigned int)time( NULL );
	srand( seed );

	for ( int i = 0; i < n; ++i )
		str[ i ] = ( rand() % ( z-a + 0X01) + a ) ;
	return ( str );
}
