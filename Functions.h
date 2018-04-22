// By Brett Gilman and Jordan Ruckle
// 4/22/2018
// Functions.h

#include<vector>
#include<string>
#include<map>

//from string
using std::string;

//from vector
using std::vector;

//from map
using std::map;
using std::pair;

//The purpose of this function is to recursively sort
//a passed in vector of integers using the quick sort method
void QuickSort(vector<int> &Vec, int StartIndex)
{
	//iterative algorithm found at: https://visualgo.net/en/sorting

	if (StartIndex < Vec.size())
	{
		int PivotIndex = StartIndex; //set the first element as the pivot
		int StoreIndex = PivotIndex + 1; //set the Store Index as the next element after the pivot
		//from the start of the unsorted partition to the end of the vector
		for (int i = StoreIndex; i < Vec.size(); i++)
		{
			//if the unsorted element is less than the pivot
			if (Vec[i] < Vec[PivotIndex])
			{
				//swap i and the store index values
				int temp = Vec[StoreIndex];
				Vec[StoreIndex] = Vec[i];
				Vec[i] = temp;

				//interate the storeindex
				StoreIndex++;
			}
		}

		//swap the pivot and store index - 1
		int temp = Vec[StoreIndex - 1];
		Vec[StoreIndex - 1] = Vec[PivotIndex];
		Vec[PivotIndex] = temp;

		//recall the function
		QuickSort(Vec, PivotIndex + 1);
	}

	return; //terminate the function
}

//The purpose of this function is to recursively find an integer
//that is passed in to the function using the Binary Search Method
int BinarySearch(vector<int> Vec, int X)
{
	return -1; //return that the element was not found
}

//The purpose of this function is to recursively sort
//a passed in vector of integers using the merge sort method
void MergeSort(vector<int> Vec)
{
	return; //terminate the function
}

//The purpose of this function is to use a custom hashing function to convert
//a passed in string into a hash
int HashFunction(string Input)
{
	int Hash = 0;
	return Hash; //return the hashed string
}


void BloomFilter()
{
	return; //terminate the function
}
