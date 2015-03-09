#include <stdio.h>

main ( )
{
int	pid ;

pid = fork();	/* Duplicate. Child and parent continue from here */

if ( pid != 0 )	/* pid is non-zero, so I must be the parent */
{
 while (1) /* Never terminate and never execute a wait ( ) */
sleep (100) ;	/* stop executing for 100 seconds
*/
}



else	/* pid is zero, so I must be the child */
{
exit (42) ;	/* exit with any number */
}
}
