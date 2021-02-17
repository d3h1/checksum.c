/********************************/
/* Program Name: Checksum.c     */
/* Author: Deni Cabaravdic      */
/* Date:   02/15/2021           */
/********************************/
/* Description: To write the same checksum program we diud in java but in C with a twist*/
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <unistd.h>
​
#define max_int (255)
#define byte unsigned char
​
int main (int argc, char * argv[], char ** envp) {
​
  int count = 10;
  int sum = 0;
  int quotient;
  int remainder;
  byte checksum;
  byte complement;
  byte buffer[10];
​
  read(STDIN_FILENO, &buffer, 10);
​
  for (int x = 0; x < count; x++) {
    printf("%d ", buffer[x]);
    printf("\n");
  }
​
  for (int x = 0; x < count; x++) {
    if (x == 5) {
      checksum = buffer[x];
      buffer[x] = 0;
    }
    sum += buffer[x];
  }
​
    quotient = sum / (max_int + 1);
    remainder = sum % (max_int + 1);
    sum = quotient + remainder;
    complement = max_int - sum;
​
  /* the following is the prototype for the read system call */
  /* int read(int fildes, void *buf, size_t nbyte);  */
​
fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}