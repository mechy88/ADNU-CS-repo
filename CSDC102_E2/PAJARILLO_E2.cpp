#include <iostream>
#include <vector>

using namespace std;

vector<int> findLargestBlock(const vector<vector<int>>&);
bool maxSquareSubmatrix(const vector<vector<int>>&, int, int, int, int);

int main(){
    int rows, &cols = rows;

    cout << "Enter the number of rows for the matrix: ";
    cin >> rows;

    vector<vector<int>> myMatrix;

    cout << "Enter the matrix row by row:" << endl;

    for(int i = 0; i < rows; i++){
        vector<int> temp;
        for(int v = 0; v < cols; v++){
            int num;
            cin >> num;
            temp.push_back(num);
        }
        myMatrix.push_back(temp);
    }
    cout << endl;

    vector<int> answer = findLargestBlock(myMatrix);

    printf("The maximum square submatrix is at (%d, %d) with size %d", answer[0], answer[1], answer[2]);
    

    cout << endl;


    return 0;
}

vector<int> findLargestBlock(const vector<vector<int>>& m){
    vector<int> returnValue;
    int side = m.size();
    bool found = false;

    for(int i = 0; i < side && !found; i++){
        for(int v = 0; v < (i + 1) && !found; v++){
            for(int b = 0; b < (i + 1) && !found; b++){
                found = maxSquareSubmatrix(m, side, v, b, i);
                if(found){
                    returnValue.push_back(v);
                    returnValue.push_back(b);
                    returnValue.push_back((side - i));
                }
            }
        }
    }

    return returnValue;
}

bool maxSquareSubmatrix(const vector<vector<int>>& m, int side, int x, int y, int iteration){
    bool returnValue;
    int total = 0, goal = (side - iteration) * (side - iteration);
    for(int i = 0; i < (side - iteration); i++){
        for(int v = 0; v < (side - iteration); v++){
            total += m[x + i][y + v];
        }
    }

    return (total == goal);
}
