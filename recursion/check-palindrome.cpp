#include <iostream>

using namespace std;

bool isPalindrome(char str[], int s, int e) {

    // if there is only one character
    if (s == e) return true;

    if (str[s] == str[e]){
    // if there are two characters check if middle substring is 
    // palindrome or not
        return isPalindrome(str, s+1, e-1);
    } else {
    // if first and last character do not match
        return false;
    }
}

int main() {
    char str[] = {'m', 'a', 'l', 'a','y', 'a', 'l', 'a', 'm'};
    int n = sizeof(str)/sizeof(str[0]);
    bool palindrome = isPalindrome(str, 0, n-1);
    cout << "Is Palindrome: " << palindrome << endl;
}