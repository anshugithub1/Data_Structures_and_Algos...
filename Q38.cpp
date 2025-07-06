/*
CodeChef: Necklace (Company problem - Amazon)
Problem Statement:
Your best friend has a very interesting necklace with n pearls. On each of the pearls of the necklace there is an integer. However, your friend wants to modify the necklace a bit and asks you for help. She wants to move the first pearl k spots to the left (and do so with all other pearls).

For example: if the necklace was originally 1,5,3,4,2 and k=2, now it becomes 3,4,2,1,5.

Help your best friend determine how the necklace will look after the modification.
 
Input Format:
First line will contain T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input, the first containing two integers n,k.
The second line of each test case contains n integers representing the integers on the pearls starting from the first one.

Output Format:
For each testcase, output in a single line n integers representing the necklace after modification.

*/
#include <bits/stdc++.h>
using namespace std;

// this template Function is same as the built-in reverse function, just implemented the my version of it. 
template<typename T>
void UnoReverse(T a, T b){
    b--; // excluding the end iterator.
    while(a<b){
        swap(*a, *b);
        a++;
        b--;
    }
}


void solve(){
    int n,k;
    cin>>n>>k;
    
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    
    UnoReverse(a.begin(),a.begin()+k);
    UnoReverse(a.begin()+k,a.end());
    UnoReverse(a.begin(),a.end());
    
    for (auto i : a) {
        std::cout << i << " ";
    }
    cout<<std::endl;
}



int main() {
	// Necklace
	
	int T;
	cin>>T;
	
	while(T--){
	    solve();
	}

}
