#include<stdio.h>
/*****************************************************************************************
IDEA: Construct two stacks - operator stack(char) for storing operators;
	  operand stack(double) for storing numeric input. 
	  Use getchar to read characters in buffer, 
	  (1) If the incoming char is numeric, add it the current operand buffer.
	  
	  (2) if the incoming char is symbolic(operators), push the operand buffer to operand stack.
	  Then, determine whether to pop the operator stack for one o, and 2 for operand stack
	  to compute the previous equation (check priority of two operators).
	  If the operator in the top of operator stack has higher or equal priority, 
	  pop two stacks to get proper binary operations.  
	  (For example 1 + 2 - 3 => 1+2 need to be calculated before the - be pushed.
				   1 * 2 + 3 => 1*2 need to be calculated before the + be pushed.)
	  After compuation, push the result and the incoming symbol to stacks.
	  Otherwise, keep push the incoming symbol to operator stack. 
	  (For example 1 + 2 * 3 => 1+2 can't be calculated before 2*3 is calculated.)
	  
	  For illigal expressions/equations, always check the state of two stacks. 
******************************************************************************************/
double opCalculate(double, double, char);   // For binary operations
int optrPriority(char);                     // Determine the priority of the operator. 
int check_stack(int, int);                  // Check the state of two stacks: operator stack can't be larger than operand stack
int check_divide0(double, char);            // Check if the expression is num/0


int main(void)
{
    double operandStack[100];				// two stack: operand stack (for numbers) and operator stack (for operators)
    char operatorStack[100];
    int operandTop = -1, operatorTop = -1, i;
    int isInvalid = 0;              		// A flag to check current expression is valid or not
    int isDigitInBuffer = 0;        		// sum is zero originally, 
											// this flag is to make sure is there are digit in the buffer (push into operand stack or not)
    int char_count = 0;             		// A flag for - detection (unary minus)

    double sum = 0.0;
    char ch;

    for( i = 0 ; i < 100 ; i++)
    {
        operandStack[i] = 0.0;
        operatorStack[i] = '\0';
    }

    while((ch = getchar()) != '\n')
    {
        if( ch >= '0' && ch <= '9')
        {
            isDigitInBuffer = 1;
            char_count++;
            sum = sum * 10.0 + (double)(ch - '0');
        }
		// Read an operator, check both stack to determine whether there an valid 2 operand and 1 operator to calcute
        else if( ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
			// For unary -  ( = 0 - current number)
            if(char_count == 0 && ch == '-')
            {
                operandStack[++operandTop] = 0.0;
            }

            char_count++;
            if(isDigitInBuffer)
            {
                operandStack[++operandTop] = sum;
            }
            sum = 0.0;
            isDigitInBuffer = 0;
            while( operatorTop > -1 && optrPriority(operatorStack[operatorTop]) >= optrPriority(ch) )
            {
                if( !check_stack(operandTop, operatorTop) )
                {
                    isInvalid = 1;
                    break;
                }
                double op1 = operandStack[operandTop-1];
                double op2 = operandStack[operandTop];
                char optr = operatorStack[operatorTop];
                if( !check_divide0(op2, optr) )
                {
                    isInvalid = 1;
                    break;
                }

                operandTop -= 2;
                operatorTop -= 1;
				// The current result should be push into the operand stack
                operandStack[++operandTop] = opCalculate(op1, op2, optr);
            }

            if(isInvalid)    break;
            operatorStack[++operatorTop] = ch;
        }
		// Ignore the space symbol
        else if(ch == '\t' || ch == ' ')        
        {
            continue;
        }
		// If there are any other symbols, the expression is invalid
        else    
        {
            isInvalid = 1;
            break;
        }

    }
    // The end of an expression is always number
	// Make sure there is actually a number in the input buffer, push into the operand stack
    if(isDigitInBuffer)
    {
        operandStack[++operandTop] = sum ;
    }

    // If there are something still in stacks, keep pop them out to calcute the results.
    while( !isInvalid && (operandTop > -1 || operatorTop > -1))
    {
        if( !check_stack(operandTop, operatorTop) )
        {
            isInvalid = 1;
            break;
        }
        double op1 = operandStack[operandTop-1];
        double op2 = operandStack[operandTop];
        char optr = operatorStack[operatorTop];
        if( !check_divide0(op2, optr) )
        {
            isInvalid = 1;
            break;
        }

        operandTop -= 2;
        operatorTop -= 1;
        operandStack[++operandTop] = opCalculate(op1, op2, optr);
    }

    if(isInvalid)       printf("invalid expression!\n");
    else                printf("%.3lf\n", operandStack[0]);

    return 0;
}

double opCalculate(double op1, double op2, char optr)
{
    if(optr == '+')                     return (op1 + op2);
    else if(optr == '-')                return (op1 - op2);
    else if(optr == '*')                return (op1 * op2);
    else if(optr == '/')                return (op1 / op2);
}

int optrPriority(char optr)
{
    if(optr == '+' || optr == '-')      return 1;
    else if(optr == '*' || optr == '/') return 2;
}

int check_stack(int operandTop, int operatorTop)
{
    if(operandTop <= operatorTop)       return 0;
    else                                return 1;
}
int check_divide0(double op2, char optr)
{
    if(optr == '/' && op2 == 0.0)       return 0;
    else                                return 1;
}
