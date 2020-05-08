#include<iostream>
#include<stdio.h>
#include "Board.h"
using namespace std;

Board::Board()
{

}
Board::~Board(){
}


//making a board usinh 2d array
void Board::makeBoardOne(){
// for(int i=4; i>=0; i--){
//     for(int j=0; j<5; j++){   
//             if(j<=i){  
//             board[i][j] = BLOCK;
//             }
//             else
//             {
//                 board[i][j] = EMPTY;
//             }
            
//         }
// }
// int rows = 5;
// int columns = 5;
// int val = rows-2;
// for(int i=0; i<rows; i++){
//     for(int j=0; j<columns; j++){    
//             if(j<=val-i){
//             board_one[i][j] = EMPTY;
//             }
//             else
//             {
//                 board_two[i][j] = BLOCK;
//             }
            
//     }
// }
int size=11;
//const char* board[5][11];
int rows = 5;
//int columns = 5;
int val = rows-2;
for(int i=0; i<rows; i++){
    for(int j=0; j<size; j++){  
        if(j<(size-1)/2){
            // std::cout<<i+1<<": ";
            if(j<=val-i){
            board[i][j] = EMPTY;
            }
            else
            {
                board[i][j] = BLOCK;
            }
        }
        else{
            if(j==5){
                board[i][j] = AREA;
            }
            else{
            board[i][j] = BLOCK;
            }
        }
    }
}

}

// making a baord using vector
void Board::makeBoardTwo(){    
    //Alternative
    int size = 11;
    vector<vector<const char*>> board(5,vector<const char*> (11,0));

// }
int rows = 5;
//int columns = 5;
int val = rows-2;
for(int i=0; i<rows; i++){
    for(int j=0; j<size; j++){  
        if(j<(size-1)/2){
            // std::cout<<i+1<<": ";
            if(j<=val-i){
            board[i][j] = " ";
            }
            else
            {
                board[i][j] = ".";
            }
        }
        else{
            if(j==5){
                board[i][j] = "||";
            }
            else{
            board[i][j] = ".";
            }
        }
    }
}

 // int rows=5;
  //columns=5;
for(int i=0; i<rows; i++){
    std::cout<<i+1<<": ";
    for(int j=0; j<11; j++)
    {
        std::cout<<board[i][j];
}
std::cout<<std::endl;
}



}



void::Board::printBoard(){
    int rows=5;
    // columns=5;
for(int i=0; i<rows; i++){
    std::cout<<i+1<<": ";
    for(int j=0; j<11; j++)
    {
        std::cout<<board[i][j];
}
std::cout<<std::endl;
}
}


