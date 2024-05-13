#include"SocialMediaApp.h"
int main()
{
	//////////////////////////////////////////////DYNAMIC VARIABLES//////////////////////////////////////////////
	const int acc{ 10 };
	int *nposts=new int {20};
	int* ncomments = new int{40};
	string currentday{"13"};
	string currentmonth{"05"};
	string currentyear{ "2024" };
	Comment* postcomments = new Comment[*ncomments];
	User* friends=new User[acc - 1];
	User* Userarray = new User[acc];
	Post* allposts = new Post[*nposts];
	User* Mainuser = new User;
	Postlikes* postlikes = new Postlikes[*nposts];
	//////////////////////////////////////////////DYNAMIC VARIABLES& & LABELS//////////////////////////////////////////////
	

	///////////////////////////////////// POSTLIKES FILE READING///////////////////////////////////////////////////////

	fstream postlikesfile;
	postlikesfile.open("Postlikes.txt", ios::in);
	if (!postlikesfile)
	{
		cout << endl << "No such Postlike file exsists" << endl;
		cout << endl << "Invalid File Or Error Opening File" << endl;
	}
	else
	{
		for (size_t i = 0; i < *nposts; i++)
		{
			postlikes[i].readdatafromfile(postlikesfile);
			//cout << "\nData copied to Posts Database successfully\n";
			postlikes[i].printpostlikes();
		}
	}

	//Functionalitymenu-->>is a label to get to the functionality menu
	// Exitapplication-->> is a label used to exit the application
	// Firstfunctionalitylabel-->> is a label to get back to the menu inside the 1 selecttion functionaltiy
	// 
	/////////////////////////////////////COMMENT FILE READING///////////////////////////////////////////////////////

	fstream commentsfile;
	commentsfile.open("Comment.txt", ios::in);
	if (!commentsfile)
	{
		cout << endl << "No such Comment file exsists" << endl;
		cout << endl << "Invalid File Or Error Opening File" << endl;
	}
	else
	{
		for (size_t i = 0; i < *ncomments; i++)
		{
			postcomments[i].datafromfile(commentsfile);
			//cout << "\nData copied to Posts Database successfully\n";
			postcomments[i].printcomments();
		}
	}
	///////////////////////////////////// POST FILE READING///////////////////////////////////////////////////////
	fstream postsfile;
	postsfile.open("Post.txt", ios::in);
	if (!postsfile)
	{
		cout << endl << "No such Post file exsists" << endl;
		cout << endl << "Invalid File Or Error Opening File" << endl;
	}
	else
	{
		for (size_t i = 0; i < *nposts; i++)
		{
			allposts[i].datafromfile(postsfile);
			//cout << "\nData copied to Posts Database successfully\n";
			allposts[i].printpost();
		}
	}
	/////////////////////////////////////USER FILE READING///////////////////////////////////////////////////////

	fstream userfile;
	userfile.open("User.txt", ios::in);
	if (!userfile)
	{
		cout << endl << "No such user file exsists" << endl;
		cout << endl << "Invalid File Or Error Opening File" << endl;
	}
	else
	{
		for (size_t i = 0; i < acc; i++)
		{
			Userarray[i].setdatafromfile(userfile);
			//cout << "\nData copied to User Database successfully\n";
		}
	}
	string select;
	///////////////////////////////////// FILE READING ENDED///////////////////////////////////////////////////////
	
	/////////////////////////////////////FILE READING ENDED ///////////////////////////////////////////////////////
	//cout << "\n<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>\n";
	
	cout << "________________________________________________________________________________________________________________________________________________________________________\n";
	cout << "************************************************************* WELCOME TO THE SOCIAL MEDIA APP **************************************************************************\n";
	cout << "________________________________________________________________________________________________________________________________________________________________________\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	  // cout << "-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>\n";
	//cout << "\n\n\n\t--> Login here\t";
	cout << "\n------>>Press '1'  to login \n------>>Press '0' to exit the application:\t";
	cin >> select;
	while (select != "1")
	{
		if (select == "0")
		{
			Exitapplication:
			system("CLS");
			cout << "________________________________________________________________________________________________________________________________________________________________________\n";
			cout << "***************************************************************** Application Closed ***********************************************************************************\n";
			cout << "________________________________________________________________________________________________________________________________________________________________________\n";
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			return 0;
		}
		

		else
		{
			cout << "\n\t\t\tPlease select from above numbers:\t";
			cin >> select;
		}
	}
	system("CLS");
	cout << "\n\n\n\n";
	if (select == "1")
	{
		//GOTO LABEL FOR LOGIN;
		Login:
		cout << "\t\t\t\t\t\t\t\t";
		cin.ignore();
		system("CLS");
		cout << "________________________________________________________________________________________________________________________________________________________________________\n";
		cout << "***************************************************************** WELCOME TO THE LOGIN PORTAL **************************************************************************\n";
		cout << "________________________________________________________________________________________________________________________________________________________________________\n";
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
		Mainuser->inputusername();
		Mainuser->inputuserpassword();

	}

    string flag="0";
	for (size_t i = 0; i < acc; i++)
	{
		if (Mainuser->getname()==Userarray[i].getname()   && Mainuser->getpassword()==Userarray[i].getpassword() )
		{

			Mainuser->setuid(Userarray[i].getuid());
			//cout << "\n\tMain User Matched\n\t";
			flag="1";
		}

	}
	//cout << Mainuser->getuid() << "\t" << Mainuser->getname() << "\t" << Mainuser->getpassword();
	if (flag=="0")
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid Username And Password\n\n\t\t\t\t\t\t\t\tPress Any Key To Continue\n\t\n\t";
		
//		cin.ignore();
		goto Login;
	}
	if (flag == "1")
	{
		
		int index{ 0 };
		for (size_t i = 0; i < acc; i++)
		{
			
			if(Userarray[i].getuid()!=Mainuser->getuid())
			{
				friends[index].setuid(Userarray[i].getuid()) ;
					friends[index].setname(Userarray[i].getname());
					index++;
			}
		}

	}
	cin.ignore();

	system("CLS");
	cout << "________________________________________________________________________________________________________________________________________________________________________\n";
	cout << "***************************************************************** You logged in as :" << (Mainuser->getname()) << " ***********************************************************************************\n";
	cout << "________________________________________________________________________________________________________________________________________________________________________\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";

	Functionalitymenu:
	select = "";
	cout <<endl<< "Press the any key to see functionalities menu" << endl << endl << endl;
	cin.ignore();
	cin >> select;
	system("_mm_pause");
	system("CLS");
	cout << "________________________________________________________________________________________________________________________________________________________________________\n";
	cout << "***************************************************************** You logged in as :" << Mainuser->getname()<< " ***********************************************************************************\n";
	cout << "________________________________________________________________________________________________________________________________________________________________________\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";
	/*cout << "\t\t\t\t\t\tYou logged in as :" << Mainuser->getname() << endl << endl << endl;*/
	/////////////////////////////////////LOGING IN DONE///////////////////////////////////////////////////////
	select = "";
	///////////////////////////////////    MENU BAR    ///////////////////////////////////////////////////////
	cout << "Press the required key for specific functionalities"<<endl << endl << endl;
	cout << "0 :\tLogin into another account\t\n";
	cout << "1 :\tView HomePage \t\n";
	cout << "2 :\tLike a Post \t\n";
	cout << "3 :\tView the list of People who liked post \t\n";
	cout << "4 :\tComment on a Post\t\n";
	cout << "5 :\tView a Post\t\n";
	cout << "6 :\tShare a memory\t\n";
	cout << "7 :\tView users profile\t\n";
	cout << "8 :\tView friend list\t\n";
	cout << "9 :\tView page\t\n";
	cout << "E :\tExit Application\t\n\n\n";
	/////////////////////////////////////MENU INVALID SELECTION///////////////////////////////////////////////////////
	cout << "\t\t\tEnter Desired Option\t: ";
	cin >> select;
	while (select != "0" && select != "1"
		&& select != "2" && select != "3"
		&& select != "4" && select != "5"
		&& select != "6" && select != "7"
		&& select != "8" &&select != "9"
		&& select != "E" && select != "e")
	{
		cout << "\nPlease Select from an Option:\t";
		cin >> select;
	}
	/////////////////////////////////////MENU VALID SELECTIONS///////////////////////////////////////////////////////
		while (select != "E" && select != "e") 
		{

		if (select == "0")
		{
			////////////////////////////////////////////AGAIN LOGIN///////////////////////////////////////////////////
			goto Login;

		}	
		/*DONE*/
		else if (select == "1")
		{
			////////////////////////////////////////////VIEWING A HOMEPAGE///////////////////////////////////////////////////
			system("CLS");
			cout << "________________________________________________________________________________________________________________________________________________________________________\n";
			cout << "***************************************************************** WELCOME TO THE HOME PAGE *****************************************************************************\n";
			cout << "________________________________________________________________________________________________________________________________________________________________________\n";
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";

			string chose2{ " " };
			Firstfunctionalitylabel:
			/////////////////////////////     MENU:FRIENDS POST & PAGES POST     ///////////////////////////////////////////
			cout << "\n\t-->>PRESS 0  TO SEE THE ALL FRIENDS POSTS\n";
			cout << "\n\t-->>PRESS 1  TO SEE THE ALL lIKED PAGES POSTS\n";
			cout << "\n\t-->>PRESS 2  TO GO BACK TO FUNCTIONALITY MENU\n";
			cout << "\n\t-->>PRESS 'e' OR 'E'  TO EXIT THE APPLICATION\n";
			cout << "\n\t";
			cin >> chose2;
			while (chose2 != "0" && chose2 != "1" && chose2 != "2" && chose2 != "e" && chose2 != "E")
			{
				cout << "\nPlease Select from an Option:\t";
				cin >> chose2;
			}

			if (chose2 == "e" || chose2 == "E")
			{
				goto Exitapplication;
			}
			else
			{
				
				if (chose2 == "0")
				{
					cout << "\n\t\t\t\t\tHERE ARE THE LAST POSTS SHARED BY THE YOUR FRIENDS IN LAST 24 HOURS\n";
					for (size_t i = 0; i < acc - 1; i++)
					{
					
						if (friends[i].getname() != Mainuser->getname())
						{
					
							for (size_t j = 0; j < *nposts; j++)
							{
								
								if (friends[i].getname() == allposts[j].getpostauthor())
								{
					
									if (stoi(allposts[j].getpostday()) == stoi(currentday) || stoi(allposts[j].getpostday()) == (stoi(currentday)-1) )
									{
										
										if (stoi(allposts[j].getpostmonth()) == stoi(currentmonth))
										{
										
											if (stoi(allposts[j].getpostyear()) == stoi(currentyear))
											{
												
												allposts[j].printpost();
											}
										}
									}
								}
							}
						}

					}
					goto Firstfunctionalitylabel;
				}
				else if(chose2 == "1")
				{



					goto Firstfunctionalitylabel;
				}
				else
				{


					goto Functionalitymenu;
				}

			}


		}
		else if (select == "2")
		{
			string choice2{ " " };
			cout << "\n\t-->>PRESS 0  TO ADD LIKE TO THE SPECIFIC POST \n";
			cout << "\n\t-->>PRESS 1  TO GO TO FUNCTIONALTIY MENU\n";
			cout << "\n\t-->>PRESS e or E  TO EXIT APPLICATION\n\t";
			cin >> choice2;
			while (choice2 != "0" && choice2 != "1" && choice2 != "2" && choice2 != "e" && choice2 != "E")
			{
				cout << "\nPlease Select from an Option:\t";
				cin >> choice2;
			}
			if (choice2 == "0")
			{
				cout << "\n\t-->>ADD A SPECIFIC POST ID YOU WANT TO LIKE IT\n\t";
				string temppostid;
				cin >> temppostid;
				for (size_t i = 0; i < *nposts; i++)
				{
					if (postlikes[i].getpostid() == temppostid)
					{
							User *tempuser=postlikes[i].getlikeduserarray();
							bool flag = true;
							for (size_t j = 0; j < stoi(postlikes[i].getpostlikes()); j++)
							{
								if (tempuser[j].getname() == Mainuser->getname())
								{
									flag = false;
									cout << "\t\nYOU CANNOT LIKE THIS POST AS U ALREADY HAD LIKED IT\n\t";
								}

							}
							if (flag)
							{
								int temp = stoi(postlikes[i].getpostlikes())+1;
								string tempstr= to_string(temp);
								(postlikes[i].setpostlikes(tempstr));

								tempuser[stoi(postlikes[i].getpostlikes()) - 1].setname(Mainuser->getname());
								cout << "HERE'S THE UPDATED POST LIKES";
								postlikes[i].printpostlikes();
							}





						/*cout << "\n________________________________________________________________________________________________________________________________________________________________________\n";
						postlikes[i].printpostlikes();*/
					}
				}
			}
			else
			{
				if (choice2 == "e" || choice2 == "E")
				{
					goto Exitapplication;
				}
				else
				{
					goto Functionalitymenu;
				}
			}
			goto Functionalitymenu;
		}
		else if (select == "3")
		{
			string choice3{ " "  };
			cout << "\n\t-->>PRESS 0  TO SEE SPECIFIC POST WITH USERS LIKED IT  \n";
			cout << "\n\t-->>PRESS 1  TO GO TO FUNCTIONALTIY MENU\n";
			cout << "\n\t-->>PRESS e or E  TO EXIT APPLICATION\n\t";
			cin >> choice3;
			while (choice3 != "0" && choice3!= "1" && choice3 != "2" && choice3 != "e" && choice3 != "E")
			{
				cout << "\nPlease Select from an Option:\t";
				cin >> choice3;
			}
			if (choice3 == "0")
			{
				cout << "\n\t-->>ADD A SPECIFIC POST ID \n\t";
				string temppostid;
				cin >> temppostid;
				for (size_t i = 0; i < *nposts; i++)
				{
					if (postlikes[i].getpostid() == temppostid)
					{
						cout << "\n________________________________________________________________________________________________________________________________________________________________________\n";
						postlikes[i].printpostlikes(); 
					}
				}
			}
			else
			{
				if (choice3 == "e" || choice3 == "E")
				{
					goto Exitapplication;
				}
				else
				{
					goto Functionalitymenu;
				}
			}
			goto Functionalitymenu;
		}
		else if (select == "4")
		{

			cout << "\n\t-->>PRESS 0  TO SEE SPECIFIC POST WITH COMMENT BY ID \n";
			cout << "\n\t-->>PRESS 1  TO GO TO FUNCTIONALTIY MENU\n";
			cout << "\n\t-->>PRESS e or E  TO EXIT APPLICATION\n";
			goto Functionalitymenu;
		}
		else if (select == "5")
		{

			string temppostid{ "" };
			cout << "\n\t-->>PRESS 0  TO SEE SPECIFIC POST WITH COMMENT BY ID \n";
			cout << "\n\t-->>PRESS 1  TO GO TO FUNCTIONALTIY MENU\n";
			cout << "\n\t-->>PRESS e or E  TO EXIT APPLICATION\n";
			cin >> temppostid;
			while (temppostid != "0" && temppostid != "1" && temppostid != "2" && temppostid != "e" && temppostid != "E")
			{
				cout << "\nPlease Select from an Option:\t";
				cin >> temppostid;
			}
			if (temppostid == "e" && temppostid == "E")
			{
				goto Exitapplication;
			}
			else {
				if (temppostid == "0") {
					cout << "\n\tENTER A VALID POST ID RNAGING FROM 000 TO 020 ONLY:\t";
					cin >> temppostid;
					while (stoi(temppostid) <= 000 || stoi(temppostid) >= 020)
					{
						cout << "\n\tPLEASE ENTER A VALID POST ID RNAGING FROM 000 TO 020 :\t";
						cin >> temppostid;
					}
					for (size_t i = 0; i < *nposts; i++)
					{
						if (allposts[i].getpostid() == temppostid)
						{
							allposts[i].printpost();
							for (size_t j = 0; j < *ncomments; j++)
							{
								if (postcomments[j].getpostcommmentid() == allposts[i].getpostid())
								{
									cout << "\n\t";
									postcomments[j].printcomments();

								}
							}

						}
					}
				}
				else
				{
					goto Functionalitymenu;
				}
			}
		}
		else if (select == "6")
		{
			////////////////////////////////////////////SHARING A MEMMORY///////////////////////////////////////////////////
			cout << "\n\t-->>PRESS 0  TO SEE SPECIFIC POST WITH COMMENT BY ID \n";
			cout << "\n\t-->>PRESS 1  TO GO TO FUNCTIONALTIY MENU\n";
			cout << "\n\t-->>PRESS e or E  TO EXIT APPLICATION\n";

			goto Functionalitymenu;
		}
		else if (select == "7")
		{
			////////////////////////////////////////////VIEW USERS PROFILE///////////////////////////////////////////////////
			cout << "\n\t-->>PRESS 0  TO SEE SPECIFIC POST WITH COMMENT BY ID \n";
			cout << "\n\t-->>PRESS 1  TO GO TO FUNCTIONALTIY MENU\n";
			cout << "\n\t-->>PRESS e or E  TO EXIT APPLICATION\n";

			goto Functionalitymenu;
		}
		else if (select == "8")
		{
			/////////////////////////////////////MENU:FRIEND LIST///////////////////////////////////////////////////////

			cout << "\n\t-->>PRESS 0  TO SEE THE FRIENDS \n";
	 		cout << "\n\t-->>PRESS 1  TO GO TO FUNCTIONALTIY MENU\n";
			cout << "\n\t-->>PRESS e or E  TO EXIT APPLICATION\n";
			string choice8;
			cin >> choice8;
			while (choice8 != "0" && choice8 != "1" && choice8 != "2" && choice8 != "e" && choice8 != "E")
			{
				cout << "\nPlease Select from an Option:\t";
				cin >> choice8;
			}
			if (choice8 == "0") 
			{
				cout << "\n\tFriends Are As Follows\n";
				for (size_t i = 0; i < acc - 1; i++)
				{
					cout << endl << "Id: " << friends[i].getuid() << "\t\t Name: " << friends[i].getname() << endl;
				}
			}
			else
			{
				if (choice8 == "e" || choice8 == "E")
				{
					goto Exitapplication;
				}
				else
				{
					goto Functionalitymenu;
				}
			}
		}
		else if (select == "9")
		{
			////////////////////////////////////////////VIEW A PAGE ///////////////////////////////////////////////////
			string choice9{""};
			cout << "\n\t-->>PRESS 0  TO SEE SPECIFIC PAGE WITH POSTS \n";
			cout << "\n\t-->>PRESS 1  TO GO TO FUNCTIONALTIY MENU\n";
			cout << "\n\t-->>PRESS e or E  TO EXIT APPLICATION\n";
			cin >> choice9;
			while (choice9 != "0" && choice9 != "1" && choice9 != "2" && choice9 != "e" && choice9 != "E")
			{

			}
			if (choice9=="0")
			{

			}
			else
			{
				if (choice9 == "e" || choice9 == "E")
				{
					goto Exitapplication;
				}
				else
				{
					goto Functionalitymenu;
				}
			}
		}
			goto Functionalitymenu;
		}
		goto Functionalitymenu;
	
	/////////////////////////////////////APPLICATION CLOSING///////////////////////////////////////////////////////
		if(select == "E" && select == "e") 
		{
			goto Exitapplication;
			
		}
		
} 
//till now , my larger array of users is dynamic and main user is dynamic , remember to delete the space