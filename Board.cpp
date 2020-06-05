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
        maxBrokenSize = 9;
        broken.reserve(maxBrokenSize);
    }
    else {
        rows = 5;
        columns = 12;
        maxBrokenSize = 7;
        broken.reserve(maxBrokenSize);
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


void Board::addTile(int row, char tile,int count,vector<char> &bagLid){
   
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
     

    addBrokenTile(count, val, tile, bagLid);
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

void Board::addFirstPlayerTile(vector<char> &bagLid){
        broken.push_back('F');
        std::rotate(broken.rbegin(), broken.rbegin() + 1, broken.rend());
        if(broken.size() > 1 && broken.size() == maxBrokenSize){
            bagLid.push_back(broken.back());
            broken.pop_back();//this
        
        }
        
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

void Board::addBrokenTile(int count, int value, char tile, vector<char> &bagLid){

    if(count > value){
        for(int i = 0; i < count - value; i++){
            if(broken.size() < maxBrokenSize) {
                broken.push_back(tile);
            }
            else {
                bagLid.push_back(tile);
            }
        }
        
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
    cout << "Broken:";
    for(unsigned i = 0; i < broken.size(); i++){
        cout << broken[i] << " ";
    }
    cout << "                                 ";
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

void Board::clearBroken(vector<char> &bagLid){
    broken.erase(std::remove(broken.begin(), broken.end(), 'F'), broken.end());
    for (int i=0; i<broken.size(); i++){
        bagLid.push_back(broken[i]); 
    }
    broken.clear();
}


void Board::printRow(int i,bool greyBoardMode){
    if(greyBoardMode){
        for(int j=0; j < (columns+2)/2; j++) {
            if(board[i][j] == 'R'){
                cout<< ("\x1b[31mR\x1b[0m" );
            }
            else if(board[i][j] == 'B'){
                cout<< ("\x1b[34mB\x1b[0m" );
            }
            else if(board[i][j] == 'L'){
                cout<< ("\x1b[96mL\x1b[0m" );
            }
            else if(board[i][j] == 'U'){
                cout<< ("\x1b[35mU\x1b[0m" );
            }
            else if(board[i][j] == 'Y'){
                cout<< ("\x1b[33mY\x1b[0m" );
            }
            else if(board[i][j] == 'O'){
                cout << ("\x1b[31;1mO\x1b[0m");
            }
            else{
                cout<< (board[i][j]);
            }
        }
        for(int p = (columns + 2)/2; p < columns; p++) {
                if(board[i][p] == 'R'){
                    cout<< ("\x1b[31m[R]\x1b[0m" );
                }
                else if(board[i][p]== 'B'){
                    cout<< ("\x1b[34m[B]\x1b[0m" );
                }
                else if(board[i][p] == 'L'){
                    cout<< ("\x1b[96m[L]\x1b[0m" );
                }
                else if(board[i][p] == 'U'){
                    cout<< ("\x1b[35m[U]\x1b[0m" );
                }
                else if(board[i][p] == 'Y'){
                    cout<< ("\x1b[33m[Y]\x1b[0m" );
                }
                else if(board[i][p] == 'O'){
                    cout << ("\x1b[31;1m[O]\x1b[0m");
                }
                else{
                    cout<<"[*]";
                }
        
        }

    }
    else{
        for(int j=0; j<(columns+2)/2; j++) {
            if(board[i][j] == 'R'){
                cout<< ("\x1b[31mR\x1b[0m" );
            }
            else if(board[i][j] == 'B'){
                cout<< ("\x1b[34mB\x1b[0m" );
            }
            else if(board[i][j] == 'L'){
                cout<< ("\x1b[96mL\x1b[0m" );
            }
            else if(board[i][j] == 'U'){
                cout<< ("\x1b[35mU\x1b[0m" );
            }
            else if(board[i][j] == 'Y'){
                cout<< ("\x1b[33mY\x1b[0m" );
            }
            else if(board[i][j] == 'O'){
                cout << ("\x1b[31;1mO\x1b[0m");
            }
            else{
                cout<< (board[i][j]);
            }
        }

        for(int p = (columns + 2)/2; p < columns; p++) {
            if(board[i][p] == BLOCK){
                if(mosaic[i][p - (columns + 2)/2] == 'R') {
                    cout << ("\u001b[41m[*]");
                    cout << ("\u001b[0m");
                }
                else if(mosaic[i][p - (columns + 2)/2] == 'B'){
                    cout << ("\u001b[44m[*]");
                    cout << ("\u001b[0m");
                }
                else if(mosaic[i][p - (columns + 2)/2] == 'Y'){
                    cout << ("\u001b[43m[*]");
                    cout << ("\u001b[0m");
                }
                else if(mosaic[i][p - (columns + 2)/2] == 'L'){
                    cout << ("\u001b[46m[*]");
                    cout << ("\u001b[0m");
                }
                else if(mosaic[i][p - (columns + 2)/2] == 'U'){
                    cout << ("\u001b[45m[*]");
                    cout << ("\u001b[0m");
                }
                else if(mosaic[i][p - (columns + 2)/2] == 'O'){
                    cout << ("\u001b[41;1m[*]");
                    cout << ("\u001b[0m");
                }

                else{
                    cout<< (board[i][p]);
                }
            }
            else {
                if(board[i][p] == 'R'){
                    cout<< ("\x1b[31m[R]\x1b[0m" );
                }
                else if(board[i][p]== 'B'){
                    cout<< ("\x1b[34m[B]\x1b[0m" );
                }
                else if(board[i][p] == 'L'){
                    cout<< ("\x1b[96m[L]\x1b[0m" );
                }
                else if(board[i][p] == 'U'){
                    cout<< ("\x1b[35m[U]\x1b[0m" );
                }
                else if(board[i][p] == 'Y'){
                    cout<< ("\x1b[33m[Y]\x1b[0m" );
                }
                else if(board[i][p] == 'O'){
                    cout << ("\x1b[31;1m[O]\x1b[0m");
                }

            }
        }

    }


  
}

bool Board::validateBoardMove(int i,char tile){
    for(int j = 0 ; j < (columns - 1)/2;j++){
        if(board[i][j] != EMPTY){
            if(board[i][j] == tile  || board[i][j] == BLOCK){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}

vector<int> Board::validRows(char tile){
    vector<int> validRows ;
    validRows.push_back(1);
    // for(int i = 0 ; i  < rows;i++ ){
    //     for(int j = 0 ; j  < (columns -1)/2;i++ ){
    //         if(board[i][j] != EMPTY){
    //             if(board[i][j] == tile  || board[i][j] == BLOCK){
    //                 cout<<i<<endl;
    // //                 // validRows.push_back(i);
    //             }
    //         }
    //     }
    // }
    return validRows;
}

void Board::printBoardValidRows(char tile)
{
    vector<int> vect = validRows(tile); 
    for (int i = 0; i < rows; i++)
    {
        for (int x : vect) {
            if( x -1 == i){
                cout<<"->";
            }
        }
        std::cout << "  "<<i + 1 << ": ";
        for (int j = 0; j < columns; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

int Board::getNumberOfEmptySpaces(){
    int count = 0 ;
    for(int i = 0 ;i < rows;i++){
        for(int j = 0 ; j < (columns-2)/2;j++){
            if(board[i][j] != EMPTY){
                if(board[i][j] == BLOCK){
                    count++;
                }
            }
        }
    }
    return count;
}