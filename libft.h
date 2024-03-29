#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <sys/ioctl.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <assert.h>
# include <ncurses.h>
# include <stdlib.h>
# include <menu.h>
# include <sys/prctl.h>
# include <time.h>
# include <math.h>
# include <limits.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netinet/tcp.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <publib.h>
# include <elf.h>
# include <ctype.h>
# include <sys/syscall.h>
# include <signal.h>
# include <magic.h>
# include <openssl/md5.h>

# define _unused	__attribute__((unused))
# define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define RANDOM_NUMBER(min, max) ((int)((double)rand() / RAND_MAX * ((max) - (min) + 1) + (min)))


# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_RESET	"\x1b[0m"

// -------------------- //
// ** Function llist ** //
// -------------------- //

typedef struct node
{
    uint64_t 	key;
    void	*content;
    size_t	size;
    struct node *left;
    struct node *right;
} node ;

typedef struct		s_list
{
	void		*content;
	size_t		content_size;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

typedef struct		s_llist_crt
{
	t_list		*llist_begin;
	t_list		*llist_last;
	void		*content;
	size_t		nb_items;
}			t_llist_crt;

// DIFFIE HELLMAN
typedef struct			s_globalInfo {
	uint32_t		prime, generator;
}				t_globalInfo;
int		GeneratePrimitiveRoot( int );
int		GeneratePrime( void );
int		compute_exp_modulo( int a, int b, int p );
int		__exchange_key_srv( unsigned char *, int, int );
int		__exchange_key_clt( unsigned char *, int, int );
void		__print_k( unsigned char *, int );

/* Return an allocated llist_crt pointer. */
/* /!\ This function uses the calloc */
t_llist_crt		*__ss_init_llist_crt( void );
t_list *	__ss_llist_crt_push_back( t_llist_crt **, void *, size_t, void (*) (void *));
t_list *	__ss_llist_crt_push_front( t_llist_crt **, void *content, size_t, void (*)(void *) );


void		__ss_callback_increase_of_items( void * );


t_list		*ft_lstnew( void const *, size_t );
void		ft_lstdelone( t_list **, t_list *, void (*)(void *, size_t) );
void		ft_lstdel( t_list **, void (*)(void *, size_t) );
void		ft_lstadd( t_list **, t_list * );
void		ft_push_back( t_list **, t_list * );
void		ft_llist_splice( t_list **, t_list *, t_list * );
t_list		*ft_lstiter( t_list *, uint8_t (*)(t_list *elem) );
uint8_t		detachNode( t_list **, t_list * );
void 		shuffle_linked_list( t_list** );


int		get_winsize( struct winsize *ws );

void		ft_itoa( int, char * );
WINDOW		*ft_create_win( int, int, int, int );
void		_time( char * );
char		*randomized_string( char *, int );
char 		*get_ip( struct sockaddr_in * );
uint32_t	get_port ( struct sockaddr_in * );
unsigned short	__rc_checksum( void *, int );
uint8_t		*__rc_read_file ( const char *, struct stat * );
char		**__rc_strsplit ( char *, int *, char * );
int		_random( register int, register int );
int		_random_except( int, int, int *, int );
void		ft_push_back( t_list **, t_list * );
void		ft_llist_splice( t_list **, t_list *, t_list * );
void 		reverse_llist( t_list * );
t_list		*find_node( t_list *, void *, int (*f)( void *, void *) );
int		intComparator( void *, void * );
int		stringComparator( void *, void * );
uint8_t		_is_elf( const char * );
int		get_arr_size( char **arr );
void		clear_arr( char **arr );

magic_t		initialize_lib_magiclib( int );
int		is_file_empty( const char *);
uint8_t		create_file_with_content( const char *, int, mode_t, const uint8_t *, uint64_t );
uint8_t		append_to_file( const char *, const uint8_t *, uint64_t );
void		ApplySuffixJmpIntel64( uint32_t, uint32_t, uint32_t, uint8_t * );
uint8_t 	ft_md5( const char *, unsigned char * );
void		display_md5( const char * );
void		get_last_part( const char *, char * );
void 		xor( uint8_t *, uint32_t, uint8_t * );
char**      my_strsplit( const char* s, const char* delim );
char**      strsplit_count( const char* s, const char* delim, size_t* nb );
void		create_encryption_key( uint64_t, int, uint8_t *);

// # Memory # //
void    *memmalloc( size_t );
void    *allocate_and_copy( void *data, size_t size );

/** Syscall **/
void	__NR_EXIT( int );
int	__NR_SOCKET( int, int, int );
int	__NR_SETSOCKOPT( int, int, int, const void *, socklen_t );
int	__NR_BIND( int, const struct sockaddr *, socklen_t);
int	__NR_LISTEN( int, int );
int	__NR_ACCEPT( int, struct sockaddr *restrict, socklen_t *restrict);
int	__NR_RT_SIGTIMEDWAIT( const sigset_t *, siginfo_t *, const struct timespec *, size_t );
int	__NR_KILL( int, int );

/** Rbtree **/
struct node	*__pg_add_node(node **, uint64_t, void *, uint64_t );
int 		__pg_search_node( node *, uint64_t );
node		*__pg_delete_node(node * , uint64_t );
void 		__pg_postorder( node* root, int (*)( node * ) );
void 		__pg_inorder( node * );
void 		__pg_preorder( node * );
int 		__pg_tree_size( node * );
node  		*__pg_search_inorder( node *, uint64_t );
int 		__pg_get_depth( node * );
node* 		__pg_copy_tree( node * );
node  		*__pg_reverse_search_inorder( node *, uint64_t );
void 		__pg_clear_tree( node ** );
int 		__pg_compare_tree ( node *, node * );
#endif
