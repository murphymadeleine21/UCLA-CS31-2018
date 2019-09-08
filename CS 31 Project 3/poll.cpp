//
//  main.cpp
//  poll.cpp
//
//  Created by Madeleine Murphy on 10/28/18.
//  Copyright © 2018 Madeleine Murphy. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

//This project essentially uses multiple different functions to split up the strings into smaller chunks and check those chunks to make sure they are in the proper format in the main bool hasProperSyntax function we are required to write. Then, the function int tallySeats will take an inputted string, party, and seatTally value and return to you the new seatTally, as long as the string is in the correct format


int tallySeats(string pollData, char party, int& seatTally);
bool hasProperSyntax(string pollData);
bool checkPartyChunks(string pC);
void stateCodeLetters(string &sC);
bool isValidUppercaseStateCode(string stateCodeLetters);
bool hasSpaces(string pollData);
bool validateStateNug(string pollData);


bool hasSpaces(string pollData)        //checks for any spaces
{
    for (int k = 0; k != pollData.size(); k++)
    {
        if (pollData[k] == ' ')
            return true;
    }
    return false;
}

//each "stateNug" is a string within the total string separated by commas
//validStateNug checks that each stateNug is in the proper format
bool validateStateNug(string pollData)
{
    // cout << pollData << endl; //COMMENT OUT
    string stateCode = pollData.substr(0, 2);
    stateCodeLetters(stateCode);            //sends first two letters of string to upper case
    // cout << stateCode << endl; //
    
    if (!isValidUppercaseStateCode(stateCode))      //checks that they are valid upper case state code
    {
        // cout << "failing" << endl;      //COMMENT OUT
        return false;
    }
    
    if (pollData.size() == 2)
        return true;
    else
    {
        string partyResults = pollData.substr(2);       //takes the rest of the substring
        // cout << partyResults << endl; //COMMENT OUT
        string partyChunks = "";
        for (int k = 0; k != partyResults.size(); k++)
        {
            partyChunks += partyResults[k];     //partyChunks are the party results (e.g. 14D)
            if (isalpha(partyResults[k]))
            {
                // cout << partyChunks << endl; //COMMENT OUT
                if (!checkPartyChunks(partyChunks))         //sends new partyChunks string to checkPartyChunks
                    return false;
                else
                    partyChunks = "";
            }
            if (k == partyResults.size()-1 && !isalpha(partyResults[k]))
                return false;
        }
    }
    
    return true;
}

bool checkPartyChunks(string pC)        //checks that party results are valid
{
    if (pC.size() > 3)
        return false;
    
    if (pC.size() == 2)     //if pc size = 2, must be one digit followed by a letter (e.g. 1R)
    {
        if (!(isdigit(pC[0]) && isalpha(pC[1])))
            return false;
        else
            return true;
    }
    
    if (pC.size() == 3)     //if pc size = 3, must be two digits followed by a letter (e.g. 14D)
    {
        if (!(isdigit(pC[0]) && isdigit(pC[1]) && isalpha(pC[2])))
        {
            return false;
        }
        else
            return true;
    }
    
    return false;
 
 }

void stateCodeLetters(string& sC)       //takes first 2 lower case letters and converts them to upper case
{
    string result = "";
    for (int i = 0; i < 2; i++)
    {
        if ( isupper(sC[i]) )
            result += sC[i];
        if ( islower(sC[i]) )
            result += toupper(sC[i]);
    }
    
    sC = result;
    //cout << result; COMMENT OUT //
}


// Return true if the argument is a two-uppercase-letter state code, or
// false otherwise.
//takes converted uppercase sC and checks if its valid
bool isValidUppercaseStateCode(string stateCodeLetters)
{
    const string codes =
    "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
    "LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
    "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCodeLetters.size() == 2  &&
            stateCodeLetters.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCodeLetters) != string::npos);  // match found
}


//******************************************************/
/*
 //CHECKING IF FIRST PART WORKS FOR IDENTIFYING A 2 LETTER UPPERCASE STATE CODE & spaces
//COMMENT OUT
 int main()
 {
     string pD = "KS4R, NV3D1R";
     if (hasProperSyntax(pD))
         cout << "yeet!" << endl;
     else
         cout << "eek!" << endl;
     int tS = -3;
     int hehe = tallySeats(pD, 'i', tS);
     cout << hehe << endl;
     cout << tS << endl;
 }
 */
//***************************************************//



//One of 2 main functions, calls other functions above to check that inputted string has proper syntax
bool hasProperSyntax(string pollData)
{
    if (pollData == "")         //empty string case
        return true;
    if (hasSpaces(pollData))       //if a string has spaces, automatically knows it's invalid
        return false;
    
    string stateNug = "";
    for (int k = 0; k != pollData.size(); k++)
    {
        if (pollData[k] != ',')         //reads through to every comma and breaks string into stateNugs
        {
            stateNug += pollData[k];        //stateNug now = up to first comma
            if (k == pollData.size()-1)
            {
                // cout << stateNug << endl;  //COMMENT OUT LATER
                if (validateStateNug(stateNug))     //checks each stateNug
                    stateNug = "";                  //resets stateNug string once true
                else
                    return false;
                break;
            }
        }
        else                    //if it's a comma
        {
            //cout << stateNug << "haha" << endl; //COMMENT OUT LATER
            if (validateStateNug(stateNug))     //checks its valid stateNug
                stateNug = "";                  //makes string empty and moves on
            else
                return false;
        }
    }
    
    if (pollData[0] == ',' || pollData[pollData.size()-1] == ',') //can't start or end with a comma
    {
        return false;
    }
    else
        return true;
    
    return false;
}



int tallySeats(string pollData, char party, int& seatTally)
{
    int origSeatTally = seatTally;
    seatTally = 0;
    
    if (!hasProperSyntax(pollData))     //if fails properSyntax test, then will return original seatTally value and 1
    {
        seatTally = origSeatTally;
        return 1;
    }
    if (!isalpha(party))        // if party is not a letter, return 2
    {
        seatTally = origSeatTally;
        return 2;
    }
    for (int k = 2; k != pollData.size(); k++)          //tallys seats for specified party
    {
        if (toupper(pollData[k]) == toupper(party))
        {
            if (!isdigit(pollData[k-1]))
                break;
            else if (isdigit(pollData[k-2]))
            {
                seatTally += 10*(pollData[k-2]-'0');
                // cout << seatTally << endl;      //comment out
                seatTally += (pollData[k-1]-'0');
                // cout << seatTally << endl;      //comment out
            }
            else
                seatTally += (pollData[k-1]-'0');
        }
    }
    return 0;
    
}


