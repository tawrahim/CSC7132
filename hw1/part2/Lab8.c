#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
main ( )
{
pid_t	parent_pid, child_pid, fork_pid, wait_pid ;
pid_t	parent_grp, child_grp, grpid ;
int	child_stat, exit_val ;

exit_val = 10 ; parent_pid = getpid ( ) ; parent_grp = getpgrp ( ) ;
printf ("\nParent process:  process ID: %ld	group ID: %ld\n", (long) parent_pid, (long) parent_grp) ;

fork_pid = fork ( ) ;

switch (fork_pid)
{
case -1:
perror ("FORK FAILED\n") ;
errno = 0 ;
break ;
case 0:
child_pid = getpid ( ) ;
child_grp = getpgrp ( ) ;
printf ("Child process:  process ID: %ld	group ID: %ld  " "parent process ID: %ld\n", (long) child_pid,
(long) child_grp, (long) getppid ( ) ) ;
grpid = setpgrp ( ) ;	/* Change the group of child */
setpgid (child_pid, grpid) ;
child_grp = getpgrp ( ) ;
printf ("Child process again: process ID: %ld group ID: %ld " "parent process ID: %ld\n", (long) child_pid,
(long) child_grp, (long) getppid ( ) ) ;
printf ("Child process: terminate with \"exit\" - value: %d\n", exit_val) ;
exit (exit_val) ;
break ;
default:
printf ("Parent process: child process with ID %ld created.\n", (long) fork_pid) ;
wait_pid = wait (&child_stat) ;
if (wait_pid == -1)
 
{
perror ("wait") ;
errno = 0 ;
}
else
{
printf ("Parent process: child process %ld has terminated.\n", (long) wait_pid) ;
}
}
}
