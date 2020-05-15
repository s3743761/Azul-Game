#include "mainGame.h"
#include <string>
#include <string.h>

using namespace std;


void mainGame::playGame(){
    cout<<"Turn For Player A:"<<endl;
    Factory* f1 = new Factory();
    f1->fillFactory();
   
    Board *board1 = new Board();
    board1->makeBoard();
    Factory *f2 = new Factory();
    f2->fillFactory();
    Board *board2 = new Board();
    board2->makeBoard();

    while(board1->gameEnd() == true && board2->gameEnd() ){
        cout << "Factories:" << endl;
        f1->print();
        cout << "Mosaic for A:" << endl;
        board1->printBoard();
        int factory;
        int row;
        string colour;
        cout<<"> ";

        cin >> factory;
        cin >> colour;
        getline(cin,colour);
        cin >> row;

        cout<<factory<<endl;
        cout<<colour<<endl;
        cout<<row<<endl;

        cout<<"before going to addTile"<<endl;
        board1->printBoard();

        
        board1->addTile(row-1,colour,factory);
    
        f1->removeElement(factory,colour);
        cout<<"Turn Successful"<<endl;
       

        cout << "Factories:" << endl;
        f2->print();
        cout << "Mosaic for B:" << endl;
        board2->printBoard();
        int factoryB;
        int rowB;
        string colourB;
        cout<<"> ";

        cin >> factoryB;
        cin >> colourB;
        cin >> rowB;

        cout<<factoryB<<endl;
        cout<<colourB<<endl;
        cout<<rowB<<endl;
        // char *cstrB = new char[colourB.size()+1];

        // strcpy(cstrB,colourB.c_str());
   
        // int valB = f2->getNumberTiles(factoryB,cstrB);
        board2->addTile(rowB-1,colourB,factoryB);
        f2->removeElement(factoryB,colourB);
        cout<<"Turn Successful"<<endl;

        // cout << "Factories:" << endl;
        // f1->print();
        // cout << "Mosaic for A:" << endl;
        // board1->printBoard();
        // int factoryC;
        // int rowC;
        // string colourC;
        // cout<<"> ";

        // cin >> factoryC;
        // cin >> colourC;
        // cin >> rowC;

        // // char *cstr = (char*)malloc(sizeof(char)+colour.size());
        // // // char *cstr = new char[colour.size()+1];
        // // // delete[] cstr;
        // // // strcpy(cstr,colour.c_str());
   
        // // int val = f1->getNumberTiles(factory,cstr);
        // board1->addTile(rowC-1,colourC,factoryC);
        // f1->removeElement(factoryC,colourC);
        // cout<<"Turn Successful"<<endl;
       
        
        // free(cstr);
        //  free(cstrB);
        // delete[] cstr;
        // delete[] cstrB;

    
    
    }

}