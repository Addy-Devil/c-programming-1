#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: test-input fileName\n");
    exit(EXIT_FAILURE);
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("fopen");
    fprintf(stderr, "Could not open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  size_t n_hands = 0;
  future_cards_t fc;
  fc.decks = malloc(sizeof(*fc.decks));
  fc.n_decks = 0;
  
  deck_t ** deck_ts = read_input(f, &n_hands, &fc);

  printf("n_hands: %zu\n", n_hands);
  
  for (int i=0; i<n_hands; i++) {
    print_hand(deck_ts[i]);
  }

  for (int i=0; i<n_hands; i++) {
    free_deck(deck_ts[i]);
  }

  free(deck_ts);

  for (int i=0; i<fc.n_decks; i++) {
    free_deck(&fc.decks[i]);
  }

  exit(EXIT_SUCCESS);
}
