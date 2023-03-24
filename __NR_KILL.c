#include "libft.h"

int	__NR_KILL( int pid, int sig )
{
	int	ret;
	__asm__ volatile ("syscall" : "=a" (ret) : "a" (__NR_kill),
		      "D" (pid), "S" (sig) : 
		      "cc", "memory", "rcx", "r11");
	return ( ret );
}
