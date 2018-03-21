//cards.h
//Authors: Denver Simmons
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <string>
using namespace std;

class hand
{

 public:
  struct card
  {
    char suit;
    char value;
    card *left;
    card *right;
    card(char s, char v);
    bool operator<(const card& source);
    bool operator>(const card& source);
    card* removeCard(char s, char v, card* parent);
    card* getMinCard();
  };
  card *root;

  hand();
  ~hand();
  void addCard(char s, char v);
  void addCardHelp(card* a, card* root);
  bool removeCard(char s, char v);
  void print();
  void printHelp(card* a);
  card* getFirstSame(hand & other, card* search);
  card* getLastSame(hand & other, card* search);
  card* find(char s, char v);
  card* findCardHelp(card* a, card* r);

};
#endif
