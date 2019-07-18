//Initial Template for C++
#include <iostream>
#include <vector>
using namespace std;

/*Statement : You need to find the gray code of the number decimal number N.  
and conver it into decimal. */

//  Function to find the gray code of given number N
char xor_c(char a, char b) { return (a == b) ? '0': '1';}

// Function to convert binary string to gray strings
string convertBinaryToGray(string binary) {
    string gray = "";
    gray += binary[0];
    for(int i = 1; i < binary.length(); i++){
        gray += xor_c(binary[i], binary[i-1]);
    }
    return gray;
}

// fn to convert decimal intger to binart string
string convertToBinary(int n) {
    string binary = "";
    vector<int> bin;
    while(n != 0) {
        int bit = n % 2;
        bin.push_back(bit);
        n = n / 2;
    }
    for (auto i = bin.rbegin(); i != bin.rend(); i++) {
        if (*i) {
            binary += "1";
        } else {
            binary += "0";
        }
    }
    return binary;
}

// fn to convert binary string to decimal integer
int grayToDecimal(string gray) {
    int deci = 0;
    int base = 1;
    int n = gray.length();
    for(int i = n-1; i >= 0; i--) {
        if (gray[i] == '1') {
            deci += base;
        }
        base = base*2;
    }
    return deci;
}

int greyConverter(int n)
{
    string binaryEq = convertToBinary(n);
    // convert decimal to binary
    string gray = convertBinaryToGray(binaryEq);
    int grayInDecimal = grayToDecimal(gray);
    return grayInDecimal;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin >> n;
        cout << greyConverter(n) << endl;
    }
}