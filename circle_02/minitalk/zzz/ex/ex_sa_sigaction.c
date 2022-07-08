#include <signal.h>
#include <fcntl.h>

int	g_fd = 1;

static void	put_siginfo_fd(int fd, siginfo_t *info)
{
	ft_putchar_fd('\n', fd);
	write(1, "\033[0;31m", 8);
	ft_putstr_fd("client_pid ", fd);
	write(1, "\033[0m", 5);
	ft_putnbr_fd(info->si_pid, fd);
	ft_putstr_fd("  si_addr ", fd);
	ft_putstr_fd(ft_itoa((long)info->si_addr), fd);
	ft_putstr_fd("  si_band ", fd);
	ft_putnbr_fd(info->si_band, fd);
	ft_putstr_fd("  si_code ", fd);
	ft_putnbr_fd(info->si_code, fd);
	ft_putstr_fd("  si_errno ", fd);
	ft_putnbr_fd(info->si_errno, fd);
	ft_putstr_fd("  si_signo ", fd);
	ft_putnbr_fd(info->si_signo, fd);
	ft_putstr_fd("  si_status ", fd);
	ft_putnbr_fd(info->si_status, fd);
	ft_putstr_fd("  si_value ", fd);
	ft_putnbr_fd((int)info->si_uid, fd);
	ft_putnbr_fd(info->si_value.sival_int, fd);
	ft_putstr_fd(", ", fd);
	ft_putstr_fd(ft_itoa((long)info->si_value.sival_ptr), fd);
}

static void	put_ucontext_fd(int fd, ucontext_t *uc_ptr)
{
	ft_putstr_fd("\n\t", fd);
	ft_putstr_fd("  ss_flags ", fd);
	ft_putnbr_fd(uc_ptr->uc_stack.ss_flags, fd);
	ft_putstr_fd("  ss_size ", fd);
	ft_putnbr_fd(uc_ptr->uc_stack.ss_size, fd);
	ft_putstr_fd("  ss_sp ", fd);
	ft_putstr_fd(ft_itoa((long)uc_ptr->uc_stack.ss_sp), fd);
}

static void	signal_catcher(int signo, siginfo_t *info, void *context)
{
	if (info->si_pid != 0 && (signo == SIGUSR1 || signo == SIGUSR2))
	{
		put_siginfo_fd(g_fd, info);
		put_ucontext_fd(g_fd, (ucontext_t *)context);
	}
}

int	main(void)
{
	g_fd = open("./output", O_WRONLY);
}
