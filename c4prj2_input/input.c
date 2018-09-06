#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "future.h"
#include "input.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc) {
  deck_t * deck = malloc(sizeof(*deck));
  deck->cards = malloc(sizeof(*deck->cards));
  deck->n_cards = 0;
  int i = 0;
  char * chNewline = "\n";
  char chQuestion = '?';
  
  while(1) {
    if (*(str+i*3) == chQuestion) {
      size_t index;
      int n = atoi((str+i*3)+1);
      index = (size_t)n;
      card_t * ptr = add_empty_card(deck);
      add_future_card(fc, index, ptr);
    }
    else {
      //printf("value: %c suit: %c\n", *(str+i*3), *((str+i*3)+1));
      card_t c = card_from_letters(*(str+i*3), *((str+i*3)+1));
      add_card_to(deck, c);
    }
    //break if the card is the last in the hand
    if (strcmp((str+i*3)+2, chNewline)==0) {
      //printf("breaking while loop\n");
      break;
    }
    i++;
  }

  if (deck->n_cards < 5) {
    fprintf(stderr, "Hand contined less than 5 cards:\nLine: %s\n", str);
    return NULL;
  }
  
  return deck;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {
  deck_t ** deck_ts = malloc(sizeof(**deck_ts));
  
  char * line = NULL;
  size_t sz = 0;
  ssize_t nChars;
  int i = 0;
  while((nChars = getline(&line, &sz, f)) > 0) {
    if (nChars < 15) {
      fprintf(stderr, "Line did not have 5 cards\nLine: %s\n", line);
      return NULL;
    }
    (*n_hands)++;
    deck_ts = realloc(deck_ts, *n_hands * sizeof(**deck_ts));
    deck_t * deck = hand_from_string(line, fc);
    deck_ts[i] = deck;
    free(line);
    line = NULL;
    i++;
  }
  free(line);

  return deck_ts;
}
