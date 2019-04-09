/****************************************************************************************
** Author: Parker Howell
** Date: 2-19-16
** File: functions.hpp
** Description: collection of functions used to demonstrate searching, sorting, and file
**              i/o.
****************************************************************************************/

#include <fstream>
#include <string>




/****************************************************************************************
** function: printArr(int arr[], int size)
** Description: prints the value of an int array to the console
** Arguments: int arr[]  -  1D array if integers.
**            int size  -  The size of the array
****************************************************************************************/
void printArr(int[], int);




/****************************************************************************************
** function: linSearch(int list[], int size, int value)
** Description: Linear Search found in Gaddis p.596
** Arguments: int list[]  -  1D array of unsorted integers.
**            int size  -  The size of the array
**            int value  -  the value being searched for
** Post Conditions: Returns a -1 if the value wasn't found, or the array index of the
**                  value.
****************************************************************************************/
int linSearch(int[], int, int);




/****************************************************************************************
** function: search1(std::string fileIn, int size)
** Description: opens a file and adds its values to an array. Then prints the array.
**              Followed by displaying if a zero was in the file or not.
** Arguments: std::string fileIn  -  name of the txt file ot open.
**            int size  -  The size of the array
****************************************************************************************/
void search1(std::string, int);




/****************************************************************************************
** function: sortArray(int array[], int size)
** Description: Selection Sort from Gaddis p.609
** Arguments: int array[]  -  1D array if integers.
**            int size  -  The size of the array.
** Post Conditions: Sorts the passed in array in ascending order.
****************************************************************************************/
void sortArray(int[], int);




/****************************************************************************************
** function: sort2File(std::string fileIn, std::string nameOfFile, int size)
** Description: opens a file, sorts the integer values and then saves them to a new
**              (or overwirtten) file of the users choice. The contents of the new file
**              are then printed.
** Arguments: std::string fileIn  -  name of file to open and read from
**            std::string nameOfFile  -  what to name the new file
**            int size  -  The size of the array
****************************************************************************************/
void sort2File(std::string, std::string, int);




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
void binarySearch(std::string, int, int);

