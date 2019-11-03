#include <bits/stdc++.h>
using namespace std;

int repeatedCharacter (string s);

// driver code
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    int index = repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}


/* 
Naive Approach will be to run two loops and if we find a repeating character break from the loop
O(n) soultion will be two run a loop keep track of left most index and a variable res
whenever a repeadted character is found update the res

A good tricker solution would be to travers the string from the right
maintain a left index array and update res when repeated character is found
 */
int repeatedCharacter (string s) 
{ 
    int n = s.length();
    int li[256];
    memset(li, -1, sizeof(li));   
    int res = -1;
    
    for(int i = n-1; i >= 0; i--) {
        if(li[s[i]] == -1)
            li[s[i]] = i;
        else
            res = i;
    }
    return res;
}

// Time Complexity: O(n), single traversal
// Space Complexity: O(Alphabet_size)
// Comapny tags: Goldman Sachs