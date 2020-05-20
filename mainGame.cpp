#include "mainGame.h"
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <limits>


using namespace std;

mainGame::mainGame(){
    
}

void mainGame::playGame(){

      
    // Factory* f1 = new Factory();
    // f1->fillFactory();
   
    Board *board1 = new Board();
    board1->makeBoard();
    // Board *board2 = new Board();
    // board2->makeBoard();
    int moves = 0;

    cout<<"Sample Mosiac Where Your Tiles will be Placed According to Colour:"<<endl;
    board1->sampleMosiac();

    while (moves < 3){
        cout<<endl;
        board1->printBoard();
        int row;
        char colour;
        int factory;

        cin>>factory;
        cin>>colour;
        cin>>row;


        board1->addTile(row-1,colour,factory);

       
        moves += 1;
    }
    // while(board1->gameEnd() == true ||  board2->gameEnd() == true){
    //     while(board1->roundEnd() != 0 && board2->roundEnd() != 0){

            // cout << endl;
            // cout<<"Turn For Player A:"<<endl;
            // f1->print();
            // cout << "Mosaic for A:" << endl;
            // board1->printBoard();
            // f1->print();
            
            // int factory;
            // int row;
            // string colour;
    
            // cout<<"> ";
            // // cin>>factory;
            // // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // cin>>row;
            // cin.ignore();
            // getline(cin,colour);
            // cin>>factory;

            // cout<<"Before function:" <<endl;
            // board1->printBoard();

            // board1->addTile(1,"U", 2);
            // board1->addTile(2,"B", 3);
            // // getline(cin,colour);
            // cin>>row;
            


            // int number = f1->getNumberTiles(factory,colour);
            // board1->addTile(row-1,colour,number);
            // f1->removeElement(factory,colour);
            

            
    //         cout<< factory<<colour<<row<<endl;
           

//             // setRow(row);
//             // setColour(colour);
//             // setCount(factory);
//         // cout<<this->row;
//         //  cout<<this->colour;
//         //   cout<< this->count<<endl;


//             // cout<<factory<<endl;
//             // cout<<colour<<endl;
//             // cout<<row<<endl;

//             // cout<<"before going to addTile"<<endl;
//             // board1->printBoard();
//             // // char *sandwich = ".";
            
        
//             // board1->addTile(row-1,colour,factory);
// Player* player1 = new Player(name1,0);

    // }
   
}

void mainGame::LoadGame(string filename){
//     Board* board1 = new Board();
//     // Board* board1 = new Board();

//     // Factory* f1 = new Factory();
// //     // Factory* f2 = new Factory();
// // // cout<<this->colour;
// // cout<<this->playerNumber;
// //     cout<<getPlayerNum();
//     board1->loadBoard2(filename);
//     // board1->loadBoard(filename);
// // Factory* factory = new Factory();
// // f1->loadFactory(filename);
// board1->copy();
//     board1->printLoadBoard();
//     // board1->addTile(3,"U",3);

    // if(getPlayerNum() == 1){
    //    

    // }
// Player* p = new Player("n",0);
// p->loPoints1("file.txt");
// cout<<p->getPoints();
    // if(getPlayerNum() == 2){
    //     board2->printLoadBoard2();

    // }



}


void mainGame::setPlayerNum(int playerNum){
    this->playerNumber= playerNum;
}

int mainGame::getPlayerNum(){
    return this->playerNumber;
}

string mainGame::getColour(){
    return this->colour;
}

int mainGame::getCount(){
    return this->count;
}

void mainGame::setColour(string colour){
    this->colour = colour;
}

void mainGame::print(int r, std::string s,int p){
    cout<<r<<endl;
    cout<<s<<endl;
    cout<<p<<endl;
}