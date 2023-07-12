#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>&, int, int);
int indexOfMinimum(vector<int>, int);
void selectionSort(vector<int>&);

int main(){
    vector<int> arr = {18, 6, 66, 44, 9, 22, 14, 5};
    selectionSort(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void swap(vector<int>& array, int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int indexOfMinimum(vector<int> array, int startIndex) {
    int minValue = array[startIndex];
    int minIndex = startIndex;

    for(int i = minIndex + 1; i < array.size(); i++) {
        if(array[i] < minValue) {
            minIndex = i;
            minValue = array[i];
        }
    } 
    return minIndex;
}; 

void selectionSort(vector<int>& array) {
  // Write this method
  for(int i = 0; i < array.size(); i++){
    int min_index = indexOfMinimum(array, i);
    if(min_index != i){
        swap(array, i, min_index);
    }
  }
};