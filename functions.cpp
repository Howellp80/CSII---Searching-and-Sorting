/****************************************************************************************
** Author: Parker Howell
** Date: 2-19-16
** File: functions.cpp
** Description: collection of functions used to demonstrate searching, sorting, and file
**              i/o.
****************************************************************************************/

#include "functions.hpp"
#include <fstream>
#include <iostream>




/****************************************************************************************
** function: printArr(int arr[], int size)
** Description: prints the value of an int array to the console 
** Arguments: int arr[]  -  1D array if integers.
**            int size  -  The size of the array
****************************************************************************************/
void printArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}




/****************************************************************************************
** function: linSearch(int list[], int size, int value)
** Description: Linear Search found in Gaddis p.596
** Arguments: int list[]  -  1D array of unsorted integers.
**            int size  -  The size of the array
**            int value  -  the value being searched for
** Post Conditions: Returns a -1 if the value wasn't found, or the array index of the 
**                  value.
****************************************************************************************/
int linSearch(int list[], int size, int value){
	int index = 0; // Used as a subscript to search array
	int position = -1; // Used to record position of search value
	bool found = false; // Flag to indicate if the value was found
	while (index < size && !found)
	{
		if (list[index] == value) // If the value is found
		{
			found = true; // Set the flag
			position = index; // Record the value's subscript
		}
		index++; // Go to the next element
	}
	return position; // Return the position, or -1
}




/****************************************************************************************
** function: search1(std::string fileIn, int size)
** Description: opens a file and adds its values to an array. Then prints the array.
**              Followed by displaying if a zero was in the file or not.
** Arguments: std::string fileIn  -  name of the txt file ot open.
**            int size  -  The size of the array
****************************************************************************************/
void search1(std::string fileIn, int size)
{
	// create a new array to hold file input
	int *arr = new int[size];

	// open the file
	std::ifstream inputFile;
	inputFile.open(fileIn.c_str());

	// put the file values into to the array
	while (!inputFile.eof())
		for (int i = 0; i < size; i++)
			inputFile >> arr[i];

	// print the file contents
	std::cout << "The values in " << fileIn << " are: ";
	printArr(arr, size);

	// get to searching
	std::cout << "The zero was found in array element: ";
	int zeroIndex = linSearch(arr, size, 0);
	if (zeroIndex == -1)
		std::cout << "Zero was not found." << std::endl << std::endl;
	else
		std::cout << zeroIndex << std::endl << std::endl;

	// close the input file
	inputFile.close();

	// delete the array
	delete[] arr;

}




/****************************************************************************************
** function: sortArray(int array[], int size)
** Description: Selection Sort from Gaddis p.609
** Arguments: int array[]  -  1D array if integers.
**            int size  -  The size of the array.
** Post Conditions: Sorts the passed in array in ascending order.
****************************************************************************************/
void sortArray(int array[], int size)
{
	int temp;
	bool swap;

	do{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap); // Loop again if a swap occurred on this pass.
}



/****************************************************************************************
** function: sort2File(std::string fileIn, std::string nameOfFile, int size)
** Description: opens a file, sorts the integer values and then saves them to a new 
**              (or overwirtten) file of the users choice. The contents of the new file 
**              are then printed.
** Arguments: std::string fileIn  -  name of file to open and read from
**            std::string nameOfFile  -  what to name the new file
**            int size  -  The size of the array
****************************************************************************************/
void sort2File(std::string fileIn, std::string nameOfFile, int size)
{
	// create a new array to hold file input
	int *arr = new int[size];

	// open the file
	std::ifstream inputFile;
	inputFile.open(fileIn.c_str());

	// put the file values into to the array
	while (!inputFile.eof())
		for (int i = 0; i < size; i++)
			inputFile >> arr[i];

	// close the input file
	inputFile.close();

	// sort the array
	sortArray(arr, size);

	// appent .txt to the file name
	nameOfFile = nameOfFile + ".txt";

	// create the file to write to 
	std::ofstream ofs; 
	ofs.open(nameOfFile.c_str());

	// add sorted data to file
	for (int i = 0; i < size; i++)
		ofs << arr[i] << " ";

	// print the sorted data
	std::cout << nameOfFile << " now contatins: " << std::endl;
	printArr(arr, size);
}




/****************************************************************************************
** function: binarySearch(std::string nameOfFile, int size, int value)
** Description: Binary Search as found in Gaddis p.601 with slight modification
** Arguments: std::string nameOfFile  -  name of a .txt file to open.
**            int size  -  The size of the array
**            int value  -  The value in the file to search for
** Post Conditions: Takes a sorted file and adds its contents to an array. Then performs 
**                  a Binary Search on the file, printing if the searched value was found 
**                  or not. If the found value is in the first index of the array it will 
**                  be displayed as being found in the 1st position.
****************************************************************************************/
void binarySearch(std::string nameOfFile, int size, int value)
{
	int first = 0, // First array element
		last = size - 1, // Last array element
		middle, // Midpoint of search
		position = -1; // Position of search value
	bool found = false; // Flag


	// appent .txt to the file name
	nameOfFile = nameOfFile + ".txt";

	// open the .txt file
	std::ifstream ifs;
	ifs.open(nameOfFile.c_str());

	// create a new array to hold file input
	int *arr = new int[size];

	// put the file values into to the array
	while (!ifs.eof())
		for (int i = 0; i < size; i++)
			ifs >> arr[i];

	while (!found && first <= last)
		{
		middle = (first + last) / 2; // Calculate midpoint
		if (arr[middle] == value) // If value is found at mid
			{
			found = true;
			position = middle;
			}
		else if (arr[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
		}

	// if the value wasn't found
	if (position == -1)
		std::cout << "The " << value << " being searched for was not found." << std::endl << std::endl;
	
	// if it was
	else
		if (position == 0)
			std::cout << "The " << value << " was found in the file in the 1st position." 
			          << std::endl << std::endl;
		else if (position == 1)
			std::cout << "The " << value << " was found in the file in the 2nd position."
			          << std::endl << std::endl;
		else if (position == 2)
			std::cout << "The " << value << " was found in the file in the 3rd position."
			          << std::endl << std::endl;
		else
			std::cout << "The " << value << " was found in the file in the " << position + 1
		          << "th position." << std::endl << std::endl;

	delete[] arr;
}