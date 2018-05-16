//
//  main.cpp
//  impossible class ranking
//
//  Created by Shaoyu on 2018/5/16.
//  Copyright © 2018年 Shaoyu. All rights reserved.
//
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{
    char cry[100];
    cin.get(cry,sizeof(cry));
    for(int i = 0 ; i <=(strlen(cry)/3) ; i++){
        if((cry[i]=='C')&&(cry[i+1]=='G')&&(cry[i+2]=='A')){
            cout <<"A";   
        }
        if((cry[i]=='C')&&(cry[i+1]=='C')&&(cry[i+2]=='A')){
            cout <<"B";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='T')&&(cry[i+2]=='T')){
            cout <<"C";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='T')&&(cry[i+2]=='G')){
            cout <<"D";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='G')&&(cry[i+2]=='C')){
            cout <<"E";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='G')&&(cry[i+2]=='T')){
            cout <<"F";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='T')&&(cry[i+2]=='T')){
            cout <<"G";   
        }
        if((cry[i]=='C')&&(cry[i+1]=='G')&&(cry[i+2]=='C')){
            cout <<"H";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='T')&&(cry[i+2]=='G')){
            cout <<"I";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='G')&&(cry[i+2]=='T')){
            cout <<"J";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='A')&&(cry[i+2]=='C')){
            cout <<"K";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='G')&&(cry[i+2]=='C')){
            cout <<"L";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='C')&&(cry[i+2]=='C')){
            cout <<"M";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='C')&&(cry[i+2]=='T')){
            cout <<"N";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='G')&&(cry[i+2]=='A')){
            cout <<"O";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='T')&&(cry[i+2]=='G')){
            cout <<"P";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='A')&&(cry[i+2]=='C')){
            cout <<"Q";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='C')&&(cry[i+2]=='A')){
            cout <<"R";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='C')&&(cry[i+2]=='G')){
            cout <<"S";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='T')&&(cry[i+2]=='C')){
            cout <<"T";   
        }
        if((cry[i]=='C')&&(cry[i+1]=='T')&&(cry[i+2]=='G')){
            cout <<"U";   
        }
        if((cry[i]=='C')&&(cry[i+1]=='C')&&(cry[i+2]=='T')){
            cout <<"V";   
        }
        if((cry[i]=='C')&&(cry[i+1]=='C')&&(cry[i+2]=='G')){
            cout <<"W";   
        }
        if((cry[i]=='C')&&(cry[i+1]=='T')&&(cry[i+2]=='A')){
            cout <<"X";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='A')&&(cry[i+2]=='A')){
            cout <<"Y";   
        }
        if((cry[i]=='C')&&(cry[i+1]=='T')&&(cry[i+2]=='T')){
            cout <<"Z";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='T')&&(cry[i+2]=='A')){
            cout <<" ";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='C')&&(cry[i+2]=='G')){
            cout <<",";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='A')&&(cry[i+2]=='T')){
            cout <<".";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='C')&&(cry[i+2]=='T')){
            cout <<":";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='C')&&(cry[i+2]=='T')){
            cout <<"0";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='C')&&(cry[i+2]=='C')){
            cout <<"1";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='A')&&(cry[i+2]=='G')){
            cout <<"2";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='C')&&(cry[i+2]=='A')){
            cout <<"3";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='A')&&(cry[i+2]=='G')){
            cout <<"4";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='G')&&(cry[i+2]=='A')){
            cout <<"5";   
        }
        if((cry[i]=='T')&&(cry[i+1]=='T')&&(cry[i+2]=='A')){
            cout <<"6";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='C')&&(cry[i+2]=='A')){
            cout <<"7";   
        }
        if((cry[i]=='A')&&(cry[i+1]=='G')&&(cry[i+2]=='G')){
            cout <<"8";   
        }
        if((cry[i]=='G')&&(cry[i+1]=='C')&&(cry[i+2]=='G')){
            cout <<"9";   
        }
        
    }
}
