//
// Created by sunny on 2016/3/28.
//

#ifndef C_PROJ_SUNNYH_H
#define C_PROJ_SUNNYH_H
#define FORMAT "%s!C is cool !\n"
#define SPACE ' '

#include <stdio.h>
#include <mem.h>
#include <ctype.h>

/**
 * ö�����͵��÷�
 */
typedef enum DepositType{
    CURRENT, //����
    TRIMESTER, //�����¶���
    HALF_YEAR, //����
    ONE_YEAR,
    TWO_YEAR,
    THREE_YEAR,
    FIVE_YEAR
}DepositType;

/**
 * �ַ������ͣ�
 * ע����Сд��ĸ��ASCII�����32
 * Сд��ĸ - 32 = ��д��ĸ
 */
void testChar1() {
    char a, b;
    a = 110;
    b = 114;

    printf("\n%c,%c:", a, b);
    printf("\n%c,%c:", a - 32, b - 32);

}

/**
 * 2.const�ؼ��֣���һ������ת���ɳ���
 */
void testConst() {

    const int age = 10;
    //age = 12;
    printf("age=%d\n", age);

}

/**
 * ��ʽ�����
 * ��%-20.3sΪ��
 * -:��ʾ�����
 * +:��ʾ�Ҷ���
 * ��������20:��ʾ������ַ����Ŀռ��С����ǰ�油�Ͽո�
 * С������3:��ʾֻ��ӡ3���ַ�����������ַ����ַ��ĸ�������ȫ����ӡ����
 * ���û��С�������磺%2s
 * ���2С���ַ�����ʱ���ַ���ȫ����ӡ��
 * ��������ַ�����������ǰ�油�϶���Ŀո���
 */
void formatPrint(const char *str) {
    printf("������ַ������ȣ�%d\n", strlen(str));
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
 * ����sizeof ����� ��size_t����
 * sizeof ���� size_t���͵�ֵ ��������һ�������͡�����һ���Զ�����޷������͵ı�����
 * ���ֱ�������typedef�����������ġ�
 * eg:
 * typedef double sunnyDouble;
 * ����һ����sunnyDouble�Ϳ��Դ���double�����ˡ�
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
        printf("d1 �� d2��ͬһ������");
    }
}

/**
 * ��ӡ������
 */
void test3() {
    printf("Hi Sunny,���������һ����д��ĸ,������Ϊ������һ��������ͼ��:\n");
    char input;
    scanf("%c", &input);
    const int ROWS = 5;
    int row;
    int blank;
    printf("################Start##############\n");
    for (row = 0; row < ROWS; row++) {
        char temp = input;
        for (blank = 0; blank < (ROWS - row); blank++) {
            //��ӡ�ո�
            printf(" ");
        }
        //��ӡ����
        int up, down;
        for (up = 0; up <= row; up++) {
            printf("%c", temp + up);
        }
        //����
        for (down = temp + row; down > temp; down--) {
            printf("%c", down - 1);
        }
        printf("\n");
    }
    printf("################End##############\n");

}

/**
 * ��������
 * ��ס���ַ����Ǵ洢���ַ��������棬��һ���������ַ���
 */
void testArray() {

    printf("��������һ������:\n");
    char word[100];
    int end;
    scanf("%s", &word);
    printf("################���濪ʼ��ӡ,���鳤��:%d##############\n", strlen(word));
    for (end = strlen(word) - 1; end >= 0; end--) {
        printf("%c", word[end]);
    }
    printf("\n");
}

/**
 * �������뺯����
 * ѭ����ȡ�û������2���������������벻��ȷʱ����ֹ
 *
 * ��ע��������Ķ����Ǻ�Ҫ��ĸ�ʽʱ���򷵻�>0��������
 * eg:scanf("%f",&a)����������Ϊ���������򷵻�1
 * ��Ҫ������2�������ҷֱ��Ǻ�ʱ���򷵻�2��
 * �Դ����ơ�
 * �෴������û�����Ķ�����Ҫ��ƥ�䣬�򷵻�0
 */
void testScanfMethod() {
    float a, b;
    printf("��������������������:\n");
    while (scanf("%f%f", &a, &b) == 2) {
        printf("(%.2f-%.2f)/(%.2f*%.2f) = %.2f\n", a, b, a, b, (a - b) / (a * b));
        printf("��������������������:\n");
    }
    printf("end\n");
}

/**
 * ����ҵ����Ϊ��������
 */
void test4(int year, DepositType type) {
    int base = 10000;
    //���ڴ����Ϣ
    float rateUp;
    switch (type) {
        case CURRENT:
            rateUp = (1 + 0.0030);
            break;
        case TRIMESTER:
            rateUp = (1 + 0.0150);
            break;
        case HALF_YEAR:
            rateUp = (1 + 0.0175);
            break;
        case ONE_YEAR:
            rateUp = (1 + 0.0200);
            break;
        case TWO_YEAR:
            rateUp = (1 + 0.0275);
            break;
        case THREE_YEAR:
        case FIVE_YEAR:
            rateUp = (1 + 0.0320);
            break;
    }

    while (year > 0) {
        rateUp *= rateUp;
        year--;
    }
    float result = base * rateUp;

    printf("���ɵñ�����Ϣ��result=%f\n", result);
}

void test5(){
    printf("����������::\n");
    char test;
    while ((test = getchar()) != '\n'){
        if(isalpha(test)){//����������һ����ĸ

            putchar(test + 1);//�ı���ӡ
        } else
            putchar(test);//ԭ����ӡ
    }
    putchar(test);
}

/**
 * ָ��
 * ֪ʶ��
 * 1��������ͬʱҲ������Ԫ�ص��׵�ַ��
 * 2��ָ���1ʱ��ָ����ָ�ĵ�ַ�����8λ
 * 3��˵����%p����ָ����ָ��Ԫ��ֵ
 * 4���ڶ�ά�������Զ�ά����zippo[4][2]Ϊ����
 *    ����zippo����������������Ԫ��(zippo[0][0])�ĵ�ַ
 *    ��zippo[0]�����1�У�ÿ��������2��Ԫ�أ�������zippo[0]��һ����2��ֵ�����飬
 *    ������zippo[0]�ִ�����Ԫ�ص�ַ����Ҳ��(zippo[0][0])��ͬ��
 *    ���գ�zippo == &zippo[0] == &zippo[0][0]
 */
void testPoint(){
    int zippo[4][2] = {{2,4},{6,8},{1,3},{2,5}};
    printf("zippo = %p,zippo + 1 = %p\n",zippo,zippo + 1);
    printf("*zippo = %p,*zippo + 1 = %p\n",*zippo,*zippo + 1);
    printf("zippo[0][0] = %p,zippo[0][0] + 1 = %p\n",zippo[0][0],zippo[0][0] + 1);
    printf("zippo[0] = %p,zippo[0] + 1 = %p\n",zippo[0],zippo[0] + 1);
    printf("zippo = %p,&zippo[0][0]= %p\n",zippo,&zippo[0][0]);
    printf("zippo = %p,&zippo[0] = %p\n",zippo,&zippo[0]);
    printf("&zippo[0][0] = %p,&zippo[0] = %p\n",&zippo[0][0],&zippo[0]);
    printf("&zippo[0][0] = %p,&zippo[0] = %p\n",&zippo[0][0],&zippo[0]);
}

#endif //C_PROJ_SUNNYH_H
