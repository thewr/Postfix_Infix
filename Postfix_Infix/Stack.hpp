//
//  Stack.hpp
//  Postfix_Infix
//
//  Created by Tyree Stevenson on 4/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include "constants.h"
class Stack
{

public:
    
    Stack();
    void Push(char symbol);
    void Pop();
    char Top();
    bool Is_Empty();
    bool Is_Full();

private:
    
    struct Node
    {
        char item;
        Node *next = nullptr;
    };
    
    Node *head;
    int size;
};
#endif /* Stack_hpp */
