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
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}



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
        for(int i=0; i<count-value; i++){
            broken.push_back(tile);
        }

        cout<<"broken:";
        for(unsigned i=0; i<broken.size(); i++){
        cout<<broken[i]<<" ";
    }
    
        cout<<endl;
    }

    else{
        cout<<"broken:";
            for(unsigned i=0; i<broken.size(); i++){
                cout<<broken[i]<<" ";
            }
        cout<<endl;
    }

}



void Board::saveBroken(string fileName){
    
    // ofstream of;
    // of.open(fileName, ios::app);
    // for(unsigned int i=0; i<broken.size(); i++){
    //     of<<lid[i];
    // }
    // of<<"\n";
    // of.close();
}


bool Board::gameEnd(){
    int size = 13;
    int newJ = (size +1)/2;
    int rows = 5;
    
    for (int i = 0; i < rows; i++) {
        for (int j = newJ; j < 12; j++) {
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

bool Board::checkTileInMosiac(int row, char tile){
    int size = 13;
    int newJ = (size+1)/2;

    for(int i  = 0 ; i < 6; i++) {
        for(int j  = newJ ; j <12; j++) {
            if(i == row){
                if(board[row][j] == tile){
                    return false;
                }
            }
        }
    }
    return true;

}


void Board::addTile(int row, char value,int count){
   
    int flag = 0 ;
    char sandwich = '.';
    int size = 11; 
   int val = getEmptyRowSize(row);


    if(checkTileInMosiac(row,value) == true){
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
    }
     
    
    printBoard();
    addBrokenTile(count,val,value);
    cout<<endl;
    
}

void Board::setSize(int size){
    this->size = size;
}
int Board::getSize(){
    return broken.size();
}

void Board::placeTileAtLast(){
    for(int i=0; i<5; i++){
        for(int j=0; j<12; j++){
            if(checkForSimilarTiles(i)==false || getEmptyRowSize(i)==0){
                addTileOnSquareBoard(i,board[i][j]);
            }
        }
    }
}

void Board::addTileOnSquareBoard(int val,  char c){
    int res;
    res = getEmptyRowSize(val);
   
    char jam = '|';
    if(res==0){
    int size =12;
    for(int i=0; i<5; i++){
        for(int j=(size-1)/2; j<12; j++)
        {
            if(board[i][j]!=jam){
                if(val+7==j && c=='B' && val+7<12){
                    board[val][j] = DarkBlue;
                }
                else if(val+8==j && c=='Y' && val+8<12){
                    board[val][j] = Yellow;
                }
                else if((val+9==j && c=='R' && val+9<12)){
                    board[val][j] = Red;
                }
                else if((val+10==j && c=='U' && val+10<12)){
                    board[val][j] = Black;
                }
                else if((val+11==j && c=='L' && val+11<12)){
                    board[val][j] = LightBlue;
                }
                else if((j-val)==3 && c=='Y')
                {
                    board[val][j] = Yellow;
                }
                else if((j-val)==4 && c=='R')
                {
                    board[val][j] = Red;
                }
                else if((j-val)==5 && c=='U')
                {
                    board[val][j] = Black;
                }
                else if((j-val)==6 && c=='L')
                {
                    board[val][j] = LightBlue;
                }
                }
            }
        }
    }
}


void Board::removeTileFromBoard(vector<char> &bagLid){
    
    char  sandwich = '.';
    char  jam = ' ';

    for(int i = 0; i < 5; i++){
        if(getEmptyRowSize(i) == 0){
            for(int j = 0; j < 5; j++){
       
                if(board[i][j] != jam){
                    bagLid.push_back(board[i][j]);
                    board[i][j] = sandwich;
                }
        
            }   
        }
    }
    cout<<endl;
    // cout<<"Lid is:";
    // for(unsigned i=0; i<lid.size(); i++){  
    //     cout<<lid[i]<<" ";
    // }
    // cout<<endl;

}
bool Board::checkIfBoardFilled(){
   
    int size =13;
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

bool Board::checkForSimilarTiles(int val){
    char jam = '.';
    for(int i = 0 ; i < 12;i++){
        for(int j=0; j<5; j++){
            if(i == val){
                if(board[val][j] == jam){
    
                }
            }
        }
    }
    return true;
}

void Board::addPoints(Player* player,Board* board){
    int points1 = 0;
  
    for (int i = 0; i < 5; i++){
        if (board->checkTilesHorizontally(i) != 5 || board->checkTilesVertically(i) != 5){
           
            points1 = board->checkTotaltiles();
        }
        if (board->checkTilesVertically(i) == 5){
            points1 = 7;
        }
        if (board->checkTilesHorizontally(i) == 5){
            points1 = 5;
        }
    }

    cout<<endl;
    cout << "Points: " << points1 << endl;
    player->setPoints(player->getPoints() + points1);

}

bool Board::checkTile(int val, char tile){
    int size = 13;
    for(int i=0; i<5; i++){
        for(int j=0; j<(size-1)/2; j++)
        {
            if(i == val){   
                if(board[val][j] == tile){
                    return true;
                }

            }
            
        }
    }
    return false;
}



int Board::adjacent(){

    int count = 0;
   
    int size = 15;
    for(int i=0; i<5; i++){
        for(int j=(size-1)/2; j<12; j++) {
            if(board[i][j] != '.'){

            }

        }
    }
    return count;
    
}

void Board::saveLid(string fileName){

    // ofstream of;
    // of.open(fileName, ios::app);
    // of<<"Lid"<<'\n';
    // for (unsigned int i=0; i<lid.size(); i++){
    //     // if(lid[i] ==  ){
    //     //     of<<"_";
    //     // }
    //     // else{
    //     of<<lid[i];
    //     // }
    // }
    // of<<"\n";
    // of.close();
}

std::string Board::returnTriangleAsString(){

    std::string boardString = "";

    for(int i = 0 ; i < 5; i++){
        for (int j = 0 ; j < 7; j++){
            boardString += board[i][j];
            boardString += " ";
        }
        
        boardString += "\n";
    }

    return boardString;

}

std::string Board::returnWallAsString(){

    std::string boardString = "";

    for(int i = 0 ; i < 5; i++){
        for (int j = 7; j < 12 ;j++){
            boardString += board[i][j];
            boardString += " ";
        }
        
        boardString += "\n";
    }

    return boardString;

}


void Board::loadBoard(std::string* triangle, std::string* wall){
    for(int i = 0 ; i < 5;i++){
        for(int  j = 0 ; j < 14; j += 2){
            char c = triangle[i].at(j);            
            board[i][j/2] = c;
        }
    }

    for(int i = 0 ; i < 5;i++){
        // std::cout << wall[i] << std::endl;
        for(int  j = 0 ; j < 10; j+= 2){
            char c = wall[i].at(j);
            board[i][j/2 + 7] = c;
            
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
    int size =13;
    int count =0;
    for(int j=(size+1)/2; j<12; j++){
      
           if(board[x][j] != '.') 
           {
            count+=1;
            }
    }
 
    if(count ==0){
        return 0;
    }
    else{
        return count;
    }
}

int Board::checkTilesVertically(int y){
  
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
    int size = 13;
    int newJ = (size +1)/2;
    int rows = 5;
    int count  =0; 
    for (int i = 0; i < rows; i++) {
        for (int j = newJ; j < 12; j++) {
            if(board[i][j] != '.'){
                count++;
            }
        }
    
    }
    if(count ==0){
    return 0;
    }else{
        return count;
    }

}

void Board::sampleMosiac(){


    for(int i = 0 ; i < 5; i++){
        for(int j = 0 ; j < 5; j++){
            cout<<sample[i][j]<<" ";
        
        }
        cout<<endl;

    }

}

void Board::testfunc(char outStr){
    char str[5][12];
    int rows = 5;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            board[i][j] = str[i][j];
        }
    }


}
