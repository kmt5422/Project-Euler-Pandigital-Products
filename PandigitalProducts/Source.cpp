/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool isPandigit(int a, int b, int product);

int main()
{
	vector<int> pandigitalNumbers;
	int minTwoDigit = 12;
	int maxTwoDigit = 98;
	int minThreeDigit = 123;
	int maxThreeDigit = 987;
	int minOneDigit = 1;
	int maxOneDigit = 9;
	int minFourDigit = 1234;
	int maxFourDigit = 9876;
	
	//Test all numbers and stores the products that match in a vector
	//Know that the factors are either 2 digits and 3 digits or 4 digits and 1 digit
	for (int a = minTwoDigit; a <= maxTwoDigit; a++)
	{
		for (int b = minThreeDigit; b <= maxThreeDigit; b++)
		{
			int product = a * b;
			if (isPandigit(a, b, product))
			{
				if (find(pandigitalNumbers.begin(), pandigitalNumbers.end(), product) == pandigitalNumbers.end())
				{
					pandigitalNumbers.push_back(product);
					cout << a << " " << b << " " << product << endl;
				}
			}
		}
	}
	for (int a = minOneDigit; a <= maxOneDigit; a++)
	{
		for (int b = minFourDigit; b <= maxFourDigit; b++)
		{
			int product = a * b;
			if (isPandigit(a, b, product))
			{
				if (find(pandigitalNumbers.begin(), pandigitalNumbers.end(), product) == pandigitalNumbers.end())
				{
					pandigitalNumbers.push_back(product);
					cout << a << " " << b << " " << product << endl;
				}
			}
		}
	}
	
	//Find the sum
	int sum = 0;
	for (int i = 0; i < pandigitalNumbers.size(); i++)
	{
		sum += pandigitalNumbers[i];
	}

	//Print to screen
	cout << sum << endl;
	system("pause");
	return 0;
}

bool isPandigit(int a, int b, int product)
{
	//Vector of number 1 through 9
	vector<int> digits = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> testDigits;
	
	//Add all of the digits from a, b and the product to the test vector
	while (a > 0)
	{
		testDigits.push_back(a % 10);
		a /= 10;
	}
	while (b > 0)
	{
		testDigits.push_back(b % 10);
		b /= 10;
	}
	while (product > 0)
	{
		testDigits.push_back(product % 10);
		product /= 10;
	}

	//Sort the numbers in the test vector and compare them to the digits vector
	if (testDigits.size() != digits.size())
	{
		return false;
	}
	else
	{
		sort(testDigits.begin(), testDigits.end());
		for (int i = 0; i < digits.size(); i++)
		{
			if (testDigits[i] != digits[i])
			{
				return false;
			}
		}
		return true;
	}
}