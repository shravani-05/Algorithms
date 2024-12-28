#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printboard(const vector<vector<int>>& board,int N){
    int queencount = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 1){
                cout<<queencount++<<" ";
            }
            else{
                cout<<". ";
            }
        }
        cout<<endl;
    }
}
bool Issafe(vector<vector<int>>& board,int row,int col,int N){
    for(int i = 0; i < row; i++){
        if(board[i][col] == 1){
            return false;
        }        
    }

    for(int i = row -1,j =col-1;i >= 0 && j >= 0; i--,j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    for(int i = row-1, j = col+1; i >= 0 && j<N;i--,j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}
bool solveNQueens(vector<vector<int>>& board,int row,int N){
    if(row>=N){
        return true;//since the approach is recursive backtrack this is the base case
        //since the algorithm is running for row= 0 to N-1 so if the number of row becomes
        //greater than N ie. row> =N this means that all the queens are placed on the board 
        //properly and no need to recurse again.        
    }
    for(int col = 0; col < N; col++){
        if(Issafe(board,row,col,N)){
            board[row][col] = 1;        

        //recursive case
        if(solveNQueens(board,row+1,N)){
            return true;
        }

        board[row][col] = 0;
        }
    }
    return false;
    
}
void NQueens(int N){

    if(N <= 0){
        cout<<"invalid input";
    }
    vector<vector<int>> board(N, vector<int>(N,0));//2D vector whose is the size of N and all the values aasigned to 0

    if (!solveNQueens(board, 0, N)) {
        cout << "Solution does not exist." << endl;
        return;
    }

    printboard(board,N);

}
int main(){
    int N;
    cout<<"Enter the number of queens: ";
    cin>>N;

    NQueens(N);

    return 0;
}