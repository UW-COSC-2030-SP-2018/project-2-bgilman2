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

//function declarations
void QuickSort(vector<int> &Vec, int StartIndex, int EndIndex);
int Partition(vector<int> &Vec, int StartIndex, int EndIndex);
int BinarySearch(vector<int> Vec, int X, int StartIndex, int EndIndex);
void MergeSort(vector<int> &Vec, int Left, int Right);
vector<int> Merge(vector<int> Vec, int Left, int Middle, int Right);
int HashFunction(string Input);
void BloomFilter();

//The purpose of this function is to recursively sort
//a passed in vector of integers using the quick sort method
void QuickSort(vector<int> &Vec, int StartIndex, int EndIndex)
{
	//quick sort algorithm found at: https://www.geeksforgeeks.org/quick-sort/
	//only the pseudo code for the quick sort function was used, not the partition
	//algorithm and no code was coppied.

	//if the partition is not zero
	if (StartIndex < EndIndex)
	{
		//calculate the new partition index
		int PartitionIndex = Partition(Vec, StartIndex, EndIndex);

		//sort again using a different partition
		QuickSort(Vec, StartIndex, PartitionIndex - 1);
		QuickSort(Vec, PartitionIndex + 1, EndIndex);
	}

	return; //terminate the function
}

int Partition(vector<int> &Vec, int StartIndex, int EndIndex)
{
	//Algorithm for partition function found at: https://visualgo.net/en/sorting

	int PivotIndex = StartIndex; //set the first element as the pivot
	int StoreIndex = PivotIndex + 1; //set the Store Index as the next element after the pivot
									 //from the start of the unsorted partition to the end of the vector
	for (int i = StoreIndex; i <= EndIndex; i++)
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

	//return the new partition index
	return (StoreIndex - 1);
}

//The purpose of this function is to recursively find an integer
//that is passed in to the function using the Binary Search Method
int BinarySearch(vector<int> Vec, int X, int StartIndex, int EndIndex)
{
	int MiddleIndex = (StartIndex + EndIndex)/2; //get the middle index
	//check if X is equal to the middle index
	if (X == Vec[MiddleIndex])
		return Vec[MiddleIndex]; //return that X was found
	//check if x is equal to the start index
	else if (X == Vec[StartIndex])
		return Vec[StartIndex];
	//check if x is equal to the end index
	else if (X == Vec[EndIndex])
		return Vec[EndIndex];
	//if there are no more elements left in the list, X was not found
	else if ((MiddleIndex == StartIndex) || (MiddleIndex == EndIndex))
		return -1; //return that the element was not found
	//check if X is less than the middle index
	else if (X < Vec[MiddleIndex])
		return BinarySearch(Vec, X, StartIndex, MiddleIndex); //check the left half of the vector
	//check if X is greater than the middle index
	else if (X > Vec[MiddleIndex])
		return BinarySearch(Vec, X, MiddleIndex, EndIndex); //check the right half of the vector
}

//The purpose of this function is to recursively sort
//a passed in vector of integers using the merge sort method
void MergeSort(vector<int> &Vec, int Left, int Right)
{
	//Algorithm given in class:
	//if r > 1
	//1. Find the middle point to divide the array into two halves:
	//		Middle m = (1+r)/2
	//2. call mergeSort for first half:
	//		call mergesort(vec, l, m)
	//3. Call mergeSort for second half:
	//		call mergeSort(Vec, m+ 1, r)
	//4. Merge the two halves sorted in step 2 and 3

	/*
	//if there are more than 1 elements in the vector, keep dividing
	if (Right > 1)
	{
		int Middle = (1 + Right) / 2;
		//call mergeSort for the first half:
		MergeSort(Vec, Left, Middle);
		//call mergeSort for the second half:
		MergeSort(Vec, Middle + 1, Right);
		//Merge the two halves:
		Vec = Merge(Vec, Left, Middle, Right);
	}
	return; //terminate the function
	*/
}

//The purpose of this function is to sort the elements in a passed in vector and return the results
vector<int> Merge(vector<int> Vec, int Left, int Middle, int Right)
{
	vector<int> Sorted; //vector for holding the sorted elements
	int LeftIter = Left; //iterator for the left side of the vector
	int RightIter = Middle; //iterator for the right side of the vector
	//While the two iterators are not at NULL (end of the list), keep sorting
	while ((LeftIter != NULL) && (RightIter != NULL))
	{
		//if the right side is at the end of the list
		if (RightIter == NULL)
		{
			Sorted.push_back(Vec[LeftIter]); //the left is larger than NULL
			LeftIter++; //increment the left iterator
		}
		//if the left side is at the end of the list
		else if (LeftIter == NULL)
		{
			Sorted.push_back(Vec[RightIter]); //the right is larger than NULL
			RightIter++; //increment the right iterator
		}
		//if the left side element is greater than or equal to the right side element
		else if (Vec[LeftIter] >= Vec[RightIter])
		{
			Sorted.push_back(Vec[RightIter]); //the right element is smaller
			RightIter++; //increment the interator
		}
		//if the right side element is greater than the left side element
		else if (Vec[LeftIter] < Vec[RightIter])
		{
			Sorted.push_back(Vec[LeftIter]); //the left element is smaller
			LeftIter++; //increment the iterator
		}
		//if the iterator is larger than the sentinel index, set it to null
		if (RightIter > Right)
			RightIter = NULL;
		if (LeftIter > Right)
			LeftIter = NULL;
	}
	return Sorted; //return the sorted vector
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
