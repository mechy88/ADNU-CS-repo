/*
Finish writing the function indexOfMinimum, which takes an array and a number startIndex, and returns the index of the smallest value that occurs with index startIndex or greater. If this smallest value occurs more than once in this range, then return the index of the leftmost occurrence within this range.

The challenge was easy, but it took some time to realize that sizeof(array)/sizeof(array[minValue]) doesn't work since the data structure used was a vector and not an array, thus doesn't have fixed size per element. Easily fixed with size() function 
*/

#include <vector>
#include <iostream>

using namespace std;

int indexOfMinimum(const vector<int>&, int);

int main(){
    vector<int> arr = {18, 6, 66, 44, 9, 22, 14, 5};
    int start = 2;

    cout << indexOfMinimum(arr, start) << endl;

    return 0;
}

int indexOfMinimum(const vector<int>& array, int startIndex) {
    // Set initial values for minValue and minIndex,
    // based on the leftmost entry in the subarray:  
    int minValue = array[startIndex];
    int minIndex = startIndex;

    // Loop over items starting with startIndex, 
    // updating minValue and minIndex as needed:
    int size = array.size();
    for(int i = startIndex; i < size; i++){
        if(array[i] < minValue){
            minValue = array[i];
            minIndex = i;
        }
    }
    
    return minIndex;
};