#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;
class Date
{
public:
	//GETTERS
	string getmonth();
	string getyear();
	string getday();
	//SETTERS
	void setmonth(string);
	void setday(string);
	void setyear(string);
	//CONTRUCT & DESTRUCT
	void printdate() ;
	Date(string day, string month, string year);
	Date();
	~Date();

private:
	string  month;
	string year;
	string day;
};

//GETTERS
string Date::getmonth()
{
	return month;
}
string Date::getyear() {
	return year;
}
string Date::getday() { 
	return day; }

//SETTERS
void Date::setmonth(string month){
	this->month = month;
}
void Date::setday(string day)
{
	this->day = day;
}
void Date::setyear(string year) 
{ 
	this->year = year; 
}

//CONST & DESTRUCT 
void Date::printdate() 
{
	cout<<day<<"-"<<month  << "-" << year ;
}
Date::Date(string day, string month, string year) 
{
	this->day = day;
	this->month = month;
	this->year = year;
}
Date::Date()
{
	this->day = "";
	this->month = "";
	this->year = "";

}
Date::~Date()
{
}


