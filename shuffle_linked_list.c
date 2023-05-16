# include "libft.h"

void shuffle_linked_list( t_list** llist )
{
	// Counting the number of elements in the list.	
	uint32_t size = 0;
	t_list* current = *llist;
	while ( current != NULL )
	{
		size++;
		current = current->next;
	}

	// Generating a random sequence of indices to shuffle the list.
	srand(time(NULL));
	for ( int i = size - 1; i > 0; i-- )
	{
		int j = rand() % (i + 1);
		// Swapping the content of the nodes at indices i and j.
		t_list* n1 = *llist;
		t_list* n2 = *llist;
		for (int k = 0; k < i; k++)
		{
			n1 = n1->next;
		}
		for (int k = 0; k < j; k++)
			n2 = n2->next;
		void *temp = n1->content;
		size_t temp_size = n1->content_size;
		n1->content = n2->content;
		n1->content_size = n2->content_size;
		n2->content = temp;
		n2->content_size = temp_size;
	}
}
