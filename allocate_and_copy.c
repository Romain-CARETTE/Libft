#include "libft.h"

void    *allocate_and_copy( void *data, size_t size )
{
    void *mem = memmalloc( size );
    if ( ! mem )
        return ( NULL );
    return ( memcpy( mem, data, size) );
}
