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
#include<algorithm>

//from iostream
using std::cout;
using std::cin;
using std::endl;

//from algorithm
using std::sort;

//function for printing arrays
void PrintArray(int arr[], string ArrayName, int ArraySize);
//function for testing if the custom sort function was successful
void CheckSort(int arrCustom[], int arrCustomSize);
//function for testing if the binary search function was successful
void CheckSearch(int arr[], int arrSize);

int main()
{
	///////////////// TESTING QUICKSORT /////////////////
	int QuickSortArr[] = { 8,9,6,5,7,8,3,2,1,0,10,4 }; //array for testing quicksort function
	int QuickSortSize = 12;
	/*Auto Checking:*/
	cout << "Testing QuickSort Function: ";
	QuickSort(QuickSortArr, 0, QuickSortSize - 1); //sor the array using the custom quick sort
	CheckSort(QuickSortArr, QuickSortSize); //check if the STL sorted array and the custom sort array are the same

	/////////////////////////////////////////////////////

	///////////////// TESTING BINARY SEARCH /////////////////
	//using the sorted quick sort array from previous test:
	cout << "Testing Binary Search Function: ";
	CheckSearch(QuickSortArr, QuickSortSize);
	/////////////////////////////////////////////////////////

	///////////////// TESTING MERGERSORT /////////////////
	int MergeSortArr[] = { 38,27,43,3,9,82,10 }; //array for testing mergesort function
	int MergeSortSize = 7;
	//print the unsorted array
	PrintArray(MergeSortArr, "Merge Sort array (unsorted)", MergeSortSize);
	//sort the array
	MergeSort(MergeSortArr, MergeSortSize);
	//print the sorted array
	PrintArray(MergeSortArr, "Merge Sort array (sorted)", MergeSortSize);
	/////////////////////////////////////////////////////


	//allow the user to see the data
	int temp = 0;
	cin >> temp;

	return 0; //terminate the function
}

void PrintArray(int arr[], string ArrayName, int ArraySize)
{
	//print header with the passed in name
	cout << "------------------------------" << endl;
	cout << "Printing Out array: " << ArrayName << endl;
	//print all the elements
	for (int i = 0; i < ArraySize; i++)
		cout << arr[i] << endl;
	cout << "------------------------------" << endl;
}

//The purpose of this function is to test if two arrays are the same. The VecSTL is sorted before the comparison
//happens and VecCustom is assumed to already be sorted
void CheckSort(int arrCustom[], int arrCustomSize)
{
	int *STLSort = new int[arrCustomSize]; //array to test the quick sort against
	//copy the contents of the passed in array to the new array
	for (int i = 0; i < arrCustomSize; i++)
		STLSort[i] = arrCustom[i];

	//assuming VecCustom is already sorted
	//sort VecSTL using the STL sort
	sort(STLSort, STLSort + arrCustomSize);
	//if the arrays are the same size

		//iterate throught the arrays and check if they are equal to each other
	for (int i = 0; i < arrCustomSize - 1; i++)
	{
		//if one element is not the same
		if (STLSort[i] != arrCustom[i])
		{
			cout << "Failed" << endl;
			return; //return that they are not the same
		}
	}
	cout << "Passed" << endl;
	return; //if program gets here, the two arrays were the same
}

//Function for checking if the binary Search function is working
void CheckSearch(int arr[], int arrSize)
{
	int FuncResult = 0; //variable that will hold the result of the binary Serach function
	int ForIndex = -1; //variable for saving if the index was found in the for loop
	int Size = 5;
	int *Numbers = new int[Size] { 8, 4, 15, -2, 10 }; //numbers to search for

	//for each of the numbers that need to be searched for
	for (int i = 0; i < Size; i++)
	{
		int X = Numbers[i]; //number that is being searched for
		FuncResult = BinarySearch(arr, X, 0, arrSize - 1);
		ForIndex = -1; //reset the search index

		//search for the number in the array using a for loop
		for (int j = 0; j < arrSize; j++)
		{
			//if the number is found
			if (X == arr[j])
			{
				ForIndex = j; //save the index
				break; //end the search;
			}
		}
		//if the two indexes are not the same
		if (ForIndex != FuncResult)
		{
			//notify the user that it failed
			cout << "Failed" << endl;
			return; //end the function
		}
	}
	cout << "Passed" << endl; //notify the user that it passed
	return; //terminate the function
}