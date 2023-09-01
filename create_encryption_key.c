#include "libft.h"

/*
 * \fn void create_encryption_key( uint64_t, int, uint8_t )
 * \brief The function create_encryption_key generates a sequence of pseudo-random values in the form of an encryption key.
 */
void	create_encryption_key( uint64_t initial_num, int size_key, uint8_t *output )
{
	uint64_t a = 6364136223846793005ULL;
	uint64_t c = 1ULL;
	uint64_t m = 0xFFFFFFFFFFFFFFFFULL;  // m (2^64 - 1)
	for (int i = 0; i < size_key; i++)
	{
		initial_num = ( (a * initial_num + c) % m) & 255;
		output[ i ] = initial_num;
	}
}

