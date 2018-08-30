#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * c = malloc(sizeof(*c));
  c->one_count_array = malloc(sizeof(c->one_count_array));
  c->len_array = 0;
  c->len_unknowns = 0;
  return c;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if (name == NULL) {
    c->len_unknowns++;
  }
  else {
    int in_array = 0;
    int i;
    for (i=0; i<c->len_array; i++) {
      if (strcmp(name, c->one_count_array[i]->some_string)==0) {
	in_array = 1;
	break;
      }
    }
    if (in_array==1) {
      c->one_count_array[i]->n_encounters++;
    }
    else {
      c->len_array++;
      c->one_count_array = realloc(c->one_count_array, c->len_array * sizeof(*c->one_count_array));
      c->one_count_array[c->len_array-1] = malloc(sizeof(one_count_t));
      c->one_count_array[c->len_array-1]->some_string = name;
      c->one_count_array[c->len_array-1]->n_encounters = 1;
    }
  }
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for (int i=0; i<c->len_array; i++) {
    fprintf(outFile, "%s: %d\n", c->one_count_array[i]->some_string, c->one_count_array[i]->n_encounters);
  }
  if (c->len_unknowns > 0) {
    fprintf(outFile, "<unknown> : %d\n", c->len_unknowns);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i=0; i<c->len_array; i++) {
    free(c->one_count_array[i]);
  }
  free(c->one_count_array);
  free(c);
}
