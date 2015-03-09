#include <stdio.h>
#include <unistd.h>
main (int argc, char *argv[] )
{
execvp ("echo",	/* program to load - PATH searched */
&argv[0] ) ;

printf ("EXEC Failed\n") ;
/* This above line will be printed only on error and not otherwise */
}

