#pragma once
#pragma once
class Worker
{
private:
    int extraHours;
    int hoursWorked;
    float salaryPerHour;
    int idNumber;
    char name[20];
    float totalSalary;
public:
    /**
     * @brief Calculates worker's salary based on the formula: hoursWorked*salaryPerHour+ salaryPerHour*extraHours*1.5
    */
    void calculateSalary();
    /**
     * @brief Gets total worker's salary
     * @return 
    */
    float getTotalSalary();
    /**
     * @brief Sets id number of worker
     * @param idNumber 
    */
    void setIdNumber(int idNumber);
    /**
     * @brief Returns id number of worker
     * @return 
    */
    int getIdNumber();

    /**
     * @brief Sets name of worker
     * @param name 
    */
    void setName(char name[20]);
    /**
     * @brief Returns name of worker
     * @return 
    */
    char* getName();

    /**
     * @brief Sets salary per hour of worker
     * @param salaryPerHour 
    */
    void setSalaryPerHour(float salaryPerHour);
    /**
    * @brief Gets salary per hour of worker
    * @param salaryPerHour
   */
    float getSalaryPerHour();

    /**
     * @brief Sets the base amount of hours
     * @param hoursWorked 
    */
    void setHoursWorked(int hoursWorked);
    /**
    * @brief Gets the base amount of hours
    * @param hoursWorked
   */
    int getHoursWorked();

    /**
     * @brief Sets the bonus hours of the worker
     * @param extraHours 
    */
    void setExtraHours(int extraHours);
    /**
     * @brief Gets the bonus hours a worker did.
     * @return 
    */
    int getExtraHours();
    /**
     * @brief Returns all hours both mandatory and bonus that the worker performed
     * @return 
    */
    int getAllHours();

};