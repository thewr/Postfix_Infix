//
//  Utils.cpp
//  Postfix_Infix
//
//  Created by Tyree Stevenson on 4/23/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "Utils.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>

using namespace std;

string infixToPostfix(string expr)//Function to perform all conversion operation
{
    
    Stack stack;//Declaring a stack for conversion purpose
    string postfix = "";//Initialize the output string as empty;
    for(int i = 0;i < expr.length(); i++)//Scan the infix string one by one
        if(expr[i] == '(')
        {
            stack.Push(expr[i]);
        }
        else if(expr[i] == ')')
        {
            while(stack.Top() != '(')
            {
                postfix = postfix + stack.Top();
                stack.Pop();
            }
            stack.Pop();
        }
        else if(isoperand(expr[i]))
        {
            postfix += expr[i];
        }
        else if(isoperator(expr[i]))
        {
            while(!stack.Is_Empty()&& !highprecendence(expr[i],stack.Top()))
            {
                postfix+= stack.Top();
                stack.Pop();
            }
            stack.Push(expr[i]);
        }
    while(!stack.Is_Empty())
    {
        postfix+= stack.Top();
        stack.Pop();
    }
    return postfix;
}

bool highprecendence(char a, char b)//Check for operator precendence
{
    int weighta = operatorweight(a);
    int weightb = operatorweight(b);
    if(weighta >= weightb) return 1;
    return 0;
}

bool isoperator(char arg)//Check weather the character is operator
{
    if(arg == '*' || arg == '/' || arg == '+' || arg == '-') return(1);
    else return(0);
}

bool isoperand(char arg)//Check weather the character is operand
{
    if(arg >= '0' && arg <= '9') return 1;
    if(arg >= 'a' && arg <= 'z') return 1;
    if(arg >= 'A' && arg <= 'Z') return 1;
    return 0;
}

int operatorweight(char arg)//Add weight to the operator
{
    int weight = 0;
    switch(arg)
    {
        case '*':
        case '/':
            weight = 2;
            break;
        case '+':
        case '-':
            weight = 1;
            break;
    }
    return(weight);
}
