#include <iostream>
#include <bitset>

using namespace std;

/*
 * Function to convert a decimal number to binary
 * The binary representation of the number is returned
 * as a string to avoid implicit conversion to decimal
 * representations.
 * @param number a positive integer to convert
 * @return       a string of the binary representation of number
 */
string decimalToBinary(int number) {
    if (number < 0) return 0;
    string result;

    while (number > 0) {
        string rem = to_string(number % 2);
        result.insert(0, rem);
        number /= 2;
    }

    return result;
}

int main() {
    for (int i = 2; i <= 256; i *= 2)
        cout << decimalToBinary(i) << endl;
    return 0;
}
