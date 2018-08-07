#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

void doTest(int * array, int n) {
  printf("maxSeq(");
  if (array==NULL) {
    printf("NULL");
  }
  else {
    printf("{");
    for (size_t i=0; i<n; i++) {
      printf("%d", array[i]);
      if (i < n-1) {
	printf(", ");
      }
    }
    printf("}");
  }
  printf(", %d) is \n", n);
  size_t p = maxSeq(array, n);
  if (p == NULL) {
    printf("NULL\n");
  }
  else {
    printf("%d\n", p);
  }
}

int main(void) {

  int array1[] = {1, 2, 3, 2, 1, 3};    // n=6
  int array2[] = {3, 1, 3, 5, 7, 2, 3}; // n=7
  int array3[] = {5000, 62, -7, 100, 0};// n=5
  int array4[] = {1, 2, 3, 1, 2, 3, 4}; // n=7

  doTest(array1, 6);
  doTest(array2, 7);
  doTest(array3, 5);
  doTest(array4, 7);
  doTest(NULL, 0);
  doTest(array1, 0);
  
  return EXIT_SUCCESS;
}
