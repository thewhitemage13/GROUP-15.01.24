#include <iostream>
#include <ctime>
#include <string>
using namespace std;
#include "Date.h"
#include "Student.h"
#include "Student.h"

class Group {
    
    unsigned short countstudent = 0;
    Student** classmates = nullptr;
    string group_name;
    string specification;
    unsigned short number_of_course;

public:
    Group()
    {   
        SetGroupName("P26");
        SetNumberOfCourse(2);
        SetSpecification("Software Development");
    }

    Group(const Group& original)
    {
        this->countstudent = original.countstudent;
        this->classmates = new Student * [original.countstudent];

        for (int i = 0; i < countstudent; i++)
        {
            this->classmates[i] = new Student(*original.classmates[i]);
        }

        this->group_name = original.group_name;
        this->specification = original.specification;
        this->number_of_course = original.number_of_course;
    }

    void Print() const
    {
        cout << group_name << "\n\n";
        for (int i = 0; i < countstudent; i++)
        {
            classmates[i]->PrintStudent();
            classmates[i]->PrintExam();
            classmates[i]->PrintHomeWork();
            classmates[i]->PrintPractic();
            classmates[i]->AverageGrade();
        }
    }
    //добавляем студента
    void AddStudent(const Student& new_student)
    {
        Student** temp = new Student* [countstudent+1];
        for (int i = 0; i < countstudent; i++)
        {
            temp[i] = classmates[i];
        }
        temp[countstudent] = new Student(new_student);
        countstudent++;
        delete[]classmates;
        classmates = temp;
    }

    void WeanStudent(unsigned short index)
    {
        Student** temp = new Student* [countstudent - 1];
        for (int i = 0, j = 0; i < countstudent; i++)
        {
            if (i != index)
            {
                temp[j++] = classmates[i];
            }
        }
        delete classmates[index];
        delete[] classmates;
        countstudent--;
        classmates = temp;
        // тут будет удалени по индексу
    }

    //удяляем за низкий сред балу за экзамен
    void Expel()
    {
        if (countstudent == 0) {
            cout << "The group is empty.\n";
            return;
        }
        int minGradeIndex = 0; // индекс студента с самым низким баллом
        // находим индекс студента с самым низким баллом
        for (int i = 1; i < countstudent; i++) {
            if (classmates[i]->GetAverageGrade() < classmates[minGradeIndex]->GetAverageGrade()) {
                minGradeIndex = i;
            }
        }
        // удаляем студента с самым низким баллом
        Student** temp = new Student * [countstudent - 1];
        for (int i = 0, j = 0; i < countstudent; i++) {
            if (i != minGradeIndex) {
                temp[j++] = classmates[i];
            }
        }
        delete classmates[minGradeIndex];
        delete[] classmates;
        countstudent--;
        classmates = temp;
        cout << "The student with the lowest grade point average is dropped from the group.\n";
    }

    void SetCountOfStudent(int countstudent)
    {
        this->countstudent = countstudent;
    }

    int GetCountOfStudent() const
    {
        return countstudent;
    }

    void SetGroupName(string group_name)
    {
        this->group_name = group_name;
    }

    string GetGroupName() const
    {
        return group_name;
    }

    void SetSpecification(string specification)
    {
        this->specification = specification;
    }

    string GetSpecification() const
    {
        return specification;
    }

    void SetNumberOfCourse(int number_of_course)
    {
        this->number_of_course = number_of_course;
    }

    int GetNumberOfCourse() const
    {
        return number_of_course;
    }

    ~Group()
    {
        delete[]classmates;
    }
};

unsigned int Student::count;

int main()
{
    setlocale(0, "");

    Student a;
    a.AddExam(11);
    a.AddExam(12);
    Student b;
    b.AddExam(10);
    b.AddExam(9);
    Group g;
    g.AddStudent(a);
    g.AddStudent(b);
    g.Print();

    g.Expel();

    g.Print();
}