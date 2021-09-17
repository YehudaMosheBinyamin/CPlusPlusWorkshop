#pragma once
class Fraction
{
public:
    /*Getters and Setters*/
    int getMoneh();
    int getMechane();
    void setMoneh(int moneh);
    void setMechane(int mechane);
    /**
     * @brief Prints the function in the format:"a/b"
    */
    void print();
    /**
     * @brief A function to ocmpare two functions and return if they are equal.
     * @param otherFraction A fraction to compared to current function
     * @return 
    */
    bool equal(Fraction otherFraction);   
private:
    int moneh;
    int  mechane;
    /**
     * @brief Reduces the function
    */
    void minimizeFraction();
};