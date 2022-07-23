

#include <iostream>
#include"windows.h"

using std::cin;
using std::cout;
int main()
{
	int choice;

	while (1)
	{
		cout << "To enter the Admin Window Enter 1\nto enter the CLient window Enter 2";
	    cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "To create an account press 1\n To change an account setting press 2,to return to the main menu press 3";
			cin >> choice;
			switch (choice)
			{
			case(1):
				{
				std::string name, address,Gaurdian;
				int age;
				std::array<int, 14> NationalID, GaurdianID;
				
				cout << "enter your name";
				cin >> name;
				cout << "enter your address";
				cin >> address;
				cout << "enter your ID and after each digit press enter";
				for (auto& num : NationalID)
				{
					cin >> num;
				}
				cout << "enter your age";
					cin >> age;
					if (age < 21)
					{
						cout << "Enter your Gaurdian name";
						cin >> Gaurdian;
						cout << "Enter your Gaurdian ID and after each digit  press enter";
						for (auto& num : GaurdianID)
						{
							cin >> num;
						}
				}
				   
					std::pair<std::array<int, 10>, std::array<int, 8>> accINFO;
					accINFO=Admin::CreateAccount(name, address, NationalID, age, Gaurdian, GaurdianID);
					cout << "your BacnkID is";
					for (auto num : accINFO.first)
					{
						cout << num;
					}
					cout << "\n";

					std::cout << "your password is";
					for (auto num : accINFO.second)
					{
						cout << num;
					}
					cout << "\n";
					

				break;
				}
			case(2):

			{
				std::cout << "To make a transaction press 1\nTo Get cash press 2\n To deposit cash press 3\n To change password press 4\n To return to the main menu press 5 ";
					cin >> choice;
					switch (choice)
					{

					case(1):
					{
						std::array<int, 10>transferID, transfreeID;
						cout << "Enter the ID of the transfer account ,press enter after each digit";
						for (auto& num : transferID)
						{
							cin >> num;
						}
						cout << "Enter the ID of the transfee account ,press enter after each digit";
						for (auto& num : transfeeID)
						{
							cin >> num;
						}

						Admin::MakeTransaction()
						break;
					}
					case (2):
					{


						break;
					}
					case (3):
					{


						break;
					}
					case (4):
					{


						break;
					}
					case (5):
					{


						break;
					}
					}


				break;
			}

			case (3):
			{


				break;
			}




			}

			break;
		}


		case 2:
		{



			break;
		}
		default:
			cout << "enter the a viable choice";
			break;




		}



	}


}

