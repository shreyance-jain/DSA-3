//Initial Template for C++
#include <iostream>
#include <vector>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// function to conver given N Gray to Binary
char xor_c(char a, char b) { return ((a == b) ? '0': '1'); }

int convertBinaryToDecimal(string binary) {
    int base = 1;
    int decimal = 0;
    int n = binary.length();
    for(int i = n-1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base = base*2;
    }
    return decimal;
}

string convertDecimalToBinary(int n) {
    string binary = "";
    vector<int> bin;
    while (n) {
        int bit = n % 2;
        bin.push_back(bit);
        n = n/2;
    }
    for(auto i = bin.rbegin(); i != bin.rend(); ++i) {
        if(*i) {
            binary += "1";
        } else {
            binary += "0";
        }
    }
    return binary;
}

string convertGrayToBinary(string gray) {
    string binary = "";
    binary += gray[0];
    for(int i = 1; i < gray.length(); i++) {
       binary += xor_c(gray[i], binary[i-1]); 
    }
    return binary;
}

int grayToBinary(int n)
{
    string gray = convertDecimalToBinary(n);
    string binary = convertGrayToBinary(gray);
    int decimal = convertBinaryToDecimal(binary);
    return decimal;
}

// Driver code
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
       cout<< grayToBinary(n)<<endl;
    }
}