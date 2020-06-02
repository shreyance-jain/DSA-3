/* 
Huffman Decoding

Difficulty: Easy     
Problem Statement

Given a binary encoded string and a Huffman MinHeap tree,
your task is to complete the function decodeHuffmanData(),
which decodes the binary encoded string and return the original string. 

Example:

Input Data : AAAAAABCCCCCCDDEEEEE
Frequencies : A: 6, B: 1, C: 6, D: 2, E: 5
Encoded Data : 
0000000000001100101010101011111111010101010
Huffman Tree: '#' is the special character used for 
               internal nodes as character field is 
               not needed for internal nodes. 
               #(20)
             /       \
        #(12)         #(8)
     /      \        /     \
    A(6)     C(6) E(5)     #(3)
                         /     \
                       B(1)    D(2)  
Code of 'A' is '00', code of 'C' is '01', ..
Decoded Data : AAAAAABCCCCCCDDEEEEE

Input:
The function takes two arguments as input, the reference pointer to the
root of the Huffman minheap tree and an binary encoded string.
There will be T test cases and for each test case the function will be called separately.

Note: Input test cases contains English alphabetical string of size N,
that will be encoded using Huffman Encoding and the encoded string will be provided to you.

Output:
For each test case print the decoded string from the provided encoded string.

Constraints:
1<=T<=200
1<=N<=103

Example:
Input:
2
01110100011111000101101011101000111
1011010011100101101110111
Output:
geeksforgeeks
India
Note: Ouput of the program would be same as input. It decodes and encodes internally.
The output shown above is for locial purpose
 */


// C++ program to encode and decode a given string using
// Huffman Coding
#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std;

// to map each character its huffman value
map<char, string> codes;

// to store frequency of character of input data
map<char, int> freq;

// A huffman tree node
struct MinHeapNode
{
	char data;	// one of the input characters
	int freq;	// frequency of this character
	MinHeapNode *left, *right;	// left and right child
	MinHeapNode(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};


// compartor for the priority queue
struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

// utility function to print characters along with their huffman value
void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// utility function to store characters along with the huffman value in a hash table
// here we have C++ STL map
void storeCodes(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;
	if (root->data != '$')
		codes[root->data]=str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

// STL priority queue to store heap tree, with respect to their heap root node value
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;


// function to build the Huffman tree and store it in minHeap
void HuffmanCodes(int size)
{
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}

// utility function to store map each character with its frequency in input string
void calcFreq(string str, int n)
{
	for (int i=0; i<str.size(); i++)
		freq[str[i]]++;
}

// complete this function
string decodeHuffmanData(struct MinHeapNode* root, string binaryString);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        string encodedString, decodedString;
        calcFreq(str, str.length());
        HuffmanCodes(str.length());
        for (auto i: str)encodedString+=codes[i];
        //cout<<encodedString<<endl;
        decodedString = decodeHuffmanData(minHeap.top(), encodedString);
        cout << decodedString << endl;
    }
	return 0;
}

/*
To decode the encoded data we require the Huffman Tree. We iterate through the binary
encoded data. To find character correspoding to current bits, we use the following steps:

1. We start from root and do the following until a leaf is found.
2. If current bit is 0, we move to left node of the tree
3. If the bit is 1, we move to right node of the tree
4. If during traversal, we encounter a leaf node, we print characters of
that particular leaf node and then again continue the iteration of 
the encoded data starting from step 1
 */
string decodeHuffmanData(struct MinHeapNode* root, string s)
{
    string ans = ""; 
    struct MinHeapNode* curr = root;
    for (int i=0;i<s.size();i++) 
    { 
        if (s[i] == '0') 
           curr = curr->left; 
        else
           curr = curr->right; 
  
        // reached leaf node 
        if (curr->left==NULL && curr->right==NULL) 
        { 
            ans += curr->data;
            curr = root; 
        } 
    } 
    // cout<<ans<<endl; 
    return ans+'\0'; 
}

/* 
Comparing Input file size and Output file size:
Comparing the input file size and the Huffman encoded output file.
We can calculate the size of the output data in a simple way.
Lets say our input is a string “geeksforgeeks” and is stored in a file input.txt.
Input File Size:

Input: "geeksforgeeks"
Total number of character i.e. input length: 13
Size: 13 character occurrences * 8 bits = 104 bits or 13 bytes.

Output File Size:

Input: "geeksforgeeks"
------------------------------------------------
Character |  Frequency |  Binary Huffman Value |
------------------------------------------------
   e      |      4     |         10            |
   f      |      1     |         1100          |   
   g      |      2     |         011           |
   k      |      2     |         00            |
   o      |      1     |         010           |
   r      |      1     |         1101          |
   s      |      2     |         111           |
------------------------------------------------

So to calculate output size:
e: 4 occurrences * 2 bits = 8 bits
f: 1 occurrence  * 4 bits = 4 bits
g: 2 occurrences * 3 bits = 6 bits
k: 2 occurrences * 2 bits = 4 bits
o: 1 occurrence  * 3 bits = 3 bits
r: 1 occurrence  * 4 bits = 4 bits
s: 2 occurrences * 3 bits = 6 bits

Total Sum: 35 bits approx 5 bytes

Hence, we could see that after encoding the data we have saved a large amount of data.
The above method can also help us to determine the value of N i.e. the length of the encoded data.
 */
