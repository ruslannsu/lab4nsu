#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char Data;
#define LEN 1003
#define STACK_FIRST_SIZE 1005
#define STACK_SECOND_SIZE 50
typedef struct {
    Data **data;
    int n;
} Stack;
typedef struct {
    Data **OperandString;
    int len;
} Operand;
typedef struct {
    Data *data;
    int n;
} OperatorStack;

void push(Data *data, Stack *st);

int is_number(char operand);


int OperatorStackCreating(OperatorStack *op_st_ptr);

int StackCreating(Stack *st_ptr);

int OperandStructureCreating(Operand *operand_ptr);
void StructureDestroy(OperatorStack *op_st_ptr, Operand *operand_ptr, Stack *st_ptr);

Data *pop(Stack *st);

void StackInit(Stack *st);

void op_push(Data data, OperatorStack *op_st);

Data op_pop(OperatorStack *op_st);

Data op_stack_top(OperatorStack *op_st);

int is_empty_op(OperatorStack *op_st);

int is_empty(Stack *st);

int IncorrectSymbolFinder(char *Input);

int Priority(char operator);

void StringDestroy(char TempString[]);

void NotationStackCreating(char *Input, Operand *operand_ptr, OperatorStack *op_st);

int is_operator(char data);

int Calculation(Operand *operand_ptr, Stack *st_ptr);

void OperandInput(OperatorStack *op_st, Operand *operand_ptr);

