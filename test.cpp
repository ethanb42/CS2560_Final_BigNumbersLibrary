#include "pch.h"
#include "BigNumbers.h"

//We could have factored out constructing BigNumbers in each test, however we need many different BigNumbers so it wouldn't
//really make the code smaller

//I commented out refactored code to show the process better

//Make a big number
/*
TEST(Constructors, CanConstructDefault) {
	BigNumbers test;
}
*/

/*
TEST(Constructors, CanConstructInt ) {
	BigNumbers test(1000);
}

TEST(Constructors, CanConstructString) {
	BigNumbers test("1234");
}

TEST(Constructors, CanConstructBigNumber) {
	BigNumbers test;
	BigNumbers test2(test);
}

//A big Number can print
TEST(Methods, CanPrint) {
	BigNumbers test(100);
	test.printNumber();
}

//A big number can call its helper methods
TEST(Methods, CanAdd) {
	BigNumbers test(100);
	BigNumbers test2(100);
	test.add(test2);
}

TEST(Methods, CanSubtractTwoNegatives) {
	BigNumbers test(-100);
	BigNumbers test2(-100);
	test.subtractTwoNegatives(test2);
}

TEST(Methods, CanSubtractTwoPositives) {
	BigNumbers test(100);
	BigNumbers test2(100);
	test.subtractTwoPositives(test2);
}

TEST(Methods, CanMultiply) {
	BigNumbers test(100);
	BigNumbers test2(100);
	test.multiply(test2);
}
TEST(Methods, CanDivide) {
	BigNumbers test(100);
	BigNumbers test2(100);
	test.divide(test2);
}

*/

/*
TEST(Methods, isEqual) {
	BigNumbers test(100);
	BigNumbers test2(100);
	EXPECT_EQ(test.toString(), test2.toString());

}
TEST(Methods, isNotEqual) {
	BigNumbers test(101);
	BigNumbers test2(100);
	EXPECT_NE(test.toString(), test2.toString());
}

*/


/*
TEST(Methods, isSmaller) {
	BigNumbers test(100);
	BigNumbers test2(100);
	EXPECT_EQ(test.isSmaller(test2), test2.isSmaller(test));

}
*/

//BigNumber operator overloads work
TEST(Operator_Overload, Addition) {
	BigNumbers test(100);
	BigNumbers test2(100);
	BigNumbers copy;
	copy = test + test2;
	if (copy.isEqual(test + test2)) {
		assert(true);
	}
	else {
		assert(false);
	}
}

TEST(Operator_Overload, Subtraction) {
	BigNumbers test(100);
	BigNumbers test2(100);
	//default equal to zero
	BigNumbers copy;
	//if we subtract these two the result should be zero
	ASSERT_EQ(copy.toString(), (test - test2).toString());

}

TEST(Operator_Overload, Multiplication) {
	std::string test = "50000";
	//If we multiply 50 by 1000 we should get 50000
	BigNumbers fifty(50);
	BigNumbers oneThousand(1000);

	ASSERT_EQ(test, (fifty*oneThousand).toString());
}

TEST(Operator_Overload, Division) {
	std::string test = "-10";
	//If we divide 100 by -10 we get -10
	BigNumbers hundred(100);
	BigNumbers negativeTen(-10);

	ASSERT_EQ(test, (hundred / negativeTen).toString());

}

TEST(Operator_Overload, Mod) {
	std::string test = "5";
	BigNumbers fifteen(15);
	BigNumbers ten(10);
	ASSERT_EQ(test, (fifteen%ten).toString());

}

TEST(Operator_Overload, Equal) {
	BigNumbers test;
	BigNumbers copy(1111);
	//We set them equal to each other, if it didn't work they would not print the same strings
	test = copy;
	ASSERT_EQ(test.toString(), copy.toString());

}

//A test to verify google tests is working
TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}