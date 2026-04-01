#include<bits/stdc++.h>
using namespace std;

class nQueen {
public:
    char **result;
    int n;
    
    bool isSafe(int row, int col) {
        for(int i = row; i >= 0; i--) {
            if(result[i][col] == 'Q')
                return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(result[i][j] == 'Q')
                return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(result[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
    bool solve(int row, int n) {
        if(row == n) {
            return true;
        }
        for(int col = 0; col < n; col++) {
            if(isSafe(row, col)) {
                result[row][col] = 'Q';
                if(solve(row + 1, n))
                    return true;
                result[row][col] = '.';
            }
        }
        return false;
    }
};

int main() {
    int n;
    cout << "Enter size of board: " << endl;
    cin >> n;
    
    nQueen obj;
    obj.n = n;
    obj.result = new char*[n];
    for(int i = 0; i < n; i++) {
        obj.result[i] = new char[n];
        for(int j = 0; j < n; j++) {
            obj.result[i][j] = '.';
        }
    }
    
    if(obj.solve(0, n)) {
        cout << "Board:" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << obj.result[i][j] << "   ";
            cout << endl;
        }
    } else {
        cout << "No solution" << endl;
    }
    
    // Deallocate memory
    for(int i = 0; i < n; i++) {
        delete[] obj.result[i];
    }
    delete[] obj.result;
    
    return 0;
}