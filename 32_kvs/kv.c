#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * getKVPair(char * line) {
  char * token;
  kvpair_t * kvpair = malloc(sizeof(*kvpair));
  token = strtok(line, "=");
  kvpair->key =  token;
  token = strtok(NULL, "=");
  kvpair->value = token;
  
  return kvpair;
}

void addPairToArray(kvarray_t * kvarray, kvpair_t * kvpair) {
  kvarray->numPairs++;
  kvarray->kvpairs = realloc(kvarray->kvpairs, kvarray->numPairs * sizeof(*kvpair));
  kvarray->kvpairs[kvarray->numPairs-1] = kvpair;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname, "r");
  if (f == NULL) {
    perror("fopen");
    fprintf(stderr, "Trying to open %s\n", fname);
    return NULL;
  }

  kvarray_t * kvarray = malloc(sizeof(*kvarray));
  char * line = NULL;
  size_t sz = 0;
  while (getline(&line, &sz, f) > 0) {
    kvpair_t * kvpair = getKVPair(line);
    addPairToArray(kvarray, kvpair);
    line = NULL;
  }
  free(line);
  
  if (fclose(f) != 0) {
    perror("fclose");
    fprintf(stderr, "Trying to close %s\n", fname);
    return NULL;
  }

  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i=0; i<pairs->numPairs; i++) {
    free(pairs->kvpairs[i]);
  }
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i=0; i<pairs->numPairs; i++) {
    printf("key = '%s' value = '%s'\n", pairs->kvpairs[i]->key, pairs->kvpairs[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for (int i=0; i<pairs->numPairs; i++) {
    if (strcmp(pairs->kvpairs[i]->key, key)==0) {
      return pairs->kvpairs[i]->value;
    }
  }
  return NULL;
}
