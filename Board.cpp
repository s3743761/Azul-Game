#include <iostream>
#include <stdio.h>
#include <vector>
#include "Board.h"

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
    



    int size = 12;
    int rows = 5;
    int val = rows - 2;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j < (size - 1) / 2)
            {
                if (j <= val - i)
                {
                    board[i][j] =  EMPTY;
                }
                else
                {
                   board[i][j] = BLOCK;
                }
            }
            else
            {
                if (j >= 5 && j <= 6)
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



void Board::printBoard()
{
    int rows = 5;
    for (int i = 0; i < rows; i++)
    {
        std::cout << i + 1 << ": ";
        for (int j = 0; j < 12; j++)
        {
            std::cout << board[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}

// const char **Board::getBoard()
// {
//     return *board;
// }


int Board::getEmptyRowSize(int val)
{
    int value =0,size=11;
    for(int i=0;i<6; i++) {
        for(int j=0; j<12; j++){
            
            if(i==val && board[i][j] == '.' && j<(size-1)/2) {
                value+=1;
            }
        }
    }
    return value;
}


void Board::addBrokenTile(int count, int value, char tile){

    if(count>value){
        int newSize = (count-value);
    setSize(newSize);

        vector<string> broken(newSize);

        for(int i=0; i<newSize; i++){
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



bool Board::gameEnd(){
    int size = 11;


    int newJ = (size +1)/2;
    int rows = 5;
    //int columns = 5;
    // int val = rows - 2;
    for (int i = 0; i < rows; i++) {
        for (int j = newJ; j < size; j++) {
            if((board[i][j] = '.') ){
                return true;
            }
        }
    }
    return false;

}



bool Board::isEmpty(){

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 12; j++) {
            if (board[i][j]== '.') {
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

void Board::addTile(int row, char value,int count){
    cout<<"In function:" <<endl;
    printBoard();

    int flag = 0 ;
    char sandwich = '.';
    int size = 11; 
   int val = getEmptyRowSize(row);

   
    for(int i  = 0 ; i < 6; i++) {
        for(int j  = 0 ; j < (size -1)/2; j++) {
            if(i == row){
                if(board[i][j] == sandwich && flag < count){
                    board[i][j] = value;
                    flag = flag +1;
                }
            }
        }
    }
     
    // make_empty(*board,6,(size -1)/2);
    cout<<"After function:" <<endl;
    printBoard();
    addBrokenTile(count,val,value);
    addTileOnSquareBoard(row,value);
    // addBrokenTile(count, empty, value);
}

void Board::setSize(int size){
    this->size = size;
}
int Board::getSize(){
    return this->size;
}

void Board::addTileOnSquareBoard(int val, char c){
    
    int res;
    res = getEmptyRowSize(val);

    if(res==0){
        cout<<"Enter your choice of column for the next board";
        int nextBoardColumn;
        cin>>nextBoardColumn;
        board[val][nextBoardColumn]=c;
    }
}

bool Board::checkIfBoardFilled(){
   
    int size =11;
    int count =0;
    for(int i=0; i<5; i++){
        for(int j=0; j<(size-1)/2; j++){
            if(board[i][j]=='.'){
                count+=1;
            }
        }
    }
    if(count==0){
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Board::checkTile(int val, char tile){
    int size = 11;
    for(int i=0; i<5; i++){
        for(int j=0; j<(size-1)/2; j++)
        {
            if(board[val][j]== tile){
                return true;
            }
        }
    }
    return false;
}

int Board::adjacent(){
// int currentx = 0;
// int currenty = 0 ;
    int count = 0;
   
    int size = 11;
    for(int i=0; i<5; i++){
        for(int j=(size-1)/2; j<size; j++) {
            if(board[i][j] != '.'){
                // currentx = i+1;
                // currenty = j;
                // if(board[currentx][currenty] != sandwich){
                //     count++;
                //     currentx = i;
                //     currenty = j;
                // }
                // // currentx = i;
                // // currenty = j+1;

            }

        }
    }
    return count;
    
}

void Board::saveBoard(string filename,Factory* factory,Player* p){
    ofstream of;
    of.open(filename,ios::app | ios::out );
    factory->saveFactory(filename);
    for(int i = 0 ; i < 5;i++){
        for (int j = 0 ; j <11 ;j++){
            of<<board[i][j]<<" ";
        }
        
        of<<endl;
    }
    p->savePlayer(filename);
    of.close();
}

void Board::loadBoard(string filename){
    // std::fstream file;
    // string line;
    // file.open(filename);
    // GotoLine(file,7);

    // int counter = 0 ;
    //     for(int i=0;i<5;i++){
    //         for(int x=0; x< 11; x++){       
    //             if(getline(file,line) && counter < 5){
    //                 char* result = new char[line.length()+1];
    //                 strcpy(result,line.c_str());
    //                 board[i][x] = result;
    //                 counter++;
    //             }
            
    //         }
    //     }
    // file.close();
    // cin.get();

}

// void Board::printLoadBoard(){
//     for(int p=0;p<5;p++){
//         // std::cout << p + 1 << ": ";
//         for (int j = 0; j < 11; j++) {
//             if(board[p][j]!= NULL){
//                 std::cout << board[p][j]<<endl;
//             }
//         }
        
//     }

   

// }

void Board::loadBoard2(string filename){
    std::fstream file;
    string line;
    file.open(filename);
    GotoLine(file,19);

    int counter = 0 ;
        for(int i=0;i<5;i++){
            for(int x=0; x< 11; x++){       
                if(getline(file,line) && counter < 5){
                    // char* result = new char[line.length()+1];
                    // strcpy(result,line.c_str());
                    loadboard[i][x] = line;
                    counter++;
                }
            
            }
        }
    file.close();
    cin.get();

}


void Board::printLoadBoard2(){
    for(int p=0;p<5;p++){
        std::cout << p + 1 << ": ";
        for (int j = 0; j < 11; j++) {
            std::cout << board[p][j]<<endl;
        }
        
    }
}
 



std::fstream& Board::GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}
int Board::checkTilesHorizontally(int x){
    int size =11;
    int count =0;
    for(int j=(size+1)/2; j<11; j++){
      
           if(board[x][j]==board[x][j+1]&& board[x][j]!= '.') 
           {
            count+=1;
        }
    }
 
    if(count ==0)
    return 0;
    else
    return count+1;
}

int Board::checkTilesVertically(int y){
   // int size =11;
    int count =0;
    for(int i=0; i<5; i++){
        if(board[i][y]==board[i+1][y] && i+1<5 && board[i+1][y]!='.'){
            count++;
        }
    }
    if(count ==0){
        return 0;
    }
   // else
    return count+1;
}



int Board::checkTotaltiles(){
          int size = 11;
      int newJ = (size +1)/2;
      int rows = 5;
      int count  =0; 
      for (int i = 0; i < rows; i++) {
        for (int j = newJ; j < 12; j++) {
            if(board[i][j]!= '.'){
                count++;
            }
    // int size =11;
    // int count =0;
    // char const * sandwich = ".";
    // for(int j=(size+1)/2; j<5; j++){
    //   if(board[j][x]!=sandwich){
    //       count++;
    //   }
    // }
        }
    if(count ==0){
    return 0;
    }
    
}
return count;
}

void Board::sampleMosiac(){


    for(int i = 0 ; i < 5; i++){
        for(int j = 0 ; j < 5; j++){
            cout<<sample[i][j]<<" ";
        
        }
        cout<<endl;

    }


}