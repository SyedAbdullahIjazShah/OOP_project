#include"Page.h"
class User
{
public:
	void setuid(string uid);
	string getuid();

	void setname(string name);
	string getname();

	void setpassword(string password);
	string getpassword() ;

	void inputusername();
	void inputuserpassword();
	void printuser();
	void setdatafromfile(fstream&);
	User(string uid, string name, string password);
	User();
	~User();

private:
	string uid;
	string name;
	string password;
	
};
void User::setpassword(string password)
{
	this->password = password;
}
string User::getpassword()
{
	return password;
}
void User::setuid(string uid)
{
	this->uid = uid;
}
string User::getuid() {
	return uid;
}
void User::setname(string name)
{
	this->name = name;

}
string User::getname() {
	return name;
}
void User::inputusername()
{
	string tempname;
	cout << "\n------>>Enter the name:";
	getline(cin, tempname);
	setname(tempname);
	

}
void User::inputuserpassword()
{
	string  temppassword;
	cout << "\n------>>Enter the password:";
	getline(cin,temppassword);
	setpassword(temppassword);

}
void User::setdatafromfile(fstream&file) {
	file >> uid >> name >> password;
	 User(uid, name, password);
}
void User::printuser()
{
	cout << "User: " << name;
}
User::User()
{
	 uid = "";
	 name = "";
	password = "";
}
User::User(string uid , string name, string password)
{
	this->uid = uid;
	this->name = name;
	this->password = password;

}
User::~User()
{

}
#pragma once
