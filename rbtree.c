#include "libft.h"

/*
 * \fn node	*__pg_create_node( void *content, uint64_t size, uint64_t key )
 * \brief
 */
node	*__pg_create_node( void *content, uint64_t size, uint64_t key )
{
	node	*new = (struct node *)malloc( sizeof( struct node ));
	if ( new == NULL )
		return ( NULL );
	memset( new, 0, sizeof( struct node ));
	new->key = key;
	new->content = calloc( sizeof( char ), size );
	if ( new->content == NULL )
	{
		free( new );
		return ( NULL );
	}
	memcpy( new->content, content, size );
	new->size = size;
	return ( new );
}

/*
 * \fn node * __pg_add_node( node **tree, uint64_t key, void *content, uint64_t size )
 * \brief
 */
node * __pg_add_node( node **tree, uint64_t key, void *content, uint64_t size )
{
	node *tmpNode = NULL;
	node *tmpTree = *tree;
	node *elem = __pg_create_node( content, size, key );
	if ( elem == NULL )
	    return ( NULL );
	if( tmpTree )
	{
		do
		{
			tmpNode = tmpTree;
			if( key > tmpTree->key )
			{
				tmpTree = tmpTree->right;
				if( ! tmpTree )
					tmpNode->right = elem;
			}
			else
			{
				tmpTree = tmpTree->left;
				if( ! tmpTree )
					tmpNode->left = elem;
			}
		}while( tmpTree );
	}
	else
		*tree = elem;
	return ( elem );
}

/*
 * \fn int __pg_search_node( node *tree, uint64_t key )
 * \brief
 */
int __pg_search_node( node *tree, uint64_t key )
{
	while( tree )
	{
		if ( key == tree->key )
			return ( 1 );
		
		if( key > tree->key )
			tree = tree->right;
		else
			tree = tree->left;
	}
	return ( 0 );
}

/*
 * \fn node  *__pg_search_inorder( node* root, uint64_t key)
 * \brief
 */
node  *__pg_search_inorder( node* root, uint64_t key)
{
	if ( root == NULL )
		return NULL;
	node	*node = NULL;
	if ( ( node =  __pg_search_inorder( root->left, key)) != NULL )
	    return node;
	if ( root->key == key )
		return ( root );
	return __pg_search_inorder(root->right, key);
}

/*
 * \fn node  *__pg_reverse_search_inorder( node* root, uint64_t key)
 * \brief
 */
node  *__pg_reverse_search_inorder( node* root, uint64_t key)
{
	if ( root == NULL )
		return NULL;
	node	*node = NULL;
	if ( ( node =  __pg_reverse_search_inorder( root->right, key)) != NULL )
	    return node;
	if ( root->key == key )
		return ( root );
	return __pg_reverse_search_inorder(root->left, key);
}

/*
 * \fn int __pg_get_depth( node* root )
 * \brief
 */
int __pg_get_depth( node* root )
{
	if (root == NULL)
		return 0;
	int left_depth = __pg_get_depth( root->left );
	int right_depth = __pg_get_depth( root->right );
	return ( MAX( left_depth, right_depth ) + 1 );
}

/*
 * \fn node* __pg_copy_tree( node* orig_root )
 * \brief
 */
node* __pg_copy_tree( node* orig_root )
{
	if ( orig_root == NULL )
	    return ( NULL );
	node	*new_node = (struct node *)malloc( sizeof( struct node ) );
	if ( new_node == NULL )
		return ( NULL );
	new_node->key = orig_root->key;
	new_node->content = malloc( orig_root->size );
	if ( new_node->content == NULL )
		return ( NULL );
	memcpy( new_node->content, orig_root->content, orig_root->size );
	new_node->size = orig_root->size;

	new_node->left = __pg_copy_tree( orig_root->left );
	new_node->right = __pg_copy_tree( orig_root->right );
    return ( new_node );
}

/*
 * \fn node* __pg_delete_node( node* root, uint64_t key)
 * \brief
 */
node* __pg_delete_node( node* root, uint64_t key)
{
	if (root == NULL)
		return ( root );
	
	if ( key < root->key )
		root->left = __pg_delete_node( root->left, key );
	else if ( key > root->key )
		root->right = __pg_delete_node( root->right, key );
	else
	{
		// Cas où le nœud à supprimer a un seul enfant ou aucun enfant
		if (root->left == NULL)
		{
			node* tmp = root->right;
			free( root );
			return ( tmp );
		}
		else if ( root->right == NULL )
		{
			node* tmp = root->left;
			free( root );
			return ( tmp );
		}
		// Cas où le nœud à supprimer a deux enfants
		node* tmp = root->right;
		while (tmp->left != NULL)
			tmp = tmp->left;
		root->key = tmp->key;
		root->right = __pg_delete_node(root->right, tmp->key);
	}
	return ( root );
}

/*
 * \fn void __pg_preorder( node* root )
 * \brief
 */
void __pg_preorder( node* root )
{
	if ( root != NULL )
	{
		printf("%ld ", root->key);
		__pg_preorder(root->left);
		__pg_preorder(root->right);
	}
}

/*
 * \fn void __pg_inorder( node* root )
 * \brief
 */
void __pg_inorder( node* root )
{
	if ( root != NULL )
	{
		__pg_inorder(root->left);
		printf("%ld ", root->key);
		__pg_inorder(root->right);
	}
}

/*
 * \fn void __pg_postorder( node* root, int (*f)( node * ) )
 * \brief
 */
void __pg_postorder( node* root, int (*f)( node * ) )
{
	if ( root != NULL )
	{
		__pg_postorder(root->left, f );
		__pg_postorder(root->right, f );
		printf("%ld ", root->key);
	}
}

/*
 * \fn int __pg_tree_size( node *root )
 * \brief
 */
int __pg_tree_size( node *root )
{
	if (root == NULL)
		return ( 0 );
        return ( __pg_tree_size(root->left) + 1 + __pg_tree_size( root->right ));
}

/*
 * \fn void __pg_clear_tree( node **tree )
 * \brief
 */
void __pg_clear_tree( node **tree )
{
	node *tmp_tree = *tree;
	if( ! tree )
		return;
	if( tmp_tree->left )
		__pg_clear_tree( &tmp_tree->left );
	if( tmp_tree->right )
		__pg_clear_tree( &tmp_tree->right );
	free( tmp_tree );
	*tree = NULL;
}

int __pg_compare_tree ( node *tree1, node *tree2 )
{
	if (tree1 == NULL && tree2 == NULL)
		return (0);
	if ( tree1 == NULL || tree2 == NULL )
		return ( -1 );
	if ( tree1->key != tree2->key )
		return ( -1 );
	int leftResult = __pg_compare_tree(tree1->left, tree2->left);
	int rightResult = __pg_compare_tree(tree1->right, tree2->right);
	if ( leftResult == -1 || rightResult == -1 )
		return ( -1 );
	return ( 0 );
}

