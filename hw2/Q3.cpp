#include <iostream>
#include <vector>
using namespace std;



void get_board(vector<vector<int>> &board, int &number_of_zeros){
    int temp;
    number_of_zeros = 0;
    for (int i = 0; i<9 ; i++){
        board.resize(i+1);
        for (int j = 0; j<9; j++){
            cin >> temp;
            if (temp == 0) number_of_zeros++;
            board[i].push_back(temp);
        }
    }
}

void show_board(vector<vector<int>> &board){
    cout<<"\n"<<endl;
    for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << " ";
            }    
            cout << endl;
        }
}


bool containsDuplicate(vector<int>& nums) {

        int pos;
        int max = 0;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i]>max) max = nums[i];
        }
        vector<bool> counts(max+1, false);

        for (int i = 0; i<nums.size(); i++){
            if (nums[i] == 0) continue;
            pos = nums[i];
            if (counts[pos] == true) return true;
            else counts[pos] = true;
        }

        return false;
}



bool check_board(vector<vector<int>> &board){
    for (int i = 0 ; i<9; i++){
        if (containsDuplicate(board[i])) return false;
        vector<int> column;
        for (int j = 0 ; j<9 ; j++){
            column.push_back(board[i][j]);
        }
        if (containsDuplicate(column)) return false;
    }
    for (int seci = 0 ; seci<3 ; seci++)
    {
        for (int secj = 0 ; secj<3 ; secj++){
        vector<int> section;
            for (int i = seci*3 ; i < (seci+1)*3 ; i++){
                for (int j = secj*3 ; j < (secj+1)*3 ; j++){
                    section.push_back(board[i][j]);
                }
            }
        if (containsDuplicate(section)) return false;
        }
    }
    return true;

}



// bool Solve (vector<vector<int>> &board, int number_of_zeros, int i, int j){
//     vector<vector<int>> temp_board = board;
//     cout << "\n" << i << " " << j << endl;
//     if (number_of_zeros == 0) return true;
//     if (temp_board[i][j] == 0){
//         for (int possible_placement = 1; possible_placement<10; possible_placement++)
//         {
//             temp_board[i][j] = possible_placement;
//             show_board(temp_board);
//             if (!check_board(temp_board)){ 
//                 if(possible_placement < 9) continue;
//                 else return false;
//             }
//             else if (j==8 and i < 8)
//             { 
//                 if (!Solve (temp_board, number_of_zeros, i+1, 0)) return false;
//                 else {
//                     board = temp_board;
//                     return true;
//                     }
//             }
//             else  if (j < 8) {
//                 if (!Solve (temp_board, number_of_zeros, i, j+1)) return false;
//                 else {
//                     board = temp_board;
//                     return true;
//                     }
//             }
//             board = temp_board;
//             return true;
            
//         }
//     }
//     else if (j==8 and i < 8)
//     { 
//        if (Solve (temp_board, number_of_zeros, i+1, 0))
//         {
//             board = temp_board;
//             return true;
//         }
//     }
//     else  if (j < 8) {
//         if (Solve (temp_board, number_of_zeros, i, j+1)){
//             board = temp_board;
//             return true;
//         }
//     }
    

// }

bool new_cords (int &ni, int &nj, int i, int j){
          if (j==8 and i < 8)
            { 
                ni=i+1;
                nj=0;
                return true;
            }
          if (j < 8) {
                ni=i;
                nj=j+1;
                return true;
            }
    return false;
}


bool Solve (vector<vector<int>> &board, int number_of_zeros, int i, int j, int possible_placement){
    vector<vector<int>> temp_board = board;
    // cout << "\n" << i << " " << j << endl;
    int ni=0;
    int nj=0;
    if(!new_cords(ni, nj, i, j)) return false;
    
    if (number_of_zeros == 0 and check_board (board)) return true;
    
    if (board[i][j]==0){
        if (possible_placement>9) return false;
        temp_board[i][j] = possible_placement;
        // show_board(temp_board);
        if (check_board(temp_board) and Solve(temp_board, number_of_zeros-1, ni, nj, 1)){
            board = temp_board;
            return true;
        }
        else if(Solve(board, number_of_zeros, i, j, possible_placement+1)){
            return true;
        }
        else return false;
    }
    else { return Solve(board, number_of_zeros, ni, nj, 1);}
    
}
int main(){
    vector<vector<int> > board;
    int number_of_zeros=0;
    get_board(board, number_of_zeros);
    // cout<<"\n"<<check_board(board)<<endl;
    // cout<<"\n"<<number_of_zeros<<endl;
    Solve(board, number_of_zeros, 0, 0, 1);
    show_board(board);
    return 0;
}