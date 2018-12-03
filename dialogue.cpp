#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include "dialogue.h"

NumStack::NumStack() : head(nullptr)
{
}

NumStack::~NumStack() 
{
    clear();
}

NumStack::NumStack(const NumStack& other) : NumStack()
{
    *this = other;
}

NumStack& NumStack::operator=(const NumStack& other)
{
    if(this != &other)
    {
        clear();
        NumStack temp;
        temp.copyReverse(other);
        copyReverse(temp);
    }
    
    return *this;
}
 
void NumStack::push(double c)
{  
    head = new Node(c, head);
}

double NumStack::pop()
{
    if(empty())
    {
        throw std::logic_error("No More NumStack");
    }
  
    double c = peak();
    Node *temp;
    temp = head;
    head = head->next;
    delete temp;
    return c;
}

double NumStack::peak()
{
    if(empty())
    {
        throw std::logic_error("No More NumStack");
    }
  
    return head->c;
}

bool NumStack::empty() const
{
    return head == nullptr;
}

void NumStack::clear()
{
    while(!empty())
    {
        pop();
    }
}

void NumStack::copyReverse(const NumStack& other)
{
    for(Node *p = other.head; p != nullptr; p = p->next)
    {
        push(p->c);
    }
}