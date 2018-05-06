// By Brett Gilman and Jordan Ruckle
// 4/22/2018
// Functions.h

#include<string>

//from string
using std::string;

// defining a bloom filter structure and using the hash function
// type define from Lab 10
typedef unsigned int(*hash_function)(const std::string&);

//function declarations
void QuickSort(int arr[], int StartIndex, int EndIndex);
int Partition(int arr[], int StartIndex, int EndIndex);
int BinarySearch(int arr[], int X, int StartIndex, int EndIndex);
void MergeSort(int arr[], int size);
void Merge(int arr[], int Left[], int LeftSize, int Right[], int RightSize);
unsigned int OurHash(const string& Input);

//The purpose of this function is to recursively sort
//a passed in vector of integers using the quick sort method
void QuickSort(int arr[], int StartIndex, int EndIndex)
{
	//quick sort algorithm found at: https://www.geeksforgeeks.org/quick-sort/
	//only the pseudo code for the quick sort function was used, not the partition
	//algorithm and no code was copied.

	//if the partition is not zero
	if (StartIndex < EndIndex)
	{
		//calculate the new partition index
		int PartitionIndex = Partition(arr, StartIndex, EndIndex);

		//sort again using a different partition
		QuickSort(arr, StartIndex, PartitionIndex - 1);
		QuickSort(arr, PartitionIndex + 1, EndIndex);
	}

	return; //terminate the function
}

int Partition(int arr[], int StartIndex, int EndIndex)
{
	//Algorithm for partition function found at: https://visualgo.net/en/sorting

	int PivotIndex = StartIndex; //set the first element as the pivot
	int StoreIndex = PivotIndex + 1; //set the Store Index as the next element after the pivot
									 //from the start of the unsorted partition to the end of the vector
	for (int i = StoreIndex; i <= EndIndex; i++)
	{
		//if the unsorted element is less than the pivot
		if (arr[i] < arr[PivotIndex])
		{
			//swap i and the store index values
			int temp = arr[StoreIndex];
			arr[StoreIndex] = arr[i];
			arr[i] = temp;

			//interate the storeindex
			StoreIndex++;
		}
	}

	//swap the pivot and store index - 1
	int temp = arr[StoreIndex - 1];
	arr[StoreIndex - 1] = arr[PivotIndex];
	arr[PivotIndex] = temp;

	//return the new partition index
	return (StoreIndex - 1);
}

//The purpose of this function is to recursively find an integer
//that is passed in to the function using the Binary Search Method
int BinarySearch(int arr[], int X, int StartIndex, int EndIndex)
{
	int MiddleIndex = (StartIndex + EndIndex) / 2; //get the middle index
												   //check if x is equal to the start index
	if (X == arr[StartIndex])
		return StartIndex;
	//check if X is equal to the middle index
	else if (X == arr[MiddleIndex])
		return MiddleIndex; //return that X was found
							//check if x is equal to the end index
	else if (X == arr[EndIndex])
		return EndIndex;
	//if there are no more elements left in the list, X was not found
	else if ((MiddleIndex == StartIndex) || (MiddleIndex == EndIndex))
		return -1; //return that the element was not found
				   //check if X is less than the middle index
	else if (X < arr[MiddleIndex])
		return BinarySearch(arr, X, StartIndex, MiddleIndex); //check the left half of the vector
															  //check if X is greater than the middle index
	else if (X > arr[MiddleIndex])
		return BinarySearch(arr, X, MiddleIndex, EndIndex); //check the right half of the vector
}

//The purpose of this function is to recursively sort
//a passed in array of integers using the merge sort method
void MergeSort(int arr[], int size)
{

	// MergeSort algorithm found at: https://www.youtube.com/watch?v=TzeBrDU-JaY&t=818s
	//no code was copied and only the algorithm for Merge Sort was used, not the function Merge (Merge function is original)

	int n = size; //get the length of the array
				  //if there is only one element left, exit the function
	if (n < 2)
		return;
	int Middle = n / 2; //get the middle index of the array
	int LeftSize = Middle;
	int RightSize = n - Middle;
	int *Left = new int[LeftSize]; //create a left array of size Middle
	int *Right = new int[RightSize]; //create a right array of size n - middle

									 //fill the left array with the left side of the array
	for (int i = 0; i <= Middle - 1; i++)
		Left[i] = arr[i];

	//fill the right array with the rioght side of the array
	for (int i = Middle; i <= n - 1; i++)
		Right[i - Middle] = arr[i];

	//split the left side of the array
	MergeSort(Left, Middle);
	//split the right side of the array
	MergeSort(Right, n - Middle);
	//merge the left and right side arrays together
	Merge(arr, Left, LeftSize, Right, RightSize);

	//delete the two arrays to free up memory
	delete[] Left;
	delete[] Right;

	return; //terminate the function
}

//The purpose of this function is to sort the elements in a passed in array
void Merge(int arr[], int Left[], int LeftSize, int Right[], int RightSize)
{
	//iterator for navigating the unsorted array, left array, and right array, respectively
	int AIter = 0,
		LIter = 0,
		RIter = 0;

	int LVal = 0; //value from the left array to be looked at
	int RVal = 0; //value from the right array to be looked at

				  //while none of the iterators have reached the end of their array
	while ((LIter < LeftSize) || (RIter < RightSize))
	{
		//if the left iterator hasn't made it to the end of the array yet
		if (LIter < LeftSize)
			LVal = Left[LIter]; //get the next value from the array

								//if the right iterator hasn't made it to the end of the array yet
		if (RIter < RightSize)
			RVal = Right[RIter]; //get the next value from the array

								 //if the left array is empty
		if (LIter >= LeftSize)
		{
			//save the right value to the unsorted array 
			arr[AIter] = RVal;
			//iterate the right array iterator
			RIter++;
		}
		//if the right array is empty
		else if (RIter >= RightSize)
		{
			//save the right value to the unsorted array 
			arr[AIter] = LVal;
			//iterate the left array iterator
			LIter++;
		}
		//if the left value is greater than the right value
		else if (LVal >= RVal)
		{
			//save the right value to the unsorted array 
			arr[AIter] = RVal;
			//iterate the right array iterator
			RIter++;
		}
		//if the left value is greater than the right value
		else if (LVal <= RVal)
		{
			//save the right value to the unsorted array 
			arr[AIter] = LVal;
			//iterate the left array iterator
			LIter++;
		}

		//iterate the unsorted array iterator
		AIter++;
	}
	return; //terminate the function
}


//The purpose of this function is to use a custom hashing function to convert
//a passed in string into a hash
// After much trial and error with good prime numbers for collisions and hashing, I was using 57 and 93 as my values. I then did a google search for the
// "best" prime number for hashing. This in turn led me to the left-shift method which appeared to be much faster and efficient.
unsigned int OurHash(const string& Input)
{

	// Initiate the hash to a number I chose randomly and initiate the intVal integer.
	unsigned int Hash(8173);
	int intVal;

	// Interates through the string and creates a hash. The value of the current character of the string is stored in intVal.
	// The Hash is then left-shifted 5 bits, added to the previous Hash, and then intVal is added to it. The left-shift of 5 bits was
	// recommended by the djb2 hashing functions, which can be found at http://www.cse.yorku.ca/~oz/hash.html
	for (int i = 0; i < Input.length(); i++) {
		intVal = Input[i];
		Hash = (Hash << 5) + Hash + intVal;
	}


	return Hash; //return the hashed string

}


// Structure of functions to be used by Bloom Filters. Contains a hash function
// and a pointer to the next hash function. Is a linked list!
struct bloomFilterFunction {

	hash_function hashFunction;
	struct bloomFilterFunction *next;

};

// Structure of the Bloom Filter itself. Contains the list of hash functions from the
// previous struct, a set of bits, and a set size.
struct bloomFilter {

	struct bloomFilterFunction *hashFunction;
	int *bits;
	size_t bloomSize;

	bloomFilter() {
		struct bloomFilterFunction *list = new bloomFilterFunction;
		bloomSize = 0;			// Set the size of the bloom filter
		bits = new int[0];		// Allocate memory for the bits
	}

};

// This function is responsible for the creation of a Bloom Filter.
bloomFilter createBloom(size_t size) {

	bloomFilter *theBloom = new bloomFilter();						// Initialize a Bloom Filter
	theBloom->bloomSize = size;			// Set the size of the bloom filter
	theBloom->bits = new int[size];		// Allocate memory for the bits

	return *theBloom;					// Return the Bloom Filter

}

// This function is responsible for adding a hash function to a Bloom Filter's
// list of functions to iterate through in the isPresent function.
void addHashFunctionToBloom(bloomFilter bFilter, hash_function function) {

	bloomFilter* bFilterP = &bFilter;

	struct bloomFilterFunction *last = bFilterP->hashFunction;		// Initializes a Bloom Filter Function for a tail

	struct bloomFilterFunction *list = new bloomFilterFunction;		// Initializes a Bloom Filter Function and its head
	list->hashFunction = function;

	while (last && last->next) {									// Interates through the list to the last function
		last = last->next;
	}
	if (last) {														// Add the provided function to the list
		last->next = list;
	}
	else {															// If a list hasn't been created yet, then this function is the first function
		bFilterP->hashFunction = list;
	}

	return;

}

// This function is responsible for add an element to a Bloom Filter.
void addToBloom(bloomFilter bFilter, string element) {

	bloomFilter* bFilterP = &bFilter;

	struct bloomFilterFunction *list = bFilterP->hashFunction;		// Initializes a Bloom Filter Function list

	int *bits = bFilterP->bits;										// Stores the Bloom Filter's bits in a pointer


	// Iterates through the list of hashes that has been provided and calculates each hash for the
	// supplied element.
	while (list) {													
		unsigned int hash = list->hashFunction(element);			// Computes the hash of the function
		hash %= bFilterP->bloomSize * 8;							// A hash to be used for verification
		bits[hash / 8] |= 1 << hash % 8;							// Calculates the Bloom Filter's nth bit. The hash is n
		list = list->next;											// Iterates to the next item
	}

	return;

}


bool isPresent(bloomFilter bFilter, string element) {

	bloomFilter* bFilterP = &bFilter;

	struct bloomFilterFunction *list = bFilterP->hashFunction;		// Initializes a Bloom Filter Function list

	int *bits = bFilterP->bits;										// Stores the Bloom Filter's bits in a pointer

	while (list) {
		unsigned int hash = list->hashFunction(element);			// Computes the hash of the function
		hash %= bFilterP->bloomSize * 8;								// A hash to be used for verification

		if (!(bits[hash / 8] & 1 << hash % 8)) {					// Checks the nth bit and returns false if it is 0
			return false;
		}
		list = list->next;											// Iterates to the next item
	}

	return true;													// Returns true otherwise as the element is *most likely* in the Bloom Filter

}
