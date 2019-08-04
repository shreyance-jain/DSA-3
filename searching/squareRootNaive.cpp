/*
Square root of an integer

Problem Statement
Given an integer x, find square root of it. If x is not a perfect square, then return floor(√x).
*/

#include <iostream>

using namespace std;

int squareRoot(int n) {
    if (n == 0 || n == 1) return n;
    int i = 1, result = 1;
    while(result <= n) {
        i++;
        result = i*i;
    }
    return i -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sq_root = squareRoot(n);
        cout << "square root or floor of square root " << sq_root << endl;
    }
}

// Time: O(root n)