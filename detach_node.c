#include "libft.h"

/*
 * \fn		uint8_t	detachNode( t_list **ALST, t_list *NODE )
 * \brief	La fonction detachNode() permet de détacher un maillon d'une liste chaînée.
 */	
uint8_t         detachNode( t_list **alst, t_list *node ) {

    uint8_t     res = 0X00;

    if ( memcmp( (*alst)->content, node->content, node->content_size ) == 0 )
    {
            if ( (*alst)->next != NULL ) {
                *alst = (*alst)->next;
                (*alst)->prev = NULL;
            }
            else
                *alst = 0x00;
            res |= 0X01;
            node->next = NULL;
            node->prev = NULL;
            return ( res );
    }
    t_list  *tmp = *alst;
    while( tmp )
    {
        if ( memcmp( tmp->content, node->content, node->content_size ) == 0 ) {
            if ( tmp->next != NULL ) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
            }
            else
                tmp->prev->next = NULL;
            res |= 0X01;
            node->next = NULL;
            node->prev = NULL;
            return ( res );
        }
        tmp = tmp->next;
    }
    return ( res );
}
