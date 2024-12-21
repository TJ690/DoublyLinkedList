#include <iostream>
#include <string>
#include "DoublyLinkedList.h"

//Used with the help of W3 Schools and GeeksforGeeks.org
using namespace std;

template <class T>
void display(DoublyLinkedList<T> & l1) {
    T curr;
    if (l1.getFirst(curr) == false) { cout << "empty list" << endl; return; }
    cout << curr << "->";
    while (l1.getNext(curr))
        cout << curr << "->";
    cout << endl;
}

template <class T>
void displayReverse(DoublyLinkedList<T> & l1) {
    T curr;
    if (l1.getLast(curr) == false) { cout << "empty list" << endl; return; }
    cout << curr << "->";
    while (l1.getPrev(curr))
        cout << curr << "->";
    cout << endl;
}

void fn1(DoublyLinkedList<string> l1) {
    string item = "s3";
    l1.remove(item);
    display(l1);
    displayReverse(l1);
}

int main()
{
    DoublyLinkedList<string> list1;
    // check insert works
    list1.insert("s1");
    list1.insert("s2");
    list1.insert("s3");
    display(list1);
    displayReverse(list1);


    string item;
    list1.getFirst(item);
    cout << item << endl;
    // check replace
    list1.replace("s3");
    display(list1);
    displayReverse(list1);
    //Checking the getLast Function
    //Checking getPrev Function
    list1.insert("s4");
    list1.insert("s5");
    display(list1);
    displayReverse(list1);

    //Checking getLast Function
    list1.getLast(item);
    cout << item << endl;

    list1.getPrev(item);
    cout << item <<endl;

    // check remove
    item = "s1";
    list1.remove(item);
    display(list1);
    displayReverse(list1);

    list1.getLast(item);
    cout << item << endl;

    // check =, makeEmpty
    DoublyLinkedList<string> list2 = list1;
    display(list2);
    displayReverse(list2);

    list2.makeEmpty();
    display(list1);
    displayReverse(list1);
    display(list2);
    displayReverse(list2);
/*
    // check copy constructor
    fn1(list1);
    display(list1);
    displayReverse(list1);
*/
    return 0;
}
