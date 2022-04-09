#include "polynomial.hpp"
int main(){
    Polynomial P1,P2,PP,PS;
    P1=ReadPoly();
    P2=ReadPoly();
    
    PS=Add(P1,P2);
    PrintPoly(PS);
    
    PP=Mult(P1,P2);
    PrintPoly(PP);

    

        //PP=Mult(P1,P2);
    // PrintPoly(PP);
    //PS=Add(P1,P2);
    // PrintPoly(PS);
}
