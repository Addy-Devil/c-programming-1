#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, int n);

int main(void) {

  int array1[] = {1, 2, 3, 2, 1, 3};    // n=6
  int array2[] = {3, 1, 3, 5, 7, 2, 3}; // n=7
  int array3[] = {5000, 62, -7, 100, 0};// n=5
  int array4[] = {3, 2, 1, 1}; // n=4
  int array5[] = {-1, -2, -1, -12}; // n=4
  int array6[] = {1, 2, 1, 2, 3, 4}; //n=6
  int array7[] = {1, 2, 1, 2}; // n=4
  int array8[] = {1, 2, 3, -1}; // n=4

  // array1 n=6 ans = 3
  // array2 n=7 ans = 4
  // array3 n=5 ans = 2
  // array4 n=4 ans = 1
  // array5 n=4 ans = 2
  // array6 n=6 ans = 4
  // array7 n=4 ans = 2
  size_t x;
  
  x = maxSeq(array1, 6);
  printf("%d\n", (int)x);
  if (x != 3) {
    return EXIT_FAILURE;
  }
  x = maxSeq(array2, 7);
  printf("%d\n", (int)x);
  if (x != 4) {
    return EXIT_FAILURE;
  }
  x = maxSeq(array3, 5);
  printf("%d\n", (int)x);
  if (x!=2) {
    return EXIT_FAILURE;
  }
  x = maxSeq(array4, 4);
  printf("%d\n", (int)x);
  if (x!=1) {
    return EXIT_FAILURE;
  }
  x = maxSeq(array5, 4);
  printf("%d\n", (int)x);
  if (x!=2) {
    return EXIT_FAILURE;
  }
  x = maxSeq(array6, 6);
  printf("%d\n", (int)x);
  if (x!=4) {
    return EXIT_FAILURE;
  }
  x = maxSeq(array7, 4);
  printf("%d\n", (int)x);
  if (x!=2) {
    return EXIT_FAILURE;
  }
  x = maxSeq(array8, 4);
  printf("%d\n", (int)x);
  if (x!=3) {
    return EXIT_FAILURE;
  }
  x = maxSeq(NULL, 0);
  printf("%d\n", (int)x);
  if (x!=0) {
    return EXIT_FAILURE;
  }
  x = maxSeq(array1, 0);
  printf("%d\n", (int)x);
  if (x!=0) {
    return EXIT_FAILURE;
  }
  /*
  x = maxSeq(array1, 1);
  printf("array1, 1 case: %d\n", (int)x);
  if (x!=1) {
    return EXIT_FAILURE;
  }
  
  x = maxSeq(array1, 1.0);
  printf("n=-1 case: %d\n", (int)x);
  if (x!=0) {
    return EXIT_FAILURE;
  }
  */
  
  return EXIT_SUCCESS;
}
