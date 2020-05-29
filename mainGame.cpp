#include "mainGame.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>


using namespace std;

mainGame::mainGame(){
    tileBag = new Bag();
    
    // player1Name = "";
    // player1Scores = 0;
    // player2Name = "";
    // player2Scores = 0;
    length = 0;
    // players = new Player*[length+1];
    //boards = new Board*[length];

    boardsLoaded = false;
   
}

void mainGame::playGame(){
    
    int numberPlayers;
    std::cout << "Enter the number of players playing: ";
    cin >> numberPlayers;
    while(cin.fail() || numberPlayers < 2 || numberPlayers > 4){
        std::cout << "Incorrect Number of Players, Try Again:" << endl;
        std::cout << "Enter the number of players playing: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> numberPlayers;
    }
    players = new Player*[numberPlayers];


    for(int i = 0 ; i < numberPlayers;i++){
            string playerName;
        // if(players[i]->getName().length() == 0){
            std::cout << "Enter a name for player " << i+1 << endl;
            std::cout << "> ";
            std::getline(std::cin >> std::ws, playerName);
            Player *player = new Player(playerName ,0);
            addPlayer(player);
        // }
    }

    int numberOfCentral = 1;
    
    if(numberPlayers > 2) {
        std::cout<<"Please Enter the number of central factories required: ";
        cin>>numberOfCentral;
    }
    
    std::cout << "\nLet's Play!" << std::endl;
    std::cout << "\n=== Start Round ===" << std::endl;

    factory = new Factory(numberPlayers, numberOfCentral);
    cout<<"here"<<endl;
    if(tileBag->getSize() == 0){
        tileBag->fillBag();
        tileBag->Shuffle();
    }

    if(factory->getTotalSize() == 0) {
        factory->fillFactory(tileBag);
    }

    if(!boardsLoaded) {
        boards = new Board*[length];

        for(int i = 0 ; i < length; i++){
            boards[i] = new Board();
            boards[i]->makeBoard();    
        }    
    }

    players[0]->setFirstPlayer(1); 
    
    Player* orderPlayers[length];
    Board* orderBoards[length];

    // for(int p = 0 ; p < length; p++){
    //     orderPlayers[p] = players[p];
    //     orderBoards[p] = boards[p];
    // }
    
    bool gameOver = false;

    //TODO: make it into a function
    while(!gameOver) {
        int order = 1;
        for(int p = 0 ; p < length; p++){
            if(players[p]->getFirstPlayer() == 1) {
                orderPlayers[0] = players[p];
                orderBoards[0] = boards[p];
                players[p]->setFirstPlayer(0);
            }
            else {
                orderPlayers[order] = players[p];
                orderBoards[order] = boards[p];
                order++;
            }
        }

        while(factory->getTotalSize() > 0) {

            for(int i = 0; i < length; i++) {
                if(factory->getTotalSize() != 0){
                    Player* currentPlayer = orderPlayers[i];
                    Board* currentBoard = orderBoards[i];
                    

                    std::cout << "TURN FOR PLAYER : " << currentPlayer->getName() << std::endl;
                    std::cout << std::endl;
                    std::cout << "Factories:" << std::endl;
                    factory->print();
                    std::cout << "Mosaic for " << currentPlayer->getName() << ":" << std::endl;
                    currentBoard->printBoard();
                
                    std::cout << "> ";
                    string command;
                    
                    string secondArgument;
                    
                    char colour;
                    int row;

                    cin >> command;
                    cin >> secondArgument;
                    

                    if(command == "turn"){
                        int factoryIndex = stoi(secondArgument);
                        cin >> colour;
                        cin >> row;
                
                        int numberTiles = factory->getNumberTiles(factoryIndex, colour);
                        
                        // TODO: reduce code redunancy 
                        if(numberOfCentral == 1){
                            if(factoryIndex != 0){
                                factory->addRemainingTiles(factoryIndex, colour, 0); 
                            } 
                            else{ 
                                factory->removeElement(factoryIndex, colour);  
                                if(factory->getTotalSize() > 0 && factory->firstPlayerTileExsists(0) == true){
                                    factory->removeElement(0, 'F');
                                    currentPlayer->setFirstPlayer(1);
                                    currentPlayer->updatePoints(-1);
                                    currentBoard->addBrokenTile(1,0,'F');
                                }
                            }
                        }
                        else{
                            int multipleCentral;
                            if(factoryIndex != 0 && factoryIndex != 1){
                                cout<< "Enter the Central Factory you want to place the tile: ";
                                cin >> multipleCentral;
                                while(cin.fail() || multipleCentral < 0 || multipleCentral > 2){
                                    std::cout << "Incorrect Central Factory, Try Again:" << endl;
                                    std::cout << "Enter the Central Factory you want to place the tile: ";
                                    cin.clear();
                                    cin.ignore(256,'\n');
                                    cin >> multipleCentral;
                                }
                                factory->addRemainingTiles(factoryIndex, colour, multipleCentral); 
                            } 
                            else{ 
                                std::cout << "Remove Element, Factory Index: " << factoryIndex << " Colour: " << colour << endl;
                                factory->removeElement(factoryIndex, colour); 
                                std::cout << "Factory Total Size: " << factory->getTotalSize() << std::endl;     
                               
                                if(factory->getTotalSize() > 0 && factory->firstPlayerTileExsists(0) == true){
                                    factory->removeElement(0, 'F');
                                    currentPlayer->setFirstPlayer(1);
                                    currentPlayer->updatePoints(-1);
                                    currentBoard->addBrokenTile(1,0,'F');
                                }
                            }

                        }
                    
                        currentBoard->addTile(row - 1, colour, numberTiles);
                    
                        std::cout<< "Turn succesful." << std::endl;
                        
                    }
                    else if(command == "save") {
                        saveGame(secondArgument + ".txt");
                        return;
                    }
                    else if(command == "help" && secondArgument == "1"){
                        help();
                        return;
                    }
                    else {
                        // return;
                        // TODO: handle invalid command, eg: "tturn 0 2 1"
                        std::cout << "Invalid Command, Try Again:" << endl;
                    }
                
                }
                
            }

        }

            
        std::cout << "=== END OF ROUND ===" << std::endl;
        for(int i = 0 ; i < length ; i++){
            boards[i]->placeTileAtLast();
        
            boards[i]->removeTileFromBoard(bagLid);
            countpoints(players[i], boards[i]);
            std::cout << players[i]->getName() << " Total Points :" << players[i]->getPoints() << std::endl;
        }

        
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < 5; j++) {
                if(boards[i]->checkTilesHorizontally(j) == 5){
                    
                    gameOver = true;
                }
            }
        }
        
        if(!gameOver) {
            if(tileBag->getSize() < 36){
                reFill(bagLid, tileBag);
            }
            factory->fillFactory(tileBag);
            std::cout << "=== START ROUND ===" << std::endl;
        }
       
    }

    std::cout << "=== GAME OVER ===" << std::endl;
    for(int i = 0 ; i < length ; i++){
        countpoints(players[i],boards[i]);
    }

}

void mainGame::saveGame(string filename) {
    // ofstream of;
    // of.open(filename, std::ofstream::out | std::ofstream::trunc);
    // of << "# Bag\n";
    // of << tileBag->returnAsString() + "\n";
    // of << "# Lid: \n";
    // of << "_ \n";
    // of << "# Factories: \n";
    // of << factory->returnAsString();
    // of << "# Player1 name: \n";
    // of << player1Name + "\n";
    // of << "# Player2 name: \n";
    // of << player2Name + "\n";
    // of << "# Player1 points: \n";
    // of << to_string(player1Scores) + "\n";
    // of << "# Player2 points: \n";
    // of << to_string(player2Scores) + "\n";
    // of << "# Player1 board: \n";
    // of << board1->returnTriangleAsString();
    // of << board1->returnWallAsString();
    // of << "# Player2 board: \n";
    // of << board2->returnTriangleAsString();
    // of << board2->returnWallAsString();
    // of.close();
    // std::cout << "Game successfully saved to " << filename << std::endl;
    // boardsLoaded = true;
    // playGame();
}

void mainGame::LoadGame(string filename){
    // fstream of;
    // of.open(filename);
    // string line;


    // // string bagStrings[1];
    // string factoryStrings[6];
    // int factoryCounter = 0;

    // string board1Triangle[5];
    // int board1TriangleCounter = 0;

    // string board1Wall[5];
    // int board1WallCounter = 0;

    // string board2Triangle[5];
    // int board2TriangleCounter = 0;

    // string board2Wall[5];
    // int board2WallCounter = 0;

    // // int bagCounter = 0 ;
    // int lineCounter = 0;
    
    // while(getline(of,line)){

    //     if(lineCounter >= 5 && lineCounter <= 10){
    //         factoryStrings[factoryCounter] = line;
    //         factoryCounter++;
    //     }

    //     if(lineCounter == 12) {
    //         player1Name = line;
    //     }
    //     if(lineCounter == 16) {
    //         player1Scores = stoi(line);
    //     }

    //     if(lineCounter == 14) {
    //         player2Name = line;
    //     }
    //     if(lineCounter == 18) {
    //         player2Scores = stoi(line);
    //     }

    //     if(lineCounter >= 20 && lineCounter <= 24){
    //         board1Triangle[board1TriangleCounter] = line;
    //         board1TriangleCounter++;
    //     }

    //     if(lineCounter >= 25 && lineCounter <= 29){
    //         board1Wall[board1WallCounter] = line;
    //         board1WallCounter++;
    //     }

    //     if(lineCounter >= 31 && lineCounter <= 35){
    //         board2Triangle[board2TriangleCounter] = line;
    //         board2TriangleCounter++;
    //     }

    //     if(lineCounter >= 36 && lineCounter <= 40){
    //         board2Wall[board2WallCounter] = line;
    //         board2WallCounter++;
    //     }

    //     lineCounter++;
        
    // }

    // factory->loadFactory(factoryStrings);
    // board1->loadBoard(board1Triangle, board1Wall);
    // board2->loadBoard(board2Triangle, board2Wall);
    // boardsLoaded = true;
   
    // playGame();

}


void mainGame::setPlayerNum(int playerNum){
    this->playerNumber= playerNum;
}

int mainGame::getPlayerNum(){
    return this->playerNumber;
}


void mainGame::countpoints(Player* player1, Board* board1){
  int points1 = 0;
    for (int i = 0; i < 5; i++){
       
        if (board1->checkTilesHorizontally(i) != 5 || board1->checkTilesVertically(i) != 5){
            points1 = board1->checkTotaltiles();
        }
        
        if (board1->checkTilesVertically(i) == 5){
            points1 = 7;
        }
        if (board1->checkTilesHorizontally(i) == 5){
            points1 = 5;
        }
       
    }
      player1->setPoints(points1 - board1->getSize());

    std::cout << player1->getName() << " points :" << player1->getPoints() << endl;
}

void mainGame::help(){
    std::cout << "A sample turn for the game looks like :";
    std::cout << "turn <factory> <colour> <row>"<<endl;

}

void mainGame::addPlayer(Player *element){
    players[length] = element;
    length++;

}

void mainGame::reFill(vector<char> bagLid, Bag* tileBag){
    Tiles* t = nullptr;
    for (std::vector<char>::const_iterator p = bagLid.begin(); p != bagLid.end(); ++p){
        if(*p == 'R'){
            t = new Tiles(Red);
        }
        else if(*p == 'B'){
            t = new Tiles(DarkBlue);
        }
        else if(*p == 'Y'){
            t = new Tiles(Yellow);
        }
        else if(*p == 'U'){
            t = new Tiles(Black);
        }
        else if(*p == 'L'){
            t = new Tiles(LightBlue);
        }
        tileBag->getList()->addNode(t);
    }
    bagLid.clear();
    // bag->getList()->printLine();
}