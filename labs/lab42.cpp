#include <iostream>

#define PROMPT "Please enter a whole number:"
#define NOT_PRIME "The number is not a prime number./n"
#define PRIME "The number is a prime number./n"
#define DONE 0          /* ends successful program */
#define FIRST_FACTOR 2  /* initial value in for loop */

using std::cout;
using std::cin;

int main(){
    int i, x=1;       /* loop counter */
    int number; /* number provided by user */
    
    cout << PROMPT;  /* promt user */
    cin >> number;  /* wait for user input */
    
    /* Prime numbers are defined as any number
     * greater than one that is only divisible
     * by one and itself. Dividing the number
     * by two shortens the time it takes to
     * complete. */
    
    for(i = FIRST_FACTOR; i < number; i++)
        if( number % i == 0 ){/* if divisible */
            x = 0;
            break;        /* exit program */
        }
    if(x == 0)
        cout << NOT_PRIME << std::endl;/* if number is not divisible by anything * than it must be prime */
    
    if(x == 1)
        cout << PRIME << number;
    return 0;     /* exit program */
}