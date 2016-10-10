//======================
// DynamicSequence.cpp
//
// Summary: Includes implementation for DynamicSequence class (DynamicSequence.h)
//
// Author: Mavey Ma
// Created: September 14, 2016
// Summary of Modifications:
//      28 Sept 2016 -- Ch.4 Programming Project #2
//      Changed Sequence class to be called DynamicSequence
//======================
#include "DynamicSequence.h"
#include <cassert> //assert()
#include <algorithm> //copy()
#include <fstream>
#include <iostream>
namespace maveym_DynamicSequence
{
    const DynamicSequence::size_type DynamicSequence::CAPACITY;

    DynamicSequence::DynamicSequence()
    {
        capacity = CAPACITY;
        data = new value_type[capacity];
        used = 0;
    }//END DEFAULT CONSTRUCTOR

    DynamicSequence::~DynamicSequence()
    {
        delete[] data;
    }//END DESTRUCTOR

    void DynamicSequence::advance()
    {
        assert(is_item());
        current_idx++;
        return;
    }//END ADVANCE

    bool DynamicSequence::resizeArray(size_type n)
    {
        //create a new dynamic array (local variable)
        value_type *biggerData = new value_type[capacity + n];
        //copied data into biggerData
        copy(data, data+used, biggerData);
        //release memory from data
        delete[] data;
        data = biggerData;
        capacity += n;
        return true;
    }

    void DynamicSequence::insert(const value_type& entry)
    {
        if (size() >= capacity)
        {
            resizeArray(1);
        }
        if (current_idx < size())
        {
            copy(data + current_idx, data + used, data + current_idx + 1);
            data[current_idx] = entry;
        }
        else //if sequence is empty, no need to shift
        {
            data[used] = entry;
        }
        used++;
        return;
    }//END INSERT

    void DynamicSequence::attach(const value_type& entry)
    {
        if (size() >= capacity)
        {
            resizeArray(1);
        }
        if (current_idx < size())
        {
            copy(data + current_idx + 1, data + used, data + current_idx + 2);
            data[current_idx + 1] = entry;
            advance();
        }
        else
        {
            data[used] = entry;
        }
        used++;
        return;
    }//END ATTACH

    void DynamicSequence::remove_current()
    {
        assert(is_item());
        //shift everything to the left by one //copy
        copy(data + current_idx + 1, data + used, data + current_idx);
        used--;
        return;
    }//END REMOVE CURRENT

    DynamicSequence::value_type DynamicSequence::current() const
    {
        assert(is_item());
        return data[current_idx];
    }//END GET CURRENT

    void DynamicSequence::insertAtFront(const value_type& entry)
    {
        current_idx = 0;
        insert(entry);
        return;
    }//END INSERT AT FRONT

    void DynamicSequence::removeFromFront()
    {
        current_idx = 0;
        remove_current();
        return;
    }//END REMOVE FROM FRONT

    void DynamicSequence::insertAtEnd(const value_type& entry)
    {
        makeLastItemCurrent();
        attach(entry);
        return;
    }//END INSERT AT END

    void DynamicSequence::makeLastItemCurrent()
    {
        assert(is_item());
        current_idx = used;
        return;
    }//END MAKE LAST ITEM CURRENT

    ostream& operator << (ostream& out, const DynamicSequence& s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            out << s.data[i] << " ";
        }
        out << endl;
        return out;
    }//END <<

    DynamicSequence operator + (DynamicSequence& x, DynamicSequence& y)
    {
        DynamicSequence combined;
        combined.start();
        x.makeLastItemCurrent();
        y.current_idx = 0;
        combined += x;
        combined += y;
        return combined;
    }//END +

    void DynamicSequence::operator += (DynamicSequence& s)
    {
        resizeArray(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            attach(s.data[i]);
            //cout << i << endl;
        }
        return;
    }//END +=

    DynamicSequence::value_type DynamicSequence::operator [] (size_type index) const
    {
        assert(index <= size());
        return data[index];
    }

    DynamicSequence& DynamicSequence::operator = (const DynamicSequence& sLeft)
    {
        if (this != &sLeft)
            *data = *(sLeft.data);
        capacity = sLeft.capacity;
        used = sLeft.used;
        current_idx = sLeft.current_idx;
        return *this;
    }
}//END NAMESPACE
