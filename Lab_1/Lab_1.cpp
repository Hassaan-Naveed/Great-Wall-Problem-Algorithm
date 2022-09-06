#include <iostream>

//Pass by value
void f(int i)
{
    i++;
}

//Pass by reference
void g(int& i)
{
    i++;
}

//Recursion
int factorial(int i)
{
    if (i < 2) {
        return 1;
    }
    else {
        return (i * factorial(i - 1));
    }
}
