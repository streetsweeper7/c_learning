/**
* Reverse Polish Calculator
* Author:   John Banda
* Date:     14 October 2025
*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "polish_calc.h"

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */
#define FUNCTION 'f'    /* signal that a command was found */
#define VARIABLE 'v'    /* signal that a variable was found */
#define MAXVAL 100      /* maximum depth of val stack */
#define VAR_REG_SZ 27   /* Maximum number of variable on the var register */ 
#define INPUT_LEN 1000  /* Maximum length of the input string */


/*********************
* Global Variables
********************/

int sp = 0;                     /* next free stack position */
double val[MAXVAL];             /* value stack */
double var_reg[VAR_REG_SZ];     /* Variable register. */

char input_line[INPUT_LEN];
int curr_input_pos = 0;

/* Handle initialisation of variable registers */
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

    // We'll use getline to get the input command
    int len = get_line(input_line, INPUT_LEN);
    (void) len;     // We'll use len to keep running the calc endlessly
    bool done = false;

    // Read in the values from the input line until we are done 
    while ((type = getop(s, input_line)) && !done)
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
                double result = pop();
                var_reg[VAR_REG_SZ - 1] = result;
                // Print
                printf("\t%.8g\n", result);
                done = true;
            break;
            default:
                printf("Error: unknown command %s\n", s);
                done = true;
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
int getop(char s[], char input_line[])
{
    int i, c;
    int op_type = 0;

    while ((s[0] = c = input_line[curr_input_pos]) == ' ' || c == '\t')
    {
        curr_input_pos++;
    }
        
    // If we reached here, it means we got a character, that's not a 
    // space, so we need to increase current position
    s[1] = '\0';
    
    if (!isalpha(c) && !isdigit(c) && c != '.' && !is_sign(c) && c != '_')
        return c;       /* not a number, perhaps an operator */

    
    i = 0;
    

    // Let's start by first checking if it's a command
    // We do this by checking if the first char is alpha 
    if (isalpha(c) || c == '_')
    {
       // If the first character is a letter, then
       // it's possible that this is a function 
       while (isalpha(s[++i] = c = input_line[++curr_input_pos]))
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
            a number or an operator */

        // Let's handle signs next
        if (is_sign(c))
        {
            s[++i] = c = input_line[++curr_input_pos];

            if (c != '.' && !isdigit(c))
            {
                /* ungetch(c);      Perhaps there's no need to reduce
                                    the current input position
                                    because this is an error condition */
                return s[0];
            }
        } 
        // Let's now handle integer and fractional parts
        if (isdigit(c))     /* collect integer part */
        {
            while (isdigit(s[++i] = c = input_line[++curr_input_pos]))
                ;

        }

        if (c == '.')       /* collect fraction part */
        {
            while (isdigit(s[++i] = c = input_line[++curr_input_pos]))
                ;
                
        }

       op_type = NUMBER;
    }

    s[i] = '\0';

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

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    c = EOF;    // Just to initialise c to stop the compiler from
                // complaining

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
