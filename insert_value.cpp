/*
In this challenge, you have to implement the insert function which will be taking three parameters as inputs: array, rightIndex, and value.

https://www.educative.io/courses/visual-introduction-to-algorithms/xlVMLPBYQA9#Problem-Statement:
*/

#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int>&, int, int);

int main(){
    vector<int> arr = {3, 5, 7, 11, 13, 2, 9, 6};
    int right_index = 4;
    int value = 2;

    cout << "Original Array: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "right_index " << right_index << endl;
    cout << "value " << value << endl;
    
    insert(arr, right_index, value);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void insert(vector<int>& array, int right_index, int value) {

  for(int i = right_index; i >= 0; i--){

        if(value < array[i]){
            array[i+1] = array[i];
        } else{
            array[i+1] = value;
            break;
        }

        if(i == 0){
            array[i] = value;
            break;
        }
  }

};