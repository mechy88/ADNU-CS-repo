/*
This code is my solution for https://www.hackerrank.com/challenges/cpp-sets/problem?isFullScreen=true
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x, type, num;
    set<int> s;
    
    cin >> x;
    for(int i = 0; i < x; i++){
        cin >> type >> num;
        
        if(type == 1){
            s.insert(num);
        } else if(type == 2){
            s.erase(num);
        } else{
            if(s.find(num) == s.end()){
                cout << "No" << endl;
            } else{
            cout << "Yes" << endl;
            }
        }
    }
    return 0;
}