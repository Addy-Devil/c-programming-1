#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t * getKVPair(char * line) {
  char *key, *value;
  //const char delim = '=';
  kvpair_t * kvpair = malloc(sizeof(*kvpair));

  /*
  //key = strsep(&line, &delim);
  value = strchr(line, delim);
  key = strsep(&line, &delim);
  */
  key = strsep(&line, "=");
  value = strsep(&line, "\n");
  kvpair->key = strdup(key);
  kvpair->value = strdup(value);
  
  return kvpair;
}

void addPairToArray(kvarray_t * pairs, kvpair_t * kvpair) {
  pairs->numPairs++;
  pairs->kvpairs = realloc(pairs->kvpairs, pairs->numPairs * sizeof(*kvpair));
  pairs->kvpairs[pairs->numPairs-1] = kvpair;
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
  kvarray->kvpairs = NULL;
  kvarray->numPairs = 0;
  char * line = NULL;
  size_t sz = 0;
  while (getline(&line, &sz, f) > 0) {
    kvpair_t * kvpair = getKVPair(line);
    addPairToArray(kvarray, kvpair);
    free(line);
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
    free(pairs->kvpairs[i]->key);
    free(pairs->kvpairs[i]->value);
    free(pairs->kvpairs[i]);
  }
  free(pairs->kvpairs);
  free(pairs);
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
