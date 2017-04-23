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
string infixToPostfix(string expr);
bool highprecendence(char a, char b);
bool isoperator(char arg);
bool isoperand(char arg);
int operatorweight(char arg);
#endif /* Utils_hpp */

