/*
	list1.cpp - using the standard library list class template.
	
	list sequence container (<list>) 
	    - allows insertion and deletion at any location in the container. 
	    - implemented as a doubly linked list. Every node in the list contains a pointer to the previous node 
	      and to the next node. 
	    - This implementation enables list to support bidirectional iterators that allow the container to be  
	      traversed both forward and backward directions. 
*/

#include <iostream>
#include <vector>
#include <list> 
#include <algorithm>
#include <iterator> 

using namespace std;

// prototype for function template printList
template <typename T> 
void dispList(const list<T>& listRef);

// a predicate to determine if an element is lessan 20. 
// predicate - a unary function that returns true or false.
bool validNum(double v) { return (v < 2); }


int main() {
	// list of doubles
	list<double> L1, L2;
	vector<double> V{5, 4e3, -33, 870};

	system("clear");
	
	// insert 6 numbers with alternating insertions at the front and back
	cout << "Front and Back insertions to L1: ";
	int k{1};
	do {
		L1.push_back(k - 35);
		L1.push_front(k * 2.5);
	} while (k++ <= 3);
	dispList(L1);
	
	// sort L1 and display
	cout << "L1 Sorted: ";
	L1.sort();
	dispList(L1);

	// insert V to L2 and display
	L2.insert(L2.cbegin(), V.cbegin(), V.cend());
	cout << "\nL2: ";
	dispList(L2);

	// remove L2 elements and insert at the end of L1
	L1.splice(L1.cend(), L2);
	cout << "L1 spliced using L2: ";
	dispList(L1);
	cout << "L2: ";
	dispList(L2);
	
	// sort L1 and display
	cout << "L1 Sorted: ";
	L1.sort();
	dispList(L1);

	// merge L2 to L1. Result is sorted.
	L1.merge(L2);
	cout << "\nL1 = L1 and L2 merged: ";
	dispList(L1);
	cout << "L2: ";
	dispList(L2);

	// remove front and back elements
	L1.pop_front(); 
	L1.pop_back(); 
	cout << "\nFront and back elements removed from L1: ";
	dispList(L1);
	cout << "Duplicate elements of L1 removed: ";
	L1.unique();
	dispList(L1);
	
	// swap L1 and L2
	L2.insert(L2.cbegin(), V.cbegin(), V.cend());
	cout << "\nL2: ";
	dispList(L2);
	L1.swap(L2); 
	cout << "L1 and L2 swapped: \n";
	cout << "L1: ";
	dispList(L1);
	cout << "L2: ";
	dispList(L2);

	// replace L1 with L2
	L1.assign(L2.cbegin(), L2.cend());
	cout << "\nL1 replaced with L2: ";
	dispList(L1);
	
	L1.emplace(L1.cbegin()++, 7.5);
	cout << "L1: ";
	dispList(L1);
	
	L1.remove_if(validNum);
	cout << "L1: all elements < 2 removed: ";
	dispList(L1);
	L1.remove(7.5);
	cout << "L1: all 7.5s removed: ";
	dispList(L1);
}


// displays a list using an ostream_iterator and the copy algorithm.
template <typename T> 
void dispList(const list<T>& p) {
	if (p.empty()) { 
		cout << "List is empty";
	} else {
		ostream_iterator<T> cWrite{cout, " "};
		copy(p.cbegin(), p.cend(), cWrite);  // copy list to cout
	}
	cout << endl;
}





