/**
* Reverse Polish Calculator
* Author:   John Banda
* Date:     17 September 2025
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define FUNCTION 'f'    /* signal that a command was found */
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100 

// Functions supported by the calculator
typedef enum fn_type
{
    PEEK,
    SWAP,
    DUPLICATE,
    CLEAR,
    SIN,
    POW,
    EXP,
    FN_INVALID
}fn_type_et;

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void clear(void);
fn_type_et get_fn_type(char []);
void swap(void);

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

/* reverse polish calculator */
int main(int argc, char *argv[])
{
    int type;
    double op2;
    char *s;

    while (--argc > 0)
    {
        s = *++argv;
        type = getop(s);
    
        switch (type)
        {
            case NUMBER:
                push(atof(s));
            break;

            case FUNCTION:
                // Handle function calls here
                fn_type_et fn = get_fn_type(s);

                switch (fn)
                {
                    case PEEK:
                        printf("Peek:\t%.8g\n", peek());
                    break;

                    case DUPLICATE:
                        push(peek());
                    break;

                    case SWAP:
                        swap();
                    break;

                    case CLEAR:
                        clear();
                    break;

                    default:
                    break;
                }
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
                printf("Error: unknown command %s\n", s);
            break;
        }
    }

    // After the computation print out the result
    printf("\t%.8g\n", pop());

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

/* peek: return the top element of the stack without popping */
double peek(void)
{
    if (sp > 0)
    {
        return val[sp - 1];
    }else
    {
        printf("error: stack empty\n");
        return 0.0;
    }

    return 0.0;
}

/* clear: All the elements of the stack */
void clear(void)
{
    sp = 0;
}

/* swap: swap the 2 topmost elements on the stack */
void swap(void)
{
    // We need to make sure we have alteast to elements on
    // the stack
    if (sp >= 2)
    {
        // Let's use a simple swapping algo :)
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else
    {
        printf("error: insufficient items on the stack\n");

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
int getop(char *s)
{
    int c;
    int op_type = 0;

    c = *s;    

    // Handle operators and unknown symbols
    if (!isalpha(c) && !isdigit(c) && c != '.' && !is_sign(c))
        return c;       /* not a number */

    // Let's start by first checking if it's a command
    // We do this by checking if the first letter is a char 
    if (isalpha(c))
    {
       // If the first character is a letter, then
       // it's possible that this is a function 
       // The other situation is that it's a variable. However
       // we are not handling variables in this version
       op_type = FUNCTION;

    } else 
    {
        // Let's handle signs next
        if (is_sign(c))
        {
            c = *(s + 1);

            if (c != '.' && !isdigit(c))
            {
                return *s;
            }
        } 

        // In its simplest form, we can assume the imput is a
        // number
        op_type = NUMBER;
    }

    return op_type;
}

fn_type_et get_fn_type(char fn[])
{
    fn_type_et retval;
    // Perhaps create my own implementation of strcmp
    if (strcmp(fn, "peek") == 0)
        retval = PEEK; 
    else if (strcmp(fn, "swap") == 0)
        retval = SWAP;
    else if (strcmp(fn, "dupl") == 0)
        retval = DUPLICATE;
    else
        retval = FN_INVALID;

    return retval;
}
