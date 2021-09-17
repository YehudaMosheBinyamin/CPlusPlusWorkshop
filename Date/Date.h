/**
 * @brief Class to represent a date. Note that the months always have 30 days and as a result years are always 360 days long.
*/
class Date
{
    int day;
    int month;
    int year;
public:
    Date(int day = 1, int month = 1, int year = 1970);
    Date(const Date& other);
    void setDate(int day, int month, int year);
    //prefix increment
    Date& operator++();
    //postfix increment
    Date operator++(int);
    Date& operator+=(int numDays);
    bool operator >(const Date& other)const;
    bool operator <(const Date& other)const;
    bool operator == (const Date& other)const;
    void print();
};