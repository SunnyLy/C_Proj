//
// Created by sunny on 2016/3/28.
//
#include <stdio.h>
#include <stdlib.h>

#include "sunnyh.h"

#define STR_CONST "Good Night!"


int main() {
    printf("Hello World\r\n");
    // testChar1();
    //testConst();
    //formatPrint(STR_CONST);
    //testSizeof();
    //test3();
    //testArray();
    //testScanfMethod();

    /*DepositType depositType;
    depositType = HALF_YEAR;
    test4(1,depositType);*/
    //test5();
    //testPoint();
    //testStr();
    testStruct();

    //return 0;//这个return 0;其实就是退出程序，与exit(0)是一样的。
    exit(EXIT_SUCCESS);//而这个0就是宏EXIT_SUCCESS:表示成功终止
                       //EXIT_FAILURE:非成功终止
}

