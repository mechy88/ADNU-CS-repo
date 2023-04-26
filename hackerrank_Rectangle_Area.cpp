/*
A solution to this problem: https://www.hackerrank.com/challenges/rectangle-area/problem?isFullScreen=true
The problem had me apply OOP. I learned the need to add public to a parent class when declaring an inheritance
relationship with a derived class to facilitate public inheritance. I tried omitting the public keyword, but methods in
the Rectangle class became unaccessible to RectangleArea class. 
*/

#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
 class Rectangle{
 public:
        int width, height;
        void display(){
            cout << width << " " << height << endl;
        }
 private:
 };
 
 class RectangleArea : public Rectangle{
 public:
    void display(){
        cout << (width*height) << endl;
    }
    void read_input(){
        cin >> width >> height;
    }
 private:
 };


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}