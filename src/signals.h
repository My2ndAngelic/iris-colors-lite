/* signals.h -- Signal processing header */
#ifndef REDSHIFT_SIGNALS_H
#define REDSHIFT_SIGNALS_H


#if defined(HAVE_SIGNAL_H) && !defined(__WIN32__)

extern volatile sig_atomic_t exiting;
extern volatile sig_atomic_t disable;

#else /* ! HAVE_SIGNAL_H || __WIN32__ */
extern volatile int exiting;
extern volatile int disable;
#endif /* ! HAVE_SIGNAL_H || __WIN32__ */


int signals_install_handlers(void);


#endif /* REDSHIFT_SIGNALS_H */
