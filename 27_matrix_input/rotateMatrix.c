#include <stdio.h>
#include <stdlib.h>

#include "rotate.c"

#define MATRIX_DIM 11

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: rotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }

  // open file
  FILE * f = fopen(argv[1], "r");
  // make sure a file was opened.
  if (f == NULL) {
    perror("Could not open file!");
    return EXIT_FAILURE;
  }
  // check that the input is correct
  int height = 0; // track how many lines matrix has
  char matrix[MATRIX_DIM, MATRIX_DIM];
  while(fgets(matrix[height], MATRIX_DIM, f) != NULL) {
    // If line has more than 10 characters
    if (strchr(matrix[height], "\n") == NULL) {
      fprintf(stderr, "Input matrix line (%d)'s width is more than 10 characters.\n", height);
      return EXIT_FAILURE;
    }
    // If line has less than 10 characters
    if (strchr(matrix[height], "\0") != NULL) {
      fprintf(stderr, "Input matrix line (%d)'s width is less than 10 characters.\n", height);
      return EXIT_FAILURE;
    }

    height++;
  }

  // if matrix has less than 10 rows
  if(height < MATRIX_DIM) {
    fprintf(stderr, "Input matrix height is %d (which is too small), but should be 10.", height-1);
    return EXIT_FAILURE;
  }

  // if matrix has more than 10 rows
  if (height > MATRIX_DIM) {
    fprintf(stderr, "Input matrix height is %d (which is too big), but should be 10.\n", height-1);
    return EXIT_FAILURE;
  }

  // if the file does not close
  if (fclose(f) != 0) {
    perror("Failed to close the file!");
    return EXIT_FAILURE;
  }

  // rotate the matrix 90 degrees clockwise and print it to stdout
  rotate(matrix);
  
  return EXIT_SUCCESS;
}
