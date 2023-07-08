#include <iostream>

using namespace std;

int binarySearch(int, int[], int);

int main(){
    int numbers[] = {20, 30, 40, 50, 55, 60, 70, 80, 90};
    int num = sizeof(numbers)/sizeof(numbers[0]);
    cout << binarySearch(80, numbers, num);
    return 0;
}

int binarySearch(int target, int arr[], int size){
    int min = 0, max = size;
    int hula;
    while(true){
        hula = (min + max)/2;

        if(min > max){
            return -1;
        }
        if(arr[hula] == target){
            return hula;
        }
        
        if(target < arr[hula]){
            max = hula - 1;
        } else{
            min = hula + 1;
        }
    }
}