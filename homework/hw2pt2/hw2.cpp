// Kramer Johnson
// CSPC 5041 02, Winter quarter, Seattle University
// 1/24/21
// Version 1.0


#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

/*
 * Function to convert a decimal number to binary
 * The binary representation of the number is returned
 * as an integer
 * @throws       invalid_argument if a negative integer is passed
 * @param number a positive integer to convert
 * @return       an integer of the binary representation of number
 */
int decimalToBinary(int number) {
    if (number < 0)
        throw invalid_argument("Input must be a positive integer");
    if (number == 0)
        return 0;
    string result;

    while (number > 0) {
        string rem = to_string(number % 2);
        result.insert(0, rem);
        number /= 2;
    }

    return stoi(result);
}

int main() {
//    assert(decimalToBinary(1)   == 1);
//    assert(decimalToBinary(2)   == 10);
//    assert(decimalToBinary(8)   == 1000);
//    assert(decimalToBinary(256) == 100000000);
//    assert(decimalToBinary(25)  == 11001);
//    assert(decimalToBinary(0)   == 0);
//    try {
//        decimalToBinary(-5);
//    } catch (invalid_argument &e) {
//        cout << "All tests have passed." << endl;
//    }
    decimalToBinary(1055);
    return 0;
}
