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
      FILE * f = fopen(argv[i], "r");
      if (f==NULL) {
	fprintf(stderr, "Failed to open file: %s\n", argv[i]);
	return EXIT_FAILURE;
      }
      // write each line into the lines array
      size_t j = 0;
      //ssize_t lineLen = 0;
      //size_t numLines = 0;
      char ** lines = NULL;
      char * line = NULL;
      size_t sz = 0;
      while(getline(&line, &sz, f) >= 0) {
	lines = realloc(lines, (j+1) * sizeof(*lines));
	//lines[j] = malloc((lineLen+1) * sizeof(char));
	lines[j] = line;
	line = NULL;
	printf("for lines[%zu]: sz = %zu\n", j, sz);
	printf("%s\n", lines[j]);
	j++;
      }
      free(line);
      // if the file has no lines of content, then j will not have incremented
      // return an error
      if (j == 0) {
	fprintf(stderr, "File (%s) must contain at least one line of text.\n", argv[i]);
	return EXIT_FAILURE;
      }
      
      // sort the data
      sortData(lines, j);

      // print the lines that have been sorted
      int k;
      for (k=0; k<j; k++) {
	printf("%s\n", lines[k]);
      }

      // free each line of lines
      for (k=0; k<j; k++) {
	free(lines[k]);
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
