////////////////////////////////////////////////////////////
/* signals.c -- Signal processing source */

////////////////////////////////////////////////////////////
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

////////////////////////////////////////////////////////////
#include <stdio.h>
#if defined(HAVE_SIGNAL_H) && !defined(__WIN32__)
# include <signal.h>
#endif

////////////////////////////////////////////////////////////
#include "signals.h"

////////////////////////////////////////////////////////////
#if defined(HAVE_SIGNAL_H) && !defined(__WIN32__)
////////////////////////////////////////////////////////////
volatile sig_atomic_t exiting = 0;
volatile sig_atomic_t disable = 0;

////////////////////////////////////////////////////////////
/* Signal handler for exit signals */
static void sigexit(int signo)
{
	exiting = 1;
}

////////////////////////////////////////////////////////////
/* Signal handler for disable signal */
static void sigdisable(int signo)
{
	disable = 1;
}

////////////////////////////////////////////////////////////
#else /* ! HAVE_SIGNAL_H || __WIN32__ */
////////////////////////////////////////////////////////////
volatile int exiting = 0;
volatile int disable = 0;
////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
int signals_install_handlers(void)
{
#if defined(HAVE_SIGNAL_H) && !defined(__WIN32__)
	struct sigaction sigact;
	sigset_t sigset;
	int r;
	sigemptyset(&sigset);

	/* Install signal handler for INT and TERM signals */
	sigact.sa_handler = sigexit;
	sigact.sa_mask = sigset;
	sigact.sa_flags = 0;

	r = sigaction(SIGINT, &sigact, NULL);
	if (r < 0) {
		perror("sigaction");
		return -1;
	}

	r = sigaction(SIGTERM, &sigact, NULL);
	if (r < 0) {
		perror("sigaction");
		return -1;
	}

	/* Install signal handler for USR1 signal */
	sigact.sa_handler = sigdisable;
	sigact.sa_mask = sigset;
	sigact.sa_flags = 0;

	r = sigaction(SIGUSR1, &sigact, NULL);
	if (r < 0) {
		perror("sigaction");
		return -1;
	}

	/* Ignore CHLD signal. This causes child processes
	   (hooks) to be reaped automatically. */
	sigact.sa_handler = SIG_IGN;
	sigact.sa_mask = sigset;
	sigact.sa_flags = 0;

	r = sigaction(SIGCHLD, &sigact, NULL);
	if (r < 0) {
		perror("sigaction");
		return -1;
	}
#endif /* HAVE_SIGNAL_H && ! __WIN32__ */

	return 0;
}

////////////////////////////////////////////////////////////
