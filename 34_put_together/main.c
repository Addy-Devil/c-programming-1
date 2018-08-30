#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t * c = createCounts();
  FILE * f = fopen(filename, "r");
  if (f==NULL) {
    perror("fopen");
    fprintf(stderr, "Could not open %s\n", filename);
    return NULL;
  }

  char * key = NULL;
  size_t sz = 0;
  char * value;//malloc(sizeof(*value));
  while(getline(&key, &sz, f) > 0) {
    value = lookupValue(kvPairs, key);
    //printf("in countFile: key = %s\n", key);
    //printf("in countFile: value = %s\n", value);
    addCount(c, value);
    free(key);
    key = NULL;
  }
  free(key);

  if (fclose(f)!=0) {
    perror("fclose");
    fprintf(stderr, "Could not close %s\n", filename);
    return NULL;
  }

  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if (argc<3) {
    fprintf(stderr, "Usage: count_values kvPairsFile listFile1 listFile2 ...\n");
    exit(EXIT_FAILURE);
  }
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);
  if (kv == NULL) {
    fprintf(stderr, "argv[1] must be a file of 'key=value' pairs\n");
    exit(EXIT_FAILURE);
  }

 //count from 2 to argc (call the number you count i)
  for (int i=2; i<argc; i++) {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c = countFile(argv[i], kv);
    //compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);

    //open the file named by outName (call that f)
    FILE * f = fopen(outName, "w");
    if (f == NULL) {
      perror("fopen");
      fprintf(stderr, "Could not open %s\n", outName);
      exit(EXIT_FAILURE);
    }
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    if (fclose(f) != 0) {
      perror("fclose");
      fprintf(stderr, "Could not close %s\n", outName);
      exit(EXIT_FAILURE);
    }
    //free the memory for outName and c
    free(outName);
    freeCounts(c);
  }

 //free the memory for kv
  freeKVs(kv);
  
  return EXIT_SUCCESS;
}
