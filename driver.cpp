//======================
// driver.cpp
//
// Summary: Driver file for DynamicDynamicSequence class
//
// Author: Mavey Ma
// Created: September 14, 2016
// Summary of Modifications:
//      28 Sept 2016 -- Ch.4 Programming Project #2
//      Changed Sequence class to be called DynamicSequence
//======================

#include <iostream>
#include <cstdlib>
#include "DynamicSequence.h"
using namespace std;
using namespace maveym_DynamicSequence;

int main()
{
    DynamicSequence s1;
    DynamicSequence s2;
    DynamicSequence s3;
    DynamicSequence s4;
    DynamicSequence s5;

    s1.start();
    s2.start();
    s3.start();
    s4.start();
    s5.start();

    s1.insert(5);
    s1.insert(6);
    s1.insert(7);

    s1.attach(1);
    s1.attach(2);
    s1.attach(3);

    //(1) A function to add a new item at the front of the DynamicSequence
    s1.insertAtFront(999);
    cout << s1;
    //(2) A function to remove an item from the front of the DynamicSequence
    s1.removeFromFront();
    cout << s1;
    //(3) A function to add a new item to the end of the DynamicSequence
    s1.insertAtEnd(-777);
    cout << s1;
    //(4) A function that makes the last item of the DynamicSequence become the current item
    s1.makeLastItemCurrent();
    s1.attach(-1);
    s1.attach(-2);
    s1.attach(-3);
    cout << s1;
    //(5a) Overloaded operators + which makes it so that x + y = new DynamicSequence that lists all x, then all y
    s2.attach(11);
    s2.attach(22);
    s2.attach(33);
    s3 = s1 + s2;
    cout << s3;

    /*


    //(5b) Overloaded operators += which makes it so that x += y appends all y to all x
    s4.insert(0);
    s4.insert(808);
    s3 += s4;
    cout << s3;

    s5.insert(s1[0]);
    s5.insert(s3[6]);
    s5.insert(s3[s3.size()]);
    cout << s5;

    */
    return EXIT_SUCCESS;
}
