/*
A solution to this problem: https://www.hackerrank.com/challenges/cpp-lower-bound/problem?isFullScreen=true
Haccerank flags this solution to be inefficient, not optimised. I did this using a brute force algorithm. I'll try a different algo next time, and a predefined funtion too
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
    int arr[N];
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> Y;
        
        bool found = false;
        for(int v = 0; v < N && !found; v++){
            if(arr[v] == Y){ 
                cout << "Yes " << (v + 1) << endl;
                found = true;
            } else if (arr[v] > Y) {
                cout << "No " << (v + 1) << endl;
                found = true;
            }
        }
    }
    return 0;
}
