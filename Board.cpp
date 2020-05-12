#include<iostream>
#include<stdio.h>
#include<vector>
#include "Board.h"
#include "TileColour.h"
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
   // vector<vector<const char*>> board(5,vector<const char*> (11,0));

// }
int rows = 5;
//int columns = 5;
int val = rows-2;
for(int i=0; i<rows; i++){
    for(int j=0; j<size; j++){  
        if(j<(size-1)/2){
            // std::cout<<i+1<<": ";
            if(j<=val-i){
            newBoard[i][j] = " ";
            }
            else
            {
                newBoard[i][j] = ".";
            }
        }
        else{
            if(j==5){
                newBoard[i][j] = "||";
            }
            else{
            newBoard[i][j] = ".";
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
        std::cout<<newBoard[i][j];
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


const char** Board::getBoard(){
    return *board;
}

vector<vector<const char*>> Board::getNewBoard(){
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

void Board::printVectorBoard(){
    int rows=5;
    // columns=5;
for(int i=0; i<rows; i++){
    std::cout<<i+1<<": ";
    for(int j=0; j<11; j++)
    {
        std::cout<<newBoard[i][j];
}
std::cout<<std::endl;
}
}

int Board::getEmptyRowSize(int val){
    int value =0,size=11;
  for(int i=0;i<6; i++){
    // for(int j=0; j<11; j++){
    //     if(i==val && strcmp(newBoard[i][j],".")==0){
    //         value++;
    //     }
    for(int j=0; j<11; j++){
    if(i==val && strcmp(newBoard[i][j], ".")==0 && j<(size-1)/2)
    {
value+=1;
    }
    }
    }
    return value;
}

void Board::addBrokenTile(int count, int value, char cstr[]){
  
   if(count>value){
    int newSize = (count-value);
//std::cout<<newSize;
string broken[newSize];

//this is using a vector
//vector<char> broken(newSize);

  //  broken.push_back(tile);
//for(int i=0; i<newSize; i++){
   //broken[i] = cstr;

   
//   for(int i=0; i<newSize; i++){
//   // broken.push_back(cstr[i]);

//    }

// //}
// cout<<"broken:";
// // for(int i=0; i<newSize; i++){

// //    cout<<broken.at(i)<<" ";
// // }
// for(auto i = broken.begin(); i!=broken.end(); ++i){
//     cout<<*i;
// }
// cout<<std::endl;

//This is using a string array
for(int i=0; i<newSize; i++){
    broken[i]=cstr;
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

void Board::addTileOnBoard(int val,string tile, int count){
    int size =11;
    int flag =0;
    
    char cstr[tile.size()+1];
    strcpy(cstr,tile.c_str());

    int value = getEmptyRowSize(val);
    //cout<<value;
    for(int i=0; i<6; i++){
        for(int j=0; j<11; j++){
           if(i==val&& (strcmp(newBoard[i][j],".")==0)&& j<(size-1)/2 &&flag<count){

            newBoard[i][j] = cstr;
            flag+=1;
          
            }
           
        }
    }


printVectorBoard();
addBrokenTile(count,value,cstr);


}