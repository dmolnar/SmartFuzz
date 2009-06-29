/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.in by autoheader.  */

/* Define to 1 if you're using AIX 5.1 or 5.2 or 5.3 */
/* #undef AIX5_LIBC */

/* Define to 1 if you're using Darwin */
#define DARWIN_LIBC 1

/* configured to run as an inner Valgrind */
/* #undef ENABLE_INNER */

/* path to GDB */
#define GDB_PATH "/usr/bin/gdb"

/* Define to 1 if you're using glibc 2.10.x */
/* #undef GLIBC_2_10 */

/* Define to 1 if you're using glibc 2.2.x */
/* #undef GLIBC_2_2 */

/* Define to 1 if you're using glibc 2.3.x */
/* #undef GLIBC_2_3 */

/* Define to 1 if you're using glibc 2.4.x */
/* #undef GLIBC_2_4 */

/* Define to 1 if you're using glibc 2.5.x */
/* #undef GLIBC_2_5 */

/* Define to 1 if you're using glibc 2.6.x */
/* #undef GLIBC_2_6 */

/* Define to 1 if you're using glibc 2.7.x */
/* #undef GLIBC_2_7 */

/* Define to 1 if you're using glibc 2.8.x */
/* #undef GLIBC_2_8 */

/* Define to 1 if you're using glibc 2.9.x */
/* #undef GLIBC_2_9 */

/* Define to 1 if you have the <asm/unistd.h> header file. */
/* #undef HAVE_ASM_UNISTD_H */

/* Define to 1 if as supports mtocrf/mfocrf. */
/* #undef HAVE_AS_PPC_MFTOCRF */

/* Define to 1 if gcc supports __sync_bool_compare_and_swap() a.o. */
/* #undef HAVE_BUILTIN_ATOMIC */

/* Define to 1 if gcc supports __builtin_expect. */
#define HAVE_BUILTIN_EXPECT 1

/* Define to 1 if you have the `clock_gettime' function. */
/* #undef HAVE_CLOCK_GETTIME */

/* Define to 1 if you have the `CLOCK_MONOTONIC' constant. */
/* #undef HAVE_CLOCK_MONOTONIC */

/* Define to 1 if you have the <endian.h> header file. */
/* #undef HAVE_ENDIAN_H */

/* Define to 1 if you have the `epoll_create' function. */
/* #undef HAVE_EPOLL_CREATE */

/* Define to 1 if you have the `epoll_pwait' function. */
/* #undef HAVE_EPOLL_PWAIT */

/* Define to 1 if you have the `eventfd' function. */
/* #undef HAVE_EVENTFD */

/* Define to 1 if you have the `eventfd_read' function. */
/* #undef HAVE_EVENTFD_READ */

/* Define to 1 if you have the `floor' function. */
#define HAVE_FLOOR 1

/* Define to 1 if you have the `getpagesize' function. */
#define HAVE_GETPAGESIZE 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `klogctl' function. */
/* #undef HAVE_KLOGCTL */

/* Define to 1 if you have the `rt' library (-lrt). */
/* #undef HAVE_LIBRT */

/* Define to 1 if you have the `mallinfo' function. */
/* #undef HAVE_MALLINFO */

/* Define to 1 if you have the `memchr' function. */
#define HAVE_MEMCHR 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have the `mkdir' function. */
#define HAVE_MKDIR 1

/* Define to 1 if you have a working `mmap' system call. */
#define HAVE_MMAP 1

/* Define to 1 if you have the <mqueue.h> header file. */
/* #undef HAVE_MQUEUE_H */

/* Define to 1 if you have the `mremap' function. */
/* #undef HAVE_MREMAP */

/* Define to 1 if you have the `ppoll' function. */
/* #undef HAVE_PPOLL */

/* can use /proc filesystem */
/* #undef HAVE_PROC */

/* Define to 1 if you have the `pthread_barrier_init' function. */
/* #undef HAVE_PTHREAD_BARRIER_INIT */

/* Define to 1 if you have the `pthread_condattr_setclock' function. */
/* #undef HAVE_PTHREAD_CONDATTR_SETCLOCK */

/* Define to 1 if you have the `pthread_create@glibc2.0' function. */
/* #undef HAVE_PTHREAD_CREATE_GLIBC_2_0 */

/* Define to 1 if you have the `PTHREAD_MUTEX_ADAPTIVE_NP' constant. */
/* #undef HAVE_PTHREAD_MUTEX_ADAPTIVE_NP */

/* Define to 1 if you have the `PTHREAD_MUTEX_ERRORCHECK_NP' constant. */
/* #undef HAVE_PTHREAD_MUTEX_ERRORCHECK_NP */

/* Define to 1 if you have the `PTHREAD_MUTEX_RECURSIVE_NP' constant. */
/* #undef HAVE_PTHREAD_MUTEX_RECURSIVE_NP */

/* Define to 1 if you have the `pthread_mutex_timedlock' function. */
/* #undef HAVE_PTHREAD_MUTEX_TIMEDLOCK */

/* Define to 1 if pthread_mutex_t has a member __data.__kind. */
/* #undef HAVE_PTHREAD_MUTEX_T__DATA__KIND */

/* Define to 1 if pthread_mutex_t has a member called __m_kind. */
/* #undef HAVE_PTHREAD_MUTEX_T__M_KIND */

/* Define to 1 if you have the `PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP'
   constant. */
/* #undef HAVE_PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP */

/* Define to 1 if you have the `pthread_rwlock_timedrdlock' function. */
/* #undef HAVE_PTHREAD_RWLOCK_TIMEDRDLOCK */

/* Define to 1 if you have the `pthread_rwlock_timedwrlock' function. */
/* #undef HAVE_PTHREAD_RWLOCK_TIMEDWRLOCK */

/* Define to 1 if you have the `pthread_spin_lock' function. */
/* #undef HAVE_PTHREAD_SPIN_LOCK */

/* Define to 1 if the installed version of Qt4 provides QMutex::tryLock(int).
   */
/* #undef HAVE_QTCORE_QMUTEX_TRYLOCK_INT */

/* Define to 1 if you have the `semtimedop' function. */
/* #undef HAVE_SEMTIMEDOP */

/* Define to 1 if you have the `signalfd' function. */
/* #undef HAVE_SIGNALFD */

/* Define to 1 if you have the `sigwaitinfo' function. */
/* #undef HAVE_SIGWAITINFO */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strpbrk' function. */
#define HAVE_STRPBRK 1

/* Define to 1 if you have the `strrchr' function. */
#define HAVE_STRRCHR 1

/* Define to 1 if you have the `strstr' function. */
#define HAVE_STRSTR 1

/* Define to 1 if you have the `syscall' function. */
#define HAVE_SYSCALL 1

/* Define to 1 if you have the <sys/endian.h> header file. */
/* #undef HAVE_SYS_ENDIAN_H */

/* Define to 1 if you have the <sys/epoll.h> header file. */
/* #undef HAVE_SYS_EPOLL_H */

/* Define to 1 if you have the <sys/eventfd.h> header file. */
/* #undef HAVE_SYS_EVENTFD_H */

/* Define to 1 if you have the <sys/klog.h> header file. */
/* #undef HAVE_SYS_KLOG_H */

/* Define to 1 if you have the <sys/poll.h> header file. */
#define HAVE_SYS_POLL_H 1

/* Define to 1 if you have the <sys/signalfd.h> header file. */
/* #undef HAVE_SYS_SIGNALFD_H */

/* Define to 1 if you have the <sys/signal.h> header file. */
#define HAVE_SYS_SIGNAL_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/syscall.h> header file. */
#define HAVE_SYS_SYSCALL_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the `timerfd' function. */
/* #undef HAVE_TIMERFD */

/* can use __thread to define thread-local variables */
/* #undef HAVE_TLS */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `utimensat' function. */
/* #undef HAVE_UTIMENSAT */

/* Define to 1 if you have the file `AC_File'. */
/* #undef HAVE__PROC_SELF_EXE */

/* Define to 1 if you have the file `AC_File'. */
/* #undef HAVE__PROC_SELF_FD */

/* Define to 1 if you have the file `AC_File'. */
/* #undef HAVE__PROC_SELF_MAPS */

/* Define to 1 if you're using Linux 2.4.x */
/* #undef KERNEL_2_4 */

/* Define to 1 if you're using Linux 2.6.x */
/* #undef KERNEL_2_6 */

/* Define to 1 if your C compiler doesn't accept -c and -o together. */
/* #undef NO_MINUS_C_MINUS_O */

/* Name of package */
#define PACKAGE "valgrind"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "valgrind-users@lists.sourceforge.net"

/* Define to the full name of this package. */
#define PACKAGE_NAME "Valgrind"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "Valgrind 3.5.0.SVN"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "valgrind"

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.5.0.SVN"

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Version number of package */
#define VERSION "3.5.0.SVN"

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef gid_t */

/* Define to `long int' if <sys/types.h> does not define. */
/* #undef off_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to `int' if <sys/types.h> doesn't define. */
/* #undef uid_t */
