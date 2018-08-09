#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y);

int n = 7;
unsigned myArray[7][3] = {
  {0, 0, 1}, // 0
  {0, 1, 0}, // 1
  {1, 0, 1}, // 2
  {2, 0, 1}, // 3
  {1, 1, 1}, // 4
  {-1, 2, 1},// 5
  {-1, 3, -1}// 6
};

int doTest(unsigned x, unsigned y, unsigned trueAns) {
  unsigned testAns = power(x, y);
  if (testAns != trueAns) {
    printf("testAns = %d, not %d like it should\n", testAns, trueAns);
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}

int main(void) {
  for (int i=0; i<n; i++) {
    int x = doTest(myArray[i][0], myArray[i][1], myArray[i][2]);
    if (x != 0) {
      exit(EXIT_FAILURE);
    }
  }
  /*
  unsigned x1 = 0;
  unsigned y1 = 0;
  unsigned ans1 = power(x1, y1);
  if (ans1 != 1) {
    printf("ans1 = %d, not 1\n", ans1);
    exit(EXIT_FAILURE);
  }

  unsigned x2 = 0;
  unsigned x2 = 1;
  unsigned ans2 = power(
  */
  
  

  return EXIT_SUCCESS;
}
