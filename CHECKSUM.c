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
#include <sys/uio.h>
#include <unistd.h>

#define max_int (255)
#define byte unassigned char


  int main (int argc, char * argv[], char ** envp) 
  {
​
  int count = 10;
  int sum = 0;
  int quotient;
  int remainder;
  byte checksum;
  byte complement;
  
  byte header[10];

  retval = read(STDIN_FILENO, &header, 10);

    for (int c = 1; c <= count ; c ++ ) 
        {
            if (c == 6) 
                {
                    checksum = header[c];
                    header[c] = 0;
                }
 
             sum += header[c];
        }
​
    quotient = sum / (max_int + 1);
    remainder = sum % (max_int + 1);
    sum = quotient + remainder;
    complement = max_int - sum;
  
  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) 
  {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}