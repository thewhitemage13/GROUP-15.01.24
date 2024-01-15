#pragma once
#include <iostream>
using namespace std;

///<summary>
///The Student class allows you to create objects of Student type
///<summary>
class Student {
    static unsigned int count;
    string surname;
    string name;
    string middlename;
    string adress;
    string phonenumber;
    int average_grade;
    unsigned int countpractic = 0;
    unsigned int counthomework = 0;
    unsigned int countexam = 0;
    int* grade_of_practic = new int[countpractic];
    int* grade_of_homework = new int[counthomework];
    int* grade_of_exam = new int[countexam];

public:
    /// <summary>
    ///  copy constructor for the Student class
    /// </summary>
    /// <param name="original"> an object of Student type will be passed here by reference with the original state </param>
    Student(const Student& original);
    /// <summary>
    /// Constructor without parameters for object of Student type
    /// </summary>
    Student();
    /// <summary>
    /// main constructor for an object of Student type
    /// </summary>
    /// <param name="surname"></param>
    /// <param name="name"></param>
    /// <param name="middlname"></param>
    /// <param name="adress"></param>
    /// <param name="phonenumber"></param>
    Student(string surname, string name, string middlname, string adress, string phonenumber);
    /// <summary>
    /// Crestructor for object of Student type
    /// </summary>
    /// <param name="surname"></param>
    /// <param name="name"></param>
    /// <param name="middlname"></param>
    /// <param name="adress"></param>
    Student(string surname, string name, string middlname, string adress);
    /// <summary>
    /// Destructor for object of Student type
    /// </summary>
    ~Student();
    /// <summary>
    /// Student type object output function
    /// </summary>
    void PrintStudent() const;
    /// <summary>
    /// Getter for object of type "count"
    /// </summary>
    /// <returns></returns>
    static unsigned int GetCount();
    /// <summary>
    /// Function for adding practice grades to an object of Student type
    /// </summary>
    /// <param name="newcountry">this will be the grade you want to add</param>
    void AddPractic(int newcountry);
    /// <summary>
    /// Function for outputting grades for practice from an object of Student type
    /// </summary>
    void PrintPractic() const;

    void AverageGrade();
    /// <summary>
    /// Getter to return an index practice grade
    /// </summary>
    /// <param name="index">whose score index we're looking for</param>
    /// <returns></returns>
    int GePracticRatesCount(unsigned int index) const;
    /// <summary>
    /// Adding a grade for assignments to an object of Student type
    /// </summary>
    /// <param name="newcountry">this will be the grade you want to add</param>
    void AddHomeWork(int newcountry);
    /// <summary>
    /// Function for outputting grades from object of Student type
    /// </summary>
    void PrintHomeWork() const;
    /// <summary>
    /// Getter to return a grade for an index grade for a dz
    /// </summary>
    /// <param name="index">whose score index we're looking for</param>
    /// <returns></returns>
    int GetHomeWorkRatesCount(unsigned int index) const;
    /// <summary>
    /// Adding an exam grade to an object of type Student
    /// </summary>
    /// <param name="newcountry">this will be the grade you want to add</param>
    void AddExam(int newcountry);
    /// <summary>
    /// Function for outputting exam grades from an object of Student type
    /// </summary>
    void PrintExam() const;
    /// <summary>
    /// Getter to return an index exam grade
    /// </summary>
    /// <param name="index">whose score index we're looking for</param>
    /// <returns></returns>
    int GetExamRatesCount(unsigned int index) const;
    /// <summary>
    /// Setter to enter the last name into an object of data type Student
    /// </summary>
    /// <param name="surname">enter the last name here</param>
    void SetSurname(string surname);
    /// <summary>
    /// Getter for a Surnanme object that returns an object of type surname
    /// </summary>
    /// <returns>return value</returns>
    string GetSurname() const;
    /// <summary>
    /// Setter to enter a name into an object of data type Student
    /// </summary>
    /// <param name="name">return value</param>
    void SetName(string name);
    /// <summary>
    /// Getter for a Surnanme object that returns an object of type name
    /// </summary>
    /// <returns>return value</returns>
    string GetName() const;
    /// <summary>
    /// Setter for entering a middle name into an object of data type Student
    /// </summary>
    /// <param name="middlname">enter the patronymic here</param>
    void SetMiddlName(string middlname);
    /// <summary>
    /// Getter for a middlename object that returns an object of type middlename
    /// </summary>
    /// <returns>return value</returns>
    string GetMiddlName() const;
    /// <summary>
    /// Setter for entering an address into an object of data type Student
    /// </summary>
    /// <param name="adress">????? ?????? ??????</param>
    void SetAdress(string adress);
    /// <summary>
    /// Getter for an adress object that returns an object of type adress
    /// </summary>
    /// <returns>return value</returns>
    string GetAdress() const;
    /// <summary>
    /// Setter to enter phone into an object of data type Student
    /// </summary>
    /// <param name="phonenumber">enter the phone number here</param>
    void SetPhone(string phonenumber);
    /// <summary>
    /// Getter for the phone object, which returns an object of type Phone
    /// </summary>
    /// <returns>return value</returns>
    string GetPhone() const;
    void SetAverageGrade(int average_grade);
    int GetAverageGrade() const;
};