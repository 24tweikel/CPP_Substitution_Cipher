/*
	
	Author: Trent Weikel
	Date: 04/11/22
	Program: C++ Substitution Cipher

	Test Cases:
		key = 6, message = "Hello, World", encrypted = "Nkrru, Cuxrj!"

		key = 60, returns "Please enter a number between 0 and 30!"

*/

#include "Cipher.h"

int main() {

	system("cls");
	char e_or_d = ' ';
	std::cout << "Encrypt Or Decrypt (e or d): ";
	std::cin >> e_or_d;

	int intKey = 0;
	std::cout << "Key: ";
	std::cin >> intKey;

	if (intKey <= 0 || intKey > 29) {

		std::cerr << "Please enter a number between 0 and 30!" << std::endl << std::endl;
		system("pause");
		return 0x1;

	}

	std::string message;
	std::cout << "Message: ";
	std::cin.ignore();
	getline(std::cin, message);
	
	if (toupper(e_or_d) == 'E') {

		std::string encrypted = cipher::substitution::encrypt(message, intKey);
		std::cout << std::endl << "Encrypted Message: " << encrypted << std::endl << std::endl;
		system("pause");

	} else if (toupper(e_or_d) == 'D') {

		std::string decrypted = cipher::substitution::decrypt(message, intKey);
		std::clog << std::endl << "Decrypted Message: " << decrypted << std::endl << std::endl;
		system("pause");

	}

}