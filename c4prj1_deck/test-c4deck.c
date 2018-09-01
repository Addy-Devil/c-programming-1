#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"



int main(int argc, char ** argv) {
  deck_t * deck = malloc(sizeof(*deck));
  deck->n_cards = 0;
  deck->cards = malloc(sizeof(*deck->cards));
  card_t c;
  for (unsigned i=10; i<15; i++) {
    c = card_from_num(i);
    deck->n_cards++;
    deck->cards = realloc(deck->cards, deck->n_cards * sizeof(*deck->cards));
    card_t * newCard = malloc(sizeof(*newCard));
    *newCard = c;
    deck->cards[deck->n_cards-1] = newCard;
    deck->cards[deck->n_cards-1]->value = newCard->value;
    deck->cards[deck->n_cards-1]->suit = newCard->suit;
    free(newCard);
  }
  
  print_hand(deck);

  free_deck(deck);
  
  exit(EXIT_SUCCESS);
}
