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

       cout<<"Enter a name for player 1"<<endl;
    string name1,name2;
    cout<<">";
    std::getline(std::cin >> std::ws, name1);
    cout<<"Enter a name for player 2"<<endl;
    cout<<">";
    std::getline(std::cin >> std::ws, name2);

      
    cout<<"Turn For Player A:"<<endl;
    Factory* f1 = new Factory();
    f1->fillFactory();
   
    Board *board1 = new Board();
    board1->makeBoard();
    Factory *f2 = new Factory();
    f2->fillFactory();
    Board *board2 = new Board();
    board2->makeBoard();
//  int factory;
//             int row;
//             string colour;
while(board1->gameEnd() == true ||  board2->gameEnd() == true){
    //     while(board1->roundEnd() != 0 && board2->roundEnd() != 0){

    //         // cout << "Factories:" << endl;
             f1->print();
            cout << "Mosaic for A:" << endl;
            board1->printBoard();
            
    //         int factory;
    //         int row;
    //         string colour;
            
    //         cin>>factory;
           
    //         cin>>colour;
    //         // getline(cin,colour);
           
    //         cin>>row;
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //         cout<< factory<<colour<<row<<endl;
            

    // //         // setColour(colour);
    //     print(factory,colour,row);
    // //         cout<<"> ";
    // //         cin >> factory;
    // //         cin.ignore(256,'\n');
    // //         getline(cin,colour);
    // //         cin >> row;
    // //         cin.ignore(256,'\n');

    //         // board1->addTile(row-1,colour,factory);
            
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
           
            string remove;
            cin>>remove;
            f1->changeTiles(remove,2);
            f1->print();
//             // cout<<endl;
            string remove2;
            cin>>remove2;
            f1->changeTiles(remove2,2);
            f1->print();

//                string remove3;
//             cin>>remove3;
//             f1->removeElement(2,remove3);
//             f1->print();

//                string remove4;
//             cin>>remove4;
//             f1->removeElement(2,remove4);
//             f1->print();


//             // board1->saveBoard("file.txt",f1);
//             // board2->saveBoard("file.txt",f2);
//             // f1->print();

//             board1->addTile(2-1,"B",3);
//             cout << board1->getSize() << " No of broken tiles"<<endl;
//             player1->updatePoints(board1->getSize());
//             board1->addTile(3-1,"L",4);
//             cout << board1->getSize() << " No of broken tiles"<<endl;
//             player1->updatePoints(board1->getSize());
//             board1->addTile(4-1,"U",4);
//             board1->printBoard();
//             cout << board1->getSize() << "No of broken tiles"<<endl;
//              player1->updatePoints(board1->getSize());


//             int points1 = 0;
            

//     for(int i = 0; i < 5; i++){
//         if(board1->checkTilesHorizontally(i) != 5 || board1->checkTilesVertically(i) != 5){
//             points1 = board1->checkTotaltiles() ;
//         }

//         if(board1->checkTilesVertically(i) ==5 ){
//             points1 = 7;
//         }
        
//         if(board1->checkTilesHorizontally(i) ==5 ){
//             points1 = 5;
//         }   

//     }
    
//     cout<<points1<<endl;
//     player1->setPoints(player1->getPoints() + points1);
//     cout << player1->getName() << " points :" << player1->getPoints() << endl;
            // board1->addTile(5-1,"Y",5);
        //  string remove2;
        //     cin>>remove2;
        //     f1->removeElement(2,remove2);
        //     f1->print();

        //     string remove3;
        //     cin>>remove3;
        //     f1->removeElement(2,remove3);
        //     f1->print();

        //     string remove4;
        //     cin>>remove4;
        //     f1->removeElement(2,remove4);
        //     f1->print();

        //      string remove5;
        //     cin>>remove5;
        //     f1->removeElement(2,remove5);
        //     f1->print();
            

            // cout << "Factories:" << endl;
            // f2->print();
            // cout << "Mosaic for B:" << endl;
            // board2->printBoard();
            // int factoryB;
            // int rowB;
            // string colourB;
            // cout<<"> ";

            // cin >> colourB;
            // cin >> factoryB;
            // cin >> rowB;

            // cout<<factoryB<<endl;
            // cout<<colourB<<endl;
            // cout<<rowB<<endl;
            // char *cstrB = new char[colourB.size()+1];

            // strcpy(cstrB,colourB.c_str());
    
            // // int valB = f2->getNumberTiles(factoryB,cstrB);
            // board2->addTile(1-1,"B",1);
            // board2->addTile(2-1,"R",2);
            // board2->addTile(3-1,"U",3);
            // board2->addTile(4-1,"L",4);
            // board2->addTile(5-1,"Y",5);
            // f2->removeElement(factoryB,colourB);
            // cout<<"Turn Successful"<<endl;
            
        }
    cout<<"end round"<<endl;

    
    

   
    // setColour(playerNumber);

    // }
    
    

//     cout<<"\nLet's Play!"<<endl;
//     cout<<"\n=== Start Round ==="<<endl;
//     //printBoard();
//     cout<<"Turn For Player A:"<<endl;
//     cout<<"Factories:"<<endl;
//     Factory* f1 = new Factory();
//     //Factory storeFactory1 = f1->fillFactory();
//     f1->fillFactory();
//     f1->print();
//     //Making a board using vectors
//     cout<<"Mosaic for A:"<<endl;
//     Board* board1 = new Board();
//     //board1->makeBoardTwo();
//     board1->makeBoard();
//     board1->printBoard();
//     cout<<endl;
//     cout<<"> turn";

// //Error is in how we call playTurn
//     // playTurn(f1,f2,board1,board2);
//     // playTurn(f1,f2,board1,board2);
   
//     cout<<"Turn Successful"<<endl;
// // // // ^ repeated code
    
//     //TODO
//     cout<<"Turn For Player B:"<<endl;
//     cout<<"Factories:"<<endl;
//     Factory* f2 = new Factory();
//     //Factory storeFactory1 = f1->fillFactory();
//     f2->fillFactory();
//     f2->print();
//     //Making a board using vectors
//     cout<<"Mosaic for B:"<<endl;
//     Board* board2 = new Board();
//     //board2->makeBoardTwo();
//     board2->makeBoard();
//     board2->printBoard();

// // //int i=0;
// // ////signifies that a player plays 2 turns
// // // while(i<3){
// // //     playTurn(f1,f2,board1,board2,i);
// // //     i+=2;
// // // }

// // // playTurn(f1,f2,board1,board2,0);
// // // playTurn(f1,f2,board1,board2,2);

// // cout<<"Player 1 Turn 1"<<endl;
// // int getNumTilesP1T1 = f1->getNumberTiles(2,"R");
// // cout<<endl;
// // int rowBoardOneT1 = 3;
// // board1->addTile(rowBoardOneT1-1,"R",getNumTilesP1T1);
// // cout<<endl;

// // cout<<"Player 2 Turn 1"<<endl;
// // int getNumTilesP2T1 = f2->getNumberTiles(3,"U");
// // cout<<endl;
// // int rowBoardTwoT1 = 4;
// // board2->addTile(rowBoardTwoT1-1,"U",getNumTilesP2T1);
// // cout<<endl;

// // cout<<"Player 1 Turn 2"<<endl;
// // int getNumTilesP1T2 = f1->getNumberTiles(5,"Y");
// // cout<<endl;
// // int rowBoardOneT2 = 4;
// // board1->addTile(rowBoardOneT2-1,"Y",getNumTilesP1T2);
// // cout<<endl;

// // cout<<"Player 2 Turn 2"<<endl;
// // int getNumTilesP2T2 = f2->getNumberTiles(1,"L");
// // cout<<endl;
// // int rowBoardTwoT2 = 2;
// // board2->addTile(rowBoardTwoT2-1,"R",getNumTilesP2T2);
// // cout<<endl;

// cout<<"Player 1 Turn 3"<<endl;
// int getNumTilesP1T3 = f1->getNumberTiles(0,"U");
// cout<<endl;
// int rowBoardOneT3 = 4;
// board1->addTile(rowBoardOneT3-1,"U",getNumTilesP1T3);
// cout<<endl;

// cout<<"Player 1 Turn 4"<<endl;
// int getNumTilesP1T4 = f1->getNumberTiles(0,"R");
// cout<<endl;
// int rowBoardOneT4 = 1;
// board1->addTile(rowBoardOneT4-1,"R",getNumTilesP1T4);
// cout<<endl;

// cout<<"Player 1 Turn 5"<<endl;
// int getNumTilesP1T5 = f1->getNumberTiles(4,"U");
// cout<<endl;
// int rowBoardOneT5 = 2;
// board1->addTile(rowBoardOneT5-1,"U",getNumTilesP1T5);
// cout<<endl;

// cout<<"Player 1 Turn 6"<<endl;
// int getNumTilesP1T6 = f1->getNumberTiles(0,"B");
// cout<<endl;
// int rowBoardOneT6 = 5;
// board1->addTile(rowBoardOneT6-1,"B",getNumTilesP1T6);
// cout<<endl;

// cout<<"Player 1 Turn 7"<<endl;
// int getNumTilesP1T7 = f1->getNumberTiles(1,"L");
// cout<<endl;
// int rowBoardOneT7 = 5;
// board1->addTile(rowBoardOneT7-1,"L",getNumTilesP1T7);
// cout<<endl;

// cout<<"Player 1 Turn 8"<<endl;
// int getNumTilesP1T8 = f1->getNumberTiles(4,"L");
// cout<<endl;
// int rowBoardOneT8 = 5;
// board1->addTile(rowBoardOneT8-1,"L",getNumTilesP1T8);
// cout<<endl;

// cout<<"Player 1 Turn 9"<<endl;
// int getNumTilesP1T9 = f1->getNumberTiles(5,"L");
// cout<<endl;
// int rowBoardOneT9 = 5;
// board1->addTile(rowBoardOneT9-1,"L",getNumTilesP1T9);
// cout<<endl;

// cout<<"Player 1 Turn 10"<<endl;
// int getNumTilesP1T10 = f1->getNumberTiles(3,"U");
// cout<<endl;
// int rowBoardOneT10 = 5;
// board1->addTile(rowBoardOneT10-1,"U",getNumTilesP1T10);
// cout<<endl;
    

}

void mainGame::LoadGame(string filename){
    Board* board1 = new Board();
//     Board* board2 = new Board();

//     // Factory* f1 = new Factory();
//     // Factory* f2 = new Factory();
// // cout<<this->colour;
// cout<<this->playerNumber;
//     cout<<getPlayerNum();
    board1->loadBoard(filename);
//     board2->loadBoard2(filename);
// Factory* factory = new Factory();
// factory->loadFactory(filename);
   board1->printLoadBoard();

    // if(getPlayerNum() == 1){
    //    

    // }

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