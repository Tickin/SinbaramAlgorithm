#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
string reverse(string target);

int main (void) {
   int T = 0;
   string origin;
   cin >> T;
   while(T--){
      cin >> origin;
      cout << reverse(origin) <<endl;
   }
   return 0;
}

string reverse(string target) {
   if(target.at(0) != 'x')
      return target.substr (0,1);
      
   string pieceA, pieceB, pieceC, pieceD;
   
   // left up
   int beginindex = 1;
   cout << target.substr(beginindex) <<endl;
   pieceA = reverse(target.substr(beginindex));
   // right up
   beginindex += pieceA.length();
   pieceB = reverse(target.substr(beginindex,MAX));
   // left down
   beginindex += pieceB.length();
   pieceC = reverse(target.substr(beginindex,MAX));
   // right down
   beginindex += pieceC.length();
   pieceD = reverse(target.substr(beginindex,MAX));
   
   string result;
   result = "x" +pieceA+pieceB+pieceC+pieceD;
   return result;
}
