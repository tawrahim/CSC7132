#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int pr_limit; // specifies number of children allowed to execute at a time
  int pr_count = 0; // number of active children
  char ch, file_name[256];
  FILE *fp;

  if (argc <= 2) {
    fprintf(stderr, "Usage: %s pr_limit file_name\n", argv[0]);
    exit(1);
  }
  
  sscanf(argv[1], "%d", &pr_limit);
  strcpy(file_name, argv[2]);

  printf("The contents of %s file are :\n", file_name);

  fp = fopen(file_name,"r"); // open file in read mode

  // bail out if file is invalid
  if(fp == NULL) {
     perror("Error while opening the file.\n");
     exit(-1);
  }

  // loop through file
  while((ch = fgetc(fp)) != EOF) {
     printf("%c",ch);
   }

   // close file to avoid leaks
  fclose(fp);

  // Return 0
  return 0;
}
