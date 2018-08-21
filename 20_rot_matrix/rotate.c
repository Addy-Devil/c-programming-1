#include <stdio.h>
#include <stdlib.h>


// transpose
void transpose(char matrix[10][10]) {
  for (int r=0; r<10; r++) {
    for (int c=r+1; c<10; c++) {
      char tmp = matrix[r][c];
      matrix[r][c] = matrix[c][r];
      matrix[c][r] = tmp;
    }
  }
}

// reverse columns
void reverseColumns(char matrix[10][10]) {
  for (int c=0; c<10; c++) {
    for (int r=0; r<10/2; r++) {
      char tmp = matrix[c][r];
      matrix[c][r] = matrix[c][10-r-1];
      matrix[c][10-r-1] = tmp;
    }
  }
}

void rotate(char matrix[10][10]) {
  transpose(matrix);
  reverseColumns(matrix);
}
