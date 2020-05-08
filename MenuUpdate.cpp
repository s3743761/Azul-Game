#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Board.h"
using namespace std;
void showMenu();
void newGame();
void loadGame();
void credits();
void quit();
//void printBoard();
// const char board[5][13] = {{' ',' ',' ',' ', '.' , '|' , '|' , '.','.','.','.','.',},
//                             {' ',' ',' ','.', '.' ,'|', '|' ,'.','.','.','.','.',},
//                             {' ',' ','.','.', '.' ,'|', '|' ,'.','.','.','.','.',},
//                             {' ','.','.','.', '.' ,'|', '|' ,'.','.','.','.','.',},
//                             {'.','.','.','.', '.' ,'|', '|' ,'.','.','.','.','.',}
//                             };

int main(int argc, char* argv[]){
    for(int i = 0; i < argc;i++){
        if(strcmp(argv[i],"-s")==0 ){
            showMenu();
        }
    }
    
    
   

    return 0;
}

void showMenu(){
    cout<< "\nWelcome to Azul!" << endl;
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout<<"\n Menu" << endl;
    cout<< "_ _ _ _ _" << endl;

    cout<<"\n1. New Game" << endl;
    cout<<"2. Load Game" << endl;
    cout<<"3. Credits" << endl;
    cout<<"4. Quit" << endl;
    string choice;
    cout<< "> ";
    cin >> choice;
    if(choice == "1"){
        cout<<"\n" << endl;
        newGame();
        
        
    }

    if(choice == "2"){
        cout<<"\n" << endl;
        loadGame();
        
        
    }
    if(choice == "3"){
         cout<<"\n" << endl;
        credits();
        
        
    }
    if(choice == "4"){
        cout<<"\n" << endl;
        quit();
       
        
    }
   
    if(choice != "1" && choice != "2" && choice != "3" && choice != "4" ){
        cout<<"Incorrect Option, please choose from the menu given" <<endl;
    }


}

void newGame(){
    cout<<"Enter a name for player 1"<<endl;
    string name1,name2;
    cout<<">";
    std::getline(std::cin >> std::ws, name1);
    cout<<"Enter a name for player 2"<<endl;
    cout<<">";
    std::getline(std::cin >> std::ws, name2);
    cout<<"\nLet's Play!"<<endl;
    cout<<"\n=== Start Round ==="<<endl;
    //printBoard();
    //Making a board using vectors
    Board* board = new Board();
    board->makeBoardTwo();
    //TODO
    



    
    showMenu();
}

void loadGame(){
    cout<<"Enter File Name from which load a game: \n";
    cout<<">";
    string fileName;
    string line;
    cin>> fileName;
    ifstream myFile(fileName);
    if(myFile.is_open()){
        cout<<"Azul game successfully loaded"<<endl;
        while(getline(myFile,line)){
            cout<<line<<'\n';
        }
        myFile.close();
    }
    else cout <<"\nUnable to Open File"<<endl;

showMenu();
}

void credits(){
    cout<<"Name: Prabhav Mehra"<<endl;
    cout<<"Student ID: s3743761" << endl;
    cout<<"Email: s3743761@student.rmit.edu.au" << endl;

    cout<<"\nName: Kaushal Gawri"<<endl;
    cout<<"Student ID: s3777121" << endl;
    cout<<"Email: - s3777121@student.rmit.edu.au" << endl;

    cout<<"\nName: Ali Tariq"<<endl;
    cout<<"Student ID: -" << endl;
    cout<<"Email: @student.rmit.edu.au" << endl;
showMenu();

}

void quit(){
    cout<<"Thanks for Playing."<<endl;
    return;
    // cout<< "Would you like to save the game ? "<<endl;
    // char choice;
    // cout<< "Y/N: ";
    // cin>>choice;
    // if(choice == 'Y'){
    //     //TODO
    //     return;
    // }

    // else if(choice == 'N'){
    //     cout<<"Thanks for Playing."<<endl;
    //     return;
    // }
    // else
    // {
        
    //     throw std::invalid_argument("You can only Enter Y or N");
    //     showMenu();
       
    // }
    

    // showMenu();
}

// void printBoard(){
//     for(int i = 0 ; i < 5;++i){
//          int p = i + 1;
//          cout<< p <<". ";
//         for(int j = 0 ; j < 12;++j){
            
//             cout<<board[i][j];
//         }
//         cout<<" "<<endl;
//     }
// }