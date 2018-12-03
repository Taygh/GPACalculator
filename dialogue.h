#pragma once

//Purpose: Create stack for NumStack (an abstract data type for GPA calculator)
//
//    Attributes:
//        struct Node: creates linked list for NumStack, including
//        a node constructor 
//        Node *head: track head of linked list
//
//    Member Functions:
//        NumStack(): Preconditions: none,
//        Postconditions: none (constructs stack)
//        ~NumStack(): Preconditions: stack exists, Postconditions:
//        none (destroys stack)
//        NumStack(): Preconditions: a stack
//        exists to be passed in, Postconditions: none (constructs
//        second stack with attributes of passed in stack, copy
//        constructor)
//        NumStack& operator=(): Preconditions:
//        two stacks exist to be compared, Postconditions: none
//        (sets the two stacks to have equal attributes,
//        overloaded assignment operator)
//        void push(): Preconditions: NumStack to push onto
//        top of stack, Postconditions: none (adds NumStack to top
//        of stack)
//        double pop(): Preconditions: none,
//        Posconditions: pops/removes NumStack at
//        top of the stack, returns that NumStack
//        double peak(): Preconditions: none.
//        Postconditions: returns top of stack
//        bool empty() const: Preconditions: none, Postconditions:
//        none (checks if stack is empty)
//        void copyReverse(): Preconditions: another NumStack object,
//        Postconditions: copy NumStack in reverse order from passed in object
//        void clear(): Preconditions: none, Postconditions: none 
//        (pops off all NumStack to clear stack)

class NumStack
{

    public:
        NumStack();
        ~NumStack();
        NumStack(const NumStack& other);
        NumStack& operator=(const NumStack& other);

        void push(double c);
        double pop();
        double peak();
        bool empty() const;
        void copyReverse(const NumStack& other);
        
  
    private:

        struct Node
        {
            double c;
            Node *next;
            Node(double c, Node *next = nullptr) : c(c), next(next) {}
        };
        Node *head;

        void clear();
};
