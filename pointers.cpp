#include <iostream>

int main()
{
    // TASK 4
    double **p = nullptr; // double **p = 0
    double *ptr = new double; //allocating memory for a pointer that will point to the value in square
    double value = 2; //value in square

    delete ptr;  //avoiding memory losses
    ptr = &value; //second pointer pointing to the square

    p = &ptr; //first pointer pointing to the second pointer

    std::cout<<**p;  // unpacking the first pointer

    return 0;
}
