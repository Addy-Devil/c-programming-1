#include <stdio.h>
#include <stdlib.h>

// size of square array
int n = 10;

// transpose
void transpose(char matrix[n][n]) {
  for (int r=0; r<n; r++) {
    for (int c=r+1; c<n; c++) {
      char tmp = matrix[r][c];
      matrix[r][c] = matrix[c][r];
      matrix[c][r] = tmp;
    }
  }
}

// reverse columns
void reverseColumns(char matrix[n][n]) {
  for (int c=0; c<n; c++) {
    for (int r=0; r<n/2; r++) {
      char tmp = matrix[c][r];
      matrix[c][r] = matrix[c][n-r-1];
      matrix[c][n-r-1] = tmp;
    }
  }
}

void rotate(char matrix[n][n]) {
  transpose(matrix);
  reverseColumns(matrix);
}
