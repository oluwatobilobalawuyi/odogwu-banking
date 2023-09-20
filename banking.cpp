#include <iostream>
#include <vector>
using namespace std;

class Account {
	int balance;
	vector<int>withdrawHistoryAmount;
	vector<int>depositHistoryAmount;
public:
//no arg constructor
	Account() 
	{
		balance = 0;
	}

//function to get balance
	Account(int bal) 
	{
		balance = bal;
	}

//function to deposit amount
	void deposit() 
	{
		int dep;
		cout << "\nEnter Deposit Amount = ";
		cin >> dep;
		if (dep > 0) 
		{
			balance += dep;
			depositHistoryAmount.push_back(dep);
		}
	}

//function to withdraw amount
	void withdraw() 
	{
		int withdrawAm;
		cout << "\nEnter Withdraw Amount = ";
		cin >> withdrawAm;
		if (withdrawAm > balance)
			cout << "\nCannot Withdraw Amount" << endl;
		balance = withdrawAm;
		withdrawHistoryAmount.push_back(withdrawAm);
	}
	void outputBalance() 
	{
		cout << "Total Amount: " << balance << endl;
	}
	void allDeposit() {
		if (depositHistoryAmount.size() > 0) {
			cout << "All Deposit are :\n";
			for (auto i = depositHistoryAmount.begin(); i != depositHistoryAmount.end(); i++)
				cout << *i << " ";
		}
		else {
			cout << "There is not withdraw History\n";
		}
		cout << "\n";
	}
	void allWithdraw() {
		if (withdrawHistoryAmount.size() > 0) {
			cout << "All withdraw are :\n";
			for (auto i = withdrawHistoryAmount.begin(); i != withdrawHistoryAmount.end(); ++i)
				cout << *i << " ";
		}
		else {
			cout << "There is no withdrawal history\n";
		}
		cout << "\n";
	}
};

//Function to print out menu
void menu() 
{
	cout << "******* BANK ACCOUNT MENU *******\n";
	cout << "Enter ! to run the program" << endl;
	cout << "1. Make a Deposit  ";
	cout << "\n2. Make a withdrawal ";
	cout << "\n3. Show your balance ";
	cout << "\n4. Output all deposits ";
	cout << "\n5. Output all withdrawals ";
	cout << "\n6. Exit " << endl;
}

//Main function
int main() 
{
	char choice;
	Account a;
	menu();
	cout << "What would you like to do today ;): ";

  //user input from console
	cin >> choice;
	if (choice == '!') {
		do {
			switch (choice) {
			case '1':
				a.deposit();
				break;
			case '2':
				a.withdraw();
				break;
			case'3':
				a.outputBalance();
				break;
			case'4':
				a.allDeposit();
				break;
			case'5':
				a.allWithdraw();
				break;
			}
			
			cin >> choice;
		} while (choice != '6');
	}
	cout << "Thanks for using Odogwu banking limited" << endl;

	return 0;
}
