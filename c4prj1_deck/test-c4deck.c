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
  for (unsigned i=10; i<15; i++) {
    card_t c = card_from_num(i);
    print_card(c);
    printf("\n");
    deck->n_cards++;
    deck->cards = realloc(deck->cards, deck->n_cards * sizeof(*deck->cards));
    
    deck->cards[deck->n_cards-1] = malloc(sizeof(*deck->cards[deck->n_cards-1]));
    *deck->cards[deck->n_cards-1] = c;
    deck->cards[deck->n_cards-1]->value = c.value;
    deck->cards[deck->n_cards-1]->suit = c.suit;
  }
  
  print_hand(deck);

  free_deck(deck);
  
  exit(EXIT_SUCCESS);
}
