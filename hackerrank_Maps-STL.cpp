/*
A solution to this problem: https://www.hackerrank.com/challenges/cpp-maps/problem?isFullScreen=true
This problem was quite easy, especially with the help of stack overflow. I was initially confused as to what
itr->second meant. I got a clafication from (https://stackoverflow.com/questions/15451287/what-does-iterator-second-mean),
so maps are esentially a list of the pair data structure, and I'm actually accessing the 2nd element of the pair.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q, order;
    
    string name;
    int grade;
    
    map <string, int> m;
    
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> order;
        
        if(order == 1){
            cin >> name >> grade;
            map<string, int>::iterator itr=m.find(name);
            if(itr == m.end()){
                m.insert(make_pair(name, grade));
            } else{
                itr->second += grade;
            }
        } else if(order == 2){
            cin >> name;
            m.erase(name);
        } else{
            cin >> name;
            map<string, int>::iterator itr=m.find(name);
            if(itr == m.end()){
                cout << 0;
            } else{
                cout << itr->second;
            }
            cout << endl;
        }
    }
    return 0;
}