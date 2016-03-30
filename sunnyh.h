//
// Created by sunny on 2016/3/28.
//

#ifndef C_PROJ_SUNNYH_H
#define C_PROJ_SUNNYH_H
#define FORMAT "%s!C is cool !\n"

#include <stdio.h>
#include <mem.h>
/**
 * 字符与整型：
 * 注：大小写字母在ASCII中相差32
 * 小写字母 - 32 = 大写字母
 */
void testChar1() {
    char a, b;
    a = 110;
    b = 114;

    printf("\n%c,%c:", a, b);
    printf("\n%c,%c:", a - 32, b - 32);

}

/**
 * 2.const关键字，把一个变量转换成常量
 */
void testConst() {

    const int age = 10;
    //age = 12;
    printf("age=%d\n", age);

}

/**
 * 格式化输出
 * 以%-20.3s为例
 * -:表示左对齐
 * +:表示右对齐
 * 整数部分20:表示分配给字符串的空间大小，在前面补上空格
 * 小数部分3:表示只打印3个字符，如果大于字符串字符的个数，则全部打印出来
 * 如果没有小数，比如：%2s
 * 如果2小于字符个数时，字符串全部打印，
 * 如果大于字符个数，则在前面补上多出的空格数
 */
void formatPrint(const char *str) {
    printf("传入的字符串长度：%d\n",strlen(str));
    printf("/%2s/\n", str);
    printf("/%20s/\n", str);
    printf("/%20.5s/\n", str);
    printf("/%+20.3s/\n", str);

    int name[40];
    float cash;
    printf("Please input your name and the cash!\n");
    scanf("%s%f", &name, &cash);
    printf("The %s family just may be $%.2f dollars richer!\r\n", name, cash);
    printf("Your name is:\"%s\"", name);


}

/**
 * 测试sizeof 运算符 与size_t类型
 * sizeof 返回 size_t类型的值 ，它不是一个新类型。而是一个自定义的无符号整型的别名。
 * 这种别名是由typedef机制来创建的。
 * eg:
 * typedef double sunnyDouble;
 * 这样一来，sunnyDouble就可以代表double类型了。
 * sunnyDouble d = 1.3;
 * double d1 = 1.3
 *
 */
void testSizeof() {
    int n = 0;
    size_t intsize;
    intsize = sizeof(int);
    printf("n=%d,n has %zd bytes;all ints have %lu bytes.\n", n, sizeof n, intsize);

    typedef double sunnyDouble;
    typedef int sunnyInt;
    double d1 = 1.3;
    sunnyDouble d2 = 1.3;
    if (d1 == d2) {
        printf("d1 与 d2是同一个类型");
    }
}

/**
 * 打印金字塔
 */
void test3() {
    printf("Hi Sunny,请随便输入一个大写字母,让我来为你生成一个金字塔图案:\n");
    char input;
    scanf("%c", &input);
    const int ROWS = 5;
    int row;
    int blank;
    printf("################Start##############\n");
    for (row = 0; row < ROWS; row++) {
        char temp = input;
        for (blank = 0; blank < (ROWS - row); blank++) {
            //打印空格
            printf(" ");
        }
        //打印升序
        int up, down;
        for (up = 0; up <= row; up++) {
            printf("%c", temp + up);
        }
        //降序
        for (down = temp + row; down > temp; down--) {
            printf("%c", down - 1);
        }
        printf("\n");
    }
    printf("################End##############\n");

}

/**
 * 测试数组
 * 记住：字符串是存储在字符数组里面，是一串连续的字符。
 */
void testArray() {

    printf("请随便键入一个单词:\n");
    char word[100];
    int end;
    scanf("%s", &word);
    printf("################下面开始打印,数组长度:%d##############\n", strlen(word));
    for (end = strlen(word) - 1; end >= 0; end--) {
        printf("%c", word[end]);
    }
    printf("\n");
}

/**
 * 测试输入函数：
 * 循环读取用户输入的2个浮点数，当输入不正确时，终止
 *
 * 备注：当输入的东西吻合要求的格式时，则返回>0的正整数
 * eg:scanf("%f",&a)如果输入的数为浮点数，则返回1
 * 当要求输入2个数，且分别吻合时，则返回2，
 * 以此类推。
 * 相反，如果用户输入的东西与要求不匹配，则返回0
 */
void testScanfMethod(){
    float a,b;
    printf("请输入任意两个浮点数:\n");
    while (scanf("%f%f",&a,&b) == 2){
        printf("(%.2f-%.2f)/(%.2f*%.2f) = %.2f\n",a,b,a,b,(a-b)/(a*b));
        printf("请输入任意两个浮点数:\n");
    }
    printf("end\n");
}

#endif //C_PROJ_SUNNYH_H
