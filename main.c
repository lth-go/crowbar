#include <stdio.h>
#include "CRB.h"
#include "MEM.h"

int
main(int argc, char **argv)
{
    CRB_Interpreter     *interpreter;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "usage:%s filename", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "%s not found.\n", argv[1]);
        exit(1);
    }
    /*创建解释器*/
    interpreter = CRB_create_interpreter();
    /*语法解析*/
    CRB_compile(interpreter, fp);
    /*解释器执行*/
    CRB_interpret(interpreter);
    /*清理*/
    CRB_dispose_interpreter(interpreter);

    MEM_dump_blocks(stdout);

    return 0;
}
