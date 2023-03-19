#include "libft.h"

int	__NR_SOCKET( int domain, int type, int protocol )
{
	int	ret;
	__asm__ volatile ("syscall" : "=a" (ret) : "a" (__NR_socket),
		      "D" (domain), "S" (type), "d" (protocol) : 
		      "cc", "memory", "rcx", "r11");
	return ( ret );
}
