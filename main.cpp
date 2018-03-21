#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
using namespace std;

int main(int argv, char** argc)
{
  hand Alice, Bob;

  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

 //Read each file
  while (getline (cardFile1, line) && (line.length() > 0))
    {
      Alice.addCard(line[0],line[2]);
    }
  cardFile1.close();
  while (getline (cardFile2, line) && (line.length() > 0))
    {
          Bob.addCard(line[0],line[2]);
    }
  cardFile2.close();
  while(true)
    {
      hand::card* aMatch = Alice.getFirstSame(Bob, Alice.root);
      if(aMatch == nullptr)
        {
          break;
        }
      cout << "Alice picked matching card " << aMatch->suit << " ";
     if(aMatch->value == '1')
        cout << "10"<<endl;
      else
        {
         cout << aMatch->value << endl;
        }
      Bob.removeCard(aMatch->suit, aMatch->value);
      Alice.removeCard(aMatch->suit, aMatch->value);
      aMatch = Bob.getLastSame(Alice, Bob.root);
      if(aMatch == nullptr)
        {
          break;
        }
      cout << "Bob picked matching card " << aMatch->suit << " ";
        if(aMatch->value == '1')
        cout << "10"<<endl;
      else
        {
         cout << aMatch->value << endl;
        }
          Alice.removeCard(aMatch->suit, aMatch->value);
          Bob.removeCard(aMatch->suit, aMatch->value);
    }
  cout << endl;
  cout <<"Alice's cards:" << endl;
  Alice.print();
  cout << endl;
  cout << "Bob's cards:" << endl;
  Bob.print();
  return 0;
}
