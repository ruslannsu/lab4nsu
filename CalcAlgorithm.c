#include "CalcHeader.h"

int Priority(char symbol) {
    if ((symbol == '+') || (symbol == '-')) {
        return 2;
    }
    if ((symbol == '/') || (symbol == '*')) {
        return 3;
    }
    if (symbol == '(') {
        return 1;
    }
    if (symbol == ')') {
        return -1;
    }
    char *op = &symbol;
    if (atoi(op) != 0) {
        return 0;
    }
    return 0;
}

int is_operator(char operator) {
    if ((operator == '+') || (operator == '-') || (operator == '/') || (operator == '*') || (operator == '(') ||
        (operator == ')')) {
        return 0;
    } else {
        return -5;
    }
}


int is_number(char operand) {
    int variable_check = operand;
    if ((variable_check < 48) || (variable_check > 57)) {
        return -5;
    } else {
        return 0;
    }
}

void StringDestroy(char TempString[]) {
    for (unsigned int i = 0; i < 32; i++) {
        TempString[i] = 0;
    }
}

void OperandInput(OperatorStack *op_st, Operand *operand_ptr) {
    operand_ptr->OperandString[operand_ptr->len][0] = op_pop(op_st);
    operand_ptr->OperandString[operand_ptr->len][1] = '\0';
    (operand_ptr->len)++;
}

void NotationStackCreating(char *Input, Operand *operand_ptr, OperatorStack *op_st) {
    char TempString[32] = "";
    operand_ptr->len = 0;
    op_st->n = 0;
    int str_counter = 0;
    for (unsigned int i = 0; i < strlen(Input); i++) {
        if ((is_number(Input[i]) == 0)) {
            TempString[str_counter] = Input[i];
            str_counter++;
        } else {
            if (strlen(TempString) != 0) {
                str_counter = 0;
                strcpy(operand_ptr->OperandString[operand_ptr->len], TempString);
                (operand_ptr->len)++;
                StringDestroy(TempString);
            }
            if (is_operator(Input[i]) == 0) {
                if (is_empty_op(op_st) == 0) {
                    op_push(Input[i], op_st);
                } else {
                    if (Input[i] == '(') {
                        op_push(Input[i], op_st);
                    }
                    if (Input[i] == ')') {
                        int elements_counter = 0;
                        while (op_stack_top(op_st) != '(') {
                            elements_counter++;
                            OperandInput(op_st, operand_ptr);
                        }
                        if (op_stack_top(op_st) == '(') {
                            op_pop(op_st);
                        }
                    }
                    if (((Input[i] == '+') || (Input[i]) == '-') || (Input[i] == '*') || (Input[i]) == '/') {
                        if (Priority(op_stack_top(op_st)) >= Priority(Input[i])) {
                            while ((Priority(op_stack_top(op_st)) >= Priority(Input[i]))) {
                                OperandInput(op_st, operand_ptr);
                                if (is_empty_op(op_st) == 0) {
                                    break;
                                }
                            }
                            op_push(Input[i], op_st);
                        } else {
                            op_push(Input[i], op_st);
                        }
                    }
                }
            }
        }
    }
    if (is_empty_op(op_st) != 0) {
        while (is_empty_op(op_st) != 0) {
            OperandInput(op_st, operand_ptr);
        }
    }
    (operand_ptr->len)++;
}


int Calculation(Operand *operand_ptr, Stack *st_ptr) {
    for (int i = 0; i < (operand_ptr->len - 1); i++) {
        push(operand_ptr->OperandString[i], st_ptr);
        if (is_operator(operand_ptr->OperandString[i][0]) == 0) {
            pop(st_ptr);
            int a = atoi(pop(st_ptr));
            int b = atoi(pop(st_ptr));
            if (operand_ptr->OperandString[i][0] == '*') {
                int c = b * a;
                char f[32];
                snprintf(f, sizeof f, "%d", c);
                push(f, st_ptr);
            }
            if (operand_ptr->OperandString[i][0] == '/') {
                if (a == 0) {
                    printf("division by zero");
                    return 1;
                }
                int c = b / a;
                char f[32];
                snprintf(f, sizeof f, "%d", c);
                push(f, st_ptr);

            }
            if (operand_ptr->OperandString[i][0] == '+') {
                int c = b + a;
                char f[32];
                snprintf(f, sizeof f, "%d", c);
                push(f, st_ptr);
            }
            if (operand_ptr->OperandString[i][0] == '-') {
                int c = b - a;
                char f[32];
                snprintf(f, sizeof f, "%d", c);
                push(f, st_ptr);
            }
        }

    }

    while (is_empty(st_ptr) == 0) {
        printf("%s", pop(st_ptr));
    }
    return 0;
}

