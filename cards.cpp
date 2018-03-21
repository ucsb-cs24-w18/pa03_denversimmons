//cards.cpp

//Authors: Denver Simmons

//Implementation of the classes defined in cards.h

#include "cards.h"
#include <string>
#include <iostream>

using namespace std;

hand::hand()
{
  root = nullptr;
}

hand::~hand()
{
  while(root != nullptr)
  {
      removeCard(root->suit, root->value);
  }
}

  hand::card::card(char s, char v)
{
  suit = s;
  value = v;
  right = nullptr;
  left = nullptr;
}


hand::card* hand::getFirstSame(hand & other, card* search)
{
  if(search ==  nullptr)
    {
      return nullptr;
    }
  card* match = getFirstSame(other, search->left);
  if(match!=nullptr)
    {
      return match;
    }
  match = other.find(search->suit,search->value);
  if(match!= nullptr)
    {
      return search;
    }
  return getFirstSame(other, search->right);
}


hand::card* hand::getLastSame(hand & other, card* search)
{
  if(search ==  nullptr)
    {
      return nullptr;
    }
  card* match = getLastSame(other, search->right);
  if(match!=nullptr)
    {
      return match;
    }
  match = other.find(search->suit,search->value);
  if(match!= nullptr)
    {
      return search;
    }
  return getLastSame(other, search->left);
}


bool hand::card::operator<(const card& source)
{
  int snum, tnum;

  switch(source.suit)
    {
    case 'c' :
      snum = 1;
      break;
    case 'd':
      snum = 2;
      break;
    case 's' :
      snum = 3;
      break;
    case 'h':
        snum = 4;
      break;
    }

    switch(this->suit)
    {
    case 'c' :
      tnum = 1;
      break;
    case 'd':
      tnum = 2;
      break;
    case 's' :
      tnum = 3;
      break;
    case 'h':
      tnum = 4;
      break;
    }

    if(tnum == snum)
      {
        switch(source.value)
          {
          case '2':
            snum = 2;
            break;
          case '3':
            snum = 3;
            break;
          case '4':
            snum = 4;
            break;
          case '5':
            snum = 5;
            break;
          case '6':
            snum = 6;
            break;
          case '7':
            snum = 7;
            break;
          case '8':
            snum = 8;
            break;
          case '9':
            snum = 9;
            break;
          case '1':
             snum = 10;
             break;
           case 'j':
             snum = 11;
             break;
          case 'q':
             snum = 12;
             break;
           case 'k':
             snum = 13;
             break;
          case 'a':
            snum = 1;
            break;
          }

         switch(this->value)
           {
           case '2':
             tnum = 2;
             break;
           case '3':
             tnum = 3;
             break;
           case '4':
             tnum = 4;
             break;
           case '5':
             tnum = 5;
             break;
           case '6':
             tnum = 6;
             break;
           case '7':
             tnum = 7;
             break;
           case '8':
            tnum = 8;
            break;
          case '9':
            tnum = 9;
            break;
          case '1':
             tnum = 10;
             break;
           case 'j':
             tnum = 11;
             break;
           case 'q':
             tnum = 12;
             break;
           case 'k':
             tnum = 13;
             break;
           case 'a':
             tnum = 1;
             break;
         }

         if(tnum==snum)
           {
             return false;
           }
         else
           {
             return tnum<snum;
           }

       }

     else
       {
        return tnum<snum;
       }
 }

 bool hand::card::operator>(const card& source)
 {
   int snum, tnum;

  switch(source.suit)
     {
     case 'c' :
       snum = 1;
       break;
     case 'd':
       snum = 2;
       break;
     case 's' :
       snum = 3;
       break;
     case 'h':
         snum = 4;
       break;
     }

     switch(this->suit)
     {
     case 'c' :
       tnum = 1;
       break;
     case 'd':
       tnum = 2;
       break;
     case 's' :
       tnum = 3;
       break;
     case 'h':
       tnum = 4;
       break;
     }

    if(tnum == snum)
      {
        switch(source.value)
          {
          case '2':
            snum = 2;
            break;
          case '3':
            snum = 3;
            break;
          case '4':
            snum = 4;
            break;
          case '5':
            snum = 5;
            break;
          case '6':
            snum = 6;
            break;
          case '7':
            snum = 7;
            break;
          case '8':
            snum = 8;
            break;
          case '9':
            snum = 9;
            break;
          case '1':
             snum = 10;
             break;
           case 'j':
             snum = 11;
             break;
         case 'q':
             snum = 12;
             break;
           case 'k':
             snum = 13;
             break;
          case 'a':
            snum = 1;
            break;
          }

         switch(this->value)
           {
           case '2':
             tnum = 2;
             break;
           case '3':
             tnum = 3;
             break;
           case '4':
             tnum = 4;
             break;
           case '5':
             tnum = 5;
             break;
           case '6':
             tnum = 6;
             break;
           case '7':
             tnum = 7;
             break;
           case '8':
            tnum = 8;
            break;
          case '9':
            tnum = 9;
            break;
          case '1':
             tnum = 10;
             break;
           case 'j':
             tnum = 11;
             break;
           case 'q':
            tnum = 12;
             break;
           case 'k':
             tnum = 13;
             break;
           case 'a':
             tnum = 1;
             break;
         }

         if(tnum==snum)
           {
             return false;
           }
         else
           {
             return tnum>snum;
           }

       }
             else
       {
        return tnum>snum;
       }

 }


void hand::addCard(char s, char v)
{
  card* a = new card(s,v);
  if(root==nullptr)
    {
      root = a;
      return;
    }
  addCardHelp(a, root);
}

void hand::addCardHelp(card* a, card* node)
{
  if(*a < *node)
    {
      if(node->left==nullptr)
        {
          node->left = a;
        }
      else
        {
          addCardHelp(a, node->left);
        }
    }
  if(*a > *node)
    {
      if(node->right==nullptr)
        {
          node->right = a;
        }
      else
        {
          addCardHelp(a, node->right);
        }
    }
}

bool hand::removeCard(char s, char v)
{
  if(root == nullptr)
    {
      return false;
    }

  card* pRemoval = nullptr;
  if(root->suit == s && root->value == v)
    {
      card temp('z','z');
      temp.left = root;
      pRemoval = root->removeCard(s,v, &temp);
      root = temp.left;
    }
  else
    {
      pRemoval = root->removeCard(s, v, nullptr);
    }
  if(pRemoval != nullptr)
    {
      delete pRemoval;
      return true;
    }
  return false;
}

hand::card* hand::card::removeCard(char s, char v, card* parent)
{
  card c(s,v);
  if(c > *this)
    {
      if(right==nullptr)
        {
            return nullptr;
        }
      return right->removeCard(s,v,this);
    }
  if(c < *this)
    {
      if(left==nullptr)
        {
          return nullptr;
        }
      return left->removeCard(s,v,this);
    }

      if(left!=nullptr && right!=nullptr)
        {
          card* pMin = right->getMinCard();
          suit = pMin->suit;
          value = pMin->value;
          return right->removeCard(suit,value, this);
        }
      if(parent->left==this)
        {
          if(left!=nullptr)
            {
              parent->left = left;
            }
          else
            {
              parent->left = right;
            }
        }
      else
        {
          if(left!=nullptr)
            {
              parent->right = left;
            }
          else
            {
              parent->right = right;
            }
        }
      return this;
}

hand::card* hand::card::getMinCard()
{
  if(left == nullptr)
    {
      return this;
    }
  return left->getMinCard();
}

void hand::print()
{
  printHelp(root);
}

void hand::printHelp(card* a)
{
  if(a==nullptr)
    {
      return;
    }
  if(a->left!=nullptr)
    {
      printHelp(a->left);
    }
  if(a->value=='1')
    {
         cout << a->suit << " " << "10";
    }
  else
  {
       cout << a->suit << " " << a->value;
  }
  cout << endl;
  if(a->right!=nullptr)
    {
      printHelp(a->right);
    }
}
hand::card* hand::find(char s, char v)
{
  card a(s,v);
  return findCardHelp(&a, root);
}
hand::card* hand::findCardHelp(card* a, card* r)
{
  if(*a<*r)
    {
      if(r->left==nullptr)
        {
          return nullptr;
        }
      return findCardHelp(a,r->left);
    }


  if(*a>*r)
    {
      if(r->right==nullptr)
        {
          return nullptr;
        }
      return findCardHelp(a,r->right);
    }
  return r;
}



