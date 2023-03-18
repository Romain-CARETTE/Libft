#include "libft.h"

void	__NR_EXIT( int ret )
{
	__asm__ volatile ("syscall" : : "a" ( __NR_exit ),
			"D" ( ret ) : 
			"cc", "memory", "rcx", "r11");
}
