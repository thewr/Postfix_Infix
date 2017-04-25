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

//=========================================================================================
// Function to perform all conversion operation
//=========================================================================================

string infix_To_Postfix(string expr)
{
    Stack<char> stack;
    string postfix = "";
    for(int i = 0;i < expr.length(); i++)
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
        else if(Is_Operand(expr[i]))
        {
            postfix += expr[i];
        }
        else if(Is_Operator(expr[i]))
        {
            while(!stack.Is_Empty()&& !Find_Highest_Precendence(expr[i],stack.Top()))
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

//=========================================================================================
// Check for operator precendence.
//=========================================================================================

bool Find_Highest_Precendence(char a, char b)
{
    int weighta = Add_Weight(a);
    int weightb = Add_Weight(b);
    if(weighta >= weightb)
        return 1;
    return 0;
}

//=========================================================================================
// Check weather the character is operator'
//=========================================================================================

bool Is_Operator(char arg)
{
    if(arg == '*' || arg == '/' || arg == '+' || arg == '-')
        return 1;
    else
        return 0;
}

//=========================================================================================
// Check weather the character is operand.
//=========================================================================================

bool Is_Operand(char arg)
{
    if(arg >= '0' && arg <= '9')
        return 1;
    if(arg >= 'a' && arg <= 'z')
        return 1;
    if(arg >= 'A' && arg <= 'Z')
        return 1;
    return 0;
}

//=========================================================================================
// Add weight to the operator.
//=========================================================================================

int Add_Weight(char arg)
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

//=========================================================================================
// Evauluate Postfix.
//=========================================================================================
string Evluate_Postfix(string expression)
{
    Stack<int> stack;
    
    for (int i = 0; i < expression.length(); i++)
    {
        if (Is_Operand(expression[i]))
        {
            int temp = expression[i] - '0';
        }
    }
}

