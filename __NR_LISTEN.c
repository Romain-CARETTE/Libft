#include "libft.h"

int	__NR_LISTEN( int sockfd, int backlog )
{
	int	ret;
	__asm__ volatile ("syscall" : "=a" (ret) : "a" (__NR_listen),
		      "D" (sockfd), "S" (backlog) : 
		      "cc", "memory", "rcx", "r11");
	return ( ret );
}
