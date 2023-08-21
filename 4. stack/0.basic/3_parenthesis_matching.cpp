#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top = -1;
    char *a;
} *obj = new stack;

void push(char c)
{
    obj->top++;
    if (c == '[')
    {
        obj->a[obj->top] = '[';
    }
    else if (c == '{')
    {
        obj->a[obj->top] = '{';
    }
    else if (c == '(')
    {
        obj->a[obj->top] = '(';
    }
}

void pop()
{
    obj->top--;
}

void create()
{
    obj->a = new char[obj->size]; //creating array dynamically

        cout << "Enter the string : ";
        cin >> obj->a;
}

void parenthesis()
{
    int i = 0, flag = 0, flag1 = 0,ok=0;
    char square = 3, curly = 2, small = 1;
    while (obj->a[i] != 0)
    {
        if (obj->a[i] == '(' || obj->a[i] == '{' || obj->a[i] == '[')
        {
            if (obj->a[i] == '[')
            {
                if (flag1 > 0 && ok ==0)
                {
                    cout << "\nOrder Is Not Right";
                    flag1=100;               // just to check condition to not print Parenthesis not match and Order is not right togethere
                    break;
                }
                else
                {
                    square++;
                    push(obj->a[i]);
                }
            }
            else if (obj->a[i] == '{')
            {
                if (flag1 > 0 && ok == 0)      //using ok if { is not poped
                {
                    cout << "\nOrder Is Not Right";
                    flag1=100;
                    break;
                }
                else
                {
                    curly++;
                    push(obj->a[i]);
                }
                if (curly == square || square>3 && ok!=0) //means no curly bracket present // square >3 to check [{}[]]
                {
                    flag1++;
                }
            }
            else if (obj->a[i] == '(')
            {
                small++;
                push(obj->a[i]);
                if (small == curly || curly>2 && ok!=0) //means no curly bracket present
                {
                    flag1++;
                }
            }
        }
        else if (obj->a[i] == ']' || obj->a[i] == '}' || obj->a[i] == ')')
        {
            if (obj->a[i] == ']')
            {
                square--;
                pop();
                ok++;
            }
            else if (obj->a[i] == '}')
            {
                curly--;
                pop();
                ok++;
            }
            else if (obj->a[i] == ')')
            {
                small--;
                pop();
                ok++;
            }
        }
        i++;
    }

    if (obj->top == -1 && small == 1 && square == 3 && curly == 2)
    {
        cout << "\nParenthesis matches\n";
    }
    else if(flag1 != 100)
    {
        cout << "\nParenthesis does'nt match\n";
    }
}

int main()
{
    cout << "Enter the size of array : ";
    cin >> obj->size;
    create();
    parenthesis();
    return 0;
}