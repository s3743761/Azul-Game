#include "Game.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>


using namespace std;

mainGame::mainGame(){
    tileBag = new Bag();
    length = 0; 
    // numberOfPlayers = 2;
    // numCentralFactories = 1;
    // sixTileMode = false;
    // greyBoardMode = false;
    gameLoadedFromFile = false;
}

void mainGame::playGame(){
    
    if(!gameLoadedFromFile) {
        
        askForGameMode();
        askForPlayers();
        askForCentralFactories();

        tileBag->setSixTileMode(sixTileMode);
        tileBag->fillBag();
        tileBag->Shuffle();
        
        factory = new Factory(numberOfPlayers, numCentralFactories);
        factory->fillFactory(tileBag);

        players[1]->setFirstPlayer(1); 
        
    }
    
    orderPlayers = new Player*[numberOfPlayers];
    orderBoards = new Board*[numberOfPlayers];

    bool gameOver = false;

    std::cout << "\nLet's Play!" << std::endl;
    std::cout << "\n=== Start Round ===" << std::endl;

    while(!gameOver) {
        int startingIndex = 0;
        startingIndex = setPlayerOrderForRound();

        while(factory->getTotalSize() > 0) {
            for(int i = 0; i < numberOfPlayers; i++) {
                if(startingIndex != 0) {
                    i = startingIndex;
                    startingIndex = 0;
                }

                if(factory->getTotalSize() > 0){

                    Player* currentPlayer = orderPlayers[i];
                    turnPlayerID = currentPlayer->getId();
                    Board* currentBoard = orderBoards[i];
                    
                    std::cout << "TURN FOR PLAYER : " << currentPlayer->getName() << std::endl;
                    std::cout << std::endl;
                    std::cout << "Factories:" << std::endl;
                    factory->print();

                    std::cout << "Mosaic for " << currentPlayer->getName() << ":" << std::endl;
                    currentBoard->printBoard();
                    currentBoard->printBroken();

                    std::cout << "> ";
                    string command;
                    
                    string secondArgument;
                    
                    char colour;
                    int row;
                    std::cin >> command;
                    // std::cin >> secondArgument;
                    
                    if(command == "turn"){
                        std::cin >> secondArgument;
                        int factoryIndex = stoi(secondArgument);
                        std::cin >> colour;
                        std::cin >> row;
                        playTurn(factoryIndex, colour, row, currentPlayer, currentBoard);
                    }
                    else if(command == "save") {
                        std::cin >> secondArgument;
                        saveGame(secondArgument + ".txt");
                        return;
                    }
                    else if(command == "help"){
                    // else if(command == "help" && secondArgument == "1"){
                        help();
                    }
                    else {
                        std::cout << "Invalid Command. Try Again" << std::endl;
                        std::cin.clear();
                        i--;
                    }
                }
            }            
            
        }   

        std::cout << "=== END OF ROUND ===" << std::endl;

        if(greyBoardMode){
            askForGreyBoardInput();
        }
        else{
            for(int i = 0 ; i < length ; i++){
                boards[i]->placeTileAtLast();
                boards[i]->removeTileFromBoard(bagLid);
                countpoints(players[i], boards[i]);
                std::cout << players[i]->getName() << "'s Total Points: " << players[i]->getPoints() << std::endl;
            }
        }

        for(int i = 0; i < length; i++) {
            if(boards[i]->gameOver() == true){
                gameOver = true;
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
    ofstream of;
    of.open(filename, std::ofstream::out | std::ofstream::trunc);
    string sixTileModeText;
    if( sixTileMode == true){
        sixTileModeText = "true";
    }
    else{
        sixTileModeText = "false";
    }
    
    string greyBoardModeText;
    if( greyBoardMode == true){
        greyBoardModeText = "true";
    }
    else{
        greyBoardModeText = "false";
    }
    of << "#Bag\n";
    of << tileBag->returnAsString() + "\n";
    of << "#Lid\n";
    of << returnLidAsString()+ "\n";
    of << "#Number Of Players\n";
    of << numberOfPlayers;
    of <<"\n";
    of << "#Number of Central Factories\n";
    of << numCentralFactories;
    of <<"\n";
    of <<"#Six Tile Mode\n";
    of << sixTileModeText + "\n";
    of <<"#Grey Tile Mode\n";
    of << greyBoardModeText + "\n";
    of << "#Factories\n";
    of << factory->returnAsString();
    of << "#player who's turn it is\n";
    of << turnPlayerID;
    of <<"\n";
    of << "#round order\n";
    for(int i = 0 ; i < numberOfPlayers ; i++){
        of << orderPlayers[i]->getId();
    }
    of<< "\n";
    for(int j = 0 ; j < numberOfPlayers ; j++){
        of << "#Player\n";
        of << orderPlayers[j]->getId();
        of <<"\n";
        of << orderPlayers[j]->getName();
        of <<"\n";
        of << orderPlayers[j]->getPoints();
        of <<"\n";
        of << orderBoards[j]->returnTriangleAsString();
        of << orderBoards[j]->returnWallAsString();
        of << orderBoards[j]->returnBrokenAsString();
        of <<"\n";
    }
    
    
}

void mainGame::LoadGame(string filename){
    fstream of;
    of.open(filename + ".txt");
    string line;

    int lineNumber = 1;
    
    vector<string> factoryStrings;
    int numFactories = 0;
    int numBoardRows = 0;

    while(getline(of,line)){

        if(lineNumber == 2) {
            tileBag->load(line);
        }
        else if(lineNumber == 4 && line != "_") {
            std::copy(line.begin(), line.end(), std::back_inserter(bagLid));
        }
        else if(lineNumber == 6) {
            numberOfPlayers = stoi(line);
            players = new Player*[numberOfPlayers];
            boards = new Board*[numberOfPlayers];
        }
        else if(lineNumber == 8) {
            numCentralFactories = stoi(line);
            factory = new Factory(numberOfPlayers, numCentralFactories);      
            numFactories = factory->getTotalFactories();      
        }
        else if(lineNumber == 10) {
            sixTileMode = line == "true";
            numBoardRows = sixTileMode ? 12 : 10;
        }
        else if(lineNumber == 12) {
            greyBoardMode = line == "true";
        }
        else if(lineNumber >= 14 && lineNumber < (14 + numFactories)){
            factoryStrings.push_back(line);
        }
        else if(lineNumber == (14 + numFactories + 1)){
            turnPlayerID = stoi(line);
        }
        else if(lineNumber == (14 + numFactories + 3)){
            playerOrder = line;
        }
        
        else if(lineNumber >= (14 + numFactories + 4)){
            if(line == "#Player"){
                int playerID;
                string playerName;
                int score;
                vector<string> triangle;
                vector<string> wall;
                string tmp;
                string broken; 

                of >> playerID >> playerName >> score;

                Player *player = new Player(playerID, playerName, score);
                Board *board = new Board(sixTileMode);
               
                for(int i = 0; i < numBoardRows / 2; i++) {
                    of >> tmp;
                    triangle.push_back(tmp);
                }

                for(int i = 0; i < numBoardRows / 2; i++) {
                    of >> tmp;
                    wall.push_back(tmp);
                }
               
                of >> broken;
                board->loadBoard(triangle, wall);
                board->loadBroken(broken);
                // TODO: if broken has F, set first player
                addPlayer(player,board);
    
            }
            
        }
        
        lineNumber++;
    
    }    
   
    factory->loadFactory(factoryStrings);
    gameLoadedFromFile = true;
    playerOrderSet = true;

    playGame();
}




void mainGame::countpoints(Player* player, Board* board){
//   int points1 = 0;
//     for (int i = 0; i < 5; i++){
       
//         if (board1->checkTilesHorizontally(i) != 5 || board1->checkTilesVertically(i) != 5){
//             points1 = board1->checkTotaltiles();
//         }
        
//         if (board1->checkTilesVertically(i) == 5){
//             points1 = 7;
//         }
//         if (board1->checkTilesHorizontally(i) == 5){
//             points1 = 5;
//         }
       
//     }
//       player1->setPoints(points1 - board1->getSize());

//     std::cout << player1->getName() << " points :" << player1->getPoints() << endl;
       std::cout << player->getName() << "'s points for this round: " << 0 << endl;
}

void mainGame::help(){
    std::cout << "A sample turn for the game looks like :";
    std::cout << "turn <factory> <colour> <row>"<<endl;

}

void mainGame::addPlayer(Player *player, Board* board){
    players[length] = player;
    boards[length] = board;
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
}

string mainGame::returnLidAsString(){
    std::string bagLidString = ""; 

    for(int i = 0; i < bagLid.size(); i++) {
        bagLidString += bagLid[i];
    }
    
    if(bagLidString.length() == 0){
        return "_";
    }
    return bagLidString;
}

void mainGame::askForPlayers(){
    length = 0;
    std::cout << "Enter the number of players playing:" << std::endl;
    std::cout << "> ";
    std::cin >> numberOfPlayers;
    while(std::cin.fail() || numberOfPlayers < 2 || numberOfPlayers > 4){
        std::cout << "Incorrect Number of Players, Try Again." << endl;
        std::cout << "Enter the number of players playing:" << std::endl;
        std::cout << "> ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> numberOfPlayers;
    }
    
    players = new Player*[numberOfPlayers];
    boards = new Board*[numberOfPlayers];

    for(int i = 0 ; i < numberOfPlayers; i++){
        string playerName;   
        std::cout << "Enter a name for player " << i+1 << endl;
        std::cout << "> ";
        std::getline(std::cin >> std::ws, playerName);
        Player *player = new Player(i+1, playerName, 0);  
        Board *board = new Board(sixTileMode); 
        board->makeBoard();
        addPlayer(player, board);
    }   
    return;

}
void mainGame::askForCentralFactories(){

    std::cout << "Please Enter the number of central factories required (1/2)?"<<endl;
    std::cout << "> ";
    std::cin >> numCentralFactories;
    while(std::cin.fail() || numCentralFactories < 1 || numCentralFactories > 2 ){
        cout << "Invalid Number of Central Factories, Try Again." << endl;
        std::cout << "Please Enter the number of central factories required (1/2)?" << endl;
        std::cout << "> ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> numCentralFactories;
    }  
    return;
}
void mainGame::askForGameMode(){
    
    char gameTypeOption;
    cout << "Would You Like To Play The 6 Tile Mode (Y/N)?"<<endl;
    std::cout << "> ";
    std::cin >> gameTypeOption;
    while(std::cin.fail() || (gameTypeOption != 'Y' && gameTypeOption != 'N' )){
        cout << "Invalid Command, Please Try Again." << endl;
        cout<< "Would You Like To Play The 6 Tile Mode (Y/N)?"<<endl;
        std::cout << "> ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> gameTypeOption;
        
    }
    if(gameTypeOption == 'Y'){
        sixTileMode = true;
    }
    else{
        sixTileMode = false;
    }

    char greyTileCommand;
    cout << "Would You Like To Play The Grey Board Mode (Y/N)?" << endl;
    std::cout << "> ";
    std::cin >> greyTileCommand;
    while(std::cin.fail() || (gameTypeOption != 'Y' && gameTypeOption != 'N' )){
        cout << "Invalid Command, Please Try Again." << endl;
        cout << "Would You Like To Play The Grey Board Mode (Y/N)?" <<endl;
        std::cout << "> ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> greyTileCommand;
        
    }
    if(greyTileCommand == 'Y'){
        greyBoardMode = true;
    }
    else{
        greyBoardMode = false;
    }
    
    return;

}

int mainGame::setPlayerOrderForRound() {
    int startingIndex = 0;

    if(!playerOrderSet) {
        
        int order = 1;
        
        for(int p = 0 ; p < numberOfPlayers; p++){
            if(players[p]->getFirstPlayer() == 1) {
                orderPlayers[0] = players[p];
                orderBoards[0] = boards[p];
                players[p]->setFirstPlayer(0);
                //TODO: remove the "F" tile from player's broken / clear broken
            }
            else {
                orderPlayers[order] = players[p];
                orderBoards[order] = boards[p];
                order++;
            }
        }
    }
    
    else{
        
        for(int i = 0; i < numberOfPlayers; i++){
            int playerIndex = (playerOrder.at(i) - '0') - 1;
            
            orderPlayers[i] = players[playerIndex];
            orderBoards[i] = boards[playerIndex];

            if(orderPlayers[i]->getId() == turnPlayerID) {
                startingIndex = i;
            }
        }
        playerOrderSet = false;
    }

    return startingIndex;
}

void mainGame::playTurn(int factoryIndex, char colour, int row, Player* currentPlayer, Board* currentBoard) {
    int numberTiles = factory->getNumberTiles(factoryIndex, colour);
                        
    if(numCentralFactories == 1){
        if(factoryIndex != 0){
            factory->addRemainingTiles(factoryIndex, colour, 0); 
        } 
        else{ 
            factory->removeElement(factoryIndex, colour);  
            if(factory->getTotalSize() > 0 && factory->firstPlayerTileExsists(0) == true){
                factory->removeElement(0, 'F');
                currentPlayer->setFirstPlayer(1);
                // currentPlayer->updatePoints(-1);
                currentBoard->addBrokenTile(1,0,'F');
            }
        }
    }
    else{
        int multipleCentral;
        if(factoryIndex != 0 && factoryIndex != 1){
            cout<< "Enter the Central Factory you want to place the tile: ";
            std::cin >> multipleCentral;
            while(std::cin.fail() || multipleCentral < 0 || multipleCentral > 2){
                std::cout << "Incorrect Central Factory, Try Again:" << endl;
                std::cout << "Enter the Central Factory you want to place the tile: ";
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> multipleCentral;
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
                // currentPlayer->updatePoints(-1);
                currentBoard->addBrokenTile(1,0,'F');
            }
        }

    }

    currentBoard->addTile(row - 1, colour, numberTiles);

    std::cout<< "Turn succesful." << std::endl;
}

void mainGame::askForGreyBoardInput(){

    for(int i = 0 ; i < length ; i ++){
        cout << "Player Name: " << players[i]->getName() << endl;
        boards[i]->printBoard();
        for(int j = 0 ; j < boards[i]->getRows();j++){

            int greyTileColumn;

            if(boards[i]->getEmptyRowSize(j) == 0){ 

                std::cout << "Which column would you like to place tile '" << boards[i]->getTile(j) <<"' from row " << j+1 << " (pick from 1-" << boards[i]->getRows()<< "):" << std::endl;
                std::cout << "> ";
                std::cin >> greyTileColumn;

                bool checkMove = boards[i]->checkAdjacent(j, greyTileColumn);

                while(std::cin.fail() || greyTileColumn < 1 || greyTileColumn > boards[i]->getRows() || checkMove == false){
                    cout << "Incorrect Column, Try Again: "<< endl;
                    cout << "Which column would you like to place tile '" << boards[i]->getTile(j) <<"' from row " << j+1 << " (pick from 1-" << boards[i]->getRows() << "):" << std::endl;
                    std::cout << "> ";
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                    std::cin >> greyTileColumn;
                    checkMove = boards[i]->checkAdjacent(j, greyTileColumn);
                }
                boards[i]->placeTileGreyBoard(j, greyTileColumn);              
            }
        }
        boards[i]->removeTileFromBoard(bagLid);
    }
}