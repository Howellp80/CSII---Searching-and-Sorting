/****************************************************************************************
** Author: Parker Howell
** Date: 2-19-16
** Description: Main to demonstrate searching and sorting functions.
****************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include "functions.hpp"

const int ARR_SIZE = 21;      // size of the int array we're working with

// Note: system("CLS") works with win / visual studio. Use "clear" for *nix...
#define CLEAR_SCREEN "clear"

int main(){

	int choice;                    // user menu selection

	std::string nameOfNo,          // file will store sorted data from noZero
	  	        nameOfEarly,       // file will store sorted data from earlyZero
		        nameOfMid,         // file will store sorted data from midZero
		        nameOfLate;        // file will store sorted data from lateZero

	// main menu
	do{
		system(CLEAR_SCREEN);
		std::cout << "Hi. This is a demonstration searches and sorts "
			      << "found in the Gaddis textbook." << std::endl;
		std::cout << "Please select a search or a sort, or to exit." << std::endl << std::endl;
		std::cout << " [1] - Unsorted search (Linear)." << std::endl;
		std::cout << " [2] - Sort the files (Selection), then search (Binary)." << std::endl;
		std::cout << " [3] - EXIT" << std::endl;
		std::cin >> choice;

		// validate choice
		while (choice < 1 || choice > 3){
			std::cout << "Please select 1 - 3" << std::endl;
			std::cin >> choice;
		}

		// if the user didn't exit
		if (choice != 3){
			
			// user selected Search for Zero 
			if (choice == 1){
				system(CLEAR_SCREEN);
				// read and search each of the files for zero
				search1("noZero.txt", ARR_SIZE);
				search1("earlyZero.txt", ARR_SIZE);
				search1("midZero.txt", ARR_SIZE);
				search1("lateZero.txt", ARR_SIZE);

				std::cout << "Press \"Enter\" to return to the main menu." << std::endl;
				std::cin.ignore();
				std::cin.get();
			}

			else {// user selected Sort the files
				system(CLEAR_SCREEN);
				// get the what the user wants to name the files
				std::cout << "Please name the file that will contain no zeros: ";
				std::cin >> nameOfNo;
				 
				std::cout << std::endl << "Please name the file that will contain an early zero: ";
				std::cin >> nameOfEarly;

				std::cout << std::endl << "Please name the file that will contain a mid zero: ";
				std::cin >> nameOfMid;

				std::cout << std::endl << "Please name the file that will contain a late zero: ";
				std::cin >> nameOfLate;
				std::cout << std::endl;
				system(CLEAR_SCREEN);


				// opens each of the files and sorts them, saving the sorted data in a new file
				// then each new file is binary searched for a value
				sort2File("noZero.txt", nameOfNo, ARR_SIZE);
				binarySearch(nameOfNo, ARR_SIZE, 0);

				sort2File("earlyZero.txt", nameOfEarly, ARR_SIZE);
				binarySearch(nameOfEarly, ARR_SIZE, 2);

				sort2File("midZero.txt", nameOfMid, ARR_SIZE);
				binarySearch(nameOfMid, ARR_SIZE, 4);

				sort2File("lateZero.txt", nameOfLate, ARR_SIZE);
				binarySearch(nameOfLate, ARR_SIZE, 7);

				std::cout << "Press \"Enter\" to return to the main menu." << std::endl;
				std::cin.ignore();
				std::cin.get();
			}
		}
	// did the user exit?
	} while (choice != 3);

	return 0;
}