#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, int n) {
  printf("sizeof(array): %d\n", sizeof(array)/sizeof(int));
  // if there are no elements, return NULL
  if (n<1 || array==NULL) {
    return 0;
  }
  // keep track of max sequence length
  size_t maxLength = 1;
  // keep track of current sequence length
  size_t seqLength = 1;
  // iterate over all the elements in an array
  int i = 1;
  while (i < n) {
    // if the ith element is greater than the (i-1)th
    // element, increment current sequence length
    if (array[i] > array[i-1]) {
      //printf("array[%d] > array[%d]\n", i, i-1);
      seqLength++;
      //printf("seqLength = %d\n", (int)seqLength);
      // if current sequence length is longer than
      // the maximum sequence length, update the longest
      // sequence length
      if (seqLength > maxLength) {
        maxLength = seqLength;
	//printf("i = %d, maxLength = %d\n", i, (int)maxLength);
      }
    } // otherwise, reset the current sequence length
    // to 1
    else {
      //printf("array[%d] <= array[%d]\n", i, i-1);
      // reset the length of the current sequence
      seqLength = 1;
      //printf("reset seqLength\n");
    }
    // increment the array index to check
    i++;
    //printf("i incremented to: %d\n", i);
  }
  // return the length of the longest sequence
  return maxLength;
}
