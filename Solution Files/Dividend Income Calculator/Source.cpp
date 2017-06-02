//Calculates the amount of annual dividend income that the user can receive from a stock purchase.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	char again = 'n';
	char anotherStock = 'n';
	string stockName;
	double investAmount, stockPrice, annualizedDiv, divIncome;

	ofstream outFile;
	outFile.open("Dividend Income Comparison Chart.txt");

	cout << "Dividend Income Calculator" << endl;
	outFile << "Dividend Income Calculator" << endl;

	do
	{
		cout << endl << "Amount to invest: $";
		outFile << endl << "Amount to invest: $";
		cin >> investAmount;
		cin.ignore();

		outFile << investAmount << endl << endl;
		outFile << "Ticker\tAnnual Income" << endl;
		outFile << "----------------------------------------------------" << endl;
		
		do {
			cout << endl << "Stock ticker: ";
			getline(cin, stockName);
			outFile << stockName << "\t";
			
			cout << "Current stock price (per share): $";
			cin >> stockPrice;

			cout << "Annualized dividend amount (per share): $";
			cin >> annualizedDiv;

			divIncome = investAmount / stockPrice * annualizedDiv;

			cout << endl << "Dividend income per year: $" << fixed << setprecision(2) << divIncome << endl << endl;
			outFile << "$" << fixed << setprecision(2) << right << divIncome << endl;

			cout << "Do you want to compare another stock? (y/n): ";
			cin >> anotherStock;
			cin.ignore();
			
		} while (anotherStock == 'y' || anotherStock == 'Y');
		
		outFile << endl << endl;
		cout << "Do you want to run the program again? (y/n): ";
		cin >> again;
		cin.ignore();

	} while (again == 'y' || again == 'Y');

	outFile.close();

	cout << endl;
	system("PAUSE");
	return 0;
}