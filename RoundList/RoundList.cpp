#include "RoundList.h"
#include <iostream>
using namespace std;
RoundList::RoundList() :
    List(), last(nullptr)
{}
void RoundList::add(int val)
{
    // add an element to the front of a double
        // ended List only need to handle addition to
        // empty List
    if (isEmpty()) 
    {
        List::add(val);
        head->next = head;
        last = head;
    }
    else 
    {
        RoundList::Link* newLink = new Link(val, head);
        //If there's only one element
        if (head == last)
        {
            last = head;
        }
        last->next = newLink;
        head = newLink;
    }
}
/**
*@author Lecturer at Machon Lev
**/
void RoundList::clear()
{
    // delete all values from collection
    List::clear();
    // then set the pointer to the last element to zero
    last = nullptr;
}


void RoundList::remove(int key)
{
   try { 
       bool found = false;
       //Impossible to find, since head is null...
       if (head == NULL||(head==last)&&(last->value!=key)) 
       {
           throw "value not found\n";
       }
        //If there's only one element in the list, with the value same as key
        if ((head == last) && (last->value == key))
        {
            removeFirst();
            return;
        }
        RoundList::Link* beforeDeleted = NULL;
        RoundList::Link* toDelete = head;
        //While value is different, and haven't reached head from other side
        while ((toDelete->value != key) && (toDelete->next != head))
        {
            beforeDeleted = toDelete;
            toDelete = toDelete->next;
            if (toDelete->value == key)
            {
                found = true;
            }
        }

        //If node to delete is the last one, then make last the element preceding it
        if (found == true) 
        {
            if (toDelete == last)
            {
                last = beforeDeleted;
            }
            beforeDeleted->next = toDelete->next;
        }

        else
        {
        throw "value not found\n";
        }
}
    catch (const char* errorMessage)
    {
        cout << errorMessage;
    }
}
void RoundList::removeFirst() {
    // remove the first element
    List::removeFirst();
    // if we remove last element
    if (isEmpty())
        last = nullptr;

}

int RoundList::search(const int& countSteps) const
{
    int count=0;//Counts number of steps in iteration
    // loop to test each element
    Link* p = head;
    while((p!=nullptr)&&(count<=countSteps))
    {
        if (count == countSteps)
        {
            return p->value;
        }
        count = count + 1;
        p = p->next;
    }
    // not found
    return -1;  
}
/**
*@author Lecturer at Machon Lev
**/
void RoundList::addToEnd(int val)
{
    // add a new element to end of a double ended List
    if (last != nullptr)
    {
        last->next = new Link(val, nullptr);
        last = last->next;
    }
    // otherwise, just add to front
    else
        add(val);
}

void RoundList::insert(int key)
{
    if (head == NULL)
    {
        add(key);
        return;
    }
    //If there's only one element in list
    if (head == last)
    {
        //Insertion at the beginning since value is small
        if (head->value > key)
        {
            Link* newLink = new Link(key, head);
            head->next = newLink;
            last = head;//Old head will become the last element
            head = newLink;
            return;
        }
        else 
        {//Insertion at end
            Link* newLink = new Link(key, head);
            last = newLink;
            head->next =newLink;
        }
    }
    else if (key < head->value)
    {
        add(key);
    }
    else 
    {
        Link* linkPtr = head;
        Link* afterLink =head;
        while ((linkPtr->next != head) && (linkPtr->value < key) && (linkPtr->next->value < key))
        {
            linkPtr = linkPtr->next;
            afterLink = linkPtr->next;
        }
        Link* newLink = new Link(key, afterLink);
        if (!newLink)
        {
            cerr << "A memory allocation error has occured" << endl;
        }
        linkPtr->next = newLink;
        //If the new element is immediately preceding head, it must be the last element
        if (afterLink == head)
        {
            last = newLink;
        }
    }

}

RoundList::RoundList(const RoundList& other)
{
    Link* src, * trg;
    if (other.head == NULL)
    {
        head = NULL;
        last = NULL;
    }
    else
    {
        head = new Link((other.head)->value, other.head->next);
        src = other.head;
        trg = head;
        while (src->next->next != other.head)
        {
            trg->next = new Link((src->next)->value, src->next->next);
            src = src->next;
            trg = trg->next;
        }
        last = other.last;
        last->next = head;
    }
}

RoundList& RoundList::operator=(const RoundList& other)
{
    Link* src, * trg;
    if (other.head == NULL)
    {
        head = NULL;
        last = NULL;
    }
    else
    {
        head = new Link((other.head)->value,other.head->next);
        src = other.head;
        trg = head;
        while (src->next->next!=other.head)
        {
            trg->next = new Link((src->next)->value,src->next->next);
            src = src->next;
            trg = trg->next;
        }
        last = other.last;
        last->next = head;
    }
    return *this;
}



ostream& operator<<(ostream& c_out, RoundList& list)
{

        for (List::Link* linkPtr = list.head;linkPtr!=list.last; linkPtr = linkPtr->next)
        {
            c_out << linkPtr->value << endl;
        }
    c_out << list.last->value << endl;
    return c_out;
}

istream& operator>>(istream& c_in, RoundList& list)
{
    int number = -1;
    int prevNumber = -2;

    while (prevNumber <= number)
    {
        prevNumber = number;
        c_in >> number;
        if (prevNumber <= number)
        {
            list.insert(number);
        }
        else
        {
            return c_in;
        }
    }
    return c_in;
}


