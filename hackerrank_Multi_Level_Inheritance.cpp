/*
A solution to this problem: https://www.hackerrank.com/challenges/multi-level-inheritance-cpp/problem?isFullScreen=true
The problem was easy. I understand that multiple levels of inheritance can happen (I've already understood this in Java).
An object of type Equilateral have methods and variables defined in both the Triangle and Isoceles classes. If I were to put
another class under Equilateral, the class under Equilateral will also inherit from Triangle, Isoceles, and Equilateral plus having
it's own methods and variables.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
		}
};

class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};

//Write your code here.
class Equilateral : public Isosceles{
    public:
        void equilateral(){
            cout << "I am an equilateral triangle\n";
        }
};
int main(){
  
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}