 #include"Date.h"

class Comment
{
public:
	string getcommentcontent();
	string getcommentauthor();
	string getpostcommmentid();
	
	void datafromfile(fstream& file);
	void setcommentcontent(string);
	void setcommmentauthor(string);

	Comment();
	Comment(string comment,string postcommentid,string commentauthor,string commentcontent) ;
	~Comment();

private:
	string commentcontent;
	string postcommentid;
	string commentid;
	string commentauthor;

};
string Comment::getcommentcontent() 
{
	return commentcontent;
}
string Comment::getcommentauthor() 
{
	return commentauthor;
}

string Comment::getpostcommmentid() 
{
	return postcommentid;
}
void Comment::setcommentcontent(string commentcontent)
{
	this->commentcontent = commentcontent;
}
void Comment::setcommmentauthor(string commentauthor) 
{
	this->commentauthor = commentauthor;
	
}
void Comment::datafromfile(fstream& file)
{
	file >> commentid >> postcommentid >> commentauthor >> commentcontent;
	Comment(commentid , postcommentid , commentauthor , commentcontent);
	
}
Comment::Comment()
{
	commentcontent = "";
	commentauthor="";
	postcommentid = "";
	commentid = "";
}
Comment ::Comment(string commentcontent, string postcommentid,string commentuthor,string postcontent)
{
	this->commentcontent = commentcontent;
	this->commentauthor=commentauthor;
	this->postcommentid = postcommentid;
	this->commentid = commentid;

}
Comment::~Comment()
{
}
#pragma once
