#include "libft.h"

/*
 * \fn t_list	*getLastLink( t_list * )
 * \brief	La fonction getLastLink() permet d'obtenir le dernier maillon d'une chaîne.
 * 		La fonction lance une exception via assert si llist est NULL.
 */
t_list	*getLastLink( t_list *llist )
{
	assert( llist != NULL );
	while ( llist->next )
		llist = llist->next;
	return ( llist );
}

/*
 * \fn	void	linkNodes( t_list **, t_list ** )
 * \brief	La fonction linkNodes() a pour but de relier deux maillons d'une liste chaînée.
 */
void	linkNodes( t_list **s1, t_list **s2 )
{
	(*s1)->prev = *s2;
	(*s2)->next = *s1;
}

void ft_llist_splice( t_list **alst, t_list *llist_s1, t_list *llist_s2 ) {

	t_list	*last = getLastLink( llist_s2 );
	if ( llist_s1 == *alst )
	{
		t_list	*nxt = (*alst)->next;
		(*alst)->next = llist_s2;
		if ( nxt )
			linkNodes( &nxt, &last );
	}
	else
	{
		t_list	*nxt = llist_s1->next;
		llist_s1->next = llist_s2;
		llist_s2->prev = llist_s1;
		if ( nxt )
			linkNodes( &nxt, &last );
	}
}
