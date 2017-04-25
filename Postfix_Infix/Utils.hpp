//
//  Utils.hpp
//  Postfix_Infix
//
//  Created by Tyree Stevenson on 4/23/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
string infix_To_Postfix(string expr);
bool Find_Highest_Precendence(char a, char b);
bool Is_Operator(char arg);
bool Is_Operand(char arg);
int Add_Weight(char arg);
#endif /* Utils_hpp */

