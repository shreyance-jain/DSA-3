#include <iostream>
#include <string>

using namespace std;

void permute(string str, int l, int r) {
    if (l == r) {
        cout << str << " ";
        return;
    }
    else {
        for(int i = l; i <= r; i++) {
            swap(str[i], str[l]);
            permute(str, l+1, r);
            swap(str[i], str[l]);
        }
    }
}

int main() {
    string str = "ABC";
    int n = str.length();
    permute(str, 0, n-1);
}