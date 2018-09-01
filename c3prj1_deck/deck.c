#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  for (size_t i=0; i<hand->n_cards; i++) {
    print_card(*hand->cards[i]);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  for (int i=0; i<d->n_cards; i++) {
    if (c.value==d->cards[i]->value && c.suit==d->cards[i]->suit) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  for (int i=0; i<d->n_cards; i++) {
    int randomIndex = random() % d->n_cards;
    card_t * tmp = d->cards[i];
    d->cards[i] = d->cards[randomIndex];
    d->cards[randomIndex] = tmp;
  }
}

void assert_full_deck(deck_t * d) {
  assert(d->n_cards==52);
  for (unsigned i=0; i<52; i++) {
    assert(deck_contains(d, card_from_num(i))==1);
  }
}

void add_card_to(deck_t * deck, card_t c) {
  deck->n_cards++;
  deck->cards = realloc(deck->cards, deck->n_cards * sizeof(*deck->cards));
  card_t * newCard = malloc(sizeof(*newCard));
  *newCard = c;
  deck->cards[deck->n_cards-1] = newCard;
  deck->cards[deck->n_cards-1]->value = newCard->value;
  deck->cards[deck->n_cards-1]->suit = newCard->suit;
  free(newCard);
}

card_t * add_empty_card(deck_t * deck) {
  card_t c;
  c.value = 0;
  c.suit = 0;
  add_card_to(deck, c);
  return deck->cards[deck->n_cards-1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards) {
  deck_t * d = malloc(sizeof(*d));
  card_t c;
  for(unsigned i=0; i<52; i++) {
    c = card_from_num(i);
    if (deck_contains(excluded_cards, c)==0) {
      add_card_to(d, c);
    }
    else {
      continue;
    }
  }
  return d;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t * d1 = malloc(sizeof(*d1));
  deck_t * d2 = malloc(sizeof(*d2));
  for (size_t h=0; h<n_hands; h++) {
    for (size_t c=0; c<hands[h]->n_cards; c++) {
      add_card_to(d1, *hands[h]->cards[c]);
    }
  }
  
  d2 = make_deck_exclude(d1);
  
  return d2;
}

void free_deck(deck_t * deck) {
  free(deck->cards);
  free(deck);
}

