#include "Cipher.h"

namespace cipher {

	std::string substitution::encrypt(const std::string message, const int intKey) {

		if (intKey >= 30 || intKey <= 0) return "";

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

				encryptedmessage += static_cast<char>(c);

			} else if (message[i] >= 'a' && message[i] <= 'z') {

				wchar_t c = ' ';

				if (message[i] + intKey > 'z') {

					int number = message[i] + intKey - 'z';
					c = static_cast<wchar_t>(('a' - 1) + number);

				} else {

					c = static_cast<wchar_t>(message[i] + intKey);

				}

				encryptedmessage += static_cast<char>(c);

			} else {

				encryptedmessage += message[i];

			}

		}

		return encryptedmessage;

	}

	//=====================================================================================================

	std::string substitution::decrypt(const std::string message, const int intKey) {

		std::string decryptedmessage = "";

		for (size_t i = 0; i < message.length(); i++) {

			if (message[i] >= 'A' && message[i] <= 'Z') {

				wchar_t c = ' ';

				if (message[i] - intKey < 'A') {

					int number = message[i] - intKey - 'A';
					c = static_cast<wchar_t>(('Z' + 1) + number);

				} else {

					c = static_cast<wchar_t>(message[i] - intKey);

				}

				decryptedmessage += static_cast<char>(c);

			} else if (message[i] >= 'a' && message[i] <= 'z') {

				wchar_t c = ' ';

				if (message[i] - intKey < 'a') {

					int number = message[i] - intKey - 'a';
					c = static_cast<wchar_t>(('z' + 1) + number);

				} else {

					c = static_cast<wchar_t>(message[i] - intKey);

				}

				decryptedmessage += static_cast<char>(c);

			} else { 
				
				decryptedmessage += message[i]; 
			
			}

		}

		return decryptedmessage;

	}

	int substitution::main() {

		std::string encrypted = encrypt("Hello, World!", 6);
		std::string decrypted = decrypt(encrypted, 6);
		std::cout << encrypted << " " << decrypted;
		return 0;

	}

}