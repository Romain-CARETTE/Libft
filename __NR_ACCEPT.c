#include "libft.h"

int	__NR_ACCEPT( int sockfd, struct sockaddr *restrict addr, socklen_t *restrict addrlen)
{
	int	ret;
	__asm__ volatile ("syscall" : "=a" (ret) : "a" (__NR_accept),
		      "D" (sockfd), "S" (addr), "d" (addrlen) :
		      "cc", "memory", "rcx", "r11");
	return ( ret );
}
