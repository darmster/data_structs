// bubbleSort.cpp
//demonstrate bubble sort
#include <iostream>
#include <vector>
using namespace std;
//------------------------------------------------------------------------
class ArrayBub
{
private:
	vector<double> v;		//vector v
	int nElems;			//number of data items
//-------------------------------------------------------------------------
	void swap(int one, int two)		//private member function 
	{
		double temp = v[one];
		v[one] = v[two];
		v[two] = temp;
	}
//------------------------------------------------------------------------
public:
//-----------------------------------------------------------------------
	ArrayBub(int max) : nElems(0)		//consturctor	
	{	
		v.resize(max);			//size the vector
	}
//----------------------------------------------------------------------
	void insert(double value)		//put element into array
	{
		v[nElems] = value;		//insert it
		nElems++;			//increment size
	}
//---------------------------------------------------------------------
	void display()				// displays array contents
	{
		for(int j=0; j<nElems; j++)	//for each element
		cout << v[j] << " ";		//display it
		cout << endl;
	}
//---------------------------------------------------------------------
	void bubbleSort()			//sorts the array
	{
		int out, in;

		for(out=nElems; out>1; out--)	//outer loop (backward) 5/5/12 check me out
		  for(in=0; in<out; in++)	//inner loop
		     if( v[in] > v[in+1])	//out of order?
			swap(in, in+1);		//swap them
	}	//end bubble sort
//---------------------------------------------------------------------
}; //end class ArrayBub
////////////////////////////////////////////////////////////////////////
int main()
{
	int maxSize = 100;			//array size
	ArrayBub arr(maxSize);			//create the array

	arr.insert(77);				//insert 10 items
	arr.insert(99);				//insert 10 items
	arr.insert(44);				//insert 10 items
	arr.insert(55);				//insert 10 items
	arr.insert(22);				//insert 10 items
	arr.insert(88);				//insert 10 items
	arr.insert(11);				//insert 10 items
	arr.insert(00);				//insert 10 items
	arr.insert(66);				//insert 10 items
	arr.insert(33);				//insert 10 items

	arr.display();				//display items
	arr.bubbleSort();			//bubble sort them
	arr.display();				//display them again
	return 0;
}	// end of main
	
