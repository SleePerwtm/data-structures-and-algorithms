#include <stdio.h>

#define MAX 1001

int main()
{
    char expr[MAX];  // 储存输入的表达式
    char stack[MAX]; // 储存运算符的静态栈
    scanf("%s", expr);

    int top = 0; // 顶指针
    // 遍历输入的表达式
    for (int i = 0; expr[i] != '\0'; i++)
    {
        switch (expr[i])
        {
        case '+':
        case '-':
            // 如果此时栈顶为*或/，则先出栈
            if (top > 0 && (stack[top - 1] == '*' || stack[top - 1] == '/'))
            {
                printf(" %c", stack[top - 1]);
                top--;
            }
            // expr[i]入栈
            printf(" ");
            stack[top] = expr[i];
            top++;
            break;
        case '*':
        case '/':
            // expr[i]入栈
            printf(" ");
            stack[top] = expr[i];
            top++;
            break;
        case '(':
            // expr[i]入栈
            stack[top] = expr[i];
            top++;
            break;
        case ')':
            // 循环出栈，直到top==0或stack[top-1]=='('
            while (top > 0 && stack[top - 1] != '(')
            {
                printf(" %c", stack[top - 1]);
                top--;
            }
            printf(" ");
            // '('出栈
            if (stack[top - 1] == '(')
                top--;
            break;
        default:
            // 为数字，直接输出
            printf("%c", expr[i]);
            break;
        }
    }
    // 弹出栈内所有剩余元素
    for (int i = top; i > 0; i--)
        printf(" %c", stack[i - 1]);

    return 0;
}