#include "libft.h"

int	stringComparator( void *s1, void *s2  )
{
	return ( memcmp( s1, s2, strlen( s1 ) ) );
}

int	intComparator( void *s1, void *s2 )
{
	return ( memcmp( s1, s2, sizeof( int )) );
}

/*
 * \fn		t_list	*find_node( t_list *HEAD, void *key )
 * \brief	La fonction findNode() a pour but de rechercher un maillon spécifique dans une liste chaînée.
 */
t_list	*find_node( t_list *head, void *key, int (*f)( void *, void *) )
{
	while( head )
	{
		if ( f( head->content, key  ) != 0 )
			head = head->next;
		else
			return ( head );
	}
	return ( NULL );
}
