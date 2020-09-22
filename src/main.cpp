#include <iostream>
#include "bag.h"
#include "sorted_bag.h"

using namespace std;

int main() {

  // /* BAG 1 */
  // cout << "BAG 1" << endl;
  // unique_ptr<SortedBag<int>> b1 = make_unique<SortedBag<int>>();
  // *b1 + 71;                 // operator+
  // *b1 << 81 << 9 << 10;     // operator<< insert item
  // cout << *b1 << endl;      // operator<< print object
  // --*b1;                    // operator--
  // cout << *b1 << endl;
  // b1->remove();             // remove
  // cout << *b1 << endl << endl;

  // /* BAG 2 */
  // cout << "BAG 2" << endl;
  // unique_ptr<SortedBag<int>> b2 = make_unique<SortedBag<int>>(2);
  // *b2 << 15 << 10 << 5;
  // (*b2).add(1000);   // add
  // cout << *b2 << endl << endl;

  // /* BAG 3 */
  // cout << "BAG 3 (copy of bag 1)" << endl;
  // unique_ptr<SortedBag<int>> b3 = make_unique<SortedBag<int>>(*b1);
  // cout << *b3 << endl;
  // cout << "First element: " << (*b3)[0] << endl;
  // (*b3)[0] = 13;
  // cout << "First element after change: " << (*b3)[0] << endl;





/* ---Use this code to enter bag elements manually--- */

  unique_ptr<SortedBag<int>> emptyBag = make_unique<SortedBag<int>>();

  unique_ptr<SortedBag<int>> b1 = make_unique<SortedBag<int>>();
  int input = 0;
  cout << "enter numbers to add to the bag. -100 to quite. -10 to clear bag. -1 to remove last element." << endl;
  while (input > -100) {
    cout << "> ";
    cin >> input;
    if (input >= 0) { *b1 << input; }
    else if (input == -10) { *b1 = *emptyBag; }
    else { --(*b1); }
    cout << *b1 << endl;
  }


  return 0;
}