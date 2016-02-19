#include <iostream>
#include <string>
using namespace std;

class quard_Tree_Node {
public :
    char me;
    quard_Tree_Node *LU;
    quard_Tree_Node *RU;
    quard_Tree_Node *LD;
    quard_Tree_Node *RD;

    quard_Tree_Node( char a ) {
        me = a;
        LU = RU = LD = RD = NULL;
    }
    void insertNode( char aBlock ) {
        me = aBlock;
        if( aBlock == 'x' ) {
            char newBlock;
            cin >> newBlock; LU = new quard_Tree_Node( newBlock ); LU->insertNode( newBlock );
            cin >> newBlock; RU = new quard_Tree_Node( newBlock ); RU->insertNode( newBlock );
            cin >> newBlock; LD = new quard_Tree_Node( newBlock ); LD->insertNode( newBlock );
            cin >> newBlock; RD = new quard_Tree_Node( newBlock ); RD->insertNode( newBlock );
        }
    }
    void printMe(){
         cout << me;
         if( me == 'x' ) {
            LD->printMe();
            RD->printMe();
            LU->printMe();
            RU->printMe();
         }
    }
};
int main() {
    int TCase;  cin >> TCase;
    while( TCase-- ) {
        char start; cin >> start;
        quard_Tree_Node *head = new quard_Tree_Node( start );
        head->insertNode(start);
        head->printMe();
        cout << endl ;
    }

    return 0;
}