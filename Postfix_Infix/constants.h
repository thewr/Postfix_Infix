//
//  constants.h
//  Postfix_Infix
//
//  Created by Tyree Stevenson on 4/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef constants_h
#define constants_h
#include <string>
#include <iostream>

const std::string MENU_PROMPT = "1. Read in an infix expression and convert it into postfix form\n2. Read in a postfix expression and evaluate the postfix expression\n3. Read in an infix expression, convert it to postfix form, and then evaluate it.\nEnter a number for the action you wish to complete: ";
const std::string INVALID_MENU_INPROMPT = "Please enter a number between 1 and 3 \n";
const int MENU_LOWER_BOUND_OPTION = 1;
const int MENU_UPPER_BOUND_OPTION = 3;
const int BASE = 36;
#endif /* constants_h */
