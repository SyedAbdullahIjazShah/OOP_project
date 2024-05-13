#include"User.h"
class Postlikes
{
public:
	string getpostlikes();
	string getpostid();
	User* getlikeduserarray();

	void printpostlikes();
	void setpostlikes(string);
	void setpostid(string);
	void setlikeduserarray(User*temp);
	void readdatafromfile(fstream&);
	Postlikes();
	Postlikes(string postlikes,string postid,string arr[5]);
	~Postlikes();

private:
	string postlikes;
	string postid;
	User* likeduserarray = new User[5];
};

string Postlikes::getpostlikes() { return postlikes; }
string Postlikes::getpostid() { return postid; };
User* Postlikes::getlikeduserarray() 
{
	return likeduserarray;
};

void Postlikes::printpostlikes()
{
	cout << "Post id : \t " << postid << " \t Postlikes: \t" << postlikes << "\t Users who liked:\t";
	for (size_t j = 0; j < 5; j++)
	{
		if (likeduserarray[j].getname() != "null")
		{
			cout << likeduserarray[j].getname();
			cout << "\t ";
		}
	}
	cout << "\n________________________________________________________________________________________________________________________________________________________________________\n";

}
void Postlikes::setpostlikes(string postlikes) { this->postlikes = postlikes; }
void Postlikes::setpostid(string postid) { this->postid = postid; }
void Postlikes::setlikeduserarray(User*temp)
{
	for (size_t i = 0; i < 5; i++)
	{
		likeduserarray[i].setname(temp[i].getname());
	}
}
void Postlikes::readdatafromfile(fstream&file)
{
	file >> postid >> postlikes;
	for (size_t i = 0; i < 5; i++)
	{
		string temp;
		file >> temp;
		likeduserarray[i].setname(temp);
	}
}


Postlikes::Postlikes(string postlikes, string postid, string arr[5]) 
{
	this->postid = postid;
	this->postlikes = postlikes;
	for (size_t i = 0; i < 5; i++)
	{
		likeduserarray[i].setname(arr[i])  ;
	}
}
Postlikes::Postlikes()
{
	this->postid = " ";
	this->postlikes = " ";
	for (size_t i = 0; i < 5; i++)
	{
		likeduserarray[i].setname(" ");
	}
}
Postlikes::~Postlikes() 
{
	for (size_t i = 0; i < 10; i++)
	{
		delete [i]likeduserarray;
	}
	likeduserarray = nullptr;
};
#pragma once
