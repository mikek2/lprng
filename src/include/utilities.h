/***************************************************************************
 * LPRng - An Extended Print Spooler System
 *
 * Copyright 1988-2003, Patrick Powell, San Diego, CA
 *     papowell@lprng.com
 * See LICENSE for conditions of use.
 ***************************************************************************/



#ifndef _UTILITIES_H_
#define _UTILITIES_H_ 1

#include <setjmp.h>

EXTERN volatile int Alarm_timed_out;      /* flag */
EXTERN volatile int Timeout_pending;

#if defined(HAVE_SIGLONGJMP)
EXTERN sigjmp_buf Timeout_env;
#  define Set_timeout() (sigsetjmp(Timeout_env,1)==0)
#else
EXTERN jmp_buf Timeout_env;
#  define Set_timeout() (setjmp(Timeout_env)==0)
#endif

/* PROTOTYPES */
char *Time_str(int shortform, time_t t);
char *Pretty_time( time_t t );
time_t Convert_to_time_t( char *str );
void Printlist( const char **m, int fd );
int Write_fd_len( int fd, const char *msg, int len );
int Write_fd_len_timeout( int timeout, int fd, const char *msg, int len );
int Write_fd_str( int fd, const char *msg );
int Write_fd_str_timeout( int timeout, int fd, const char *msg );
int Read_fd_len_timeout( int timeout, int fd, char *msg, int len );
plp_sigfunc_t plp_signal (int signo, plp_sigfunc_t func);
plp_sigfunc_t plp_signal_break (int signo, plp_sigfunc_t func);
void plp_block_all_signals ( plp_block_mask *oblock );
void plp_unblock_all_signals ( plp_block_mask *oblock );
void plp_set_signal_mask ( plp_block_mask *in, plp_block_mask *out );
void plp_unblock_one_signal ( int sig, plp_block_mask *oblock );
void plp_block_one_signal( int sig, plp_block_mask *oblock );
void plp_sigpause( void );
int safestrcasecmp (const char *s1, const char *s2);
int safestrncasecmp (const char *s1, const char *s2, int len );
int safestrcmp( const char *s1, const char *s2 );
int safestrlen( const char *s1 );
int safestrncmp( const char *s1, const char *s2, int len );
char *safestrchr( const char *s1, int c );
char *safestrrchr( const char *s1, int c );
char *safestrpbrk( const char *s1, const char *s2 );
int plp_usleep( int i );
int plp_sleep( int i );
int Get_max_servers( void );
int Get_max_fd( void );
char *Brk_check_size( void );
char *mystrncat( char *s1, const char *s2, int len );
char *mystrncpy( char *s1, const char *s2, int len );
int Get_nonblock_io( int fd );
int Set_nonblock_io( int fd );
int Set_block_io( int fd );
int Read_write_timeout(
	int readfd, char *inbuffer, int maxinlen, int *readlen,
	int writefd, char **outbuffer, int *outlen, int timeout );
void Set_timeout_signal_handler( int timeout, plp_sigfunc_t handler );
void Set_timeout_alarm( int timeout );
void Set_timeout_break( int timeout );
void Clear_timeout( void );
void Setup_uid(void);
int To_euid_root(void);
int To_daemon(void);
int To_user(void);
int To_ruid(int ruid);
int To_euid( int euid );
int setuid_wrapper(uid_t to);
int Full_daemon_perms(void);
int Full_root_perms(void);
int Full_user_perms(void);
int Getdaemon(void);
int Getdaemon_group(void);
int Set_full_group( int euid, int gid );
int Setdaemon_group(void);
void Reset_daemonuid(void);
double Space_avail( const char *pathname );
/* VARARGS2 */
#ifdef HAVE_STDARGS
 int safefprintf (int fd, const char *format,...) PRINTFATTR(2,3)
#else
 int safefprintf (va_alist) va_dcl
#endif
;
#endif
