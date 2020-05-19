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
    



    int size = 11;
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

// vector<vector<const char *>> Board::getNewBoard()
// {
//     return newBoard;
// }

// void Board::addTileOnBoard(int val,Tiles* tile){
//     for(int i=0; i<6; i++){
//         for(int j=0; j<11; j++){
//            if(i==val){
//             newBoard[i][j] = "K";
//            }
//         }
//     }
// }

// void Board::printVectorBoard()
// {
//     int rows = 5;
//     // columns=5;
//     for (int i = 0; i < rows; i++)
//     {
//         std::cout << i + 1 << ": ";
//         for (int j = 0; j < 11; j++)
//         {
//             std::cout << newBoard[i][j];
//         }
//         std::cout << std::endl;
//     }
// }

int Board::getEmptyRowSize(int val)
{
    int value =0,size=11;
    for(int i=0;i<6; i++) {
        for(int j=0; j<11; j++){
            
            if(i==val && strcmp(board[i][j], ".")==0 && j<(size-1)/2) {
                value+=1;
            }
        }
    }
    return value;
}

void Board::addBrokenTile(int count, int value, std::string tile){

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

// vector<const char *> Board::copyBoard(){
//    vector<const char *> copy;
//     for (int i  = 0 ; i < 6;++i){
//         for (int j  = 0 ; j < 11;++j){
//             copy.push_back(newBoard[i][j]);

//         }
//     }
//     return copy;
// }

bool Board::isEmpty(){

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 11; j++) {
            if (strcmp(board[i][j], ".") == 0) {
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
    // stringstream geek(row); 
    // int rowInt = 0; 
    // geek >>rowInt;

    // stringstream geek(row); 
    // int rowInt = 0; 
    // geek >>rowInt;
   

    int flag = 0 ;
    const char *sandwich = ".";
    const char* c = value.c_str();
    int size = 11; 
    int val = getEmptyRowSize(row);

   
    for(int i  = 0 ; i < 6; i++) {
        for(int j  = 0 ; j < (size -1)/2; j++) {
            if(i == row){
                if(board[i][j] == sandwich && flag < count){
                    board[i][j] = c;
                    flag = flag +1;

                }

            }

        }
    }
     
    // make_empty(*board,6,(size -1)/2);
    printBoard();
    addBrokenTile(count,val,value);
    addTileOnSquareBoard(row,c);
    // addBrokenTile(count, empty, value);
}

// int Board::roundEnd(){
//     int size = 11;
//     int count = 0;
//     char const *sandwich = ".";
//     int newJ = (size -1)/2;
//     int rows = 5;
  
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < newJ; j++) {
//             if(board[i][j] == sandwich){
//                 count++;

//             }
//         }
//     }

//     return count;
// }

void Board::addTileOnSquareBoard(int val, const char* c){
    
    int res;
    res = getEmptyRowSize(val);
    //cout<<val;

    if(res==0){
        cout<<"Enter your choice of column for the next board";
        int nextBoardColumn;
        cin>>nextBoardColumn;
        board[val][nextBoardColumn]=c;
    }
}

bool Board::checkIfBoardFilled(){
    char const *sandwich = ".";
    int size =11;
    int count =0;
    for(int i=0; i<5; i++){
        for(int j=0; j<(size-1)/2; j++){
            if(board[i][j]==sandwich){
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

bool Board::checkTile(int val, string tile){
    int size = 11;
    for(int i=0; i<5; i++){
        for(int j=0; j<(size-1)/2; j++)
        {
            if(board[val][j]==tile.c_str()){
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
    char const *sandwich = ".";
    int size = 11;
    for(int i=0; i<5; i++){
        for(int j=(size-1)/2; j<size; j++) {
            if(board[i][j] != sandwich){
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
    std::fstream file;
    string line;
    file.open(filename);
    GotoLine(file,7);
int counter = 0;
     for(int i=0;i<5;i++){
        for(int x=0; x< 11; x++){
            
            // while()&& (file.good())){
                if(getline(file,line)){
                    loadboard[i][x] = line;
                    counter++;
                }
                // cout<<loadboard[i][x]<<endl;
            // }

        }
     }
    file.close();
    cin.get();

    // std::fstream file;
   
    // file.open(filename);
    // GotoLine(file,7);

    // for(int i=0;i<5;i++){
    //     for(int x=0; x< 11; x++){
    //         file >> loadboard[i][x];
    //     }
    // }
    // file.close();
}


std::fstream& Board::GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

void Board::printLoadBoard(){
    for(int p=0;p<5;p++){
        // std::cout << p + 1 << ": ";
        for (int j = 0; j < 11; j++) {
            std::cout << loadboard[p][j]<<endl;
        }
        // std::cout << std::endl;
        
    }
}

void Board::loadBoard2(string filename){
    std::fstream file;
   
    file.open(filename);
    GotoLine(file,18);

    for(int i=0;i<5;i++){
        for(int x=0; x< 11; x++){
            file >> loadboard2[i][x];
        }
    }
    file.close();
}


void Board::printLoadBoard2(){
    for(int p=0;p<5;p++){
        std::cout << p + 1 << ": ";
        for (int j = 0; j < 11; j++) {
            std::cout << loadboard2[p][j];
        }
        std::cout << std::endl;
        
    }
}
 
    
void Board::setSize(int size){
    this->size = size;
}
int Board::getSize(){
    return this->size;
}


int Board::checkTilesHorizontally(int x){
    int size =11;
    int count =0;
    char const * sandwich = ".";
    for(int j=(size+1)/2; j<10; j++){
      
           if(board[x][j]==board[x][j+1]&& board[x][j]!=sandwich) 
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
    char const* sandwich = ".";
    for(int i=0; i<5; i++){
        if(board[i][y]==board[i+1][y] && i+1<5 && board[i+1][y]!=sandwich){
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
      char const *sandwich = ".";
      int count  =0; 
      for (int i = 0; i < rows; i++) {
        for (int j = newJ; j < size; j++) {
            if(board[i][j]!=sandwich){
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