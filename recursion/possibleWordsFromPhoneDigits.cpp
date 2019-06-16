// amazon flipkart
#include <iostream>
#include <string>
using namespace std;
void possibleWords(int a[],int n);
int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	  possibleWords(a,N);
	   cout << endl;
	}
	
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//Complete this function
const char hashTable[10][5]={"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
void printWordsUtil(int number[], int curr_digit, char output[], int N){
    int i;
    if (curr_digit == N) {
        cout << output << " ";
        return;
    }
    for(i = 0; i < strlen(hashTable[number[curr_digit]]); i++){
        output[curr_digit] = hashTable[number[curr_digit]][i];
        printWordsUtil(number, curr_digit+1, output, N);
        if (number[curr_digit] == 0 || number[curr_digit] == 1){
            return;
        }
    }
}
void possibleWords(int a[],int N)
{
    //Your code here
    char result[N+1];
    result[N] = '\0';
    printWordsUtil(a, 0, result, N);
    
}