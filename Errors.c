#include "CalcHeader.h"

int is_bracket(char symbol) {
    if (symbol == '(') {
        return 5;
    }
    if (symbol == ')') {
        return -5;
    }
    return 1;
}

int is_operator_without_bracket(char operator) {
    if ((operator == '+') || (operator == '-') || (operator == '/') || (operator == '*')) {
        return 0;
    } else {
        return 1;
    }
}

int IncorrectSymbolFinder(char *Input) {
    char alphabet[32] = "+-/*()";
    bool is_symbol;
    int left_brackets_counter = 0;
    int right_brackets_counter = 0;
    int operator_counter = 0;
    int operand_counter = 0;
    if ((Input[0]) == '\n') {
        return 1;
    }
    for (unsigned int i = 0; i < strlen(Input) - 1; i++) {
        if ((Input[i] == '(') && ((Input[i + 1]) == ')')) {
            return 1;
        }
        if ((is_operator_without_bracket(Input[i]) == 0) && (is_operator_without_bracket(Input[i + 1]) == 0)) {
            return 1;
        }
        is_symbol = false;
        if (Input[i] == '(') {
            left_brackets_counter++;
        }
        if (Input[i] == ')') {
            right_brackets_counter++;
            if (right_brackets_counter > left_brackets_counter) {
                return 1;
            }
        }
        for (unsigned int j = 0; j < strlen(alphabet); j++) {
            if ((Input[i] == alphabet[j]) || (is_number(Input[i]) != -5)) {
                is_symbol = true;
            }
        }
        if (is_symbol == false) {
            return 1;
        }
        if (is_operator_without_bracket(Input[i]) == 0) {
            operator_counter++;
        } else {
            operand_counter++;
        }
        if ((is_bracket(Input[i]) == 5) && ((is_operator_without_bracket(Input[i + 1]) == 0))) {
            return 1;
        }
    }
    if (operator_counter > operand_counter) {
        return 1;
    }
    if (left_brackets_counter != right_brackets_counter) {
        return 1;
    }
    if ((is_operator_without_bracket(Input[0]) == 0) || (is_operator_without_bracket(Input[strlen(Input) - 2]) == 0)) {
        return 1;
    }
    return 0;
}
