#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "future.h"

void malloc_new_decks(future_cards_t * fc, size_t index) {
  fc->decks = realloc(fc->decks, (index+1) * sizeof(*fc->decks));
  for(int i=fc->n_decks; i<=index; i++) {
    deck_t * deck = malloc(sizeof(*deck));
    deck->cards = malloc(sizeof(*deck->cards));
    deck->n_cards = 0;
    fc->decks[i] = deck;
  }
  fc->n_decks = index+1;
}

void add_pointer(future_cards_t * fc, size_t index, card_t * ptr) {
  if (fc->deck[index]->n_cards == 0) {
    fc->deck[index]->n_cards++;
    fc->deck[index]->cards[0] = ptr;
  }
  else {
    fc->deck[index]->n_cards++;
    fc->deck[index]->cards = realloc(fc->deck[index]->n_cards * sizeof(*fc->deck[index]->cards));
    fc->deck[index]->cards[fc->deck[index]->n_cards-1] = ptr;
  }
}

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr) {
  if (fc->n_decks==0 || index>fc->n_decks-1) {
    malloc_new_decks(fc, index);
  }

  add_pointer(fc, index, ptr);
}

