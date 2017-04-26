//
//  main.cpp
//  Postfix_Infix
//
//  Created by Tyree Stevenson on 4/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>
#include "constants.h"
#include "Stack.hpp"
#include "Utils.hpp"
using namespace std;

void Menu(int choice);

int main() {
    int menu_option = User_Inputted_Number(MENU_PROMPT, INVALID_MENU_INPROMPT, INVALID_MENU_INPROMPT, MENU_LOWER_BOUND_OPTION, MENU_UPPER_BOUND_OPTION);
    Menu(menu_option);
    return 0;
}

void Menu(int choice)
{
    switch (choice)
    {
        case 1:
        {
            string expression;
            cout<< "Enter Infix Expression: ";
            getline(cin,expression);
            cout << "Postfix: " <<  infix_To_Postfix(expression) << "\n";
            break;
        }
        
        case 2:
        {
            string postfix;
            cout << "Enter Postfix: ";
            getline(cin, postfix);
            cout << "Evaluated Postfix: "  << Evluate_Postfix(postfix) << "\n";
            break;
        }
            
        case 3:
        {
            string expression;
            cout<< "Enter Infix Expression: ";
            getline(cin,expression);
            string postfix = infix_To_Postfix(expression);
            cout << "Postfix: " <<  postfix << "\n";
            cout << "Evaluated Postfix: "  << Evluate_Postfix(postfix) << "\n";
            break;
        }
    }
}
