//
// Created by sunny on 2016/3/28.
//

#ifndef C_PROJ_SUNNYH_H
#define C_PROJ_SUNNYH_H
#define FORMAT "%s!C is cool !\n"

#include <stdio.h>
#include <mem.h>

/**
 * �ַ������ͣ�
 * ע����Сд��ĸ��ASCII�����32
 * Сд��ĸ - 32 = ��д��ĸ
 */
void testChar1(){
    char a,b;
    a = 110;
    b = 114;

    printf("\n%c,%c:",a,b);
    printf("\n%c,%c:",a-32,b-32);

}

/**
 * 2.const�ؼ��֣���һ������ת���ɳ���
 */
void testConst(){

    const int age = 10;
    //age = 12;
    printf("age=%d\n",age);

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
void formatPrint(const char* str){
    printf("������ַ������ȣ�%d\n",strlen(str));
    printf("/%2s/\n",str);
    printf("/%20s/\n",str);
    printf("/%20.5s/\n",str);
    printf("/%+20.3s/\n",str);

    int name[40];
    float cash;
    printf("Please input your name and the cash!\n");
    scanf("%s%f",&name,&cash);
    printf("The %s family just may be $%.2f dollars richer!\r\n",name,cash);
    printf("Your name is:\"%s\"",name);


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
void testSizeof(){
    int n=0;
    size_t intsize;
    intsize = sizeof(int);
    printf("n=%d,n has %zd bytes;all ints have %lu bytes.\n",n,sizeof n,intsize);

    typedef double sunnyDouble;
    typedef int sunnyInt;
    double d1 = 1.3;
    sunnyDouble d2 = 1.3;
    if(d1 == d2){
        printf("d1 �� d2��ͬһ������");
    }
}

/**
 * ��ӡ������
 */
void test3(){
  printf("Hi Sunny,���������һ����д��ĸ,������Ϊ������һ��������ͼ��:\n");
    char input;
    scanf("%c",&input);
    const int ROWS = 5;
    int row;
    int blank;
    printf("################Start##############\n");
    for(row = 0;row<ROWS;row ++){
        char temp = input;
            for(blank = 0;blank<(ROWS-row);blank++){
                //��ӡ�ո�
                printf(" ");
            }
            //��ӡ����
            int up,down;
            for(up = 0;up<=row;up++){
                printf("%c",temp + up);
            }
            //����
            for(down = temp + row  ;down > temp;down -- ){
                printf("%c",down-1);
            }
        printf("\n");
    }
    printf("################End##############\n");

}

/**
 * ��������
 * ��ס���ַ����Ǵ洢���ַ��������棬��һ���������ַ���
 */
void testArray(){

    printf("��������һ������:\n");
    char word[100];
    int end;
    scanf("%s",&word);
    printf("################���濪ʼ��ӡ,���鳤��:%d##############\n", strlen(word));
    for(end = strlen(word) -1 ;end >=0;end-- ){
        printf("%c",word[end]);
    }
    printf("\n");
}
#endif //C_PROJ_SUNNYH_H
