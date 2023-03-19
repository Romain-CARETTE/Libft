#include "libft.h"

int	__NR_BIND( int sockfd, const struct sockaddr *addr, socklen_t addrlen )
{
	int	ret;
	__asm__ volatile ("syscall" : "=a" (ret) : "a" (__NR_bind),
		      "D" (sockfd), "S" (addr), "d" (addrlen) :
		      "cc", "memory", "rcx", "r11");
	return ( ret );
}
