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
string Get_Input(string prompt);
string To_Lower(string word);

int main() {
    cout << "This is a program that converts and evevaluates postfix and infix equations in base 36!\n\n";
    bool continue_program;
    do
    {
        int menu_option = User_Inputted_Number(MENU_PROMPT, INVALID_MENU_INPROMPT, INVALID_MENU_INPROMPT, MENU_LOWER_BOUND_OPTION, MENU_UPPER_BOUND_OPTION);
        Menu(menu_option);
        string user_choice;
        
        cout << "\nDo you wish to continue the program enter yes else enter no: ";
        getline(cin, user_choice);
        
        user_choice = To_Lower(user_choice);
        
        while (user_choice != "yes" && user_choice != "no" )
        {
            cout << "Please enter yes to conitnue or enter no to quit: ";
            getline(cin, user_choice);
            user_choice = To_Lower(user_choice);
        }
        
        continue_program = (user_choice == "yes");
    } while (continue_program);
    return 0;
}

void Menu(int choice)
{
    switch (choice)
    {
        case 1:
        {
            string expression = Get_Input("Enter Infix Expression: ");
            cout << "Postfix: " <<  infix_To_Postfix(expression) << "\n";
            break;
        }
        
        case 2:
        {
            string postfix = Get_Input("Enter Postfix: ");
            cout << "Evaluated Postfix: "  << Evluate_Postfix(postfix) << "\n";
            break;
        }
            
        case 3:
        {
            string expression = Get_Input("Enter Infix Expression: ");
            string postfix = infix_To_Postfix(expression);
            cout << "Postfix: " <<  postfix << "\n";
            cout << "Evaluated Postfix: "  << Evluate_Postfix(postfix) << "\n";
            break;
        }
    }
}

string Get_Input(string prompt)
{
    string expression;
    bool invaild_input;
    
    do
    {
        cout<< prompt;
        getline(cin, expression);
        invaild_input = Validate_Input(expression);
        
        if (!invaild_input)
        {
            cout << "\nInvalid Input!\n\n";
        }
    } while (!invaild_input);
    
    return expression;
}

string To_Lower(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    
    return word;
}
