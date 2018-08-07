#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, int n);

void doTest(int * array, int n) {
  int p = maxSeq(array, n);
  printf("maxSeq(");
  if (array==NULL || n<1) {
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
  if (p == 0) {
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
  int array4[] = {3, 2, 1, 1}; // n=4
  int array5[] = {-1, -2, -1, -12}; // n=4
  int array6[] = {1, 2, 1, 2, 3, 4}; //n=6
  int array7[] = {1, 2, 1, 2}; // n=4
  
  doTest(array1, 6);
  doTest(array2, 7);
  doTest(array3, 5);
  doTest(array4, 4);
  doTest(array5, 4);
  doTest(array6, 6);
  doTest(array7, 4);
  doTest(NULL, 0);
  doTest(array1, 0);
  doTest(array1, 1);
  doTest(array1, -1);
  doTest(array1, 60);
  
  return EXIT_SUCCESS;
}
