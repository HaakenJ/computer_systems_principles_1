// Created by Kramer Johnson
// 01/08/21
// Version 1.0



#include <iostream>
using namespace std;

// Function:      power
// Purpose:       computes num to the exp power
// Parameters:  The number – num, and the exponent – exp
// Returns:       0 if exp is negative; 1 if exp is 0; raise num to the exp
//                power otherwise.
int power(int num, int exp) {
    if (exp <  0) return 0;
    if (exp == 0) return 1;

    int result = num;
    for (int i = 1; i < exp; i++) {
        result *= num;
    }
    return result;
}

/*
 * Computes the log of a number with a given base
 *
 * @throws      invalid_argument if base is less than or equal to 1
 * @param base  the base number to calculate with
 * @param num   the number to find the log of
 * @return      the logorithm of num with base base
 */
int myLog(int base, int num) {
    if (base <= 1)
        throw invalid_argument("Log with base 1 or below is "
                               "undefined for real numbers");

    int result = 1;
    while (power(base, result) < num) {
        result++;
    }
    return (power(base, result) > num ? --result : result);
}

/*
 * Test driver for power function.
 * Notifies client of failure and returns if any test fails.
 */
void testPower() {
    if (power(2, -1) != 0) {
        cout << "Failed at exp = -1" << endl;
        return;
    }

    if (power(2, -200) != 0) {
        cout << "Failed at exp = -200" << endl;
        return;
    }

    if (power(2, 0) != 1) {
        cout << "Failed at exp = 0" << endl;
        return;
    }

    if (power(2, 3) != 8) {
        cout << "Failed at num = 2 and exp = 3" << endl;
        return;
    }

    if (power(3, 4) != 81) {
        cout << "Failed at num = 3 exp = 4" << endl;
        return;
    }
}

/*
 * Test driver for myLog function.
 * Notifies client of failure and returns if any test fails.
 */
void testLog() {
    if (myLog(2, 16) != 4) {
        cout << "Failed at base 2 num 16" << endl;
        return;
    }
    if (myLog(5, 625) != 4) {
        cout << "Failed at base 5 num 625" << endl;
        return;
    }
    if (myLog(5, 777) != 4) {
        cout << "Failed at base 5 num 777" << endl;
        return;
    }
    if (myLog(2, 1024) != 10) {
        cout << "Failed at base 2 num 1024" << endl;
        return;
    }
    try {
        myLog(0, 2343);
        cout << "Failed at base 0" << endl;
    } catch (invalid_argument) {
    }

    try {
        myLog(1, 2343);
        cout << "Failed at base 1" << endl;
    } catch (invalid_argument) {
    }

    try {
        myLog(-4, 234);
        cout << "Failed at base -4" << endl;
    } catch (invalid_argument) {
    }
}

int main() {
    testPower();
    testLog();

    int base = 0;
    int exp  = 0;
    int num = 0;

    cout << "---Power test---" << endl;
    cout << "Enter a base: ";
    cin >> base;

    cout << "Enter an exponent: ";
    cin >> exp;

    cout << base << " to the " << exp;
    cout << " is " << power(base, exp) << endl;

    cout << endl;

    cout << "---Log test---" << endl;
    cout << "Enter a base: ";
    cin >> base;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Log of " << num << " base " << base;
    cout << " is " << myLog(base, num) << endl;

    return 0;
}
