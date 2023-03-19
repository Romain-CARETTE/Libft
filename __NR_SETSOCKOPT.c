#include "libft.h"

int	__NR_SETSOCKOPT( int sockfd, int level, int optname, const void *optval, socklen_t optlen )
{
	int	ret;
	register long r10 asm("r10") = (long)optval;
	register long r8 asm("r8") = optlen;
	__asm__ volatile ("syscall" : "=a" (ret) : "a" (__NR_setsockopt),
		      "D" (sockfd), "S" (level), "d" (optname), "r" (r10), "r" (r8) : 
		      "cc", "memory", "rcx", "r11");
	return ( ret );
}
