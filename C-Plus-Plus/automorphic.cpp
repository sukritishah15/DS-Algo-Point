#include <iostream>

/**
 * @brief check if the number is automorphic
 * @param a the natural number to check
 * @return bool true if number is automorphic and its square can fit within
 *          64 bits.
 */
bool automorphic_number(unsigned int a)
{
    unsigned long long b = a * a;

    while (a != 0)
    {
        if (a % 10 != b % 10)
            return false;
        else
        {
            a /= 10;
            b /= 10;
        }
    }

    return true;
}

int main()
{
    unsigned int a;
    std::cin >> a;

    if (automorphic_number(a))
        std::cout << a << " is an automorphic number.\n";
    else
        std::cout << a << " is not an automorphic number.\n";
}

/*
Time complexity: O(log_10 a)
Space complexity: O(2)

An automorphic number (sometimes referred to as a circular number) is a natural number in a given number base b whose square "ends" in the same digits as the number itself.
Here we are considering base 10.

INPUT:
5
OUTPUT:
5 is an automophic number.

INPUT:
25
OUTPUT:
25 is an automophic number.

INPUT:
6
OUTPUT:
6 is not an automophic number.

*/