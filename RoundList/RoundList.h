#include "List.h" 
/**
 * @brief Class to represent a list with a sentinel (named last) at its end.
*/
class RoundList : public List
{
public:
    /*constructors*/
    RoundList();
    RoundList(const RoundList& l);
    /**
     * @brief Adds value to a new node at the beginning of a RoundList
     * @param value 
    */
    void add(int value);
    /**
     * @brief Clears a RoundList
    */
    void clear();
    /**
     * @brief Removes first element of a RoundList
    */
    void removeFirst();
    /**
     * @brief Returns value at countSteps from head of the list(counting from zero). 
     * In case of not found, -1 will be returned
     * @param countSteps 
     * @return 
    */
    int search(const int& countSteps) const;
    /**
     * @brief Removes the first occurence of key in the list
     * @param key 
    */
    void remove(int key);
    /**
     * @brief Adds a new element to the end of the list
     * @param value 
    */
    void addToEnd(int value);
    /**
     * @brief Insert key to the correct place in the list. I.e to the first place for which key is larger or equal to the element preceding it.
     * @param key 
    */
    void insert(int key);
    /**
     * @brief Prints the list
     * @param c_out 
     * @param list 
     * @return c_out
    */
    friend ostream& operator<<(ostream& c_out, RoundList& list);
    /**
     * @brief Inputs from keyboard values and inserts them into the list, until a value which is smaller than the preceding one is inputted.
     * @param c_in 
     * @param list 
     * @return 
    */
    friend istream& operator>>(istream& c_in, RoundList& list);
    /**
     * @brief *this list will receive all values of list
     * @param other 
     * @return *this
    */
    RoundList& operator=(const RoundList& other);
protected:
    /**
     * @brief Sentinel
    */
    Link* last;
};
