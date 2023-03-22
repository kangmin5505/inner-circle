# 42seoul-minitalk
> Summary: The purpose of this project is to code a small data exchange program using UNIX signals.

## Common Instructions
- Must use C language
- Norm
- No error(segmentation falut, bus error, double free, etc)
- No leak
- Submit Makefile which will compile your source files
  - Flags -Wall, -Wextra and -Werror
  - Use cc(compiler)
  - No relink
  - Least contain $(NAME), all, clean, fclean, re
- To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers libraies of functions that are forbidden on the main part of the project.\
Bonuses must be in a different file _bonus.{c/h}.
- If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile.\
Your project's Makefile must compile the library by using its Makefile, then compile the project.
- The executable files must be named client and server
- You have to handle errors sensitively.\
In no way can your program quit unexpectedly(Segmentation falut, bus error, double free, etc).
- Your program cannot have memory leaks.
- You can use one global variable but it must be justified.
- On the mandatory part you are allowed to use the following functions:
  - write
  - ft_printf and any equivalent YOU coded
  - signal
  - sigemptyset
  - sigaddset
  - sigaction
  - kill
  - getpid
  - malloc
  - free
  - pause
  - sleep
  - usleep
  - exit

## Mandatory Part
- You must create a communication program in the form of a client and server.
- The server must be launched first, and after being launched it must display its PID.
- The client will take as parameters:
  - The server PID.
  - The string that should be sent.
- The client must communicated the string passed as a parameter to the server.\
Once the string has been received, the server must display it.
- Communication between your programs should ONLY be done using UNIX signals.
- The server must be able to disply the string pretty quickly.\
By quickly we mean that if you think it is too long, then it is probably too long (hint: 1 second for 100 characters is COLOSSAL)
- Your server should be able to receive strings from several clients in a row, without nedding to e restarted.
- You can only use the two signals SIGUSR1 and SIGUSR2.

![image](https://user-images.githubusercontent.com/74703501/146633592-5c707c20-6466-4768-b3f5-b9cdf071b67c.png)

## Bonus
- The server confirms every signal received by sending a signal to the client.
- support Unicode characters!

## Background
```c
#include "ft_printf.h"

int           ft_printf(const char *fmt, ...);

#include <unistd.h>

ssize_t       write(int fildes, const void *buf, size_t nbyte);
pid_t         getpid(void);
int           pause(void);
unsigned int  sleep(unsigned int seconds);
int           usleep(useconds_t microseconds);

#include <signal.h>

void          (*signal(int sig, void (*func)(int)))(int);
/*
easy version
typedef void (*sig_t)(int);

sig_t signal(int sig, sig_t func);
*/
int           sigemptyset(sigset_t *set);
int           sigaddset(sigset_t *set, int signo);
struct sigaction {
  union     __sigaction_u __sigaction_u; /* signal handler */
  sigset_t  sa_mask;                     /* signal mast to apply */
  int       sa_flags;                    /* see signal options below */
 };

union __sigaction_u {
  void      (*__sa_handler)(int);
  void      (*__sa_sigaction)(int, siginfo_t *, void *);
};

#define sa_handler    __sigaction_u.__sa_handler
#define sa_sigaction  __sigaction_u.__sa_sigaction
int           sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
int           kill(pid_t pid, int sig);

#include <stdlib.h>

void          *malloc(size_t size);
void          free(void *ptr);
void          exit(int status);
```

### int ft_printf(const char *fmt, ...)
- Define : Formatted output conversion
- Description : The printf() family of functions produces output according to a <u>format</u> as described below
- Return value : These functions return the number of characters printed (not including the trailing '\0' used to end output to strings)
- Error : In addition to the errors documented for the write(2) system call, the printf() family of functions may fail if:
  - An invalid wide character code was encountered.
  - Insufficient storage space is available.

### ssize_t write(int fildes, const void *buf, size_t nbyte)
- Define : Write output
- Description : write() attempts to write nbyte of data to the object referenced by the descriptor fildes from the buffer pointed to by buf.
- Return value : Upon successful completion the number of bytes which were written is returned.\
Otherwise, a -1 is returned and the global variable errno is set to indicate the error.

### pid_t getpid(void)
- Define : Get parent or calling process identification
- Description : getpid() returns the process ID of the calling precess.\
The ID is guaranteed to be unique and is useful for constructing temporary file names.
- Return value : getpid() returns the process ID of the calling precess.
- Errors : The getpid() function is always successful, and no return value is reserved to indicate an error.

### int pause(void)
- Define : Stop until signal
- Description : Pause is made obsolete by sigsuspend(2).\
The pause() function causes the calling thread to pause until a signal is received from either the kill(2) function or an interval timer. (See setitimer(2).)
Upon termination of a signal handler started during a pause(), the pause() call will return.
- Return value : Always returns -1.
- Error : The pause() function always returns:
  - The call was interrupted.

### unsigned int sleep(unsigned int seconds)
- Define : Suspend thread execution for an interval measured in seconds
- Description : The sleep() function suspends execution of the calling thread until either <u>seconds</u> seconds have elapsed or a signal is delivered to the thread and its action is to invoke a signal-catching function or to terminated the thread or process.\
System activity may lengthen the sleep by an indeterminate amount.\
\
This function is implemented using nanosleep(2) by pausing for <u>seconds</u> seconds or until a signal occurs.\
Consequently, in this implementation, sleeping has no effect on the state of precess timers, and there is no special handling for SIGALRM.
- Return value : If the sleep() function returns because the requested time has elapsed, the value returned will be zero.\
If the sleep() function returns due to the delivery of a signal, the value returned will be the unslept amount (the requested time minus the time actually slept) in seconds.

### int usleep(useconds_t microseconds)
- Define : Suspend thread execution for an interval measured in microseconds
- Description : The usleep() function suspends execution of the calling thread until either <u>microseconds</u> microseconds have elapsed or a signal is delivered to the thread and its action is to invoke a signal-catching function or to terminate the process.\
System activity or limitations may lengthen the sleep by an indeterminate amount.\
\
This function is implemented using nanosleep(2) by pausing for <u>microseconds</u> microseconds or until a signal occurs.\
Consequently, in this implementation, sleeping has no effect on the state of process timers, and there is no special handling for SIGALRM.\
Also, this implementation does not put a limit on the value of <u>microseconds</u> (other than that limited by the size of the <u>useconds_t</u> type); some other platforms require it to be less than one millon.
- Return value : The usleep() function returns the value 0 if successful; otherwise the value -1 is returned and the global variable <u>errno</u> is set to indicate the error.
usleep(useconds_t microseconds);
- Error : The usleep() function will fail if:
  - A signal was delivered to the precess and its action was to invoke a signal-catching function.

### void (*signal(int sig, void (*func)(int)))(int)
- Define : Simplified software signal facilities
- Description : This signal() facility is a simplified interface to the more general sigaction(2) facility.\
- Return value : The previous action is returned on a successful call.\
Otherwise, SIG_ERR is returned and the global variable errno is set to indicate the error.
- Error : The signal() function will fail and no action will take place if one of the following occur:
  - The sig argument is not a valid signal number
  - An attempt is made to ignore or supply a handler for SIGKILL or SIGSTOP.

### int sigemptyset(sigset_t *set)
- Define : Manipulate signal sets
- Description : These functions manipulate signal sets, stored in a sigset_t.\
Either sigemptyset() or sigfillset() must be called for every object of type sigset_t before any other use of the object.\
The sigemptyset() function initializes a signal set to be empty.
- Return value : return 0.
- Error : Currently, no errors are detected.

### int sigaddset(sigset_t *set, int signo)
- Define : Manipulate signal sets
- Description : These functions manipulate signal sets, stored in a sigset_t.\
The sigaddset() function adds the specified signal signo to the signal set.
- Return value : return 0.
- Error : Currently, no errors are detected.

### int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
```c
struct sigaction {
  union     __sigaction_u __sigaction_u; /* signal handler */
  sigset_t  sa_mask;                     /* signal mast to apply */
  int       sa_flags;                    /* see signal options below */
 };

union __sigaction_u {
  void      (*__sa_handler)(int);
  void      (*__sa_sigaction)(int, siginfo_t *, void *);
};

#define sa_handler    __sigaction_u.__sa_handler
#define sa_sigaction  __sigaction_u.__sa_sigaction
```
- Define : Software signal facilities
- Description : The system defines a set of signals that may be delivered to a process.\
Signal delivery resembles the occurrence of a hardware interrupt: the signal is normally blocked from further occurrence, the current process context is saved, and a new one is built.\
A process may specify a handler to which a signal is delivered, or specify that a signal is to be ignored.\
A process may also specify that a default action is to be taken by the system when a signal occurs.\
A signal may also be blocked, in which case its delivery is postponed until it is unblocked.\
The action to be taken on delivery is determined at the time of delivery.\
Normally, signal handlers execute on the current stack of the process.\
This may be changed, on a per-handler basis, so that signals are taken on a special signal stack.\
\
Signal routines normally execute with the signal that caused their invocation blocked, but other signals may yet occur.\
A global signal mask defines the set of signals currently blocked from delivery to a process.\
The signal mask for a process is initialized from that of its parent (normally empty).\
It may be changed with a sigprocmask(2) call, or when a signal is delivered to the process.\
\
When a signal condition arises for a process, the signal is added to a set of signals pending for the process.\
If the signal is not currently blocked by the process then it is delivered to the process.\
Signals may be delivered any time a process enters the operating system (e.g., during a system call, page fault or trap, or clock interrupt).\
If multiple signals are ready to be delivered at the same time, any signals that could be caused by traps are delivered first.\
Additional signals may be processed at the same time, with each appearing to interrupt the handlers for the previous signals before their first instructions.\
The set of pending signals is returned by the sigpending(2) system call.\
When a caught signal is delivered, the current state of the process is saved, a new signal mask is calculated (as described below), and the signal handler is invoked.\
The call to the handler is arranged so that if the signal handling routine returns normally the process will resume execution in the context from before the signal's delivery.\
If the process wishes to resume in a different context, then it must arrange to restore the previous context itself.\
\
When a signal is delivered to a process a new signal maks is installed for the duration of the process' signal handler (or until a sigprocmask(2) system call is made).\
This mask is formed by taking the union of the current signal mask set, the signal to be delivered, and the signal mask associated with the handler to be invoked.\
\
The sigaction() system call assigns an action for a signal specified by sig.\
If act is non-zero, it specifies an action (SIG_DFL, SIG_IGN, or a handler routine) and mask to be used when delivering the specified signal.\
If oact is non-zero, the previous handling information ofr the signal is returned to the user.\
\
Once a signal handler is installed, it normally remains installed until another sigaction() system call is made, or an execve(2) is performed.\
A signal-specific default action may be reset by setting sa_handler to SIG_DFL.\
The defaults are process termination, possibly with core dump; no action; stopping the process; or continuing the process;\
See the signal list below for each signal's default action.\
If sa_handler is SIG_DFL, the default action for the signal is to discard even if the signal is masked.\
If sa_handler is set to SIG_IGN current and pending instances of the signal are ignored and discarded.\
\
The sa_mask field specified in act is not allowed to block SIGKILL or SIGSTOP.\
Any attempt to do so will be silently ignored.
- Return value : The sigaction() function returns the value 0 if successful; otherwise the value -1 is returned and the global variable errno is set to indicated the error.
- Error : The sigaction() system call will fail and no new signal handler will be installed if one of the following occurs:
  - Either act or oact points to memory that is not a valid part of the process address space.
  - The sig argument is not a valid signal number.
  - An attempt is made to ignore or supply a handler for SIGKILL or SIGSTOP.
  - An attempt was made to set the action to SIG_DFL for a signal that cannot be caught or ignored (or both).

### int kill(pid_t pid, int sig)
- Define : send signal to a process
- Description : The kill() function sends the signal specified by sig to pid, a process or a group of processes.\
Typically, Sig will be one of the signals specified in sigaction(2).\
A value of 0, however, will cause error checking to be performed (with no signal being sent).\
This can be used to check the validity of pid.\
\
For a process to have permission to send a signal to a process designated by pid, the real or effective user ID of the receiving process must match that of the sending process or the user must have appropriate privileges (such as given by a set-user-ID program or the user is the super-user).\
\
If pid is greater than zero:
Sig is sent to the process whose ID is equal to pid.\
\
If pid is zero:
Sig is sent to all processes whose group ID is equal to the process group ID of the sender, and for which the process has permission; this is a variant of killpg(2).
If pid is -1:
If the user has super-user privileges, the signal is sent to all processes excluding system processes and the process sending the signal.\
If the user is not the super user, the signal is sent to all processes with the same uid as the user, excluding the process sending the signal.\
No error is returned if any process could be signaled.\
\
For compatibility with System V, if the process number is negative but not -1, the signal is sent to all processes whose process group ID is equal to the absolute value of the process number.\
This is a variant of killpg(2).
- Return value : Upon successfule completion, a value of 0 is returned.\
Otherwise, a value of -1 is  returned and errno is set to indicate the error.
- Error : kill() will fail and no signal will be sent if:
  - Sig is not a valid, supported signal number.
  - The sending process is not the super-user and its effective user id does not match the effective user-id of the receiving precess.\
    When signaling a process group, this error is returned if any members of the group could not be signaled.
  - No process or process group can be found corresponding to that specified by pid.
  - The process id was given as 0, but the sending process does not have a process group.

### void *malloc(size_t size)
- Define : Memory allocation
- Description : The malloc() function allocates size bytes of memory and returns a pointer to the allocated memory.\
The allocated memory is aligned such that it can be used for any data type, including AltiVec- and SSE-related types.
- Return value : If successful, function returns a pointer to allocated memory.\
If there is an error, they return a NULL pointer and set errno to ENOMEM.

### void free(void *ptr)
- Define : Memory allocation
- Description : The free() function fress allocations that were created via the preceding allocation functions.\
The free() function deallocates the memory allocation pointed to by ptr.\
If ptr is a NULL pointer, no operation is performed.
- Return value : The free() function does not return a value.

### void exit(int status)
- Define : Perform normal program termination
- Description : The exit() function terminates a process.\
Before termination, exit() performs the following functions in the order listed:
  1. Call the functions registered with the atexit(3) function, in the reverse order of their registration.
  2. Flush all open output streams.
  3. Close all open streams.
  4. Unlink all files created with the tmpfile(3) function.
- Return value : The exit() function never return.
void          exit(int status);
