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

size_t getNumLines(FILE * f) {
  size_t n = 0;
  char * line = NULL;
  size_t sz = 0;
  while(getline(&line, &sz, f) > 0) {
    printf("In getNumLines: %s\n", line);
    n++;
  }
  free(line);
  f -= n;
  return n;
}

int main(int argc, char ** argv) {
  /*
  if (argc==1) {
    //read from stdin
    FILE * f = stdin;
  }
  else {
    //read from argvs
    FILE * f = fopen(argv[1], "r");
  }
  */

  // store lines of input so they can be sorted
  
  
  
  //WRITE YOUR CODE HERE!
  if(argc==1) {
    char * line = NULL;
    size_t sz = 0;

    extern FILE * stdin;
    if (stdin==NULL) {
      fprintf(stderr, "You must enter at least a line of text.\n");
      return EXIT_FAILURE;
    }
    // get the number of lines to read and malloc an array to hold them
    size_t numLines = getNumLines(stdin);
    char ** lines = malloc(numLines * sizeof(*lines));
    // write each line into the lines array
    size_t i = 0;
    while(getline(&line, &sz, stdin) > 0) {
      lines[i] = line;
      i++;
    }
    // free last line from getline
    free(line);
    // sort the data
    sortData(lines, numLines);

    // print the lines that have been sorted
    for (i=0; i<numLines; i++) {
      printf("%s\n", lines[i]);
    }
    
    // free malloced lines array
    free(lines);
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
      size_t numLines = getNumLines(f);
      if (fclose(f) != 0) {
	perror("File did not close.");
	return EXIT_FAILURE;
      }
      printf("num lines in file: %s : %zu\n", argv[i],  numLines);
      char ** lines = malloc(numLines * sizeof(char*));
      // write each line into the lines array
      size_t j = 0;
      size_t lineLen = 0;
      f = fopen(argv[i], "r");
      while((lineLen=getline(&line, &sz, f)) > 0) {
	lines[j] = malloc((lineLen+1) * sizeof(char));
	lines[j] = line;
	j++;
      }
      printf("Pre sorted array.\n");
      for (int k=0;k<numLines;k++) {
	printf("%s\n", lines[k]);
      }
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
