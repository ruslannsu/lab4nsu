#include "CalcHeader.h"

int main() {
    char InputString[LEN];
    if (fgets(InputString, LEN, stdin) == 0) {
        return 0;
    }
    if (IncorrectSymbolFinder(InputString) == 1) {
        printf("syntax error");
        return 0;
    }
    Stack st;
    Stack *st_ptr = &st;
    if (StackCreating(st_ptr) == 1) {
        return 0;
    }
    OperatorStack op_st;
    OperatorStack *op_st_ptr = &op_st;
    if (OperatorStackCreating(op_st_ptr)) {
        return 0;
    }
    Operand operand;
    Operand *operand_ptr = &operand;
    if (OperandStructureCreating(operand_ptr) == 1) {
        return 0;
    }
    NotationStackCreating(InputString, operand_ptr, op_st_ptr);
    StackInit(st_ptr);
    Calculation(operand_ptr, st_ptr);
    StructureDestroy(op_st_ptr, operand_ptr, st_ptr);
    return 0;

}

