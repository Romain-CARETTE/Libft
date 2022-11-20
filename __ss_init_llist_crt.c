#include "libft.h"

/*
 * \fn t_llist_crt	*__ss_init_llist_crt( void )
 * \brief Return an allocated llist_crt pointer.
 * \brief /!\ This function uses the calloc
 */
t_llist_crt	*__ss_init_llist_crt( void ) { return ( (t_llist_crt *)calloc( sizeof( char ), sizeof( t_llist_crt ))); }
