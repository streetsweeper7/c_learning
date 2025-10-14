
#ifndef POLISH_CAL_H
#define POLISH_CAL_H

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

/*********************
* Stack ops
*********************/
void push(double);
double pop(void);
double peek(void);
void clear(void);
void swap(void);    // Not really a stack op

/*********************
* Input handling 
*********************/
int get_line(char s[], int lim);
int getop(char s[], char input_line[]);
fn_type_et get_fn_type(char []);

/*********************
* Variable Register 
*********************/
void init_var_reg();

#endif /* POLISH_CALC_H */
