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
string Evluate_Postfix(string expression);
int Solve_Expression(char operation, int operand1, int operand2);
int Convert_From_Base_36_To_Base_10(char number);
string Convert_From_Base_10_To_Base_36(int number);
int User_Inputted_Number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds);
bool Validate_Input(string postfix);
int String_To_Int(const char *str);
#endif /* Utils_hpp */

