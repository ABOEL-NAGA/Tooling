#pragma once
#include<string>
#include <vector>
#include<algorithm>
#include<array>
#include<random>
#include<utility>

enum class status
{
	closed,
	active,
	suspended
};
struct account
{
	std::string Name;
	std::string Address;
	 std::array<int,14> NationalID;
	int Age;
	std::array<int, 10> BankAccID;

	std::string Gaurdian;
	std::array<int, 14> GaurdianID;
	int Balance;
	std::array<int, 8> Password;
	status State;



	account(std::string name, std::string address, std::array<int, 14> nationalID, int age, std::string gaurdian,  std::array<int, 14> gaurdianID): Name(name),Age(age),Address(address),Gaurdian(gaurdian),State(0),Balance(0)

	{
		
		std::copy(std::begin(NationalID), std::end(NationalID), nationalID);
		std::copy(std::begin(GaurdianID), std::end(GaurdianID), gaurdianID);
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist9(0, 9);
		for (auto& num : BankAccID)
		{
			num = dist9(rng);
		}

		for (auto& num : Password)
		{
			num = dist9(rng);
		}

		 
		
	}
};

class Person
{
protected:
	static std::vector<account*> Accounts;

public:
	
   static  bool MakeTransaction(std::array<int, 10> TransferID, std::array<int, 10> TransfreeID, int sum);
	static bool GetCash(std::array<int, 10> ID, int sum);
	static void deposit(std::array<int, 10> ID, int sum);

};

bool Person::MakeTransaction(std::array<int, 10> TransferID, std::array<int, 10> TransfreeID, int sum)
{
	auto Transfer = std::find_if(std::begin(Accounts), std::end(Accounts), [TransferID](account* ACC)
		{
			return ACC->BankAccID == TransferID;


		}
	);

	auto Transfree = std::find_if(std::begin(Accounts), std::end(Accounts), [TransfreeID](account* ACC)
		{
			return ACC->BankAccID == TransfreeID;


		}
	);
	if ((*Transfer)->Balance > sum)
	{
		(*Transfer)->Balance -= sum;
	}
	else return false;

	(*Transfree)->Balance += sum;



	return true;

}

bool Person::GetCash(std::array<int, 10> ID, int sum)
{
	auto Customer = std::find_if(std::begin(Accounts), std::end(Accounts), [ID](account* ACC)
		{
			return ACC->BankAccID == ID;


		}
	);

	if ((*Customer)->Balance >= sum)
	{
		(*Customer)->Balance -= sum;
	}
	else return false;

	return true;

}

void Person::deposit(std::array<int, 10> ID, int sum)
{
	auto Customer = std::find_if(std::begin(Accounts), std::end(Accounts), [ID](account* ACC)
		{
			return ACC->BankAccID == ID;


		}
	);

		(*Customer)->Balance += sum;
	
}
class Admin :public Person
{
private:
	
public:
	static std::pair<std::array<int,10>, std::array<int ,8>> CreateAccount(std::string name, std::string address, std::array<int, 14> NationalID, int age, std::string Gaurdian, std::array<int, 14> GaurdianID);
	
	static void ChangeStatus(std::array<int, 10> ID, int status);
	
};


std::pair<std::array<int, 10>, std::array<int, 8>> Admin::CreateAccount(std::string name, std::string address, std::array<int, 14> NationalID, int age, std::string Gaurdian, std::array<int, 14> GaurdianID)
{
	 account* ACC =  new account(name, address, NationalID, age, Gaurdian, GaurdianID);
	  std::array<int, 10> ID = ACC->BankAccID;
	  std::array<int, 8> password = ACC->Password;
	  std::pair<std::array<int, 10>, std::array<int, 8>> accINFO;
	  accINFO.first = ID;
	  accINFO.second = password;

	Accounts.push_back(ACC);
	return accINFO;


}
void Admin::ChangeStatus(std::array<int, 10> ID, int status)
{
	auto Customer = std::find_if(std::begin(Accounts), std::end(Accounts), [ID](account* ACC)
		{
			return ACC->BankAccID == ID;
			

		}
	);
	(*Customer)->State = status;

}

class Client :public Person
{
	static void change_password(std::array<int, 10> ID, std::array<int, 8> password);
};


void Client::change_password(std::array<int, 10> ID, std::array<int, 8> password)
{
	auto Customer = std::find_if(std::begin(Accounts), std::end(Accounts), [ID](account* ACC)
		{
			return ACC->BankAccID == ID;


		}
	);
	(*Customer)->Password = password;
		

}
