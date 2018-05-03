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
#include<algorithm> //STL sort to check sort functions
#include"RandomUtilities.h" //for generating random numbers

//from iostream
using std::cout;
using std::cin;
using std::endl;

//from algorithm
using std::sort;

//from STDLib.H
using std::rand;
using std::srand;

//function for printing arrays
void PrintArray(int arr[], string ArrayName, int ArraySize);
//function for testing if the custom sort function was successful
bool CheckSort(int arrCustom[], int arrCustomSize);
//function for testing if the binary search function was successful
void CheckSearch(int arr[], int arrSize);
//function for filling arrays with random numbers
void FillArray(int arr[], int arrSize);
//function for rigerously testing sorts 
void RigerousSortTest(string TestType, int TestTimes);

int main()
{
	///////////////// TESTING QUICKSORT /////////////////

	int QuickSortArr[12]; //array for testing quicksort function
	int QuickSortSize = 12; //size of the array
	//Fill the array with random numbers
	FillArray(QuickSortArr, QuickSortSize);
	QuickSort(QuickSortArr, 0, QuickSortSize - 1); //sort the array using the custom quick sort

	//Full rigerous test
	RigerousSortTest("Quick", 100);
	/////////////////////////////////////////////////////

	///////////////// TESTING BINARY SEARCH /////////////////
	//using the sorted quick sort array from previous test:
	CheckSearch(QuickSortArr, QuickSortSize);
	/////////////////////////////////////////////////////////

	///////////////// TESTING MERGERSORT /////////////////
	RigerousSortTest("Merge", 100);
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
bool CheckSort(int arrCustom[], int arrCustomSize)
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
			//cout << "Failed" << endl;
			return 0; //return that they are not the same
		}
	}
	//cout << "Passed" << endl;
	return 1; //if program gets here, the two arrays were the same
}

//Function for checking if the binary Search function is working
void CheckSearch(int arr[], int arrSize)
{
	int FuncResult = 0; //variable that will hold the result of the binary Serach function
	int ForIndex = -1; //variable for saving if the index was found in the for loop
	srand(time(NULL)); //seed the random number generator
	int Size = rand() % 80 + 1; //get the size of the array (from 1 to 80);
	int *Numbers = new int[Size]; //numbers to search for
	FillArray(Numbers, Size); //fill the array with random numbers

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
			delete[] Numbers; //delete the array that was used
			//notify the user that it failed
			cout << "Binary Search Failed" << endl;
			return; //end the function
		}
	}
	delete[] Numbers; //delete the array that was used
	cout << "Binary Search Passed" << endl; //notify the user that it passed
	return; //terminate the function
}

//the purpose of this function is to fill the passed in array with random numbers
void FillArray(int arr[], int arrSize)
{
	//fill the array with random numbers
	for (int i = 0; i < arrSize; i++)
		arr[i] = randInt(0, 100); //get a random number from 0 to 100 and save it to the array

	return; //terminate the function
}

//type "Merge" for merge sort, "Quick" for quick sort, and test times is how many arrays should be sorted
void RigerousSortTest(string TestType, int TestTimes)
{
	srand(time(NULL)); //seed the random number generator
	int ArrSize = rand() % 80 + 1; //get the size of the array (from 1 to 80)
	int *Arr = new int[ArrSize]; //create the array with the generated size

	//test the sort functions
	for (int i = 0; i < TestTimes; i++)
	{
		FillArray(Arr, ArrSize); //fill the array with random numbers
		bool Results = 0; //variable for storing the results

		//if the user wants a merge sort, use the merge sort
		if (TestType == "Merge")
			MergeSort(Arr, ArrSize); //sort the array
		//if the user wants a quick sort, use the quick sort
		else if (TestType == "Quick")
			QuickSort(Arr, 0, ArrSize - 1); //Sort the array
		else
		{
			cout << "Error, Sort not found" << endl;
			return; //terminate the function
		}

		Results = CheckSort(Arr, ArrSize); //check the sort
		//if the sort failed, terminate the function early and notify user
		if (Results == false)
		{
			delete[] Arr; //delete the array that was used
			//notify the user that the test failed
			cout << TestType << " Sort Failed Rigerous Test" << endl;
			return; //terminate the function
		}
	}
	delete[] Arr; //delete the array that was used
	//notify the user that the test passed
	cout << TestType << " Sort Passed Rigerous Test" << endl;
	return; //terminate the function
}