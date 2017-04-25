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
template <class XType> class Stack
{

public:
    
    Stack();
    void Push(XType symbol);
    void Pop();
    XType Top();
    bool Is_Empty();
    bool Is_Full();

private:
    
    struct Node
    {
        XType item;
        Node *next = nullptr;
    };
    
    Node *head;
    int size;
};

//=========================================================================================
// Intialize Stack Object.
//=========================================================================================

template <class XType> Stack<XType>:: Stack()
{
    size = 0;
    head = nullptr;
}

//=========================================================================================
// Returns boolean value on whether stack is empty or not.
//=========================================================================================

template <class XType> bool Stack<XType>:: Is_Empty()
{
    return size == 0 && head == nullptr;
}

//=========================================================================================
// Returns boolean value on whether stack is full or not.
//=========================================================================================

template <class XType> bool Stack<XType>:: Is_Full()
{
    return false;
}

//=========================================================================================
// Returns top of the stack.
//=========================================================================================

template <class XType> XType Stack<XType>:: Top()
{
    return head->item;
}

//=========================================================================================
// Adds new item to the stack.
//=========================================================================================

template <class XType> void Stack<XType>:: Push(XType symbol)
{
    Node *new_node = new Node;
    new_node->item = symbol;
    new_node->next = head;
    head = new_node;
    size++;
}

//=========================================================================================
// Removes item from the stack.
//=========================================================================================

template <class XType> void Stack<XType>:: Pop()
{
    head = head->next;
    size--;
}
#endif /* Stack_hpp */
