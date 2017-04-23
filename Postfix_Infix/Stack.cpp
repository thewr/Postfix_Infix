//
//  Stack.cpp
//  Postfix_Infix
//
//  Created by Tyree Stevenson on 4/14/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "Stack.hpp"

Stack:: Stack()
{
    size = 0;
    head = nullptr;
}

bool Stack:: Is_Empty()
{
    return size == 0 && head == nullptr;
}

bool Stack:: Is_Full()
{
    return false;
}

char Stack:: Top()
{
    return head->item;
}

void Stack:: Push(char symbol)
{
    Node *new_node = new Node;
    new_node->item = symbol;
    new_node->next = head;
    head = new_node;
    size++;
}

void Stack:: Pop()
{
    head = head->next;
    size--;
}
