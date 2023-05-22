/*
Resources used:
iterator1.cpp - demonstrates using iterators for I/O (from intermediate programming course)
https://www.youtube.com/watch?v=SgcHcbQ0RCQ
*/

#include <iostream>
#include <vector>

int main(){
    std::vector<int> eggs{5, 10, 15, 20, 16};

    //how I normally do it using indexes
    for(int i = 0; i < eggs.size(); i++){
        std::cout << eggs[i] << " " << '\n';
    }
    std::cout << std::endl;
    
    //range based loop "foreach" loop I used in Java that also works in c++
    //this probably uses iterators in the background. The video reference
    //had documentation available offline, so I'll find a way to secure a copy too
    //so I can know for sure
    for(int egg : eggs){
        std::cout << egg << " " << '\n';
    }
    std::cout << std::endl;

    //using iterators; begin() "points" to the first element and end() points to
    //a unit after the last element. iterators are kindof like pointers with more
    //functionality specific to the container. They are used to iterate through elements
    //in a container. I could implement an iterator myself, kind of or something that funtions
    //similarly.
    for(std::vector<int>::iterator i = eggs.begin(); i != eggs.end(); i++){
        std::cout << *i << " " << '\n';
    }
    std::cout << std::endl;

    return 0;
}