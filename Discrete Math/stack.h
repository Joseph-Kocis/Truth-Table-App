//
//  stack.h
//  Discrete Math
//
//  Created by Jody Kocis on 3/3/19.
//  Copyright © 2019 Joseph Kocis. All rights reserved.
//

#ifndef stack_h
#define stack_h


#endif /* stack_h */


#define ERROR_CHAR '?'

typedef struct node
{
    char element;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

stack *create_stack()
{
    stack *new_stack;
    
    new_stack = malloc(sizeof(stack));
    new_stack->top = NULL;
    
    return new_stack;
}

node *create_node(char element)
{
    node *new_node = malloc(sizeof(node));
    new_node->next = NULL;
    new_node->element = element;
    
    return new_node;
}

void push(stack *st, char element)
{
    node *new_node;
    
    if (st == NULL)
        return;
    
    new_node = create_node(element);
    
    new_node->next = st->top;
    new_node->element = element;
    
    st->top = new_node;
}

// Returns ERROR_CHAR if the stack is empty
char pop(stack *st)
{
    char element;
    node *new_top;
    
    if (st == NULL)
        return ERROR_CHAR;
    
    if (st->top == NULL)
        return ERROR_CHAR;
    
    new_top = st->top->next;
    element = st->top->element;
    free(st->top);
    st->top = new_top;
    
    return element;
}

// Returns 1 if the stack is empty, returns 0 otherwise.
int is_empty(stack *st)
{
    if (st == NULL || st->top == NULL)
        return 1;
    
    return 0;
}

char top(stack *st)
{
    if (st == NULL || st->top == NULL)
        return ERROR_CHAR;
    
    return st->top->element;
}

void free_stack(stack *st)
{
    node *cur_node, *last_node;
    
    if (st == NULL)
        return;
    
    cur_node = st->top;
    
    while (cur_node != NULL)
    {
        last_node = cur_node;
        cur_node = cur_node->next;
        free(last_node);
    }
    
    free(st);
}

void print_stack(stack* st)
{
    node *top;
    
    if (st == NULL)
        return;
    
    top = st->top;
    
    printf("-----\n");
    
    while (top != NULL)
    {
        printf("%3c\n", top->element);
        printf("-----\n");
        
        top = top->next;
    }
}


