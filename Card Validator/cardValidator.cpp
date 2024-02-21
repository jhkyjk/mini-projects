#include <iostream>
#include <string>


bool isValidNumber(const std::string& creditCardNumber) 
{
	int length = creditCardNumber.length();
	for (int i = 0; i < length; i++) 
	{
		if (creditCardNumber[i] < '0' || creditCardNumber[i] > '9')
			return false;
	}
	return true;
}

int main()
{
	std::cout << "This program uses the Luhn Algorigthm to validate a credit card number.";
	std::cout << "Enter \"exit\" to quit \n";

	while (true)
	{
		std::cout << "Enter credit card number to validate: \n";
		std::string creditCardNumber;
		std::cin >> creditCardNumber;

		if (creditCardNumber == "exit")
			break;
		else if (!isValidNumber(creditCardNumber))
			std::cout << "Bad input!\n";



		int sumOfDigits = 0;

		//doubling every other digit starting from the right;
		for (int i = creditCardNumber.length() - 2; i >= 0; i -= 2)
		{
			int doubledNumber = (creditCardNumber[i] - '0') * 2;
			if (doubledNumber > 9)
			{
				sumOfDigits += (doubledNumber % 10) + (doubledNumber / 10);
			}
			else
			{
				sumOfDigits += doubledNumber;
			}

		}
	
		//adding leftover digits excluding check digit;
		for (int i = creditCardNumber.length() - 3; i >= 0; i -= 2)
		{
			sumOfDigits += (creditCardNumber[i] - '0');
		}

		sumOfDigits *= 9;

		int checkDigit = (creditCardNumber.back() - '0') % 10;
		//Last digit of sum after multiplication;
		int lastDigit = sumOfDigits % 10;

		if (lastDigit == checkDigit)
			std::cout << "Valid!\n";
		else
			std::cout << "Not Valid!\n";

	}
}

