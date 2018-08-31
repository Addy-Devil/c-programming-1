#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"



int main(int argc, char ** argv) {
  deck_t * d = malloc(sizeof(*d));
  d->n_cards = 0;
  d->cards = malloc(sizeof(*d->cards));
  card_t c = card_from_num(0);
  add_card_to(d, c);

  print_hand(d);

  free_deck(d);
  
  exit(EXIT_SUCCESS);
}
