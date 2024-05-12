 #include"Date.h"

class Comment
{
public:
	string getcommentcontent();
	string getcommentauthor();
	
	
	void datafromfile(fstream& file);
	void setcommentcontent(string);
	void setcommmentauthor(string);

	Comment();
	Comment(string comment,string) ;
	~Comment();

private:
	string commentcontent;
	string commentid;
	User commentauthor;

};
string Comment::getcommentcontent() 
{

}
string Comment::getcommentauthor() 
{

}


void Comment::setcommentcontent(string commentcontent)
{
	this->commentcontent = commentcontent;
}
void Comment::setcommmentauthor(string commentauthor) 
{
	
}
void Comment::datafromfile(fstream& file)
{
	file >> postid >> postday >> postmonth >> postyear >> postauthor >> posttype >> postlikes >> postcontent;
	Post(postid, postday, postmonth, postyear, postauthor, posttype, postlikes, postcontent);
	setpostdate(postday, postmonth, postyear);
}
Comment::Comment()
{
	commentcontent = "";
	commentauthor("", "", "");
}
Comment ::Comment(string commentcontent,string author)
{
	this->commentcontent = commentcontent;
	commentauthor("", author, "");

}


Comment::~Comment()
{
}
#pragma once
