#include"Comment.h"
class Post
{
public:
	
	void setpostcontent(string) ;
	void setpostid(string);
	void setposttype(string);
	void setpostauthor(string);
	void setpostdate(string ,string,string);
	void printpost();

	string getpostcontent();
	string getpostid();
	string getposttype();
	string getpostauthor();
	string getpostday();
	string getpostmonth();
	string getpostyear();


	void datafromfile(fstream& );
	Post();
	Post(string postid, string postday,string postmonth,string postyear,string postauthor, string posttype, string postcontent);
	~Post();
private:
	string postcontent;
	string postid;
	string posttype;
	string postauthor;
	string postday;
	string postmonth;
	string postyear;
	Date postdate;
};

//SETTERS
void Post:: setpostcontent(string postcontent)
{
	this->postcontent = postcontent;
}
void Post::setpostauthor(string postauhtor)
{
	this->postauthor = postauthor;
}
void Post::setpostid(string postid)
{
	this->postid = postid;
}
void Post::setposttype(string posttype)
{
	
	this->posttype = posttype;
	
}
void Post::setpostdate(string day,string month,string year) 
{
	postdate.setday(day);
	postdate.setyear(year);
	postdate.setmonth(month);
}

//GETTERS

string Post::getpostcontent()
{
	return postcontent;
}
string Post::getpostauthor()
{
	return postauthor;
}
string Post::getpostid()
{
	return postid;
}
string Post::getposttype()
{
	return posttype;
}
string Post::getpostday()
{ return postday; }
string Post::getpostmonth() 
{ return postmonth; }
string Post::getpostyear() 
{ return postyear; }
//FILE INPUT 
void Post::datafromfile(fstream& file) 
{
	file >>postid>>postday>>postmonth>>postyear>>postauthor>>posttype>>postcontent;
	Post(postid,postday,postmonth,postyear,postauthor,posttype,postcontent);
	setpostdate(postday, postmonth, postyear);
}

//CONST & DESTRUCT

void Post::printpost() 
{
	cout << "\nPOST DETAILS- Postid : " << postid << "\t";
	postdate.printdate();
	cout << " \tPost Auhtor: " << postauthor << "\t Post Type: " << posttype <<"\t Post Content: ";
	for (size_t i = 0; postcontent[i] != '\0'; i++)
	{
		if (postcontent[i] == '.')
		{
			cout << " ";
		}
		else
		{
			cout << postcontent[i];
		}
		
	}
	cout<<"\n________________________________________________________________________________________________________________________________________________________________________\n";
}
Post::Post(string postid, string postday, string postmonth, string postyear, string postauthor, string posttype, string postcontent)
{
	this->postid = postid;
	this->postcontent = postcontent;
	this->posttype = posttype;
	this->postauthor = postauthor;
	setpostdate(postday, postmonth, postyear);
	
	
}
Post::Post()
{
	postid = "";
	postcontent = "";
	posttype = "";
	postauthor = "";
	postday="";
	postmonth="";
	postyear="";
	setpostdate(postday, postmonth, postyear);
}
Post::~Post()
{
}
#pragma once
