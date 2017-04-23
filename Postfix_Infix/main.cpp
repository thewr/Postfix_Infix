//
//  main.cpp
//  Postfix_Infix
//
//  Created by Tyree Stevenson on 4/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>
#include "Stack.hpp"
#include "Utils.hpp"
using namespace std;

int main() {
    string expression;
    cout<< "Enter Infix Expression: ";
    getline(cin,expression);
    string postfix = infixToPostfix(expression);
    cout << "Output = " << postfix<< "\n";
    return 0;
}
