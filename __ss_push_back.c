#include "libft.h"

t_list	*__ss_llist_crt_push_back( t_llist_crt **llist, void *content, size_t content_size, \
		void (*callback)( void * ))
{
	assert( llist != NULL );
	t_list *new = ft_lstnew( content, content_size );
	if ( new == NULL )
		goto __ss_llist_crt_push_back_err;
	(*llist)->llist_last->next = new;
	new->prev = (*llist)->llist_last;
	(*llist)->llist_last = new;

	( callback != NULL ) ? ( void )callback( (*llist)->content ) : 0X00;
__ss_llist_crt_push_back_err:
			return ( 0X00 );
}
