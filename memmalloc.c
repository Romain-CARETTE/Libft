#include "libft.h"

void	*memalloc( size_t size )
{
	void	*mem;

	if (!(mem = malloc( size )))
		return (NULL);
	memset(mem, 0, size);
	return ( mem );
}
