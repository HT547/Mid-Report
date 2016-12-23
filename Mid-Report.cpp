/*Name: 1. M. Umar Allauddin
2. Hassan Tahir

Mid Report: Bingo
*/
#include <iostream>
#include <iomanip>

using namespace std;

class Bingo
{
protected:
	int arr[5][5];
public:
	int validate_Card(int arr[5][5], int a, int b)  //function to check that the cards allocated are valid or no

	{
		if (arr[a][b] <= 0 || arr[a][b] > 25)  //checks if the cards are in the desired range
			return 0;
		for (int i = 0; i <= a; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == a &&j == b)
					return 1;
				if (arr[a][b] == arr[i][j])  //checks if the numbers are being repeated or not
					return 0;
			}
		}
		return 1;
	}
	// assigning 0 to values which the user and the computer asks to strike
	int move(int x)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr[i][j] == x) // striken number 'x' is located in the array through nested loop---finding the number in the array
				{
					arr[i][j] = 0; //and then is replaced by zero
					return 1;
				}
			}
		}
		return 0;
	}
};
class Player : public Bingo  // Player class inheriting from Bingo class
{
public:
	// function to allow card input
	void enter_Card()
	{
		for (int i = 0; i<5; i++)
		{
			for (int j = 0; j<5; j++)
			{
				cin >> arr[i][j];
				if (!validate_Card(arr, i, j))                       // condition to check card validity
				{
					cout << "The card entered is invalid. Re-enter!" << endl;
				}
			}
		}
	}

	// function to display card
	void displayPl()
	{
		for (int i = 0; i<5; i++)
		{
			for (int j = 0; j<5; j++)
			{
				if (arr[i][j] != 0)
					cout << arr[i][j] << "   ";
				else
					cout << "X   ";
			}
			cout << "\n";
		}
	}

};
class Computer : public Bingo {};

void main() {

	cout << "---------------        Welcome to the Bingo        ---------------\n";

	int x, ch;
	Player mycard;  // declaring Player class object
	Computer compcard;  // declaring Computer class object
	do
	{
		cout << "\n\nEnter 1 for Single Player Game(vs Comp.)";
		cout << "\nEnter 2 to Go back to the Main Screen\n";
		cin >> ch;
		if (ch == 2) {
			main();
			cout << "\n\n";
		}

		else if (ch == 1)
		{
			int chance = 1, t;
			cout << "\n\nPlease Input Your Card\n";
			mycard.enter_Card();
			mycard.displayPl();

			if (chance == 1)
			{

				cout << "Enter Number To be Striken:";
				cin >> x;
				while (!mycard.move(x))
				{
					cout << "Enter Valid Number To be Striken:";
					cin >> x;
				}
				compcard.move(x);
				chance *= -1;

				cout << "Computer's Card" << endl;
				cout << "\nYour Card\n";
				mycard.displayPl();
			}
			else
			{
				cout << "Computer's Card\n";
				cout << "\nYour Card\n";
				mycard.displayPl();
				chance *= -1;

			}
		}
	} while (ch != 3);

}
