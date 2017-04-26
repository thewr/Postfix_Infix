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
            while(!stack.Is_Empty() && Find_Highest_Precendence(stack.Top(), expr[i]))
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
        return true;
    return false;
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
            int temp = Convert_From_Base_36_To_Base_10(expression[i]);
            stack.Push(temp);
        }
        
        else if (Is_Operator(expression[i]))
        {
            int operand2 = stack.Top();
            stack.Pop();
            int operand1 = stack.Top();
            stack.Pop();
            int result_of_operation = Solve_Expression(expression[i], operand1, operand2);
            stack.Push(result_of_operation);
        }
    }
    
    string result = "";
    result +=  Convert_From_Base_10_To_Base_36(stack.Top());
    return result;
}

//=========================================================================================
// Solves an expression.
// Uses the char operator as the operation.
// Uses oprand1 and oprand2 as the operands
// example:
//          result = operand1 (char operator) operand2
//          return result;
//=========================================================================================

int Solve_Expression(char operation, int operand1, int operand2)
{
    int result = 0;
    switch (operation)
    {
        case '+':
            result = operand1 + operand2;
            break;
        
        case '-':
            result = operand1 - operand2;
            break;
            
        case '*':
            result = operand1 * operand2;
            break;
            
        case '/':
            result = operand1/operand2;
            break;
    }
    
    return result;
}

//=========================================================================================
// Converts base 36 number to base 10.
//=========================================================================================

int Convert_From_Base_36_To_Base_10(char number)
{
    int result = 0;
    
    if ('0' <= number && number <= '9')
    {
        result = number - '0';
    }
    
    else
    {
        result = number - 65;
        result += 10;
    }
    
    return result;
}

//=========================================================================================
// Converts base 10 number to base 32.
//=========================================================================================

string Convert_From_Base_10_To_Base_36(int number)
{
    string result = "";
    bool is_negative = number < 0;
    number = is_negative? number *= -1 : number;
    
    while (number != 0)
    {
        int remainder = number % BASE;
        
        if (remainder >= 10)
        {
            char temp = (remainder - 10) + 'A';
            result = temp + result;
        }
        
        else
            result = to_string(remainder) + result;
        number /= BASE;
    }
    result = is_negative? "-" + result : result;
    return result;
}

//=========================================================================================
// Make user user enters a valid number
//=========================================================================================

int User_Inputted_Number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds)
{
    int number = -1;
    string user_entered_number;
    
    while (number == -1 || (number < lower_bounds || number > upper_bounds))
    {
        cout << prompt;
        getline(cin, user_entered_number);
        number = String_To_Int(user_entered_number.c_str());
        cout << "\n";
        if (number == -1)
        {
            cout << invalid_prompt << "\n\n";
        }
        
        else if (number < lower_bounds || number > upper_bounds)
        {
            cout << out_of_bounds_prompt << "\n";
        }
    }
    
    return number;
}

//=========================================================================================
// Validates user input.
//=========================================================================================

bool Validate_Input(string postfix)
{
    int operators = 0;
    int operands = 0;
    bool input_is_valid = true;
    
    for(int i = 0; i < postfix.length() && input_is_valid; i++)
    {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            operators++;
        }
        
        else if (('A' <= postfix[i] && postfix[i] <= 'Z') || ('0' <= postfix[i] && postfix[i] <= '9') || (postfix[i] == ')' || postfix[i] == '('))
        {
            operands++;
        }
        
        else
        {
            input_is_valid = false;
        }
        
    }
    
    if (input_is_valid)
    {
        input_is_valid = (operators <= operands);
    }
    
    return input_is_valid;
}

//==========================================================================================
// Takes constant char pointer and converts it into a string.
// If one of the characters are not a digit the function returns -1.
//==========================================================================================

int String_To_Int(const char *str)
{
    int result = 0;
    int prefix = 0;
    
    if (str[0] == '\0')
    {
        return -1;
    }
    
    else if (str[0] == '-' || str[0] == '+')
    {
        prefix = 1;
    }
    
    for (int i = prefix; str[i] != '\0'; ++i)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            result = result*10 + str[i] - '0';
        }
        
        else
        {
            return -1;
        }
    }
    
    if (str[0] == '-')
    {
        result *= -1;
    }
    
    return result;
}
