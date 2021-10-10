#include "List.h"
#include<iostream>
using namespace std;
List::List()
{
    head = NULL;
    // no further initialization
}
List::List(const List& l)
{
    Link* src, * trg;
    if (l.head == NULL)
        head = NULL;
    else
    {
        head = new Link((l.head)->value, NULL);
        src = l.head;
        trg = head;
        while (src->next != NULL)
        {
            trg->next = new Link
            ((src->next)->value, NULL);
            src = src->next;
            trg = trg->next;
        }
    }
}
List::~List()
{
    clear();
}
List& List::operator=(const List& other)
{
    Link* src, * trg;
    if (other.head == NULL)
        head = NULL;
    else
    {
        head = new Link((other.head)->value, NULL);
        src = other.head;
        trg = head;
        /*Create links with same values as other*/
        while (src->next != NULL)
        {
            trg->next = new Link((src->next)->value, NULL);
            src = src->next;
            trg = trg->next;
        }
    }
    return *this;
}
void List::clear()
{
    // empty all elements from the List
    Link* next;
    for (Link* p = head; p != NULL; p = next)
    {
        // delete the element pointed to by p
        next = p->next;
        p->next = NULL;
        delete p;
    }
    // mark that the List contains no elements
    head = NULL;
}
void List::add(int val)
{
    //Add a new value to the front of a Linked List
    head = new Link(val, head);
    if (head == nullptr)
        throw "failed in memory allocation";
}
void List::insert(int key)
{
    if (head == NULL)
    {
        add(key);
        return;
    }
    if (head->value > key)
    {
        head = new Link(key, head);
        return;
    }
    Link* linkPtr = head;
    Link* afterLink = NULL;
    while ((linkPtr->next != NULL) && (linkPtr->value < key) && (linkPtr->next->value < key))
    {
        linkPtr = linkPtr->next;
        if (linkPtr != NULL)
        {
            afterLink = linkPtr->next;
        }
    }
    Link* newLink = new Link(key, afterLink);
    if (!newLink)
    {
        cerr << "A memory allocation error has occured" << endl;
    }
    linkPtr->next = newLink;
}
void List::remove(int key)
{
    bool found = search(key);
    if (found == false)
    {
        throw "value not found\n";
    }
    List::Link* beforeDeleted = NULL;
    List::Link* toDelete = head;
    while (toDelete->value != key)
    {
        beforeDeleted = toDelete;
        toDelete = toDelete->next;
    }
    //If we are to delete head
    if (beforeDeleted == NULL)
    {
        removeFirst();
        return;
    }
    beforeDeleted->next = toDelete->next;
}
int List::firstElement() const
{
    // return first value in List
    if (isEmpty())
    {
        throw "the List is empty, no first Element";
    }
    return head->value;
}
bool List::search(const int& val) const
{
    // loop to test each element
    for (Link* p = head; p != nullptr; p = p->next)
        if (val == p->value)
            return true;
    // not found
    return false;
}
bool List::isEmpty() const
{
    return head == nullptr;
}
void List::removeFirst()
{
    // make sure there is a first element
    try {
        if (isEmpty())
            throw 1;
    }
    catch (int g)
    {
        cout << "the List is empty, no Elements to remove" << endl;
    }
    // save pointer to the removed node
    Link* p = head;
    // reassign the first nodej
    head = p->next;
    p->next = nullptr;
    // recover memory used by the first element
    delete p;
}



List::Link::Link(int linkValue, Link* nextPtr)
{
    value = linkValue;
    next = nextPtr;
}

List::Link::Link(const Link& a)
{
    value = a.value;
    next = a.next;

}

ostream& operator<<(ostream& c_out, List& list)
{
    for (List::Link* linkPtr = list.head; linkPtr != NULL; linkPtr = linkPtr->next)
    {
        c_out << linkPtr->value << endl;
    }
    return c_out;
}

istream& operator>>(istream& c_in, List& list)
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