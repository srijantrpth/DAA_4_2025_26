#include<bits/stdc++.h>
using namespace std;

class nQueen_2 {
public:
    char **result;
    int n, count;
    
    nQueen_2() : count(0) {}
    
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
    
    void solve(int row, int n) {
        if(row == n) {
            count++;
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isSafe(row, col)) {
                result[row][col] = 'Q';
                solve(row + 1, n);
                result[row][col] = '.';
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter size of board: " << endl;
    cin >> n;
    
    nQueen_2 obj;
    obj.n = n;
    obj.result = new char*[n];
    for(int i = 0; i < n; i++) {
        obj.result[i] = new char[n];
        for(int j = 0; j < n; j++) {
            obj.result[i][j] = '.';
        }
    }
    
    obj.solve(0, n);
    cout << "It has " << obj.count << " distinct solutions" << endl;
    
    // Deallocate memory
    for(int i = 0; i < n; i++) {
        delete[] obj.result[i];
    }
    delete[] obj.result;
    
    return 0;
}