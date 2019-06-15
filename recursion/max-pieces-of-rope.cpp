#include <iostream>

using namespace std;

int max3(int a, int b, int c) {
    int res = max(a,b);
    res = max(res, c);
    return res;
}

/**
 * The idea is to consider every possibility using recursion. 
 * We consider all three choices for the first cut. 
 * Recursively compute number of pieces for every choice. 
 * If none of the choices lead to a solution, we return -1. 
 * Otherwise, we return the maximum.
 */

/**
 * Illustration - For n = 23, we make three recursive calls for 23-9, 23-11 and 23-12 
 * which are for 14, 12 and 11 respectively.
 *  Each of these 3 makes three recursive calls. 
 * 14 makes three recursive calls for 14-9, 14-11 and 14-12.
 * Similarly, 12 and 11 make three recursive calls. 
 * This keeps on going until we reach either 0 or negative value.
 * 
 * Note that all values at leaves are negative and they will return -1. 
 * So, parents of all -ve will return -1. 
 * So you get -1 from the first recursive call for 14. 
 * From second and third recursive calls you get 1. You add 1 to it and return 2
 */

int maxCuts(int n, int a, int b, int c) {
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;
    int result = max3(maxCuts(n-a, a, b, c), maxCuts(n-b, a, b, c),maxCuts(n-c, a, b, c));
    if (result == -1) {
        return -1;
    } else  {
        return result + 1;
    }
}

int main() {
    int n = 23, a = 11, b = 12, c= 9;
    cout << maxCuts(n, a, b, c) << endl;
}