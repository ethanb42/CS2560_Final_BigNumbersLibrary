#pragma once
#pragma once
#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdbool>
#include <string>


/** @file BigNumbers.h
 *  @brief Header file for BigNumbers
 *
 * This contains the signatures for the BigNumbers class
 *
 *
 *  @author Ethan Balderas
 */




class BigNumbers {
public:
	static int const maximum = 1000; /*!<The max size of a big number */

    std::vector<int> nums; /*!<A vector of intergers that represents a Big Number*/
	bool positive; /*!<A boolean to keep track of the sign of the Big Number*/
	int size; /*!<A int to keep track of the size of a Big Number*/


	//! A Constructor
	/*! The default constructor for a BigNumber*/
	BigNumbers();

	//! A Constructor
	/*! An Overloaded constructor for a BigNumber
	/@param number An int to be made into a BigNumber
	*/
	BigNumbers(int number);

	//! A Constructor
	/*! An Overloaded constructor for a BigNumber
	/@param big A BigNumber to be made into a BigNumber
	*/
	BigNumbers(BigNumbers& big);

	//! A Constructor
	/*! An Overloaded constructor for a BigNumber
	/@param s A string to be made into a BigNumber
	*/
	BigNumbers(std::string s);


	/** @brief Prints out the contents of a BigNumber
	*
	*  @return Void.
	*/
	void printNumber();
	//OO Methods

	/** @brief Overload the add symbol for BigNumbers
	*
	*  Adds two BigNumbers together and returns the result
	*
	*  @param big The BigNumber to be added
	*
	*/
	BigNumbers operator+ (BigNumbers const& big);

	/** @brief Overload the subtract symbol for BigNumbers
	*
	*  Subtract two BigNumbers together and returns the result
	*
	*  @param big The BigNumber to be subtracted
	*
	*/
	BigNumbers operator- (BigNumbers const& big);

	/** @brief Overload the multiply symbol for BigNumbers
	*
	*  Multiplies two BigNumbers together and returns the result
	*
	*  @param big The BigNumber to be multiplied
	*
	*/
	BigNumbers operator* (BigNumbers const& big);

	/** @brief Overload the divide symbol for BigNumbers
	*
	*  Divides two BigNumbers together and returns the result
	*
	*  @param big The BigNumber to be divided
	*
	*/
	BigNumbers operator/ (BigNumbers const& big);

	/** @brief Overload the mod symbol for BigNumbers
	*
	*  Mods two BigNumbers together and returns the result
	*
	*  @param big The BigNumber to be modded
	*
	*/
	BigNumbers operator% (BigNumbers const& big);

	/** @brief Overload the equal symbol for BigNumbers
	*
	*  Sets one BigNumber equal to the other
	*
	*  @param big The BigNumber to be set equal to
	*
	*/
	BigNumbers operator= (BigNumbers const& big);

	//Support Methods

	/** @brief Determines which BigNumber is smaller
	*
	* Compares two BigNumbers to determine if one is smaller
	* Returns False if  big var is larger
	* Returns True if the caller is equal to or bigger
	* @param big The BigNumber to compare
	* @return The results
	*/
	bool isSmaller(BigNumbers const&);

	/** @brief Determines if two BigNumbers are equal
	*
	* Compares two BigNumbers to determine if one equal by looping through both big numbers
	* @param big The BigNumber to compare
	* @return The results
	*/
	bool isEqual(BigNumbers const& big);

	/** @brief Adds two big numbers
	*
	* Compares two BigNumbers to determine if one equal by looping through both big numbers and adding their elements
	* @param big The BigNumber to add
	* @return The new BigNumber from adding
	*/
	BigNumbers add(BigNumbers const& big);

	/** @brief Subtracts two negative BigNumbers
	*
	* Determines which BigNumber is larger for sign and then performs subtraction  rules.
	* @param big The BigNumber to subtract
	* @return The new BigNumber from subtracting
	*/
	BigNumbers subtractTwoNegatives(BigNumbers const& big);

	/** @brief Subtracts two positive BigNumbers
	*
	* Determines which BigNumber is larger for sign and then performs subtraction  rules.
	* @param big The BigNumber to subtract
	* @return The new BigNumber from subtracting
	*/
	BigNumbers subtractTwoPositives(BigNumbers const& big);

	/** @brief Multiplies two BigNumbers together
	*
	* Follows multiplication rule. Starts from the end of big and multiplies it to all of the base number.
	* Then it repeats but increases by a power of ten each time.
	* @param big The BigNumber to multiply
	* @return The new BigNumber from multiplying
	*/
	BigNumbers multiply(BigNumbers const& big);

	/** @brief Divides two BigNumbers
	*
	* Determines which BigNumber by calculating how many times big can be subtracted from the base
	* @param big The BigNumber to divide
	* @return The new BigNumber from dividing
	*/
	BigNumbers divide(BigNumbers const& big);


 /** @brief Returns the BigNumbers as a string
*
*  Returns a string of the BigNumber, this is only used for testing
*
*
*/
	std::string toString();
};

