#include "conversion.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>


// Used for printing commands dependent on the --print flag
void printProcess(const std::string& value, bool isPrint, bool endln = true)
{
	if (!isPrint) return;
	std::cout << value;

	if (endln)
		std::cout << std::endl;
}


void printSeparator(bool isPrint)
{
	printProcess("====================================", isPrint);
}


// Helper function for decimalToBase (do not call directly)
void convertDecimalEq(int& prevQuotient, int& base, std::string& answer, bool isPrint)
{
	printProcess(std::to_string(base) + "|" + std::to_string(prevQuotient) + " - ", isPrint, false);

	int remainder = prevQuotient % base;
	std::string remainderStr = std::to_string(remainder);

	// Used for handling the characters of remainders above 9
	if (remainder >= 10) {
		remainderStr = remainder - 10 + 'A';
	}
	answer += remainderStr;

	prevQuotient = std::floor(prevQuotient / base);
	printProcess(remainderStr, isPrint);
}

std::string decimalToBase(long double value, int base, int decimalPrecision, bool isPrint)
{
	// The following code is for the integer part of the value
	int prevQuotient = std::floor(value);
	std::string answer = "";
	while (prevQuotient >= base)
	{
		convertDecimalEq(prevQuotient, base, answer, isPrint);
	}
	convertDecimalEq(prevQuotient, base, answer, isPrint);

	// Reverse to get the correct answer
	std::reverse(answer.begin(), answer.end());
	printProcess("Answer Int: " + answer, isPrint);


	// The ff code is for the decimal part of the value
	long double decimal = value - std::floor(value);

	
	std::string ansDecimal = "";
	int currentLoop = 0; // To prevent infinite looping on irrational numbers

	while (decimal != 0 && currentLoop < decimalPrecision)
	{
		long double newDecimal = decimal * base;
		char intAnswer;
		if (newDecimal >= 10)
			intAnswer = std::floor(newDecimal) + 'A' - 10;
		else
			intAnswer = std::floor(newDecimal) + '0';

		ansDecimal += intAnswer;

		printProcess(std::to_string(decimal) + " * " + std::to_string(base) + " = " + 
			std::to_string(newDecimal), isPrint);

		decimal = newDecimal - std::floor(newDecimal);
		currentLoop++;
	}

	// Decimal part
	printProcess("Answer Decimal: " + ansDecimal, isPrint);

	printSeparator(isPrint);
	// Final answer
	if (ansDecimal == "")	return answer;
	return answer + "." + ansDecimal;
}

std::string baseToDecimal(const std::string& value, int base, bool isPrint)
{
	// For the integer part of value
	std::string intValue = value;
	int intAns = 0;
	size_t decPos = value.find(".");
	if (decPos != std::string::npos)
		intValue = value.substr(0, decPos);

	std::reverse(intValue.begin(), intValue.end());
	for (int digit = 0; digit < static_cast<int>(intValue.length()); digit++)
	{
		int digitValue = intValue[digit] - '0';
		if (std::toupper(intValue[digit]) >= 'A')
			digitValue = std::toupper(intValue[digit]) - 'A' + 10; // Allow support for hexadecimal values

		int digitAns = digitValue * static_cast<int>(std::pow(base, digit));
		intAns += digitAns;

		printProcess(std::to_string(digitValue) + " * " + std::to_string(base) + "^" + 
			std::to_string(digit) + " = " + std::to_string(digitAns), isPrint);
	}
	printProcess("Answer Int: " + std::to_string(intAns), isPrint);

	// For decimal part of value
	long double decAns = 0;
	if (decPos != std::string::npos)
	{		
		long double decValue = std::stold(value.substr(decPos, value.length() - 1));
		if (decValue != 0)
		{
			std::string stringDecValue = std::to_string(decValue);
			stringDecValue.erase(0, 2);  // Removes the "0." from decimal
			
			
			int decLength = stringDecValue.length();
			for (int digit = 0; digit < decLength; digit++)
			{
				int digitValue =  stringDecValue[digit] - '0';
				long double digitAns = digitValue * std::pow(base, -(digit + 1));
				decAns += digitAns;
				printProcess(std::to_string(digitValue) + " *" + std::to_string(base) + "^" + std::to_string(-(digit + 1)) + 
					" = " + std::to_string(digitAns), isPrint);
			}

			// Since decAns currently appends to int convert it to decimal
			printProcess("Answer Decimal: " + std::to_string(decAns), isPrint);
		}
	}
	printSeparator(isPrint);
	
	if (decAns == 0) return std::to_string(intAns);
	return std::to_string(decAns + intAns);
}

std::optional<std::string> binaryToBase(const std::string& value, int base, bool isPrint)
{
	// Checks if base supports direct binary conversion
	long double posOnSequence = std::log2(base); 	// This variable will separate the value into groups
	if (posOnSequence - std::floor(posOnSequence) != 0)	return std::nullopt;

	// For the integer part of value
	
	std::string intValue = value;
	size_t decPos = value.find(".");
	if (decPos != std::string::npos)
		intValue = value.substr(0, decPos);

	std::reverse(intValue.begin(), intValue.end());  // We have to reverse is to ensure that the order loops correctly
	
	std::string intAnswer = "";
	
	for (int iGrp = 0; iGrp < std::ceil(intValue.length() / posOnSequence); iGrp++)
	{
		int grpTotal = 0;
		for (int iDigit = 0; iDigit + iGrp * posOnSequence <= intValue.length() - 1 && iDigit < posOnSequence; iDigit++)
		{		
			int digitValue = intValue[iGrp * posOnSequence + iDigit] - '0';
			int multiplier = std::pow(2, iDigit);
			int intAns = digitValue * multiplier; 
			grpTotal += intAns;
			printProcess(std::to_string(digitValue) + " * " + std::to_string(multiplier) + " = " + std::to_string(intAns),
				       	isPrint);
		}

		// Allows support for hexadecimal values
		std::string grpTotalChar = std::to_string(grpTotal); // Allows for hexadecimal values
		if (grpTotal >= 10)
		{
			grpTotalChar = grpTotal - 10 + 'A';	
		}

		intAnswer += grpTotalChar;
		printProcess("=" + grpTotalChar + "\n------", isPrint);
	}

	std::reverse(intAnswer.begin(), intAnswer.end());  // Due to incremental, the correct value is reversed
	printProcess("Answer Int: " + intAnswer, isPrint);


	// This part is for the decimal part of value
	if (decPos != std::string::npos)
	{	
		std::string decValue = value.substr(decPos + 1, value.length() - 1);

		std::string decAnswer = "";

		for (int iGrp = 0; iGrp < std::ceil(decValue.length() / posOnSequence); iGrp++)
		{
			int grpTotal = 0;
			for (int iDigit = 0; iDigit + iGrp * posOnSequence <= decValue.length() - 1 && iDigit < posOnSequence; iDigit++)
			{
				int digitValue = decValue[iGrp * posOnSequence + iDigit] - '0';
				int multiplier = std::pow(2, posOnSequence - 1 - iDigit);
				int decAns = digitValue * multiplier;
				grpTotal += decAns;

				printProcess(std::to_string(digitValue) + " * " + std::to_string(multiplier) + " = " + 
						std::to_string(decAns), isPrint);
			}


			// Allows support for hexadecimal values
			std::string grpTotalChar = std::to_string(grpTotal); // Allows for hexadecimal values
			if (grpTotal >= 10)
			{
				grpTotalChar = grpTotal - 10 + 'A';	
			}

			decAnswer += grpTotalChar;
			printProcess("=" + grpTotalChar + "\n------", isPrint);
		}

		printProcess("Answer Decimal: " + decAnswer, isPrint);
		printSeparator(isPrint);
		return intAnswer + "." + decAnswer;
	}
	else
	{
		printSeparator(isPrint);
		return intAnswer;
	}
}	

std::optional<std::string> baseToBinary(const std::string& value, int base, bool isPrint)
{
	// Checks if base supports direct binary conversion
	long double posOnSequence = std::log2(base); 	// This variable will separate the value into groups
	if (posOnSequence - std::floor(posOnSequence) != 0)	return std::nullopt;

	// Integers value
	std::string intAnswer = "";
	std::string intValue = value;
	size_t decPos = value.find(".");
	if (decPos != std::string::npos)
		intValue = value.substr(0, decPos);

	for (int iDigit = 0; iDigit < static_cast<int>(intValue.length()); iDigit++)
	{
		// Convert digit to decimal then to binary
		std::string digit;

		// Supports hexadecimalvalues
		if (std::toupper(intValue[iDigit]) >= 'A')
			digit = std::to_string(intValue[iDigit] - 'A' + 10);  // Converts hex values to integral values
		else
			digit.push_back(intValue[iDigit]);

		//long double decimalOfDigit = std::stold(baseToDecimal(digit, base));
		std::string binOfDigit = decimalToBase(std::stold(digit), 2);
		// Ensure binOfDigit has 3 characters
		while (static_cast<int>(binOfDigit.length()) < static_cast<int>(posOnSequence))
		{
			binOfDigit = "0" + binOfDigit;
		}
		printProcess(binOfDigit + " - " +  digit, isPrint);

		intAnswer += binOfDigit;
	}

	// Check if there are leading zeroes in intAnswer
	while (intAnswer[0] == '0')
	{
		intAnswer.erase(intAnswer.begin());
	}

	//Decimal value
	std::string decAnswer = "";
	std::string decValue = value;
	if (decPos != std::string::npos)
	{
		std::string decValue = value.substr(decPos + 1, value.length() - 1);

		printProcess(".", isPrint);  // This is to add a separator between integers and decimal values
	
		for (int iDigit = 0; iDigit < static_cast<int>(decValue.length()); iDigit++)
		{
			// Convert digit to decimal then to binary
			std::string digit;
			digit.push_back(decValue[iDigit]);
			long double decimalOfDigit = std::stold(baseToDecimal(digit, base));
			std::string binOfDigit = decimalToBase(decimalOfDigit, 2);
			// Ensure binOfDigit has 3 characters
			while (static_cast<int>(binOfDigit.length()) < static_cast<int>(posOnSequence))
			{
				binOfDigit = "0" + binOfDigit;
			}
			printProcess(binOfDigit + " - " +  digit, isPrint);
			decAnswer += binOfDigit;
		}
		printSeparator(isPrint);
		return intAnswer + "." + decAnswer;
	}

	printSeparator(isPrint);
	return intAnswer;
}