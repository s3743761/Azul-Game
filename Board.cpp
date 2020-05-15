#include <iostream>
#include <stdio.h>
#include <vector>
#include "Board.h"
#include "TileColour.h"
#include<bits/stdc++.h>
using namespace std;

Board::Board()
{
}
Board::~Board()
{
}

//making a board usinh 2d array
void Board::makeBoard()
{
    // AREA = new Tiles("||");
    // BLOCK = new Tiles(".");
    // EMPTY = new Tiles(" ");



    int size = 11;
    //const char* board[5][11];
    int rows = 5;
    //int columns = 5;
    int val = rows - 2;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j < (size - 1) / 2)
            {
                if (j <= val - i)
                {
                    board[i][j] = EMPTY;
                }
                else
                {
                    board[i][j] = BLOCK;
                }
            }
            else
            {
                if (j == 5)
                {
                    board[i][j] = AREA;
                }
                else
                {
                    board[i][j] = BLOCK;
                }
            }
        }
    }
}

// making a baord using vector

void ::Board::printBoard()
{
    int rows = 5;
    for (int i = 0; i < rows; i++)
    {
        std::cout << i + 1 << ": ";
        for (int j = 0; j < 11; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

const char **Board::getBoard()
{
    return *board;
}

vector<vector<const char *>> Board::getNewBoard()
{
    return newBoard;
}

// void Board::addTileOnBoard(int val,Tiles* tile){
//     for(int i=0; i<6; i++){
//         for(int j=0; j<11; j++){
//            if(i==val){
//             newBoard[i][j] = "K";
//            }
//         }
//     }
// }

void Board::printVectorBoard()
{
    int rows = 5;
    // columns=5;
    for (int i = 0; i < rows; i++)
    {
        std::cout << i + 1 << ": ";
        for (int j = 0; j < 11; j++)
        {
            std::cout << newBoard[i][j];
        }
        std::cout << std::endl;
    }
}

int Board::getEmptyRowSize(int val)
{
    int value = 0, size = 11;
    for (int i = 0; i < 6; i++)
    {
        // for(int j=0; j<11; j++){
        //     if(i==val && strcmp(newBoard[i][j],".")==0){
        //         value++;
        //     }
        for (int j = 0; j < 11; j++)
        {
            if (i == val && strcmp(newBoard[i][j], ".") == 0 && j < (size - 1) / 2)
            {
                value += 1;
            }
        }
    }
    return value;
}

void Board::addBrokenTile(int count, int value, std::string tile){

  if(count>value){
    int newSize = (count-value);
//std::cout<<newSize;
//string broken[newSize];
vector<string> broken(newSize);

for(int i=0; i<newSize; i++){
    //broken[i]=tile;
    broken[i] = tile;
}
cout<<"broken:";
for(int i=0; i<newSize; i++){
    cout<<broken[i]<<" ";
}
cout<<endl;
}
else{
    cout<<"broken:"; 
}
}
    
    // if(count>value){
    //     int newSize = (count-value);

    //     vector<string> broken(newSize);

    //     for(int i=0; i<newSize; i++){
   
    //         broken[i] = tile;
    //     }
        
    //     cout<<"broken:";
    
    //     for(int i=0; i<newSize; i++){
    //         cout<<broken[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // else{
   
    // cout<<"broken:"; 
    
    // }


bool Board::gameEnd(){
      int size = 11;
    // vector<vector<const char*>> board(5,vector<const char*> (11,0));

    // }
    char const *sandwich = ".";
    int newJ = (size +1)/2;
    int rows = 5;
    //int columns = 5;
    // int val = rows - 2;
    for (int i = 0; i < rows; i++) {
        for (int j = newJ; j < size; j++) {
            if((board[i][j] = sandwich) ){
                return true;
            }
        }
    }
    return false;

}

vector<const char *> Board::copyBoard(){
   vector<const char *> copy;
    for (int i  = 0 ; i < 6;++i){
        for (int j  = 0 ; j < 11;++j){
            copy.push_back(newBoard[i][j]);

        }
    }
    return copy;
}

bool Board::isEmpty(){

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 11; j++) {
            if (strcmp(newBoard[i][j], ".") == 0) {
                return true;
            }
        }
    }
    return false;


}

bool Board::does_exist(const vector< vector<const char *> >&  v){

    vector< vector<const char *> >::const_iterator  row; 
    for (row = v.begin(); row != v.end(); row ++) { 
        if(find(row->begin(), row->end(), ".") != row->end() ){
            return true;
        }
    }
    return false;
}

void Board::addTile(int row,string value,int count){
    cout<<"before"<<endl;
    printBoard();
    cout<<row<<endl;
    cout<<value<<endl;
    cout<<count<<endl;
    int flag = 0 ;
    const char *sandwich = ".";
    const char* c = value.c_str();
    int size = 11; 

   
    for(int i  = 0 ; i < 6; i++) {
        for(int j  = 0 ; j < (size -1)/2; j++) {
            if( i == row){
                if(board[i][j] == sandwich && flag < count){
                    board[i][j] = c;
                    flag = flag +1;

                }

            }

        }
    }
     
    // make_empty(*board,6,(size -1)/2);
    printBoard();
    // addBrokenTile(count, empty, value);
}

