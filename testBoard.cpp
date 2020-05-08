// #include<iostream>
// #include<vector>
// using namespace std;

// #define BLOCK "."

// int main(){
//    // int size=12;
//    // int row=5;
// //const char* board[5][11];

// //method 1

// // vector<vector<char>> board(5,vector<char> (12,0));
// // //char board_two[5][5];

// // // for(int i=0; i<=4; i++){
// // //     for(int j=0; j<=4; j++){    
// // //             if(j<=3-i){
// // //             board[i][j] = ' ';
// // //             }
// // //             else
// // //             {
// // //                 board[i][j] = '.';
// // //             }
            
// // //     }
// // // }
// // int rows = 5;
// // //int columns = 5;
// // int val = rows-2;
// // for(int i=0; i<rows; i++){
// //     for(int j=0; j<size; j++){  
// //         if(j<(size-1)/2){
// //             // std::cout<<i+1<<": ";
// //             if(j<=val-i){
// //             board[i][j] = ' ';
// //             }
// //             else
// //             {
// //                 board[i][j] = '.';
// //             }
// //         }
// //         else{
// //             if(j==5||j==6){
// //                 board[i][j] = '|';
// //             }
// //             else{
// //             board[i][j] = '.';
// //             }
// //         }
// //     }
// // }
    
//     //Alternative
//     int size = 11;
//     vector<vector<const char*>> board(5,vector<const char*> (11,0));
// //char board_two[5][5];

// // for(int i=0; i<=4; i++){
// //     for(int j=0; j<=4; j++){    
// //             if(j<=3-i){
// //             board[i][j] = ' ';
// //             }
// //             else
// //             {
// //                 board[i][j] = '.';
// //             }
            
// //     }
// // }
// int rows = 5;
// //int columns = 5;
// int val = rows-2;
// for(int i=0; i<rows; i++){
//     for(int j=0; j<size; j++){  
//         if(j<(size-1)/2){
//             // std::cout<<i+1<<": ";
//             if(j<=val-i){
//             board[i][j] = " ";
//             }
//             else
//             {
//                 board[i][j] = ".";
//             }
//         }
//         else{
//             if(j==5){
//                 board[i][j] = "||";
//             }
//             else{
//             board[i][j] = ".";
//             }
//         }
//     }
// }

            
// //     }
// // }
// // for(int i=0; i<rows; i++){
// //     board[i][5] = "||";
// // }

// // for(int i=rows+1; i<size;i++){
// //     for(int j=rows+1; j<size; j++){
// //         board[i][j] = ".";
// //     }

// // }

//     // for(int k=4;k>=i;k--)
//     //         {
//     //             board[i][k] = '.';
//     //         }
            
//         //}

//     //     for(int i=1; i<=5; i++){
//     // for(int j=i; j<5; j++){   
//     //         board[i][j]= ' ';
//     // }
//     // for(int k=1; k<=i; k++){
//     //     board[i][k]= '.';
//     // }
            
//     //     }


// // for(int i=0; i<5; i++){
// //     for(int j=4; j>=0; j--){   
// //             if(j>=i){  
// //             board[i][j] = '.';
// //             }
// //             else
// //             {
// //                 board[i][j] = ' ';
// //             }
            
// //         }
// // }

// //  int rows=5;
// //     int columns = 5;
// //     for(int i=0; i<5; i++){
// //         for(int j=0; j<5; j++){
// //             board_two[i][j] = BLOCK;
// //         }

// // }

// for(int i=0; i<5; i++){
//     std::cout<<i+1<<": ";
//     for(int j=0; j<11; j++)
//     {
//         std::cout<<board[i][j];
// }
// std::cout<<std::endl;

// }
// return 0;
// }
#include<iostream>
#include<vector>
#include "Board.h"
using namespace std;

int main(){

    Board* board = new Board();

//making board using array
board->makeBoardOne();
board->printBoard();
//making board using vector and displaying it
std::cout<<std::endl;
std::cout<<"Board using vector";
board->makeBoardTwo();
}
