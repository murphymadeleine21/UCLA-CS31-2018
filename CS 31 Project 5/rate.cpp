//
//  main.cpp
//  rate.cpp
//
//  Created by Madeleine Murphy on 11/11/18.
//  Copyright © 2018 Madeleine Murphy. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
using namespace std;



const int MAX_WORD_LENGTH = 20;
int makeProper(char word1[][MAX_WORD_LENGTH+1],
               char word2[][MAX_WORD_LENGTH+1],
               int separation[],
               int nPatterns);

int rate(const char document[],
         const char word1[][MAX_WORD_LENGTH+1],
         const char word2[][MAX_WORD_LENGTH+1],
         const int separation[],
         int nPatterns);


int makeProper(char word1[][MAX_WORD_LENGTH+1],
               char word2[][MAX_WORD_LENGTH+1],
               int separation[],
               int nPatterns)
{
    if (nPatterns < 0)  //treat negative nPatterns as if its 0
        nPatterns = 0;
    
    for(int i = 0; i < nPatterns; i++){
        bool isBad = false;
        int j = 0;
        int length1 = 0;
        if(word1[i][j]=='\0')
            isBad = true;     //if a word contains no characters
        else while(word1[i][j] != '\0'){
            if (!isupper(word1[i][j]) && !islower(word1[i][j]))
                isBad = true;   //if a word contains something other than a letter
            else    //make lower case
            {
                word1[i][j] = tolower(word1[i][j]);
                length1++;
            }
            j++;
        }
        word1[i][length1] = '\0';   //null terminate
        
        //repeat steps for word2 in the pattern
        int h = 0;
        int length2 = 0;
        if(word2[i][h]=='\0')
            isBad = true;
        else while(word2[i][h] != '\0'){
            if (!isupper(word2[i][h]) && !islower(word2[i][h]))
                isBad = true;
            else
            {
                word2[i][h] = tolower(word2[i][h]);
                length2++;
            }
            h++;
        }
        word2[i][length2] = '\0';   //null terminate
        
        if (separation[i] < 0)
            isBad = true;
        if (isBad){
            for(int k = 0; k < MAX_WORD_LENGTH+1; k++){
                word1[i][k] = '\0';
                word2[i][k] = '\0';
            }
        }
    }
    
    
    for (int i = 0; i < nPatterns-1; i++)   //Now check if any patterns have same words
    {
        
        for (int k = i+1; k < nPatterns; k++){
            
            if (word1[i][0] == '\0')
                break;
            if (strcmp(word1[i], word1[k]) == 0 && strcmp(word2[i], word2[k]) == 0){    //if they have same words in pattern
                if (separation[i] > separation[k]){     //delete one with lower separation
                    for(int j = 0; j < MAX_WORD_LENGTH+1; j++){
                        word1[k][j] = '\0';
                        word2[k][j] = '\0';
                    }
                }
                else {
                    for(int j = 0; j < MAX_WORD_LENGTH+1; j++){ //delete if first has lower separation or equal separation
                        word1[i][j] = '\0';
                        word2[i][j] = '\0';
                    }
                }
            }
            else if (strcmp(word1[i], word2[k]) == 0 && strcmp(word1[k], word2[i]) == 0){
                if (separation[i] > separation[k]){     //delete one with lower separation
                    for(int j = 0; j < MAX_WORD_LENGTH+1; j++){
                        word1[k][j] = '\0';
                        word2[k][j] = '\0';
                    }
                }
                else {
                    for(int j = 0; j < MAX_WORD_LENGTH+1; j++){ //delete if first has lower separation or equal separation
                        word1[i][j] = '\0';
                        word2[i][j] = '\0';
                    }
                    
                }
            }
        }
    }
    
    char temp1[10000][MAX_WORD_LENGTH+1]; //create c string arrays of arbitrarily large size
    char temp2[10000][MAX_WORD_LENGTH+1];
    int temp3[10000];
    int count1 = 0;
    int count2 = 0;
    int count3 =0;
    
    
    for (int k = 0; k < nPatterns; k++){
        if(word1[k][0] != '\0'){            //copy all valid arrays into new array
            strcpy(temp1[count1], word1[k]);
            temp3[count3] = separation[k];
            count1++;
            count3++;
        }
        
        if (word2[k][0] != '\0'){
            strcpy(temp2[count2], word2[k]);
            count2++;
        }
    }
    
    if (count1 == 0 && count2 == 0) //if all strings in array are invalid, return 0
        return 0;
    
    for (int j = 0; j < nPatterns; j++){        //copy new arrays with valid strings into original arrays
        strcpy(word1[j], temp1[j]);
        strcpy(word2[j], temp2[j]);
        separation[j] = temp3[j];
    }
    //it doesn't matter what is in array after the valid strings, so don't need to do anything to those elements
    

    return count1;
};

int rate(const char document[],
         const char word1[][MAX_WORD_LENGTH+1],
         const char word2[][MAX_WORD_LENGTH+1],
         const int separation[],
         int nPatterns)
{
    
    if (nPatterns < 0)  //treat a negative nPatterns as if it were 0
        nPatterns = 0;
    
    char tempDoc[251][10000];
    int wordCount = 0;
    int charCount = 0;
    
         
    for (int k = 0; k < 251; k++)
    {
        if (isalpha(document[k])){      //if its a letter, put it in the new temp document
            tempDoc[wordCount][charCount] = tolower(document[k]);    //uppercase treated like lowercase
            charCount++;
        }
        else if (document[k] == ' ')
        {
            tempDoc[wordCount][charCount] = '\0';
            wordCount++;
            charCount = 0;
        }
        else if (document[k] == '\0'){
            tempDoc[wordCount][charCount] = '\0';
            wordCount++;
            break;
        }
        
    }
 
    int rate = 0;
    
    int emptyWords = 0;
    for (int j = 0; j < wordCount; j++){        //count how many empty words we have
        if (tempDoc[j][0] == '\0')
            emptyWords++;
    }
    
    if (emptyWords == wordCount)                //if every word is empty, no valid words, return 0
        return 0;
            
    
    for (int m = 0; m < nPatterns; m++){        //now we calculate the rate
        bool foundPattern = false;
        for(int i = 0; i < wordCount; i++)
        {
            for (int k = 0; tempDoc[i][k] != '\0'; k++){
                if (foundPattern) break;
                if (k >= 1) break;      //we don't need to keep doing this, just check if the first char is nullbyte
                    if (strcmp(tempDoc[i], word1[m]) == 0){     //if we find word1 in the document
                        for (int j = 0; j < wordCount; j++){
                            if (strcmp(tempDoc[j], word2[m]) == 0 && j-i-1 <= separation[m] && j-i-1 >= 0){
                                rate++;
                                foundPattern = true;
                                break;
                            }
                        }
                    }
                    else if (strcmp(tempDoc[i], word2[m]) == 0){    //if we find word 2 in the document
                        for (int j = 0; j < wordCount; j++)
                            if (strcmp(tempDoc[j], word1[m]) == 0 && j-i-1 <= separation[m] && j-i-1 >= 0){
                                foundPattern = true;
                                rate++;
                                break;
                            }
                    }
                
            }
            if (foundPattern) break;
        }
        
    }
    
    
    return rate;
}

int main() {
    //test with given complicated example that it reduces down to four
    char firstTest1[8][MAX_WORD_LENGTH+1] = {"mad", "deranged", "NEFARIOUS", "half-witted", "robot", "plot", "have", "NeFaRiOuS"};
    char firstTest2[8][MAX_WORD_LENGTH+1] = {"scientist", "robot", "PLOT", "assistant", "deranged", "Nefarious", "mad", "pLoT"};
    int separation1[8] = {1, 3, 0, 2, 1, 0, 12, 0};
    int nPatterns1 = 8;
    assert(makeProper(firstTest1, firstTest2, separation1, nPatterns1) == 4);
   
    const int TEST1_NRULES = 4;
    char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "mad",       "deranged", "nefarious", "have"
    };
    char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
        "scientist", "robot",    "plot",      "mad"
    };
    int test1dist[TEST1_NRULES] = {
        1,           3,          0,           12
    };
    
    int z = rate("  That plot: NEFARIOUS!",
                 test1w1, test1w2, test1dist, TEST1_NRULES);
            cout << z << endl;
    
    assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot.",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    assert(rate("The mad UCLA scientist unleashed    a deranged robot.",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
    assert(rate("**** 2018 ****",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    assert(rate("  That plot: NEFARIOUS!",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    assert(rate("deranged deranged robot deranged robot robot",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
    assert(rate("That scientist said two mad scientists suffer from deranged-robot fever.",
                test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
    assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot.", test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
   
    
    int test2dist[TEST1_NRULES] = {
        1, -1, 0, 12};
    assert(makeProper(test1w1, test1w2, test2dist, TEST1_NRULES) == 3); //check that it gets rid of negative values
     int test4dist[TEST1_NRULES] ={
        -1, -1, -1, -12};
    int test5dist[TEST1_NRULES] ={
        -1, -1, 0, -12};
    assert(makeProper(test1w1, test1w2, test5dist, TEST1_NRULES) == 1); //check if one value is still proper
    assert(makeProper(test1w1, test1w2, test4dist, TEST1_NRULES) == 0); //check that it gets rid of negative values
    
    
  
    const int TEST2_NRULES = 7;
    char test2w1[TEST2_NRULES][MAX_WORD_LENGTH+1] = { "rick", "morty", "beth", "summer", "birdperson", "mr", "wubbalubbadubdub" };
    char test2w2[TEST2_NRULES][MAX_WORD_LENGTH+1] = { "morty", "jessica", "husband", "popular", "tammy", "poopybutthole", "rick"};
    int test3dist[TEST2_NRULES] = {1, 2, 3, 3, 2, 0, 5};
 
    
   
    assert(makeProper(test2w1, test2w2, test3dist, TEST2_NRULES) == 7);
    assert(rate("Rick and morty love it when rick says wubbalubbadubdub", test2w1, test2w2, test3dist, TEST2_NRULES) == 2);
    assert(rate("Summer is the most popular girl in school", test2w1, test2w2, test3dist, TEST2_NRULES) == 1);
    assert(rate("Morty is in love with Jessica", test2w1, test2w2, test3dist, TEST2_NRULES) == 0);
    assert(rate("Beth hates her husband. Mr. Poopybutthole says 'oooweee' a lot!", test2w1, test2w2, test3dist, TEST2_NRULES) == 2);    //check with periods and other non-letter characters in between
    assert(rate("rick morty morty jessica beth husband summer popular birdperson tammy mr poopybutthole rick wubbalubbadubdub", test2w1, test2w2, test3dist, TEST2_NRULES) == 7);//check if all words are in there
    assert(rate("Hello, how are you rick?", test2w1, test2w2, test3dist, TEST2_NRULES) == 0); //check if one word is in there
    assert(rate("Rick says wubba lubba dub dub", test2w1, test2w2, test3dist, TEST2_NRULES) == 0);  //check that recognizes spaces, doesn't cound as one word
    assert(rate("Morty morty", test2w1, test2w2, test3dist, TEST2_NRULES) == 0); //both word1s and word2s, but for different pattern
    assert(rate("Birdperson married tam", test2w1, test2w2, test3dist, TEST2_NRULES) == 0); //checks that it doesn't cound half of the word as the word
    assert(rate("rick is mortylicious. summer wants popularity", test2w1, test2w2, test3dist, TEST2_NRULES) == 0); //checks if word is within another word, still doesn't count
    assert(rate("asdjhfadfajhdfahfrmortyasdjkfkadrick", test2w1, test2w2, test3dist, TEST2_NRULES) == 0); //tests if two words are within a bunch of random characters
    assert(rate("87^*rick*4723984 morty", test2w1, test2w2, test3dist, TEST2_NRULES) == 1); //tests that it ignores other random characters
    assert(rate("", test2w1, test2w2, test3dist, TEST2_NRULES) == 0); //test empty string
    assert(rate("%^&*()#!@$", test2w1, test2w2, test3dist, TEST2_NRULES) == 0); //test bad string
    assert(rate("", test2w1, test2w2, test3dist, -1) == 0); //treats negative nPatterns as if its 0
    assert(rate("rick and morty", test2w1, test2w2, test3dist, -12) == 0); //treats negative nPatterns as if its 0

    
    
    const int TEST3_NRULES = 4;
    char test3w1[TEST3_NRULES][MAX_WORD_LENGTH+1] = {"a", "b*b%& b7", "c", "a" };
    char test3w2[TEST3_NRULES][MAX_WORD_LENGTH+1] = {"b", "b", "a", "c" };
    int test6dist[TEST3_NRULES]={1, 1, 3, 1};
    assert(makeProper(test3w1, test3w2, test6dist, TEST3_NRULES) == 2);
    assert(makeProper(test3w1, test3w2, test6dist, -1) == 0); //treat negative nPatterns as if it were 0
    
    cout << "All tests succeeded" << endl;
    

}
