#include <iostream>
#include <stdio.h>
#include <vector>
#include "Board.h"

#include<bits/stdc++.h>
using namespace std;

Board::Board(bool sixTileMode)
{
    if(sixTileMode) {
        rows = 6;
        columns = 14;
    }
    else {
        rows = 5;
        columns = 12;
    }
    board = new char*[rows];
    mosaic = new char*[rows];
    for(int i = 0; i < rows; ++i){
        board[i] = new char[columns];        
        mosaic[i] = sixTileMode ? sixTileMosaic[i] : fiveTileMosaic[i];
        
    }
}

Board::~Board()
{
}


void Board::makeBoard()
{
    int val = rows - 2;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int midBoard = (columns - 1) / 2;
            if (j < midBoard)
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
                if (j >= midBoard && j <= (midBoard + 1))
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
    for (int i = 0; i < rows; i++)
    {
        std::cout << i + 1 << ": ";
        for (int j = 0; j < columns; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}


int Board::getEmptyRowSize(int row)
{
    int midBoard = (columns - 1) / 2;
    int value = 0;

    for(int j = 0; j < columns; j++){
        if(board[row][j] == BLOCK && j < midBoard){
            value += 1;
        }
    }
   
    return value;
}


bool Board::checkTileInMosiac(int row, char tile){
    int size = columns + 1;
    int newJ = (size + 1)/2;

    for(int j  = newJ ; j < columns; j++) {
        if(board[row][j] == tile){
            return false;
        }
    }
    
    return true;
}



void Board::placeTileAtLast(){
    for(int i = 0; i < rows; i++){
        if(getEmptyRowSize(i) == 0){
            addTileOnSquareBoard(i, board[i][(columns - 3) / 2]);
        }
    }
}


void Board::addTile(int row, char tile,int count){
   
    int flag = 0;
    char sandwich = BLOCK;
    int val = getEmptyRowSize(row);


    if(checkTileInMosiac(row, tile) == true){
        for(int j  = 0 ; j < (columns - 1) / 2; j++) {
            if(board[row][j] == sandwich && flag < count){
                board[row][j] = tile;
                flag = flag + 1;
            }      
        }
    }
     
    
    printBoard();
    addBrokenTile(count, val, tile);
    cout<<endl;
    
}


void Board::addTileOnSquareBoard(int row, char c){

    int i = 0;
    for(int j = (columns + 2)/2; j < columns; j++) {
        if(mosaic[row][i] == c) {
            board[row][j] = c;
        }
        i++;
    }

}


void Board::removeTileFromBoard(vector<char> &bagLid){
    
    char  sandwich = BLOCK;
    char  jam = EMPTY;

    for(int i = 0; i < rows; i++){
        if(getEmptyRowSize(i) == 0){
            for(int j = 0; j < (columns - 1 )/2; j++){
       
                if(board[i][j] != jam){
                    bagLid.push_back(board[i][j]);
                    board[i][j] = sandwich;
                }
        
            }   
        }
    }
    cout<<endl;
 

}


std::string Board::returnTriangleAsString(){

    std::string boardString = "";

    for(int i = 0 ; i < rows; i++){
        for (int j = 0 ; j < (columns - 1) /2; j++){
            boardString += board[i][j];
            boardString += "";
        }
        
        boardString += "\n";
    }

    return boardString;

}

std::string Board::returnWallAsString(){

    std::string boardString = "";

    for(int i = 0 ; i < rows; i++){
        for (int j = (columns + 3) / 2; j < columns ;j++){
            boardString += board[i][j];
            boardString += "";
        }
        
        boardString += "\n";
    }

    return boardString;

}


void Board::loadBoard(std::vector<string> triangle, std::vector<std::string> wall){

    for (auto i = triangle.begin(); i != triangle.end(); ++i) {
        std::string line = *i;
        int rowIndex = std::distance(triangle.begin(), i);

        int blankSpaces = rows - line.length();

        for(int b = 0; b < blankSpaces; b++) {
            board[rowIndex][b] = EMPTY;
        }


        for(int j = 0; j < line.length(); j++) {
            char tile = line.at(j);
            board[rowIndex][blankSpaces + j] = tile;
        }

        board[rowIndex][rows] = AREA;
        board[rowIndex][rows + 1] = AREA;
    }

    for (auto i = wall.begin(); i != wall.end(); ++i) {
        std::string line = *i;
        int rowIndex = std::distance(wall.begin(), i);
        
        for(int j = 0; j < line.length(); j++) {
            char tile = line.at(j);
            board[rowIndex][rows + 2 + j] = tile;
        }
    }
    
}


int Board::checkTilesHorizontally(int x){
    int count = 0;
    for(int j = (columns + 2)/2; j < columns; j++){
      
        if(board[x][j] != BLOCK) {
            count+=1;
        }
    }
 
    return count;
    
}

//TODO: see how it gets called in Scoring function
int Board::checkTilesVertically(int y){
  
    int count = 0;
    if(y < (columns - 1) / 2) {
        return count;
    }

    for(int i = 0; i < rows; i++){
        if(board[i][y] != BLOCK && board[i][y] != EMPTY && board[i][y] != AREA ){
            count++;
        }
    }
    
    return count;
}



int Board::checkTotaltiles(){
    int newJ = (columns + 2)/2;
    int count = 0; 
    for (int i = 0; i < rows; i++) {
        for (int j = newJ; j < columns; j++) {
            if(board[i][j] != BLOCK){
                count++;
            }
        }
    
    }

    return count;

}
bool Board::checkAdjacent(int row, int j){
    
    char tile =  getTile(row);
    int midBoard =  (columns - 1)/2; 
    int col = midBoard + 2;

    if(row < 0 || j < 1) {
        return false;
    }

    if(board[row][j + col - 1] != BLOCK){
        return false;
    }

    for(int p = col ; p < columns ; p++){
            
        if(board[row][p] == tile){    
            return false;
        }
    }
  
    for (int i = 0; i < rows; i++) {
        
        if(board[i][j + col - 1] == tile){
            return false;
        }
            
    }
    return true;
        
}

void Board::addBrokenTile(int count, int value, char tile){

    if(count > value){
        for(int i = 0; i <count - value; i++){
            broken.push_back(tile);
        }

        cout << "broken:";
        for(unsigned i = 0; i < broken.size(); i++){
            cout << broken[i] << " ";
        }
    
        cout << endl;
    }

    else{
        cout << "broken:";
            for(unsigned i = 0; i < broken.size(); i++){
                cout << broken[i] << " ";
            }
        cout << endl;
    }

}

int Board::getSize(){
    return broken.size();
}

bool Board::gameOver(){

    for(int j = 0; j < rows; j++) {
        if(checkTilesHorizontally(j) == rows){
            return true;     
        }
    }
    return false;
        
}

void Board::placeTileGreyBoard(int i, int j ){
    int midBoard =  (columns - 1)/2;

    if(getEmptyRowSize(i) == 0){
        if(checkAdjacent(i, j)){
            board[i][ j + midBoard + 1] = getTile(i);
        }
    }

}

int Board::getRows(){
    return rows;
}

char Board::getTile(int i){
    return board[i][(columns - 3) / 2];
}

int Board::getColumns(){
    int midBoard =  (columns - 1)/2;
    return midBoard;
}

void Board::loadBroken(string brokenString){
   

    if(brokenString == "_"){
        return;
    } 

    std::copy(brokenString.begin(), brokenString.end(), std::back_inserter(broken));

}

vector<char> Board::getBroken(){
    return broken;
}

void Board::printBroken(){
    cout << "broken:";
    for(unsigned i = 0; i < broken.size(); i++){
        cout << broken[i] << " ";
    }
    
    cout << endl;
}

string Board::returnBrokenAsString(){
    std::string brokenString = ""; 

    for(int i = 0; i < broken.size(); i++) {
        brokenString += broken[i];
    }
    
    if(brokenString.length() == 0){
        return "_";
    }
    return brokenString;
}