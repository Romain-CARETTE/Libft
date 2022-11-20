#include "libft.h"

void	__ss_callback_increase_of_items( void *content )
{
	int *tmp = (int *)content;
	*tmp = ( *tmp + 0X01 );
}
