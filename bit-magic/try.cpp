#include <iostream>

using namespace std;

// brihanghan alogrithm
int countSet(int n) {
    int res = 0;
    while (n > 0) {
        n = ( n & n-1 );
        res++;
    }
    return res;
}

int countSetTillN(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++){
        count += countSet(i);
    }
    return count;
}

int main() {
    int n = 17;
    int noOfSetBits = countSetTillN(n);
    cout << "No of set bits " << noOfSetBits << endl;
}