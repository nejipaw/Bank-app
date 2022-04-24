#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //Declare variables to store input
    float initInv, monDep, AnuInt, years, months;
    //to store year end total amount
    float totalAm;
    //to store interest and year end interest
    float intAmt, yearTotInt;

    //Display form to user
    cout << "*************************\n";
    cout << "********Data Input*******\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";
    //To get press any key to continue line
    system("PAUSE");

    //Get data from user
    cout << "*************************\n";
    cout << "********Data Input*******\n";
    cout << "Initial Investment Amount: ";
    cin >> initInv;
    cout << "Monthly Deposit: ";
    cin >> monDep;
    cout << "Annual Interest: ";
    cin >> AnuInt;
    cout << "Number of years: ";
    cin >> years;
    months = years * 12;


    system("PAUSE");

    //Set totalAm = initInv
    totalAm = initInv;

    //Display year data without monthly deposits
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {
        //Calculate yearly interest
        intAmt = (totalAm) * ((AnuInt / 100));
        //Calculate year end total
        totalAm = totalAm + intAmt;
        //We set fixed and set precision to show only 2 decimal points
        cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAm << "\t\t\t" << intAmt << "\n";
    }


    //For monthly
    totalAm = initInv;

    //Display year data with monthly deposits
    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";


    for (int i = 0; i < years; i++) {
        //Set yearly interest to zero at the start of the year
        yearTotInt = 0;
        for (int j = 0; j < 12; j++) {
            //Calculate monthly interest
            intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12);
            //Calculate month end interest
            yearTotInt = yearTotInt + intAmt;
            //Calculate month end total
            totalAm = totalAm + monDep + intAmt;

        }
        cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAm << "\t\t\t" << yearTotInt << "\n";

    }

    return 0;

}