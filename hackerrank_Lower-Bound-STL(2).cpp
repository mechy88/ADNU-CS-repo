/*
A solution to this problem: https://www.hackerrank.com/challenges/cpp-lower-bound/problem?isFullScreen=true
More efficient version that passes all test cases
I had trouble understanding (a - arr.begin() + 1) but I realized as a pointer, a would have a lot of extra values, so removing the
value extras on the address would correct the value for finding the current index
say for example a is at address 1005, and begin is at 1000, to find the index I just have to subtract 1000 from 1005
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, temp, Q, Y;
    cin >> N;
    vector<int> arr;
    
    for(int i = 0; i < N; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> Y;
        
        vector<int>::iterator a = lower_bound(arr.begin(), arr.end(), Y);
        if(Y == *a)
            cout << "Yes " << a - arr.begin() + 1 << endl;
        else
            cout << "No " << a - arr.begin() + 1  << endl;
    }
    return 0;
}
