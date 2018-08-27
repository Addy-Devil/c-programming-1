#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  if(argc==1) {
    printf("Work on tmp.txt first\n");
    return EXIT_FAILURE;
  }
  else {
    size_t i = 1;
    while (i < argc) {
      char * line = NULL;
      size_t sz = 0;
      FILE * f = fopen(argv[i], "r");
      if (f==NULL) {
	fprintf(stderr, "Failed to open file: %s\n", argv[i]);
	return EXIT_FAILURE;
      }

      // get the number of lines to read and malloc an array to hold them
      /*
      size_t numLines = getNumLines(f);
      printf("num lines in file: %s : %zu\n", argv[i],  numLines);
      */
      // write each line into the lines array
      size_t j = 0;
      ssize_t lineLen = 0;
      size_t numLines = 1;
      char ** lines = malloc(numLines * sizeof(char*));
      while((lineLen=getline(&line, &sz, f)) > 0) {
	lines[j] = malloc((lineLen+1) * sizeof(char));
	lines[j] = line;
	j++;
	numLines++;
	lines = realloc(lines, numLines * sizeof(char*));
      }

      // if the file has no lines of content, then j will not have incremented
      // return an error
      if (j == 0) {
	fprintf(stderr, "File (%s) must contain at least one line of text.\n", argv[i]);
	return EXIT_FAILURE;
      }
      
      // while loop right above adds 1 too many to numLines and reallocs to `lines`,
      // so take them away
      if (numLines > 1) {
	numLines--;
	lines = realloc(lines, numLines * sizeof(char*));
      }
      
      // DELETE THIS LATER
      // check array has correct info in it...
      printf("Pre sorted array.\n");
      for (int k=0;k<numLines;k++) {
	printf("%s", lines[k]);
      }
      // DELETE THIS LATER
      
      // free last line from getline
      free(line);
      // sort the data
      sortData(lines, numLines);

      // print the lines that have been sorted
      for (j=0; j<numLines; j++) {
	printf("%s\n", lines[j]);
      }

      // free each line of lines
      for (j=0; j<numLines; j++) {
	free(lines[j]);
      }
      // free malloced lines array
      free(lines);
      i++;
      if (fclose(f) != 0) {
	perror("Failed to close the file!");
	return EXIT_FAILURE;
      }
    }
  }
  return EXIT_SUCCESS;
}
