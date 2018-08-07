#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, int n) {
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
      printf("array[%d] > array[%d]\n", i, i-1);
      seqLength++;
      printf("seqLength = %d\n", (int)seqLength);
      // if we have checked all the items in the array
      // and last element of the array is part of the
      // largest strictly increasing sequence,
      // set the length of the max sequence
      if (seqLength > maxLength) {
        maxLength = seqLength;
	printf("i = %d, maxLength = %d\n", i, (int)maxLength);
      }
    }
    // otherwise, check if the length of the currrent
    // sequence is greater than the length of the
    // longest sequence
    else {
      printf("array[%d] <= array[%d]\n", i, i-1);
      /*
      if (seqLength > maxLength) {
	// if the current sequence is longer,
	// update the max sequence length
	maxLength = seqLength;
	printf("maxLength updated to: %d\n", maxLength);
      }
      */
      // reset the length of the current sequence
      seqLength = 1;
      printf("reset seqLength\n");
    }
    // increment the array index to check
    i++;
    printf("i incremented to: %d\n", i);
  }
  // return the length of the longest sequence
  return maxLength;
}
