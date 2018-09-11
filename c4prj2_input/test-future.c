#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "future.h"

int main(int argc, char ** argv) {
  future_cards_t fc;
  fc.decks = malloc(sizeof(fc.decks));
  fc.n_decks = 0;
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = NULL;//malloc(sizeof(*deck->cards));
  deck->n_cards = 0;
  
  card_t * ptr = add_empty_card(deck);

  size_t index = 0;
  add_future_card(&fc, index, ptr);

  for (int i=0; i<fc.n_decks; i++) {
    print_hand(&fc.decks[i]);
  }

  free_deck(deck);
  
  for (int i=0; i<fc.n_decks; i++) {
    free_deck(&fc.decks[i]);
  }

  free(fc.decks);
  
  exit(EXIT_SUCCESS);
}
