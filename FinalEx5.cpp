/*
5) Write a program that lets the user enter a charge account number. The program should determine if the number is 
valid by checking  for it in the following list :

5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4568555, 5050552, 
782877, 1250255, 5552012, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002

The list of numbers above should be initialized in a singe on-dimensional array. A simple linear search should be
used to locate the number entered by the user. If the user enters a number that is in the array, the program should display
a message saying that the number is valid. If the user enters a number that is not in the array, the program should display
a message indicating that the number is invalid.
*/
#include<iostream>

using namespace std;

void checkAccount(int list[], int listlength, int check);
int main()
{
	int acc[18] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4568555, 5050552, 782877, 1250255, 5552012, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
	int accCheck; //account in question
	int length = sizeof(acc)/sizeof(acc[0]); //Length of array doesn't change, but if accounts could be added, this will help adapt it
	char cont; //continue program variable
	bool menu = true; //allows for a loop of main program
	
	cout << "Welcome to Account Validator 2022" << endl << endl;
	
while(menu) //Loop to be able to run program again
{
	cout << "Please enter your Seven (7) digit account number" << endl;
	cin >> accCheck; //User entered number to verify against accounts
	if(cin.fail())
	{
		cout << "Please enter a valid Seven (7) digit Account number" << endl;
		cin >> accCheck;
	}
	else if(accCheck < 1000000 || accCheck > 9999999) // Checking to see if account is 7 digits
	{
		cout << "Please enter a valid seven (7) digit account number" << endl;
		cin >> accCheck;
	}
	else checkAccount(acc, length, accCheck); 
	
	bool checkagain = true;
	
	while(checkagain) //Menu to Run program again
	{
	    cout << "Would you like to verify another account? (Y/N)" << endl;
	    cin >> cont;
	    if(cont == 'Y' || cont == 'y')
	    {
	        menu = true;
	        checkagain = false;
	    }
	else if(cont == 'N' || cont == 'n')
	    {
	        cout << "Thank you for using Account Validator 2022. Goodbye!" << endl;
	        menu = false;
	        checkagain = false;
	    }
	else cout << "Invalid Response";
    }	
}
	return 0;
}
void checkAccount(int list[], int listLength, int check)
{
	bool valid = false; //Need to initialize it as false otherwise the check doesn't work the way I have it set up
	
	for(int i = 0; i < listLength; i++)
	{		
		if(list[i] == check)
			valid = true; //If one of the account numbers matches the check it stores a bool. This could be a try catch block
	}
	if(valid) cout << "Valid account" << endl;
	else if(!valid) cout << "Invalid account" << endl;
}