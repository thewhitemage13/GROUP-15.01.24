#include "Student.h"

Student::Student(const Student& original)
{
    count++;
    // ?? ??????? ????? ??????????? ? ?????? ???????????? ? ????? ??????, ?? ? ???? ????????? ?????????? ?????????? ??????????? ???? ????? ?????????, ??? ????? ????, ????????? ??? ??? ???
    // ????? ?? ????????? = ????????? ????? (??? ??????? ??????) this->
    // ?????? ?? ????????? = ????????? ????????, ? ???????? ????????? ?????????

    // ??? ???? ????????????? ??????????? (??? ?????-????????????)
    this->surname = original.surname;
    this->name = original.name;
    this->middlename = original.middlename;
    this->adress = original.adress;
    this->phonenumber = original.phonenumber;
    this->countpractic = original.countpractic;
    this->counthomework = original.counthomework;
    this->countexam = original.countexam;
    this->count = original.count;
    this->average_grade = original.average_grade;
    this->grade_of_practic = new int[original.countpractic];
    for (int i = 0; i < countpractic; i++)
    {
        this->grade_of_practic[i] = original.grade_of_practic[i];
    }

    this->grade_of_homework = new int[original.counthomework];
    for (int i = 0; i < counthomework; i++)
    {
        this->grade_of_homework[i] = original.grade_of_homework[i];
    }

    this->grade_of_exam = new int[original.countexam];
    for (int i = 0; i < countexam; i++)
    {
        this->grade_of_exam[i] = original.grade_of_exam[i];
    }
}

Student::Student() : Student("Studenchenko", "Student", "Studentovich", "Studencheskaya 38", "0630300033") { count++; }

Student::Student(string surname, string name, string middlname, string adress, string phonenumber)
{
    count++;
    SetSurname(surname);
    SetName(name);
    SetMiddlName(middlname);
    SetAdress(adress);
    SetPhone(phonenumber);
}

Student::Student(string surname, string name, string middlname, string adress) :Student(surname, name, middlename, adress, "0687680685") {}



Student::~Student()
{
    count--;
    if (grade_of_practic != nullptr)
        delete[] grade_of_practic;
    if (grade_of_homework != nullptr)
        delete[] grade_of_homework;
    if (grade_of_exam != nullptr)
        delete[] grade_of_exam;
}

void Student::PrintStudent() const
{
    cout << "Surname: " << surname << "\n";
    cout << "Name: " << name << "\n";
    cout << "Midlname: " << middlename << "\n";
    cout << "Adress: " << adress << "\n";
    cout << "Phonnumber: " << phonenumber << "\n";
}
unsigned int Student::GetCount()
{
    return count;
}
void Student::AddPractic(int newcountry)
{
    int* temp = new int[countpractic + 1];
    for (int i = 0; i < countpractic; i++)
    {
        temp[i] = grade_of_practic[i];
    }

    temp[countpractic] = newcountry;
    countpractic++;
    delete[]grade_of_practic;
    grade_of_practic = temp;
}

void Student::PrintPractic() const
{
    cout << "Practic: ";
    for (int i = 0; i < countpractic; i++)
    {
        cout << grade_of_practic[i] << ", ";
    }
    cout << "\n";
}

int Student::GePracticRatesCount(unsigned int index) const
{
    if (index < countpractic)
    {
        return grade_of_practic[index];
    }
}

void Student::AddHomeWork(int newcountry)
{
    int* temp = new int[counthomework + 1];
    for (int i = 0; i < counthomework; i++)
    {
        temp[i] = grade_of_homework[i];
    }
    temp[counthomework] = newcountry;
    counthomework++;
    delete[]grade_of_homework;
    grade_of_homework = temp;
}

void Student::PrintHomeWork() const
{
    cout << "HomeWork: ";
    for (int i = 0; i < counthomework; i++)
    {
        cout << grade_of_homework[i] << ", ";
    }
    cout << "\n";
}

int Student::GetHomeWorkRatesCount(unsigned int index) const
{
    if (index < counthomework)
    {
        return grade_of_homework[index];
    }
}

void Student::AddExam(int newcountry)
{
    int* temp = new int[countexam + 1];
    for (int i = 0; i < countexam; i++)
    {
        temp[i] = grade_of_exam[i];
    }
    temp[countexam] = newcountry;
    countexam++;
    delete[]grade_of_exam;
    grade_of_exam = temp;
}




void  Student::AverageGrade()
{

    for (int i = 0; i < countexam; i++)
    {
        average_grade += grade_of_exam[i] / countexam;
    }
    cout << average_grade << "\n";
}

void Student::PrintExam() const
{
    cout << "Exam: ";
    for (int i = 0; i < countexam; i++)
    {
        cout << grade_of_exam[i] << ", ";
    }
    cout << "\n";
}

int Student::GetExamRatesCount(unsigned int index) const
{
    if (index < countexam)
    {
        return grade_of_exam[index];
    }
}

void Student::SetSurname(string surname)
{
    this->surname = surname;
}

string Student::GetSurname() const
{
    return surname;
}

void Student::SetName(string name)
{
    this->name = name;
}

string Student::GetName() const
{
    return name;
}

void Student::SetMiddlName(string middlname)
{
    this->middlename = middlname;
}

string Student::GetMiddlName() const
{
    return middlename;
}

void Student::SetAdress(string adress)
{
    this->adress = adress;
}

string Student::GetAdress() const
{
    return adress;
}

void Student::SetPhone(string phonenumber)
{
    this->phonenumber = phonenumber;
}

string Student::GetPhone() const
{
    return phonenumber;
}
void Student::SetAverageGrade(int average_grade)
{
    this->average_grade = average_grade;
}
int Student::GetAverageGrade() const
{
    return average_grade;
}