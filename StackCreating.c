#include "CalcHeader.h"

void op_push(Data data, OperatorStack *op_st) {
    op_st->data[op_st->n] = data;
    (op_st->n)++;
}

Data op_pop(OperatorStack *op_st) {
    Data op_res;
    op_res = op_st->data[op_st->n - 1];
    (op_st->n)--;
    return op_res;
}

int is_empty_op(OperatorStack *op_st) {
    if ((op_st->n) == 0) {
        return 0;
    } else {
        return -5;
    }
}

Data op_stack_top(OperatorStack *op_st) {
    return op_st->data[op_st->n - 1];
}

int OperatorStackCreating(OperatorStack *op_st_ptr) {
    op_st_ptr->data = malloc(sizeof(op_st_ptr->data) * STACK_FIRST_SIZE);
    if (op_st_ptr->data == NULL) {
        return 1;
    }
    return 0;
}


void push(Data *data, Stack *st) {
    strcpy(st->data[st->n], data);
    (st->n)++;

}

Data *pop(Stack *st) {
    Data *res;
    res = st->data[st->n - 1];
    (st->n)--;
    return res;
}

void StackInit(Stack *st) {
    st->n = 0;
}

int StackCreating(Stack *st_ptr) {
    st_ptr->data = malloc(sizeof(st_ptr->data) * STACK_FIRST_SIZE);
    if (st_ptr->data == NULL) {
        return 1;
    }
    for (int i = 0; i < STACK_FIRST_SIZE; i++) {
        st_ptr->data[i] = malloc(sizeof((st_ptr->data)) * STACK_SECOND_SIZE);
        if (st_ptr->data[i] == NULL) {
            return 1;
        }
    }
    return 0;
}

int OperandStructureCreating(Operand *operand_ptr) {
    operand_ptr->OperandString = malloc(sizeof(operand_ptr->OperandString) * STACK_FIRST_SIZE);
    if (operand_ptr->OperandString == NULL) {
        return 1;
    }
    for (int i = 0; i < STACK_FIRST_SIZE; i++) {
        operand_ptr->OperandString[i] = malloc(sizeof((operand_ptr->OperandString)) * STACK_SECOND_SIZE);
        if (operand_ptr->OperandString[i] == NULL) {
            return 1;
        }
    }
    return 0;
}

void StructureDestroy(OperatorStack *op_st_ptr, Operand *operand_ptr, Stack *st_ptr) {
    for (int i = 0; i < STACK_FIRST_SIZE; i++) {
        free(operand_ptr->OperandString[i]);
    }
    free(operand_ptr->OperandString);
    free(op_st_ptr->data);
    for (int i = 0; i < STACK_FIRST_SIZE; i++) {
        free(st_ptr->data[i]);
    }
    free(st_ptr->data);
}

int is_empty(Stack *st) {
    return st->n == 0;
}




