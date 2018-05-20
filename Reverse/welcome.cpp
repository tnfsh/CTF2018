//
//  main.cpp
//  welcome
//
//  Created by Student on 2018/5/20.
//  Copyright © 2018年 Student. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
  char wel[100];
  cin.get(wel,sizeof(wel));
  for(int i = strlen(wel)-1 ; i >= 0 ; i--){
    cout << char(wel[i]);
   }
   cout<<endl;

  return 0;
}
