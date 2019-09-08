//
//  main.cpp
//  rental.cpp
//
//  Created by Madeleine Murphy on 10/13/18.
//  Copyright © 2018 Madeleine Murphy. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int main()
{
    cout << "Odometer at start: ";
    int odometerStart;
    cin >> odometerStart;
    
    cout << "Odometer at end: ";
    int odometerEnd;
    cin >> odometerEnd;
    
    cout << "Rental days: ";
    int rentalDays;
    cin >> rentalDays;
    cin.ignore(10000, '\n'); //must do when going from int to string
    
    cout << "Customer name: ";
    string customerName;
    getline(cin, customerName);
    
    cout << "Luxury car? (y/n): ";
    string luxuryStatus;
    getline(cin, luxuryStatus);
    
    cout << "Month (1=Jan, 2=Feb, etc.): ";
    int month;
    cin >> month;
    
    int baseRate; //this following if/else statement sets up base charge for a rental
    if (luxuryStatus == "n")
        baseRate = 33*rentalDays;
    else
        baseRate = 61*rentalDays;
    
    double rentalCharge = 0.0;
    int totalMiles = odometerEnd - odometerStart;
    
    if (totalMiles <= 100) //sets up charge if miles driven is less than 100
        rentalCharge = baseRate + (0.27*totalMiles);
    else if (totalMiles > 100) //determines charge if miles driven is over 100
    {
    if (month == 4 || month == 5 || month == 6 || month == 7 || month == 8 || month == 9 || month == 10 || month == 11) //non-winter months have specific charge
    {   if (totalMiles <= 400) //for next 300 miles after 100 calculation
            rentalCharge = baseRate + (0.27*100) + 0.21*(totalMiles - 100);
        else if (totalMiles > 400) //if miles driven = more than 400, there is an additional charge for miles over 400
            rentalCharge = baseRate + (0.27*100) + (0.21*300) + 0.19*(totalMiles-400); //took a while to figure out math, see report
    }
    else if (month == 1 || month == 2 || month == 3 || month == 12) //winter months have their own charges as well
    {
        if (totalMiles <= 400)
            rentalCharge = baseRate + (0.27*100) + 0.27*(totalMiles - 100);
        else if (totalMiles > 400)
            rentalCharge = baseRate + (0.27*100) + (0.27*300) + 0.19*(totalMiles-400);
    }
    }
    
    cout << "---" << endl;
                            //series of if/else if statements that are outputted if there is an error in the input from the user. else if ensures that only one statement will be outputted, even if there are multiple errors
    if (odometerStart <=0)
        cout << "The starting odometer reading must be nonnegative." << endl;
    
    else if (odometerEnd < odometerStart)
        cout << "The final odometer reading must be at least as large as the starting reading." << endl;
        
    else if (rentalDays <=0)
        cout << "The number of rental days must be positive." << endl;
        
    else if (customerName.size() == 0) //making sure a customer name is entered by checking that string length is not 0
        cout << "You must enter a customer name." << endl;

    else if (luxuryStatus != "n" && luxuryStatus != "y")
        cout << "You must enter y or n." <<endl;
    
    else if (month != 1 && month != 2 && month != 3 && month != 2 && month != 4 && month != 5 && month != 6 && month != 7 && month != 8 && month != 9 && month != 10 && month != 11 && month != 12)
        cout << "The month number must be in the range 1 through 12." << endl;
    
    else
    {   cout.setf(ios::fixed);
        cout.precision(2);
        cout << "The rental charge for " << customerName << " is $" << rentalCharge << endl;
    }
}

