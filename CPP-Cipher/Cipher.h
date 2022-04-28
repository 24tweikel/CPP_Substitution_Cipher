#ifndef _CIPHER_
#define _CIPHER_
#ifndef _STRING_
#include <string>
#endif
#ifndef _IOMANIP_
#include <iomanip>
#endif
#ifndef _IOSTREAM_
#include <iostream>
#endif

namespace cipher { 

	class substitution {

		public:
			static std::string encrypt(const std::string message, const int intKey = 5);
			static std::string decrypt(const std::string message, const int intKey = 5);

		private:
			static int main();

	};

}
#endif /* _CIPHER_ */