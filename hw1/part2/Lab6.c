#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

main ( )
{
int	number=0, statval ;
printf ("%d: I'm the parent !\n", getpid ( ) ) ;
printf ("%d: number = %d\n", getpid ( ), number ) ;
printf ("%d: forking ! \n", getpid ( ) ) ;

if ( fork ( ) == 0 )
{
printf ("%d: I'm the child !\n", getpid ( ) ) ;
printf ("%d: number = %d\n", getpid ( ), number ) ;
printf ("%d: Enter a number : ", getpid ( ) ) ;
scanf ("%d", &number) ;
printf ("%d: number = %d\n", getpid ( ), number ) ;
printf ("%d: exiting with value %d\n", getpid ( ), number ) ;
exit (number) ;
}

printf ("%d: number = %d\n", getpid ( ), number ) ; printf ("%d: waiting for my kid !\n", getpid ( ) ) ; wait (&statval) ;

if ( WIFEXITED (statval) )
{

printf ("%d: my kid exited with status %d\n",
		getpid ( ), WEXITSTATUS (statval) ) ;


}
else
{
printf ("%d: My kid was killed off!\n",getpid());
}
}






