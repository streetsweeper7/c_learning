/**
* Reverse Polish Calculator
* Author:   John Banda
* Date:     13 October 2025
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */
#define FUNCTION 'f'    /* signal that a command was found */
#define VARIABLE 'v'    /* signal that a variable was found */
#define MAXVAL 100      /* maximum depth of val stack */
#define BUFSIZE 100 
#define VAR_REG_SZ 27   /* Maximum number of variable on the var register */ 

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
int getch(void);
void ungetch(int);
fn_type_et get_fn_type(char []);
void swap(void);
void init_var_reg();

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

double var_reg[VAR_REG_SZ];

void init_var_reg()
{
    for (int i = 0; i < VAR_REG_SZ; ++i)
    {
        var_reg[i] = NAN;
    }
}

/* reverse polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    // Initialise the variable register to have NANs
    init_var_reg();

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
            break;

            case VARIABLE:
                // If a variable is set, push its value to the
                // stack, else, push its index
                
                // Let's check if the index is less than 26
                if (s[0] == '_')
                {
                    // This represents the last printed value
                    push(var_reg[VAR_REG_SZ - 1]);
                } else
                {
                    // Next we assume it's a variable
                    int ix = s[0] - 'a';

                    if (!isnan(var_reg[ix]))
                    {
                        // This means that the variable is set
                        push(var_reg[ix]);
                    } else
                    {
                        // This means the variable is not set
                        // so we just push the index 
                        push(ix); 
                    }
                }
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
                    
                    case SIN:
                        // Handle sin
                        double arg = pop();
                        push(sin(arg));
                    break;
                    case EXP:
                        // Handle sin
                        double exp_arg = pop();
                        push(exp(exp_arg));
                    break;
                    case POW:
                        // Handle sin
                        double exponent = pop();
                        double base     = pop();
                        push(pow(base, exponent));
                    break;

                    default:
                        // Handle default cases
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
            case '=':
                // The assumption is that an expression of the
                // form var value =, e.g a 5 =, was entered
                
                double value = pop();
                int var_index = pop();
                
                if (var_index >= 0 && var_index <= VAR_REG_SZ)
                {

                    // Make sure var_index is between 0 and 26
                    // then set the variable register
                    var_reg[var_index] = value;

                    // push back the final value to the stack 
                    push(value); 
                }
            break;
            case '\n':
                // Before printing a value save it in the last printed variable
                var_reg[VAR_REG_SZ - 1] = pop();
                printf("\t%.8g\n", var_reg[VAR_REG_SZ - 1]);
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
int getop(char s[])
{
    int i, c;
    int op_type = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    
    if (!isalpha(c) && !isdigit(c) && c != '.' && !is_sign(c) && c != '_')
        return c;       /* not a number */

    i = 0;

    // Let's start by first checking if it's a command
    // We do this by checking if the first letter is a char 
    if (isalpha(c) || c == '_')
    {
       // If the first character is a letter, then
       // it's possible that this is a function 
       while (isalpha(s[++i] = c = getch()))
           ;

        // Variables only have one character, therefore
        // We check the length to see if we have a 1 character
        // value
        
        if (i <= 1)
        {
            op_type = VARIABLE;
        } else
        {
            op_type = FUNCTION;
        }

    } 
    else 
    {
        /* At this point we know we have not received
            a number of an operator */

        // Let's handle signs next
        if (is_sign(c))
        {
            s[++i] = c = getch();
            if (c != '.' && !isdigit(c))
            {
                ungetch(c);
                return s[0];
            }
        } 
        // Let's now hand integer and fractional parts
        if (isdigit(c))     /* collect integer part */
            while (isdigit(s[++i] = c = getch()))
                ;
        if (c == '.')       /* collect fraction part */
            while (isdigit(s[++i] = c = getch()))
                ;

       op_type = NUMBER;
    }

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return op_type;
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
    else if (strcmp(fn, "sin") == 0)
        retval = SIN;
    else if (strcmp(fn, "exp") == 0)
        retval = EXP;
    else if (strcmp(fn, "pow") == 0)
        retval = POW;
    else
        retval = FN_INVALID;

    return retval;
}
