#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "future.h"

int main(int argc, char ** argv) {
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->n_decks = 0;
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = malloc(sizeof(*deck->cards));
  deck->n_cards = 0;
  
  card_t * ptr = add_empty_card(deck);

  add_future_card(fc, 2, ptr);

  for (int i=0; i<fc->n_decks; i++) {
    print_hand(&fc->decks[i]);
  }

  free_deck(deck);

  /*
  for (int i=0; i<fc->n_decks; i++) {
    free(fc->decks[i].cards);
    free(fc->decks[i]);
  }
  */
  
  exit(EXIT_SUCCESS);
}
