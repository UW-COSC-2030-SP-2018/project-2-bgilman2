// By Brett Gilman and Jordan Ruckle
// 4/22/2018
// TestBed.cpp

/////////////// PURPOSE ///////////////
// The purpose of this program is to //
// test the five functions that will //
// be implemented in Functions.h     //
///////////////////////////////////////

//importing functions
#include<iostream>
#include"Functions.h"

//from iostream
using std::cout;
using std::cin;
using std::endl;

//function for printing vectors
void PrintVector(vector<int> Vec, string VecName);

int main()
{
	///////////////// TESTING QUICKSORT /////////////////
	//vector<int> QuickSortVec = {8,9,6,5,7,8,3,2,1,0,10,4}; //vector for testing quicksort function
	vector<int> QuickSortVec = { 8,9,6,5,7 };
	//print the unsorted vector
	PrintVector(QuickSortVec, "Quick Sort Vector (unsorted)");
	//sort the vector
	QuickSort(QuickSortVec, 0);
	//print the sorted vector
	PrintVector(QuickSortVec, "Quick Sort Vector (sorted)");
	/////////////////////////////////////////////////////

	//allow the user to see the data
	int temp = 0;
	cin >> temp;

	return 0; //terminate the function
}

void PrintVector(vector<int> Vec, string VecName)
{
	//print header with the passed in name
	cout << "------------------------------" << endl;
	cout << "Printing Out Vector: " << VecName << endl;
	//print all the elements
	for (int i = 0; i < Vec.size(); i++)
		cout << Vec[i] << endl;
	cout << "------------------------------" << endl;
}