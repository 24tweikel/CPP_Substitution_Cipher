/*
	Author: Trent Weikel
	Date: 04/11/22
	Program: C++ Substitution Cipher

	Test Cases:
		key = 6, message = Hello, World, encrypted = Nkrru, Cuxrj!

		key = 60, returns "Please enter a number between 0 and 30!"

*/

#include <iostream> 
#include <string>
#include <iomanip>

int main() {

	int intKey = 0;
	std::cout << "Key: ";
	std::cin >> intKey;

	if (intKey <= 0 || intKey > 29) {

		std::cout << "Please enter a number between 0 and 30!" << std::endl;
		system("pause");
		return 1;

	}

	std::string message = "";
	std::cout << "Message: ";
	std::cin.ignore();
	getline(std::cin, message);

	std::string encryptedmessage = "";

	for (size_t i = 0; i < message.length(); i++) {

		if (message[i] >= 'A' && message[i] <= 'Z') {

			wchar_t c = ' ';

			if (message[i] + intKey > 'Z') {

				int number = message[i] + intKey - 'Z';
				c = static_cast<wchar_t>(('A' - 1) + number);

			} else {

				c = static_cast<wchar_t>(message[i] + intKey);

			}

			std::wcout << c;

		} else if (message[i] >= 'a' && message[i] <= 'z') {

			wchar_t c = ' ';

			if (message[i] + intKey > 'z') {

				int number = message[i] + intKey - 'z';
				c = static_cast<wchar_t>(('a' - 1) + number);

			} else {

				c = static_cast<wchar_t>(message[i] + intKey);

			}

			std::wcout << c;

		} else {

			std::cout << message[i];

		}

	}

	std::cout << std::endl;
	system("pause");

}