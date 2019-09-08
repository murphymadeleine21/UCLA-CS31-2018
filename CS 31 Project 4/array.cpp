//
//  main.cpp
//  array.cpp
//
//  Created by Madeleine Murphy on 11/4/18.
//  Copyright © 2018 Madeleine Murphy. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);


int main()
{
    //string people[6] = { "a", "b", "c", "b", "d", "v" };
    //int j = appendToAll(people, 6, "!!!");
    
    //int j = lookup(people, 6, "ed");
    //cout << j << endl;
    
    // int j = rotateLeft(people, 5, 2);
    /* cout << j << endl;
    cout << people[0] << endl;
    cout << people[1] << endl;
    cout << people[2] << endl;
    cout << people[3] << endl;
    cout << people[4] << endl; */
    
    //int j = positionOfMin(people, 6);
    //cout << j << endl;
    
    //string d[9] = {
    //     "xavier", "betty", "mary", "john", "ed", "clara", "murph", "peter", "john"};
    // int j = countRuns(d, 9);
    
    //int j = flip(d, 9);
    //cout << "official" << endl;
    //string folks[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
    // int q = flip(folks, 4);
 /*   cout << q << endl;
    cout << folks[0] << endl;
    cout << folks[1] << endl;
    cout << folks[2] << endl;
    cout << folks[3] << endl;
    cout << folks[4] << endl;
    cout << folks[5] << endl; */
    //cout << d[6] << endl;
    //cout << d[7] << endl;
    //cout << d[8] << endl;
    
   /* string folks[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
    string group[5] = { "betty", "john", "dianne", "", "xavier" };
    string blah[5] = { "arthur", "john", "dianne", "", "xavier" };
    int r = differ(folks, 6, group, 5);  //  returns 2
    int s = differ(folks, 2, group, 1);  //  returns 1
    int j = differ(blah, 5, group, 5);
    cout << "final" << endl;
    cout << r << endl;
    cout << s << endl;
    cout << j << endl; */
 /*
    string names[10] = { "eleni", "betty", "gavin", "kevin", "greg", "fiona", "betty", "gavin", "kevin"};
    string names1[10] = { "gavin", "kevin", "greg" };
    int t = subsequence(names, 6, names1, 3);  // returns 2
    cout << t << endl;
    string names2[10] = { "eleni", "greg" };
    int u = subsequence(names, 5, names2, 2);  // returns -1
    cout << u << endl;
    string names3[10] = {"eleni", "betty" };    //returns 0
    int j = subsequence(names, 5, names3, 2);
    cout << j << endl;
    string names4[10] = {"betty", "gavin", "kevin"};  //returns 1
    int p = subsequence(names, 5, names4, 3);
    cout << p << endl;
    string names5[10] = {"betty", "gavin", "kevin", "olaf"}; //returns -1
    int r = subsequence(names, 5, names5, 4);
    cout << r << endl;
    string names6[10] = {"betty", "gavin", "kevin"}; //returns 1 even tho appears twice!
    int w = subsequence(names, 9, names6, 3);
    cout << w << endl;
    string colors[10] = {"red", "blue"};        //returns -1
    int c = subsequence(names, 9, colors, 2);
    cout << c << endl;
    
    int q = subsequence(names1, 3, names5, 4);  //returns -1, n2 cannot be > n1
    cout << q << endl;
  */
   
    /*
    string names[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
    string set1[10] = { "dianne", "betty", "greg", "gavin" };
    int v = lookupAny(names, 6, set1, 4);  // returns 1 (a1 has "gavin" there)
    cout << v << endl;
    string set2[10] = { "xavier", "ed" };
    int w = lookupAny(names, 6, set2, 2);  // returns -1 (a1 has none)
    cout << w << endl;
    string set3[10] = { "dianne", "betty", "greg" }; //should return 3?
    int p = lookupAny(names, 6, set3, 3);
    cout << p << endl;
    string set4[10] = { "robert", "cheng", "fiona" }; //5
    int u = lookupAny(names, 6, set4, 3);
    cout << u << endl;
    string set5[10] = { "robert", "cheng", "fiona" }; //-1
    int r = lookupAny(names, 6, set5, -3);  //negative
    cout << r << endl;
    string set6[10] = { "robert", "cheng", "burt" }; //
    int q = lookupAny(set3, 3, set5, 3);
    cout << q << endl;
     */
    
   /*string letters[7] = { "a", "d", "e", "c", "j", "k", "b" };
    string candidate[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
    int x = divide(candidate, 6, "eleni"); //  returns 3
    cout << x << endl;
    cout << candidate[0] << endl;
    cout << candidate[1] << endl;
    cout << candidate[2] << endl;
    cout << candidate[3] << endl;
    cout << candidate[4] << endl;
    cout << candidate[5] << endl;
    */
    

  //ASSERT SEQUENCES

  string h[7] = { "birdperson", "lois", "morty", "chris", "", "rick", "morty" };
  assert(lookup(h, 7, "rick") == 5);
  assert(lookup(h, 7, "morty") == 2);
  assert(lookup(h, 2, "morty") == -1);
  assert(positionOfMax(h, 7) == 5);
  
 
  string g[4] = { "rick", "morty", "summer", "stewie" };
  assert(appendToAll(g, 4, "!!") == 4 && g[0] == "rick!!" && g[3] == "stewie!!");
  assert(rotateLeft(g, 4, 1) == 1 && g[1] == "summer!!" && g[3] == "morty!!");
  
    string people[6] = { "a", "b", "c", "b", "d", "b" };
    int j = appendToAll(people, 6, "!!!");  // returns 6
    assert(j==6);
    assert(people[0]=="a!!!");
    assert(people[1]=="b!!!");
    assert(people[5]=="b!!!");
   
    string humanz[5] = { "gloria", "sam", "bart", "lisa", "stefano" };
    int m = rotateLeft(humanz, 5, 1);
    assert(m==1);
    assert(humanz[0]=="gloria");
    assert(humanz[1]=="bart");
    assert(humanz[2]=="lisa");
    assert(humanz[3]=="stefano");
    assert(humanz[4]=="sam");
    
    
    string humans[6] = { "mark", "niko", "", "mads", "gaby", "colin" };
    int q = flip(humans, 4);
    assert(q==4);
    assert(humans[0]=="mads");
    assert(humans[1]=="");
    assert(humans[2]=="niko");
    assert(humans[3]=="mark");
    assert(humans[4]=="gaby");
    assert(humans[5]=="colin");
    
    string test1[] = {"yuh", "yeet", "yah"};
    string test2[] = {"yuh", "YEET", "yah"};
    
    assert(differ(test1, 1, test2, 1)==1); //the smaller n should be given: 1, both arrays equal
    assert(differ(test1, 2, test2, 1)==1); //verifies that an irrelevant change in size makes no difference
    assert(differ(test1, 1, test2, 2)==1); //same
    assert(differ(test1, 2, test2, 2)==1); //since a difference has been found, the index 1 where it occurs is returned
    assert(differ(test1, 3, test2, 3)==1); //since a difference is found halfway in, the rest of the array doesn't matter
    assert(lookupAny(test1, 1, test2, 1)==0); //first match, 0 is always returned
    assert(lookupAny(test1, 3, test2, 3)==0); //same
    
    string d[5] = { "gavin", "gavin", "gavin", "xavier", "xavier" };
    assert(countRuns(d, 5) == 2);
    string p[9] = {
            "xavier", "betty", "john", "john", "ed", "ed", "ed", "john", "john"};
    assert(countRuns(p, 9) == 5);
    string w[9] = {
        "betty", "betty", "xavier", "john", "ed", "mary", "ed", "ed", "john"};
    assert(countRuns(w, 9) == 7);
    
    string sub1[] = {"blah", "wubba", "lubba", "rick", "morty"};
    string sub2[] = {"wubba", "lubba", "rick", "morty"};
    assert(subsequence(sub1, 5, sub2, 4)==1);
    assert(subsequence(sub1, 4, sub2, 4)==-1); //sub2 is found in sub1, but we can't see the part where they completely coincide
    assert(subsequence(sub1, 4, sub2, 3)==1); //see if sub2 can shift correctly and be found in sub1 at index 1
    assert(subsequence(sub1, 2, sub2, 1)==1);
    //checking cases where they have same length
    string sub3[] = {"blah", "wubba", "lubba", "rick"};
    string sub4[] = {"wubba", "lubba", "rick", "morty"};
    string sub5[] = {"blah", "wubba", "lubba", "rick"};
    assert(subsequence(sub3, 4, sub4, 4)==-1);
    assert(subsequence(sub3, 4, sub5, 4)==0);

    
    
    string stuffAns[] = {"art", "bat", "cat", "dolphins", "elephant"};
    string stuff1[] = {"art", "bat", "cat", "dolphins", "elephant"};
    string stuff2[] = {"art", "bat", "cat", "dolphins", "elephant"};
    string stuff3[] = {"art", "bat", "cat", "dolphins", "elephant"};
    string stuff4[] = {"art", "bat", "cat", "dolphins", "elephant"};
    string stuff5[] = {"art", "bat", "cat", "dolphins", "elephant"};
    
    assert(divide(stuff1, 5, "cat")==2);
    assert(divide(stuff2, 5, "art")==0);
    assert(divide(stuff3, 5, "az")==1);
    assert(divide(stuff4, 5, "ele")==4);
    assert(divide(stuff5, 5, "ez")==5); //test if n is returned if all strings are less than "ez"
    
    cout << "All tests succeeded" << endl;

}

int appendToAll(string a[], int n, string value) //all positions in string now have value attached
{
    if (n < 0)
        return -1;
    for (int k = 0; k < n; k++)
        a[k] += value;
    return n;
}

int lookup(const string a[], int n, string target)  //see if target is in the string, return position
{
    if (n < 0)
        return -1;
    
    for (int k = 0; k < n; k++)
        if (a[k] == target)
        {
            return k;
            break;
        }
    return -1;
}

int positionOfMax(const string a[], int n)  //returns position of largest element-in last alphabetical order
{
    if (n < 0)
        return -1;
    
    int k = 0;
    int currentMaxIndex = k;        //use currentMaxIndex to store value
    
    if (n == 1)
        return 0;
    for (int k = 1; k < n; k++)
    {
        if (a[currentMaxIndex] < a[k])
            currentMaxIndex = k;        //can replace currentMaxIndex every time we find a bigger one
    }
    return currentMaxIndex;
}


int rotateLeft(string a[], int n, int pos)  //place specific element at end and rotate all else to left
{
    if (n < 0)
        return -1;
    if (pos < 0)
        return -1;
    if (n <= pos)       //accounting for a position that would require looking at the contents of an element past the last element we're interested in
        return -1;
    
    for (int k = 0; k < n; k++)
    {
        if (k == pos)       //find correct position
        {
            string temp = a[k];     //temp = necessary place holder
            for (int i = k; i < n-1; i++)
                a[i] = a[i+1];          //store next value in current
            a[n-1] = temp;              //store temp at end after rotating all over
            return pos;
        }
    }
    return -1;
}

//string d[5] = { "gavin", "gavin", "gavin", "xavier", "xavier" };
//assert(countRuns(d, 5) == 2);

int countRuns(const string a[], int n)      //return number of sequences with 1 or more consecutive identical items
{
    if (n < 0)
        return -1;
    if (n == 1){
        return 1;
    }
    
    int totalItems = 1;     //make a tally
    
    for (int k = 0; k < n-1; k++)
    {
        if (a[k] != a[k+1])
            totalItems++;       //add to tally
        else continue;
    }
    return totalItems;
}


int flip(string a[], int n)     //finds given position element, flips all things in reverse before it
{
    if (n < 0)
        return -1;
    
    for (int k = 0; k < n; k++)
    {
        if (k == n-1)
        {
            for (int i = 0; i < n/2; i++)
            {
                string tempFinal = a[k];    //need to store a[k] and a[i] so they're not lost
                string tempInitial = a[i];
                a[i] = tempFinal;
                a[k] = tempInitial;
                k--;
            }
            break;
        }
        
    }
    return n;
}


int differ(const string a1[], int n1, const string a2[], int n2)    //return position of first elements not equal
{
    if (n1 < 0 || n2 < 0)
        return -1;
    
    if (n1 == 0 && n2 == 0)
        return 0;
    
    if (n1 > n2)
    {
        int k;
        for (k = 0; k < n2; k++)
        {
            if (a1[k] != a2[k])
            {
                return k;
                break;
            }
        }
        return n2;
        
    }
    else
    {
        for (int k = 0; k < n1; k++)
            if (a1[k] != a2[k])
            {   return k;
                break;
            }
        return n1;
    }
    return 0;
}

//DEBUG INFO
//string names[10] = { "eleni", "blah", "gavin", "kevin", "greg", "betty", };
//string names1[10] = { "gavin", "kevin", "greg" };
// int t = subsequence(names, 6, names1, 3);  // returns 1
//string sub1[] = {"here", "there", "nowhere", "somewhere", "anywhere"};
//string sub2[] = {"there", "nowhere", "somewhere", "anywhere"};
//int x = (subsequence(sub1, 2, sub2, 1)); //sub2 is found in sub1 starting at index 1

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)
        return -1;
    if (n2 > n1)        //n2 cannot be greater than n1 b/c n1 could not possibly hold all of n2
        return -1;
   
    if (n2 == n1)
    {
        for (int k = 0; k < n1; k++)
        {
            if (a1[k] != a2[k])     //if we have the case where they are same length, every position must match
                return -1;
        }
        return 0;
    }
    
    for (int k = 0; k <= n2; k++)
    {
        
        if (a1[k] == a2[0])
        {
            int initial = k;
            int i = 1;
          
            for (int j = k+1; j < (n2+initial); j++)
            {
                if (a1[j] != a2[i])
                {
                    initial = -1;
                    break;
                }
                i++;
            }
            return initial;
        }
       
    }
    
    
    return -1;
}


//Return the smallest position in a1 of an element that is equal to any of the n2 elements in a2.
int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)
        return -1;
    
    for (int k = 0; k < n1; k++)
    {
        int firstPosition;
        for (int i = 0; i < n2; i++)
        {
            if (a1[k] == a2[i])
            {
                firstPosition = k;
                return firstPosition;
                break;
            }
        }
    }
    return -1;
}



//string candidate[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
//int x = divide(candidate, 6, "eleni");  //  returns 3
//assert(divide(stuff5, 5, "ez")==5); //test if n is returned if all strings are less than "ez"
            //return n not negative 1 at bottom!

int divide(string a[], int n, string divider)
{
    if (n < 0)
        return -1;
    
   for (int k = 0; k < n; k++)     //first sort everything alphabetically
    {
        string placeHold = a[k];
        for (int i = k; i < n; i++)
        {
                        //cout << a[i] << endl; //comment out
            if (a[i] < placeHold)
            {
                a[k] = a[i];
                        //cout << a[k] << endl;   //comment out
                a[i] = placeHold;
                        //cout << a[i] << endl;   //comment out
                placeHold = a[k];
                        //cout << temp << endl;   //comment out
            }
        }
    }
    
    for (int i = 0; i < n; i++)     //then check for first position >= divider
        if (a[i] >= divider)
            return i;
    
    return n;   //one assert failed, had to remember to return n not -1!
    
}





