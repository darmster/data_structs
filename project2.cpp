//============================================================================
// Name        : project1.cpp
// Author      : Darmis Hoskins CS2
// Version     : 5.03
// Copyright   : Dr. Hyman code conduct policies
// Description : This program read,add, and print "large integers".
//============================================================================
/* Precondition: Enter two integers that's less than or equal 10 */
/* Postcondition: If the values is less than or equal to 10, the function returns the results
	unless the max_digits has been exceeded. */

#include <iostream>
#include <string>

using namespace std;


const int MAX_DIGITS = 10;

struct BigInt {
    int Digits[MAX_DIGITS];
    int numDigits;
};

bool ReadBigInt( BigInt& n); //return false if num is too big 
bool AddBigInts( const BigInt& num1, const BigInt& num2, BigInt& sum );
void PrintBigInt( const BigInt& num );
bool AddWithLongestFirst( const BigInt& longer, const BigInt& shorter, BigInt& sum );

int main ()
{
    BigInt num1, num2, sum;
    char ans;
    

    do 
	{
        while (!ReadBigInt(num1));
        while (!ReadBigInt(num2));
        if (AddBigInts(num1, num2, sum)) 
		{
            PrintBigInt(sum);
        }
        cout << endl << "Would like to add another? (y or n)" << endl;
        cin >> ans; 
        cin.ignore();
    } while (ans == 'y');
    cout << "Program terminated on request." << endl;
	system("pause");
    return 0;
}



bool ReadBigInt( BigInt& n )
	/* 
	   Precondition: None
	   Postcondition: return true if n is less than equal to MAX_DIGITS else return false
	*/
{
    
    string str;
    
    cout << "Enter integer: ";
    getline(cin,str);

    if (str.length() > MAX_DIGITS) 
	{
        cout << "Must be <= " << MAX_DIGITS << endl;
        return false;
    }
    // save length numDigits to num1
    n.numDigits = (int)str.length();
    

    
    // Converted & moved forward through num1 and backwards through string so ones digit is put in array[0], tens digit put in array[1], ...
    for (int i = n.numDigits-1, x=0; i>=0; x++, i--) 
	{
        n.Digits[x] = str[i] - '0';
    }
            
    return true;
}



bool AddBigInts( const BigInt& num1, const BigInt& num2, BigInt& sum )
	/* Precondition: num1 & num2 are valid
	   PostCondition: return true after AddWithLongestFirst()returns true */
{    

    if (num1.numDigits > num2.numDigits) 
	{
        return AddWithLongestFirst(num1, num2, sum);
    }
    else 
	{
        return AddWithLongestFirst(num2, num1, sum);
    }
}



bool AddWithLongestFirst( const BigInt& longer, const BigInt& shorter, BigInt& sum )
	/*  Precondition: add longer and shorter
	    PostCondition: return results */
{
	//some place holders & etc
	int carryOver = 0, value = 0;
    
    sum.numDigits = longer.numDigits;
    // shorter loop
	for (int i = 0; i < shorter.numDigits; i++) 
	{
        value = longer.Digits[i] + shorter.Digits[i] + carryOver;
        sum.Digits[i] = value % 10;
        carryOver = value/10;
    }
	// longer loop
    for (int i = shorter.numDigits; i < longer.numDigits; i++) 
	{
        value = longer.Digits[i] + carryOver;
        sum.Digits[i] = value % 10;
        carryOver = value/10;
    }
    
    //  Check for Overflow & if there's carry over, save the extra carry digit
    if (carryOver > 0) 
	{
        if (sum.numDigits == MAX_DIGITS) 
		{
            cout << "overflow" << endl;
            return false;
        }
        sum.Digits[sum.numDigits] = carryOver;
        sum.numDigits++;
    }
    return true;
}



void PrintBigInt( const BigInt& num ) 
	/*Precondition: num is true
	  Postcondition: print num */
{
    // display starting from high valued digit working down to ones place
    for(int i = num.numDigits-1; i >= 0; i--)
	{
        cout << num.Digits[i];
	}
    cout << endl;
}
