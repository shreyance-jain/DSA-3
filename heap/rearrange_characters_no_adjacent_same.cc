/* 
Rearrange characters

Difficulty: Medium

Problem Statement

Given a string S with repeated characters (only lowercase).
The task is to rearrange characters in a string such that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case contains a single line containing a string
of lowercase english alphabets.

Output:
For each test case in a new line print "1" (without quotes) if the generated string doesn't contains any same adjacent characters, else if no such string is possible to be made print "0" (without quotes).

Constraints:
1 <= T <= 100
1 <= length of string <= 104

Example:
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb

Output:
1
1
0

Explanation:
Testcase 1: All the repeated characters of the given string can be rearranged so that no adjacent characters in the string is equal.
Testcase 3: Repeated characters in the string cannot be rearranged such that there should not be any adjacent repeated character.
 */

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

string rearrangeString(string);

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str;
	    cin>>str;
	    str = rearrangeString(str);
	    int flag = 1;
	    if(str != "-1"){
    	for(int i=1;i<str.length();i++){
    		if(str[i-1]==str[i])
    			flag=0;
	    }
    	if(flag == 1)
    		cout<<"1\n";
    	else
    	    cout<<"0\n";
	    }
	    else
	        cout<<"0\n";
	}
    return 0;
}

/* 
The idea is to put the highest frequencty character first (a greedy approach).
We use a priority queue (or Binary Max Heap) and put all the characters ordered by their
frequencies (highest frequency character at top). We one by one take highest frequency
character from the heap and add it to the result. After we add,
we decrease the frequency of the character and we temporarily move this character out of 
prirority queue so that it is not picked next time.

Algo:
1. Build a priority_queue or max_heap, pq that stores characters and their frequencies.
Priority_queue or max heap is built on the basis of frequency of the character.

2. Create a temporary Key that will be used as the previously visited element(the previous
element in the resultant string). Initialise it {char = '#', freq = -1}

3. While pq is not empty
    a. Pop an element and add it to the result.
    b. Decrease frequency of the popped element by '1'
    c. Push the previous element back into the priority_queue if it's frequency > '0'
    d. Make the current element as the previous element for the next iteration.

4. If the lenght of the resultant string and original string is not equal, print "not possible"
    else print the result.
 */
struct Key { // key of priority queue
    int freq;
    char ch;

    // funtion for priority_queue to store key according
    // to frequency
    bool operator<(const Key &k) const{
        return freq < k.freq;
    }
};

string rearrangeString(string str){
    int n = str.length();

    // store frequencies of all characters in string
    int count[MAX_CHAR] = {0};
    for(int i = 0; i < n; i++) {
	    count[str[i] - 'a']++;
	}

    // insert all characters with their frequencies 
    // into a priority queue
    priority_queue<Key> pq;
	
	for(char c = 'a'; c <= 'z'; c++)
	    if (count[c - 'a'] != 0)
	        pq.push(Key {count[c - 'a'], c});
	
    // string s will use the resultant string
	string s;

    // work as previous visited element
    // initial previous element be. ('#' and its freq be '-1')
	Key prev {-1, '#'};
    
    // traverse queue
	while(pq.empty() == false) {
        // pop top element and add it to string
	    Key k = pq.top();
	    pq.pop();
	    s += k.ch;

        // decrease frequency by 1
	    (k.freq)--;
	    
        // if the freq of prev item is less than 0, it means
        // it is useless, we need not push it
	    if (prev.freq > 0)
	        pq.push(prev);
	   
        // make the current character as prev
        // as it will serve prev for next iteration
	    prev = k;
	}
	if (s.length() != str.length())
	    return "-1";
	return s;
}

// Time complexity: O(nlogn) // to remove n items from max heap
// Space complexity: O(1) for freq array, O(n) for heap of struct {freq, ch}

// Company tags: Amazon
