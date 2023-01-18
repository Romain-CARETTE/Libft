#include "libft.h"

t_list	*__ss_llist_crt_push_front( t_llist_crt **llist, void *content, size_t content_size, \
		void(*callback)( void *))
{
	assert( llist != NULL );
	t_list *new = ft_lstnew( content, content_size );
	if ( new == NULL )
		goto __ss_llist_crt_push_front_err;
	if ( (*llist)->llist_last == NULL  && (*llist)->llist_begin == NULL )
	{
		(*llist)->llist_begin = new;
		(*llist)->llist_last = new;
	}
	else
	{
		new->next = (*llist)->llist_begin;
		(*llist)->llist_begin->prev = new;
		(*llist)->llist_begin = new;
	}
	(*llist)->nb_items += 0X01;	
	( callback != NULL ) ? ( void )callback( (*llist)->content ) : 0X00;
	return ( new );
__ss_llist_crt_push_front_err:
			return ( (void *)0X00 );
}
