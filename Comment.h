 #include"Date.h"

class Comment
{
public:
	//GETTERS
	string getcommentcontent();
	string getcommentauthor();
	string getpostcommmentid();
	string getcommentid();
	//SETTERS
	void datafromfile(fstream& file);
	void setcommentcontent(string);
	void setcommmentauthor(string);
	void setcommentid(string);
	void setpostcommentid(string);
	void printcomments();

	/// <summary>
	///CONSTRUCTOR AND DESTRUCTOR
	/// </summary>
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
string Comment::getcommentid() 
{
	return commentid;
}

void Comment::setcommentcontent(string commentcontent)
{
	this->commentcontent = commentcontent;
}
void Comment::setcommmentauthor(string commentauthor) 
{
	this->commentauthor = commentauthor;
	
}
void Comment::setcommentid(string commentid)
{
	this->commentcontent = commentid;
}
void Comment::setpostcommentid(string postcommentid)
{
	this->postcommentid = postcommentid;

}
void Comment::datafromfile(fstream& file)
{
	file >> commentid >> postcommentid >> commentauthor >> commentcontent;
	Comment(commentid, postcommentid, commentauthor, commentcontent);
	
}
void Comment::printcomments()
{
	cout << commentid << "\t" << postcommentid << "\t" << commentauthor << "\t" ;
	for (size_t i = 0;  commentcontent[i]!='\0'; i++)
	{
		if(commentcontent[i] == ' '){
			cout << " ";
		}
		
		else
		{
			cout << commentcontent[i];
		}
		
	}
	cout << endl;
}
Comment::Comment()
{
	commentcontent = "";
	commentauthor="";
	postcommentid = "";
	commentid = "";
}
Comment ::Comment(string commentcontent, string postcommentid,string commentuthor,string commentid)
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
