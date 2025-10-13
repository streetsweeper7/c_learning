/**
* Reverse Polish Calculator
* Author:   John Banda
* Date:     15 September 2025
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <stdbool.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100 

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

/* reverse polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
            break;
            case '+':
                push(pop() + pop());
            break;

            case '*':
                push(pop() * pop());
            break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: zero divisor\n");
            break;
            case '-':
                op2 = pop();
                push(pop() - op2);
            break;
            case '%':
                op2 = pop();
                push( (int)pop() % (int)op2); // Make sure they are ints
            break;
            case '\n':
                printf("\t%.8g\n", pop());
            break;
            default:
                printf("Error: unkown command %s\n", s);
            break;
        }
    }

    return 0;

}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    } else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }else
    {
        printf("error: stack empty\n");
        return 0.0;
    }

    return 0.0;

}

/* is_sign: Checks if a character is a sign ( +/-) */
inline bool is_sign(char c)
{
    switch (c)
    {
        case '+':
        case '-':
            return true;
        default:
            return false;
    }
    return false;
}


/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    
    if (!isdigit(c) && c != '.' && !is_sign(c))
        return c;       /* not a number */

    // Let us handle signs first
    i = 0;

    if (is_sign(c))
    {
        s[++i] = c = getch();
        if (c != '.' && !isdigit(c))
        {
            ungetch(c);
            return s[0];
        }
    } 
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

int getch(void)     /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }else
    {
        buf[bufp++] = c;
    }
}
