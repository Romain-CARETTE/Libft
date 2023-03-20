#include "libft.h"

int	__NR_RT_SIGTIMEDWAIT( const sigset_t *set, siginfo_t *info, const struct timespec *timeout, size_t sigsetsize )
{
	int	ret;
	register long r8 asm("r8") = sigsetsize;
	__asm__ volatile ("syscall" : "=a" (ret) : "a" (__NR_rt_sigtimedwait),
		      "D" (set), "S" (info), "d" (timeout), "r" (r8) : 
		      "cc", "memory", "rcx", "r11");
	return ( ret );
}
