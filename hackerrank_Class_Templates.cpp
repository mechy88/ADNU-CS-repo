/*
A solution to this problem: https://www.hackerrank.com/challenges/c-class-templates/problem?isFullScreen=true
This program implements Class templates, meaning a class is able to handle different kinds of data types to perform
general operations. The program also implements specialized templates where I can dictate the behaviour of the class
depending on the data type of the input.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/
template <class T>
class AddElements{
    public:
    AddElements(T arg){
        element = arg;
    }
    T add(T addend){
        return addend + element;
    }
    private:
        T element;
};

template <>
class AddElements <> {
    public:
    AddElements(string arg){
        element = arg;
    }
    string concatenate(string arg){
        string temp;
        temp = element + arg;
        return temp;
    }
    private:
        string element;
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
