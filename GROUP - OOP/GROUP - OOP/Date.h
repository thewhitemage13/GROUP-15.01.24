#pragma once

class Date {
    unsigned short day;
    unsigned short month;
    long long year;
public:
    Date();

    Date(unsigned short day, unsigned short month, long long year);
    //?????????????
    Date(unsigned short day, unsigned short month) : Date(day, month, 2005) {};



    void PrintDate() const;
    //day SetGet
    void SetDay(unsigned short day);
    unsigned short GetDay() const;
    //month SetGet
    void SetMonth(unsigned short month);
    unsigned short GetMonth() const;
    //year SetGet
    void SetYear(long long year);
    long long GetYear() const;
};