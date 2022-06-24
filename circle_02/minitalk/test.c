#include <unistd.h>
#include <signal.h>
#include "libft.h"

static void	sigkill(int sig)
{
	/*some code neglected*/
	exit(0);
}
static void	sigint(int sig)
{
	flag=1;
}

static void	alive(void)
{
	unsigned int	m_seconds;
	int				return_code;

	signal(SIGINT, sigint);
	signal(SIGKILL, sigkill);
	alarm(10);
	while (1)
	{
		printf("%d\n",flag);
		sleep(1);
		if (flag == 1)
		{
			printf("no\n");
			flag = 0;
		}
	}
	m_seconds = 500000;
	return_code = usleep(m_seconds);
}

static void	child_function(void)
{
	/* Perform initialization. */
	ft_printf("Server started...  My pid is %d.\n", (int)getpid());
	/* Let parent know you’re done. */
	kill (getppid (), SIGUSR1);
	/* Continue with execution. */
	write ("Bye, now....", 1);
	exit (0);
}

static void	catch_sigusr(int signo)
{
	ft_putstr_fd("SIGUSR1 Receive ", 1);
	ft_putnbr_fd(signo, 1);
	write(1, "\n", 1);
	// signal(SIGINT,SIG_DFL);
}

static void	handler(int signum)
{
	/* Take appropriate actions for signal delivery */
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	static sigset_t		signal_mask;

	pid = getpid();
	ft_putstr_fd("Server started...  My pid is ", 1);
	ft_putnbr_fd((int)getpid(), 1);
	write(1, "\n", 1);
	// struct sigaction
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	// struct sigset_t
	sigemptyset (&signal_mask);
	sigaddset (&signal_mask, SIGINT);
	sigaddset (&signal_mask, SIGTERM);
	/* Restart functions if interrupted by handler */
	sa.sa_flags = SA_RESTART;
	if (signal(SIGUSR1, (void *) catch_sigusr) == SIG_ERR)
	{
		/* Handle error */;
	}
	if (kill(pid, SIGUSR1) == -1)
	{	
		/* Handle error */;
	}
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		/* Handle error */;
	}
	pause();
	while (1)
	{
		if ()
	}
	
	return (0);
}