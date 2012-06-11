
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


class BigInt {
    // overload the stream insertion and extraction operations
	friend BigInt operator+(const BigInt& num1, const BigInt& num2);
    friend ostream& operator<< (ostream& os, const BigInt& num);
	friend bool AddBigInts( const BigInt& num1, const BigInt& num2, BigInt& sum );
	friend bool AddWithLongestFirst( const BigInt& longer, const BigInt& shorter, BigInt& sum );
public:
	static const int MAX_DIGITS = 5;
	BigInt();
	BigInt(const string& goodString);
	//added 3/22/12
    void PrintBigInt( const BigIntStruct& num );

private:
    void StringToBigInt(const string& goodString);
    int Digits[MAX_DIGITS];
    int numDigits;
};

class OverFlowException
{
public: 
	BigInt m_num1,m_num2;
	char m_op;
	OverFlowException(const BigInt& num1,const BigInt& num2, char op)
	{
		m_num1 = num1;
		m_num2 = num2;
		m_op = op;
	}
};

BigInt::BigInt() {
	numDigits = 0;
}

BigInt::BigInt(const string& goodString) {
	StringToBigInt(goodString);
}

void BigInt::StringToBigInt(const string& goodString)
{
    numDigits = (int)goodString.length();
    
    // Converted & moved forward through num1 and backwards through string so ones digit is put in array[0], tens digit put in array[1], ...
    for (int i = numDigits-1, x=0; i>=0; x++, i--) 
	{
        Digits[x] = goodString[i] - '0';
    }
}

ostream& operator<< (ostream& os, const BigInt& num)
{
   /* for(int i = num.numDigits-1; i >= 0; i--)
	{
        os << num.Digits[i];
	}
	return os; */
	;
}

BigInt operator+(const BigInt& num1, const BigInt& num2)
{
	BigInt sum;
	if (!AddBigInts(num1, num2, sum))
	{
		//throw exception here
		;
	}
	return sum;
}

bool AddBigInts( const BigInt& num1, const BigInt& num2, BigInt& sum )
	/* Precondition: num1 & num2 are valid
	   PostCondition: return true after AddWithLongestFirstStr()returns true */
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
        if (sum.numDigits == BigInt::MAX_DIGITS) 
		{
            //cout << "overflow" << endl;
            return false;
        }
        sum.Digits[sum.numDigits] = carryOver;
        sum.numDigits++;
    }
    return true;
}

/*
BigInt operator+(const BigInt& num1, const BigInt& num2)
{

	return
}
*/

const int MAX_DIGITS_STR = 10;

struct BigIntStruct {
    int Digits[MAX_DIGITS_STR];
    int numDigits;
};

bool ReadBigInt( BigIntStruct& n); //return false if num is too big 
bool AddBigIntsStr( const BigIntStruct& num1, const BigIntStruct& num2, BigIntStruct& sum );
void PrintBigInt( const BigIntStruct& num );
bool AddWithLongestFirstStr( const BigIntStruct& longer, const BigIntStruct& shorter, BigIntStruct& sum );

int main ()
{
    BigIntStruct num1, num2, sum;
    char ans;
    
    string str;
    
    cout << "Enter integer: ";
    getline(cin,str);

    if (str.length() > MAX_DIGITS_STR) 
	{
        cout << "Must be <= " << MAX_DIGITS_STR << endl;
        return false;
    }
	BigInt x(str);
	cout << "x = " << x << endl;

    cout << "Enter integer: ";
    getline(cin,str);

    if (str.length() > MAX_DIGITS_STR) 
	{
        cout << "Must be <= " << MAX_DIGITS_STR << endl;
        return false;
    }
	BigInt y(str);
	cout << "y = " << y << endl;
	BigInt z = x + y;
	cout << "z = " << z << endl;

    cout << "Program terminated on request." << endl;
	system("pause");
	return 0;
    // save length numDigits to num1
	/*
    do 
	{
        while (!ReadBigInt(num1));
        while (!ReadBigInt(num2));
        if (AddBigIntsStr(num1, num2, sum)) 
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
	*/
}



bool ReadBigInt( BigIntStruct& n )
	/* 
	   Precondition: None
	   Postcondition: return true if n is less than equal to MAX_DIGITS_STR else return false
	*/
{
    
    string str;
    
    cout << "Enter integer: ";
    getline(cin,str);

    if (str.length() > MAX_DIGITS_STR) 
	{
        cout << "Must be <= " << MAX_DIGITS_STR << endl;
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



bool AddBigIntsStr( const BigIntStruct& num1, const BigIntStruct& num2, BigIntStruct& sum )
	/* Precondition: num1 & num2 are valid
	   PostCondition: return true after AddWithLongestFirstStr()returns true */
{    

    if (num1.numDigits > num2.numDigits) 
	{
        return AddWithLongestFirstStr(num1, num2, sum);
    }
    else 
	{
        return AddWithLongestFirstStr(num2, num1, sum);
    }
}



bool AddWithLongestFirstStr( const BigIntStruct& longer, const BigIntStruct& shorter, BigIntStruct& sum )
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
        if (sum.numDigits == MAX_DIGITS_STR) 
		{
            cout << "overflow" << endl;
            return false;
        }
        sum.Digits[sum.numDigits] = carryOver;
        sum.numDigits++;
    }
    return true;
}



void PrintBigInt( const BigIntStruct& num ) 
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