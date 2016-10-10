//======================
// Class Name: DynamicSequence
//
// Description: Implements the DynamicSequence class with Dynamic Array
//======================

#ifndef DYNAMIC_SEQUENCE_H
#define DYNAMIC_SEQUENCE_H

#include <cstdlib>
#include <fstream>
using namespace std;

namespace maveym_DynamicSequence
{
    class DynamicSequence
    {
        public:
            //======================
            typedef int value_type;
            // DynamicSequence will hold ints
            typedef size_t size_type;
            // DynamicSequence's size is measured with size_type
            static const size_type CAPACITY = 30;
            // Since it's dynamic, it can change size
            //======================
            //
            //======================
            DynamicSequence();
            // Summary: Default constructor for the DynamicSequence class
            // Postcondition: Creates an empty DynamicSequence
            //======================
            ~DynamicSequence();
            // Summary: DESTRUCTOR
            // Postcondition: Deletes data array of elements
            //======================
            //
            //======================
            bool resizeArray(size_type n);
            // Summary: Resize by n
            // Precondition: Pass through how many spaces to increase array by
            // Postcondition: Capacity will be increased by n

            //======================
            void start() {current_idx = 0;}
            // Summary: Begins the DynamicSequence
            // Postcondition: The first item in the DynamicSequence becomes the current item (but if the DynamicSequence is empty, then there's no current item)
            //======================
            //
            //======================
            void advance();
            // Summary: Traverse through DynamicSequence; one move forward
            // Precondition: is_item returns true.
            // Postcondition: If the current item was already the last item in the DynamicSequence, then there is no longer any current item. Otherwise, increment current_idx by one
            //======================
            //
            //======================
            void insert(const value_type& entry);
            // Summary: Inserts a value into DynamicSequence, BEFORE the current item
            // Precondition: size() < CAPACITY
            // Postcondition: A new copy of entry has been inserted into the DynamicSequence BEFORE the current item. If there's no current item, then entry has been inserted at the front. In either case, the new item is now the current item of the DynamicSequence.
            //======================
            //
            //======================
            void attach(const value_type& entry);
            // Summary: Attaches a value into the DynamicSequence, AFTER the current item
            // Precondition: size() < CAPACITY
            // Postcondition: A new copy of entry has been inserted into the DynamicSequence AFTER the current item. If there's no current item, then entry has been attached at the end of the DynamicSequence. In either case, the new item is now the current item of the DynamicSequence.
            //======================
            //
            //======================
            void remove_current();
            // Summary: Takes out the current item from the DynamicSequence
            // Precondition: is_item() returns true
            // Postcondition: Copy everything to the right of the current and shift to the right (which overwrites and thus removes current), then decrements used
            //======================
            //
            //======================
            size_type size() const {return used;}
            // Summary: Tells you how many items are in the array right now
            // Precondition: Call DynamicSequenceItem.size();
            // Postcondition: Returns used
            //======================
            //
            //======================
            bool is_item() const {return (current_idx < used);}
            // Summary: Tells you if the current item is valid or not
            // Precondition: Call DynamicSequenceItem.is_item();
            // Postcondition: A true return value indicates that there's a valid "current" item that may be retrieved by the current member function. A false return value indicates that there is no valid current item
            //======================
            //
            //======================
            value_type current() const;
            // Summary: Accessor for the current item
            // Precondition: is_item() returns true
            // Postcondition: Returns the current item in the DynamicSequence
            //======================
            //
            //======================
            void insertAtFront(const value_type& entry);
            // Summary: Adds a new item at the front of the DynamicSequence
            // Precondition: size() < CAPACITY
            // Postcondition: A new copy of entry has been inserted at the BEGINNING of the DynamicSequence. If there's no current item, then entry has been inserted at the front. In either case, the new item is now the current item of the DynamicSequence.
            //======================
            //
            //======================
            void removeFromFront();
            // Summary: Removes an item from the front of the DynamicSequence
            // Precondition: is_item returns true
            // Postcondition: Deletes the first item in the array by copying everything over (shift to the left once), decrement used
            //======================
            //
            //======================
            void insertAtEnd(const value_type& entry);
            // Summary: Adds an item to the end of the DynamicSequence
            // Precondition: size() < CAPACITY
            // Postcondition: Appends entry to the end of the array if there's still room.
            //======================
            //
            //======================
            void makeLastItemCurrent();
            // Summary: Makes the last item of the DynamicSequence become the current item
            // Precondition: is_item returns true
            // Postcondition: Sets current_idx to data
            //======================
            //
            //======================
            value_type operator [] (size_type index) const;
            // Summary: Access items like they were in an array
            // Postcondition: Index is a less than or equal to the DynamicSequence size
            // Precondition: Returns the specified item
            //======================
            friend ostream& operator << (ostream& out, const DynamicSequence& s);

            friend DynamicSequence operator + (DynamicSequence& x, DynamicSequence& y);
            // Summary: Combines two DynamicSequences
            // Precondition: DynamicSequence object on both sides of +
            // Postcondition: Returns a new DynamicSequence that lists all x, then all y

            DynamicSequence& operator = (const DynamicSequence& sLeft);

            void operator += (DynamicSequence& s);

            //======================
        private:
            size_type capacity; //total size of the array
            size_type used; //how many items in the array
            size_type current_idx; //convenient cursor within the Sequence
            value_type *data; //pointer that will point to an array
    };
}//END NAMESPACE maveym_DynamicSequence

#endif //DYNAMIC_SEQUENCE_H
