/** @file BigNumbers.cpp
 *  @brief The CPP file for BigNumbers
 *
 * This contains the definitions for the BigNumbers class
 *
 *
 *  @author Ethan Balderas
 */

#include "stdafx.h"
#include "BigNumbers.h"


 //! A Constructor
 /*! The default constructor for a BigNumbers*/
 //! Creates a BigNumbers that represents zero
BigNumbers::BigNumbers()
{
	positive = true;
	nums = { 0 };
	size = 1;
}

//! A Constructor
/*! An Overloaded constructor for a BigNumbers
/@param number An int to be made into a BigNumbers
*/
BigNumbers::BigNumbers(int number)
{
	//Check for positive or negative first
	if (number >= 0) {
		positive = true;
	}
	else {
		positive = false;
		number = number * -1;
	}

	//Check how large the size needs to be 
	size = 1;    //every number has at least 1 place

	//we need to check up to what place the number goes to
	int temp = number;
	while ((temp / 10) != 0) {
		size++;
		temp = temp / 10;
	}

	temp = number;
	//We need to put each digit into the vector 
	for (int x = size; x > 0; x--) {
		int place = temp / (pow(10, x - 1));
		nums.push_back(place);
		temp -= place * pow(10, x - 1);
	}

}

//! A Constructor
/*! An Overloaded constructor for a BigNumbers
/@param big A BigNumbers to be made into a BigNumbers
*/
BigNumbers::BigNumbers(BigNumbers & big)
{
	nums = big.nums;
	size = big.size;
	positive = big.positive;
}

//! A Constructor
/*! An Overloaded constructor for a BigNumbers	/param s A string to be made into a BigNumbers
*/
BigNumbers::BigNumbers(std::string s)
{
	//convert from string to int
	std::string myString = s;
	int number = atoi(myString.c_str());

	//Check for positive or negative first
	if (number >= 0) {
		positive = true;
	}
	else {
		positive = false;
		//get rid of the negative sign
		number *= -1;
	}
	size = 1;

	//we need to check up to what place the number goes to
	int temp = number;
	while ((temp / 10) != 0) {
		size++;
		temp = temp / 10;
	}

	temp = number;
	//We need to put each digit into the vector
	for (int x = size; x > 0; x--) {
		int place = temp / (pow(10, x - 1));
		nums.push_back(place);
		temp -= place * pow(10, x - 1);
	}

}

/** @brief Prints out the contents of a BigNumbers
	* Loops through all the elements in the BigNumbers's vector and prints them out
	*  @return Void.
	*/
void BigNumbers::printNumber()
{
	//Prints out the "-" symbol if negative
	if (!positive) {
		std::cout << "-";
	}

	//Prints our each value left to right
	for (int x = 0; x < size; x++) {
		std::cout << nums.at(x);
	}
	std::cout << std::endl;
}


/** @brief Determines which BigNumbers is smaller
	*
	* Compares two BigNumbers to determine if one is smaller
	* Returns False if  big var is larger
	* Returns True if the caller is equal to or bigger
	* @param big The BigNumbers to compare
	* @return The results
	*/
bool BigNumbers::isSmaller(BigNumbers const& big)
{
	int n1 = nums.size();
	int n2 = big.nums.size();
	//Check the sizes first
	if (n1 < n2)
		return true;
	if (n2 < n1)
		return false;
	//Check each element
	for (int i = 0; i < n1; i++)
		if (nums.at(i) < big.nums.at(i))
			return true;
		else if (nums.at(i) > big.nums.at(i))
			return false;

	return false;
}

/** @brief Determines if two BigNumbers are equal
	*
	* Compares two BigNumbers to determine if one equal by looping through both big numbers
	* @param big The BigNumbers to compare
	* @return The results
	*/
bool BigNumbers::isEqual(BigNumbers const& big) {
	int n1;
	//check if they are the same powers 
	if (big.nums.size() == nums.size()) {
		n1 = big.nums.size();
	}
	else {
		return false;
	}
	//check for each element if they are the same
	for (int i = 0; i < n1; i++)
		if (nums.at(i) < big.nums.at(i))
			return false;
		else if (nums.at(i) > big.nums.at(i))
			return false;

	return true;
}


/** @brief Adds two big numbers
	*
	* Compares two BigNumbers to determine if one equal by looping through
	* both big numbers and adding their elements. Starts by adding the 1st place, then
	* the 2nd, 3rd.....till it reaches the end.
	* @param big The BigNumbers to add
	* @return The new BigNumbers from adding
	*/
BigNumbers BigNumbers::add(BigNumbers const& big)
{
	//Variables for addings calculations
	int carry = 0; /*!<The Carry Var is a value of carry for adding (0 or 1)*/
	int temp; /*!<The temp var is a value for each small addition*/
	//Indexes for the BigNumbers
	int indexOne = nums.size(); /*!<The max var is the max index of base BigNumbers*/
	int indexTwo = big.nums.size(); /*!<The max var is the max index of big BigNumbers*/
	int largest; /*!<The largest var is the larger of indexOne and indexTwo*/
	//determine the max index
	if (indexOne > indexTwo) {
		largest = indexOne;
	}
	else {
		largest = indexTwo;
	}
	//Create object to return
	BigNumbers returnMe; /*!returnMe is a BigNumbers object is returned*/
	returnMe.nums.clear();
	returnMe.size = 0;
	//we have to start left to right
	for (int x = 0; x < largest + 1; x++) {
		indexOne--;
		indexTwo--;
		if (indexOne >= 0 && indexTwo >= 0) {
			//we add both and do the carry

			temp = nums.at(indexOne) + big.nums.at(indexTwo) + carry;
			if (temp > 9) {
				carry = 1;
				temp -= 10;
			}
			else {
				carry = 0;
			}

			//Increase returnMe size and put in the new value
			returnMe.size++;
			returnMe.nums.insert(returnMe.nums.begin(), temp);
		}
		else if (indexOne >= 0) {
			//we just add carry and one's values
			temp = nums.at(indexOne) + carry;
			if (temp > 9) {
				carry = 1;
				temp -= 10;
			}
			else {
				carry = 0;
			}
			//Increase returnMe size and put in the new value
			returnMe.size++;
			returnMe.nums.insert(returnMe.nums.begin(), temp);

		}
		else if (indexTwo >= 0) {
			//we just add carry and two's values
			temp = big.nums.at(indexTwo) + carry;
			if (temp > 9) {
				carry = 1;
				temp -= 10;
			}
			else {
				carry = 0;
			}
			//Increase returnMe size and put in the new value
			returnMe.size++;
			returnMe.nums.insert(returnMe.nums.begin(), temp);

		}
		else {
			//finally we just check the final value for a carry 
			if (carry == 1) {
				returnMe.size++;
				returnMe.nums.insert(returnMe.nums.begin(), 1);
			}
		}
	}
	return returnMe;
}

/** @brief Subtracts two negative BigNumbers
	*
	* Determines which BigNumbers is larger for sign and then performs subtraction  rules.
	* When you subtract two negatives it is really just -x+y.
	* @param big The BigNumbers to subtract
	* @return The new BigNumbers from subtracting
	*/
BigNumbers BigNumbers::subtractTwoNegatives(BigNumbers const& big) {
	//create object to be returned
	BigNumbers returnMe; /*!< returnMe is a BigNumbers Object is returned*/
	returnMe.nums.clear();
	returnMe.size = 0;

	//size of both numbers
	int indexOne = nums.size() - 1; /*!<indexOne var is the Max index for base BigNumbers*/
	int indexTwo = big.nums.size() - 1;/*!<indexTwo var is the Max index for big BigNumbers*/
	int temp = 0; /*!<The temp var stores the calculated values for each place holder (1s,10s,100s,...*/
	int carry = 0; /*!<The carry var stores the borrowed value (0 or 1)*/

	//If they are both the same number the result is 0
	if (isEqual(big)) {
		returnMe.size = 1;
		returnMe.nums = { 0 };
		returnMe.positive = true;
		return returnMe;
	}
	//If the second negative is bigger then the result is posiive 
	if (isSmaller(big)) {
		returnMe.positive = true;
		while (indexTwo >= 0) {
			if (indexOne >= 0) {
				temp = big.nums.at(indexTwo) - nums.at(indexOne) - carry;
			}
			else {
				temp = big.nums.at(indexTwo) - carry;
			}

			if (temp < 0) {
				carry = 1;
				temp += 10;
			}
			else {
				carry = 0;
			}
			//Write the value to the array
			returnMe.size++;
			returnMe.nums.insert(returnMe.nums.begin(), temp);

			//increment
			indexTwo--;
			indexOne--;
		}

	}
	//If the first negative is bigger then the result is negative
	else {
		returnMe.positive = false;
		while (indexOne >= 0) {
			if (indexTwo >= 0) {
				temp = nums.at(indexOne) - big.nums.at(indexTwo) - carry;
			}
			else {
				temp = nums.at(indexOne) - carry;
			}

			if (temp < 0) {
				temp += 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			//Write the value to the array
			returnMe.size++;
			returnMe.nums.insert(returnMe.nums.begin(), temp);
			//increment at the end
			indexOne--; indexTwo--;
		}

	}
	//Clean up carried over zeros
	while (returnMe.nums.size() > 1 && returnMe.nums[0] == 0) {
		returnMe.nums.erase(returnMe.nums.begin());
		returnMe.size--;
	}
	return returnMe;
}

/** @brief Subtracts two positive BigNumbers
	*
	* Determines which BigNumbers is larger for sign and then performs subtraction  rules.
	* @param big The BigNumbers to subtract
	* @return The new BigNumbers from subtracting
	*/
BigNumbers BigNumbers::subtractTwoPositives(BigNumbers const& big) {
	//create object to be returned
	BigNumbers returnMe; /*!<returnMe is a BigNumbers Object to be returned*/
	returnMe.nums.clear();
	returnMe.size = 0;

	//size of both numbers
	int indexOne = nums.size() - 1; /*!<The indexOne var is the max index of base BigNumbers */
	int indexTwo = big.nums.size() - 1;/*!<The indexTwo var is the max index of big BigNumbers */
	int temp;/*!< Temp var stores one subtractions */
	int carry = 0; /*!<Carry var stores (0 or 1) based on borrowing subtraction */
	//First check for equal
	if (isEqual(big)) {
		returnMe.size = 1;
		returnMe.nums = { 0 };
		returnMe.positive = true;
		return returnMe;
	}

	if (isSmaller(big)) {
		returnMe.positive = false;
		while (indexTwo >= 0) {
			if (indexOne >= 0) {
				temp = big.nums.at(indexTwo) - nums.at(indexOne) - carry;
			}
			else {
				temp = big.nums.at(indexTwo) - carry;
			}

			if (temp < 0) {
				carry = 1;
				temp += 10;
			}
			else {
				carry = 0;
			}
			//Write the value to the array
			returnMe.size++;
			returnMe.nums.insert(returnMe.nums.begin(), temp);

			//increment
			indexTwo--;
			indexOne--;
		}

	}
	else {
		returnMe.positive = true;
		while (indexOne >= 0) {
			if (indexTwo >= 0) {
				temp = nums.at(indexOne) - big.nums.at(indexTwo) - carry;
			}
			else {
				temp = nums.at(indexOne) - carry;
			}

			if (temp < 0) {
				temp += 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			//Write the value to the array
			returnMe.size++;
			returnMe.nums.insert(returnMe.nums.begin(), temp);
			//increment at the end
			indexOne--; indexTwo--;
		}

	}
	//delete leading zeros
	while (returnMe.nums.size() > 1 && returnMe.nums[0] == 0) {
		returnMe.nums.erase(returnMe.nums.begin());
		returnMe.size--;
	}

	return returnMe;
}


/** @brief Multiplies two BigNumbers together
	*
	* Follows multiplication rule. Starts from the end of big and multiplies it to all of the base number.
	* Then it repeats but increases by a power of ten each time.
	* The method determines the positive value after performing the calculation
	* @param big The BigNumbers to multiply
	* @return The new BigNumbers from multiplying
	*/
BigNumbers BigNumbers::multiply(BigNumbers const& big)
{
	BigNumbers temp; /*!<temp is a BigNumbers object to hold single multiplication results*/
	temp.nums.clear();
	temp.size = 0;

	BigNumbers returnMe; /*!<BigNumbers object to be returned*/

	//Case 1: Multiply by zero
	if ((big.nums.size() == 1 && big.nums.at(0) == 0) || (nums.size() == 1 && nums.at(0) == 0)) {
		returnMe.size = 1;
		returnMe.nums = { 0 };
		returnMe.positive = true;
		return returnMe;

	}
	//Multiplication Algorithm
	//Credit to GeeksForGeeks.com for the algorithm, mine was very slow and took forever
	//The code was edited to fit my code and I looked over it and tested it 
	{
		int n1 = nums.size();
		int n2 = big.nums.size();


		// Keep the result number in a vector 
		// in reverse order 
		std::vector<int> result(n1 + n2, 0);

		// Below two indexes are used to find positions 
		// for results  
		int i_n1 = 0;
		int i_n2 = 0;

		// Go from right to left in num1 
		for (int i = n1 - 1; i >= 0; i--)
		{
			int carry = 0;
			int n1 = nums[i];

			// To shift position to left after every 
			// multiplication of a digit in num2 
			i_n2 = 0;

			// Go from right to left in num2              
			for (int j = n2 - 1; j >= 0; j--)
			{
				// Take current digit of second number 
				int n2 = big.nums[j];

				// Multiply with current digit of first number 
				// and add result to previously stored result 
				// at current position.  
				int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

				// Carry for next iteration 
				carry = sum / 10;

				// Store result 
				result[i_n1 + i_n2] = sum % 10;

				i_n2++;
			}

			// store carry in next cell 
			if (carry > 0)
				result[i_n1 + i_n2] += carry;

			// To shift position to left after every 
			// multiplication of a digit in num1. 
			i_n1++;
		}

		// ignore '0's from the right 
		int i = result.size() - 1;
		while (i >= 0 && result[i] == 0)
			i--;

		// If all were '0's - means either both or 
		// one of num1 or num2 were '0' 
		if (i == -1)
			return returnMe;

		// generate the result string 
		std::string s = "";

		while (i >= 0)
			s += std::to_string(result[i--]);
		BigNumbers transfer(s);
		returnMe = transfer;
	}

	//Multiplication Algorithm
	//Case 2: Positive * Negative
	if (positive & !big.positive) {
		returnMe.positive = false;
		return returnMe;
	}
	//Case 3: Positve * Positive
	if (positive & big.positive) {
		returnMe.positive = true;
		return returnMe;
	}
	//Case 4: Negative * Positive
	if (!positive & big.positive) {
		returnMe.positive = false;
		return returnMe;
	}
	//Case 5: Negative * Negative
	if (!positive & !big.positive) {
		returnMe.positive = true;
		return returnMe;
	}
}

/** @brief Divides two BigNumbers
	*
	* Determines which BigNumbers by calculating how many times big can be subtracted from the base
	* TODO: Implement a more efficient algorithm
	* @param big The BigNumbers to divide
	* @return The new BigNumbers from dividing
	*/
BigNumbers BigNumbers::divide(BigNumbers const& big)
{
	std::cout << "Start" << std::endl;
	BigNumbers one;
	one.nums = { 1 };
	one.size = 1;
	one.positive = true;

	BigNumbers copy2;
	copy2.nums = nums;
	copy2.size = size;
	copy2.positive = true;

	BigNumbers copy;
	copy.nums = big.nums;
    copy.size = big.size;
	copy.positive = true;

	BigNumbers returnMe; /*!<returnMe is a BigNumbers object to be returned*/
	returnMe.nums.clear();
	returnMe.size = 0;


	//Check Basic Cases first
	if (big.nums.size() == 1 && big.nums.at(0) == 0) {
		//error divide by zero
		throw "Can not divide by zero!";
	}

	if (isEqual(big)) {
		std::cout << "Same size!" << std::endl;
		returnMe.size = 1;
		returnMe.nums = { 1 };
		returnMe.positive = true;
		return returnMe;
	}

	if (isSmaller(big)) {
		// (x/ (x+1) = 0 
		returnMe.size = 1;
		returnMe.nums = { 0 };
		returnMe.positive = true;
		return returnMe;
	}

	while (copy2.positive) {
		copy2 = (copy2 - copy);
		if (copy2.positive) {
			returnMe = returnMe + one;
			std::cout << "One++" << std::endl;
		}

	}


	//Case 2: Positive / Negative
	if (positive & !big.positive) {
		returnMe.positive = false;
		return returnMe;
	}
	//Case 3: Positve / Positive
	if (positive & big.positive) {
		returnMe.positive = true;
		return returnMe;
	}
	//Case 4: Negative / Positive
	if (!positive & big.positive) {
		returnMe.positive = false;
		return returnMe;
	}
	//Case 5: Negative / Negative
	if (!positive & !big.positive) {
		returnMe.positive = true;
		return returnMe;
	}


	return returnMe;
}



/** @brief Overload the add symbol for BigNumbers
	*
	*  Adds two BigNumbers together and returns the result
	*
	*  @param big The BigNumbers to be added
	*
	*/
BigNumbers BigNumbers::operator+(BigNumbers const& big)
{
	BigNumbers returnMe; /*!<returnMe is a BigNumbers object to be returned*/
	returnMe.nums.clear();
	returnMe.size = 0;

	if (positive && big.positive) {
		returnMe = add(big);

	}
	else if (!positive && !big.positive) {
		returnMe = add(big);
		returnMe.positive = false;

	}
	else if (positive && !big.positive) {
		//Big needs to be positive to be interpreted by the subtraction method
		returnMe = subtractTwoPositives(big);
	}
	else if (!positive && big.positive) {
		returnMe = subtractTwoNegatives(big);
	}

	if (returnMe.size > maximum) {
		throw "Max BigNumber Size Exceeded";
	}
	return returnMe;
}

/** @brief Overload the subtract symbol for BigNumbers
	*
	*  Subtract two BigNumbers together and returns the result
	*
	*  @param big The BigNumbers to be subtracted
	*
	*/
BigNumbers BigNumbers::operator-(BigNumbers const& big) {
	//create object to return
	BigNumbers returnMe;/*!<returnMe is a BigNumbers object to be returned*/
	returnMe.nums.clear();
	returnMe.size = 0;
	//x-y
	if (positive && big.positive) {
		returnMe = subtractTwoPositives(big);
	}
	//x- (-y)  == x+y
	else if (positive && !big.positive) {
		returnMe = add(big);
		returnMe.positive = true;
	}
	//-x-y == -(x+y)
	else if (!positive && big.positive) {
		returnMe = add(big);
		returnMe.positive = false;
	}
	//-x -(-y) == -x+y
	else if (!positive && !big.positive) {
		// make a reliable subtract
		returnMe = subtractTwoNegatives(big);
	}

	if (returnMe.size > maximum) {
		throw "Max BigNumber Size Exceeded";
	}
	return returnMe;
}


/** @brief Overload the multiply symbol for BigNumbers
	*
	*  Multiplies two BigNumbers together and returns the result
	*
	*  @param big The BigNumbers to be multiplied
	*
	*/
BigNumbers BigNumbers::operator*(BigNumbers const& big)
{
	BigNumbers returnMe;/*!<returnMe is a BigNumber object to be returned*/
	returnMe.nums.clear();
	returnMe.size = 0;

	returnMe = multiply(big);
	return returnMe;

}


/** @brief Overload the divide symbol for BigNumbers
	*
	*  Divides two BigNumbers together and returns the result
	*
	*  @param big The BigNumbers to be divided
	*
	*/
BigNumbers BigNumbers::operator/(BigNumbers const& big)
{
	BigNumbers returnMe;/*!<returnMe is a BigNumbers object to be returned*/
	returnMe.nums.clear();
	returnMe.size = 0;
	returnMe = divide(big);
	if (returnMe.size > maximum) {
		throw "Max BigNumber Size Exceeded";
	}
	return returnMe;
}

/** @brief Overload the mod symbol for BigNumbers
	*
	*  Mods two BigNumbers together and returns the result
	*
	*  @param big The BigNumbers to be modded
	*
	*/
BigNumbers BigNumbers::operator%(BigNumbers const& big)
{
	//create object to return
	//mod is just the remainder, but that can be a big number still cuz big %1 is the big number
	BigNumbers returnMe;/*!<returnMe is a BigNumbers object to be returned*/
	returnMe.nums.clear();
	returnMe.size = 0;

	BigNumbers divisor; /*!<divisor is a BigNumbers that is the divisor*/
	divisor.nums = big.nums;
	divisor.size = big.size;
	divisor.positive = big.positive;

	BigNumbers base;/*!<base is a BigNumbers that is the base*/
	base.nums = nums;
	base.size = size;
	base.positive = positive;


	//Find base/divisor --> round down
	returnMe = (base / divisor);
	//Multiply the divisor by the result


	returnMe = (divisor * returnMe);

	//Subtract that result from base
	returnMe = base - returnMe;
	returnMe.printNumber();
	//the left over is the mod

	if (returnMe.size > maximum) {
		throw "Max BigNumber Size Exceeded";
	}
	return returnMe;
}

/** @brief Overload the equal symbol for BigNumbers
*
*  Sets one BigNumbers equal to the other
*
*  @param big The BigNumbers to be set equal to
*
*/
BigNumbers BigNumbers::operator=(BigNumbers const& big)
{
	nums = big.nums;
	size = big.size;
	positive = big.positive;
	return *this;
}

/** @brief Returns the BigNumbers as a string
*
*  Returns a string of the BigNumber, this is only used for testing
*
*
*/
std::string BigNumbers::toString()
{
	std::string s;
	std::string myString;
	int number;
	printNumber();
	//Prints out the "-" symbol if negative
	if (!positive) {
		s += "-";
	}

	//Prints our each value left to right
	for (int x = 0; x < size; x++) {
		number = nums.at(x);
		s += std::to_string(number);
	}
	return s;
}
