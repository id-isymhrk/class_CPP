// test_pointers.cpp
// COMPLETE include necessary headers
int main(void)
{
    //
    // 1. Declare a variable f as a pointer to a float
    // 2. Create a float variable named pi, and store the value 3.14159f
    // 3. Make f points to pi
    // 4. Print out the content of the memory location pointed to by f

    //
    short a[] = {5, 4, 3, 2, 1};
    // 5. Declare a variable ip as a pointer to a short integer
    // 6. Make ip points to the beginning of the array a
    // 7. Print out what ip points to and the content of a[0] (verify they are the same)
    // 8. Increase ip by 2 and check that what it points to corresponds to a[2]
    // 9. Make ip points to the last element of the array by increasing it by 2
    //     and check that what it points to corresponds to a[4]

    //
    int n = 20;
    // 10. Declare a variable d as a pointer to double and
    // make it point to an array of "n" element of type "double" created on the heap
    // 11. Store in each d[i] (for i=0 to n-1) the value double(i) / 5.0;
    // 12. Print out each element of d
    // 13. Delete the previously allocated memory

    //
    int m = 5;
    n = 10;
    double **dd;
    // 14. Allocate memory for a 2d array of size m * n on the heap (i.e. m arrays of size n).
    // Make dd points to this 2d array.
    // 15. Set the element dd[i][j] to be equal to double(i)*double(j)
    // 16. Delete the memory allocated for the 2d array

    // 17. Create a reference to the variable f (1. above). Name it rf
    // 18. Assign the value 2.71828 to rf
    // 19. Print out the value of f and rf and verify that they are equal

    return 0;
}