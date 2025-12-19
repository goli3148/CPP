#include <iostream>
using namespace std;

class Date{
    public:
        Date(int year, int month, int day);
        Date();
        ~Date();
        void operator=(const Date&);
        friend Date operator+(const Date&, const Date&);
        friend Date operator-(const Date&, const Date&);

        void date_overload_handler();
        void show_date();

    private:
        int day;
        int month;
        int year;
};

Date::Date(int year, int month, int day){
    this->day = day;
    this->month = month;
    this->year = year;
    date_overload_handler();
}
Date::Date(){

}
Date::~Date(){

}


void Date::operator=(const Date& d){
    day = d.day;
    month = d.month;
    year = d.year;
}

Date operator+(const Date& a, const Date& b){
    Date result(0, 0, 0);
    result.day = a.day + b.day;
    result.month = a.month + b.month;
    result.year = a.year + b.year;
    result.date_overload_handler();
    return result;
}

Date operator-(const Date& a, const Date& b){
    Date result(0, 0, 0);
    result.day = a.day - b.day;
    result.month = a.month - b.month;
    result.year = a.year - b.year;
    result.date_overload_handler();
    return result;
}

void Date::date_overload_handler(){
    while(day < 0){
        month --;
        day += 30;
    }
    while(month < 0){
        year --;
        month += 12;
    }
    while(day > 30){
        month ++;
        day -= 30;
    }
    while(month > 12){
        year ++;
        month -= 12;
    }
}

void Date::show_date(){
    cout << "Date: yyyy/mm/dd -> " << year << "/" << month << "/" << day << endl;  
}

int main(){
    Date date1(2011, 11, 30);
    Date date2(0, -1, 61);

    date1.show_date();
    date2.show_date();

    Date date3;
    date3 = date1 - date2;

    date3.show_date();

    return 0;
}