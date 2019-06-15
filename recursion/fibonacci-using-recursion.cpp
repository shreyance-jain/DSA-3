#include <iostream>

using namespace std;

long long fibonacci(int n);

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        cout << fibonacci(n) << endl;
    }
}

long long fibonacci(int n){
    if (n < 1) return -1;
    if (n == 1 || n == 2) return 1;
    return (fibonacci(n-1) + fibonacci(n-2));
}
