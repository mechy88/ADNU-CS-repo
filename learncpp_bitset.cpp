/*
Learning Bit flags and bit manipulation via std::bitset from: https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/
*/
#include <iostream>
#include <bitset>

int main(){
    std::bitset<4> bitty;
    std::cout << bitty; //output: 0000 //I guess the default is off/false/zero
    std::bitset<4> x{0b01010};
    std::cout << x; //output: 00001010
    x.flip(1);
    std::cout << x; //000010101000 as expected
    return 0;
}