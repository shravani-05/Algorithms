#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> add(const vector<vector<int>>& A, const vector<vector<int>>& B){
    int n = A.size();

    vector<vector<int>> result(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

vector<vector<int>> subtract(const vector<vector<int>>& A, const vector<vector<int>>& B){
    int n = A.size();

    vector<vector<int>> result(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

vector<vector<int>> strassen(const vector<vector<int>> &A, const vector<vector<int>> &B){
    int n = A.size();

    if(n == 1){
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;

    vector<vector<int>> A11(newSize, vector<int>(newSize)),
    A12(newSize, vector<int>(newSize)),
    A21(newSize, vector<int>(newSize)),
    A22(newSize, vector<int>(newSize)),
    B11(newSize, vector<int>(newSize)),
    B12(newSize, vector<int>(newSize)),
    B21(newSize, vector<int>(newSize)),
    B22(newSize, vector<int>(newSize));


    for(int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+newSize];
            A21[i][j] = A[i+newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][newSize];
            B21[i][j] = B[i+newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];


        }
    }

    vector<vector<int>> M1 = strassen(add(A11, A22), add(B11, B22));
    vector<vector<int>> M2 = strassen(add(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, subtract(B12, B22));
    vector<vector<int>> M4 = strassen(A22, subtract(B21, B11));
    vector<vector<int>> M5 = strassen(add(A11, A12), B22);
    vector<vector<int>> M6 = strassen(subtract(A21, A11), add(B11, B12));
    vector<vector<int>> M7 = strassen(subtract(A12, A22), add(B21, B22));


    vector<vector<int>> C(n, vector<int>(n));
    for(int i = 0; i < newSize ; i++){
        for(int j = 0; j < newSize; j++){
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + newSize] = M3[i][j] + M5[i][j];
            C[i + newSize][j] = M2[i][j] + M4[i][j];
            C[i + newSize][j + newSize] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    return C;

}

void printmatrix(const vector<vector<int>> A){
    int n = A.size();
    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(){
    int n;
    cout<<"Enter the dimension of the matrix in the (power of 2): ";
    cin>>n;

    if (!isPowerOfTwo(n)) {
        cout << "Error: Dimension must be a power of 2." << endl;
        return 1;
    }
    vector<vector<int>> A(n,vector<int>(n)) , B(n,vector<int>(n));//definiing 2D matrix fro dynamic allocation

    cout<<"Enter the elements of matrix A: "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>A[i][j];
        }
    }

    cout<<"Enter the elements of matrix B: "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>B[i][j];
        }
    }

    auto result = strassen(A, B);

    cout<<"The resultant matrix : ";
    cout<<endl;
    printmatrix(result);

    return 0;
}