#include <stdio.h>
#include <unistd.h>

main (argc, argv )
int argc ;
char *argv[ ] ;
{
execv ("/bin/echo",	/* program to load - full path only */
&argv[0] ) ;

printf ("EXEC Failed\n") ;
/* This above line will be printed only on error and not otherwise */
}

