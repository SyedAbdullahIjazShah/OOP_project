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
	//////////////////////////////////////////////DYNAMIC VARIABLES& & LABELS//////////////////////////////////////////////
	

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
	/////////////////////////////////////COMMENT POST READING///////////////////////////////////////////////////////
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
	label:
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
		goto label;
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
	cout << "\t\t\t\t\t\tYou logged in as :" << Mainuser->getname() << endl;

	Functionalitymenu:
	select = "";
	cout <<endl<< "Press the any key to see functionalities menu" << endl << endl << endl;
	cin.ignore();
	cin >> select;
	system("_mm_pause");
	system("CLS");
	cout << "________________________________________________________________________________________________________________________________________________________________________\n";
	cout << "***************************************************************** You logged in as :" << Mainuser->getname()<< "* **********************************************************************************\n";
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
	cout << "3 :\tView the list of People who liked your post \t\n";
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
	while (select != "E" && select != "e") {

		if (select == "0")
		{
			goto label;

		}
		else if (select == "1")
		{
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
		}
		else if (select == "3")
		{

		}
		else if (select == "4")
		{

		}
		else if (select == "5")
		{

		}
		else if (select == "6")
		{

		}
		else if (select == "7")
		{

		}
		else if (select == "8")
		{
			/////////////////////////////////////MENU:FRIEND LIST///////////////////////////////////////////////////////
			cout << "\n\tFriends Are As Follows\n";
			for (size_t i = 0; i < acc - 1; i++)
			{
				cout << endl <<"Id: " << friends[i].getuid() << "\t\t Name: " << friends[i].getname() << endl;
			}
		}
		else if (select == "9")
		{

		}
		goto Functionalitymenu;
	}
	/////////////////////////////////////APPLICATION CLOSING///////////////////////////////////////////////////////
		if(select == "E" && select == "e") 
		{
			goto Exitapplication;
			/*cout << "________________________________________________________________________________________________________________________________________________________________________\n";
			cout << "***************************************************************** Application Closed ***********************************************************************************\n";
			cout << "________________________________________________________________________________________________________________________________________________________________________\n";
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n";

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			
				return 0;*/
		}
	
} 
//till now , my larger array of users is dynamic and main user is dynamic , remember to delete the space