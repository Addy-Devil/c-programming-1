#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  // if there are no elements, return NULL
  if (n==0) {
    return NULL;
  }
  // keep track of max sequence length
  size_t maxLength = 1;
  // keep track of current sequence length
  size_t seqLength = 1;
  // iterate over all the elements in an array
  size_t i = 1;
  while (i < n) {
    // if the ith element is greater than the (i-1)th
    // element, increment current sequence length
    if (array[i] > array[i-1]) {
      seqLength++;
    }
    // otherwise, check if the length of the currrent
    // sequence is greater than the length of the
    // longest sequence
    else {
      if (seqLength > maxLength) {
	// if the current sequence is longer,
	// update the max sequence length
	maxLength = seqLength;
      }
      // reset the length of the current sequence
      seqLength = 1;
    }
    // increment the array index to check
    i++;
  }
  // return the length of the longest sequence
  return maxLength;
}
