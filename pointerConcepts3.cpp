#include <stdio.h>

// Function taking a pointer to int
//This function takes a pointer to an integer as an argument. 
// Inside the function, you manipulate the value pointed to by the pointer a. 
// Changes made to *a within the function will affect the original value 
// passed to the function.
void funPointer(int* a) {
    *a = 20; // Change the value pointed to by a
}

// Function taking a reference to int
// This function takes an integer reference as an argument.
// References in C++ are essentially aliases for variables.
// Inside the function, you manipulate the reference a directly, 
// and any changes made to a will directly affect the original variable 
// passed to the function. Unlike pointers, references cannot be reassigned
//  to point to another variable after initialization.

//not possible in c
void funReference(int& a) {
    a = 30; // Change the value referred to by a
}

int main() {
    int num = 10;

    printf("Before function calls: %d\n", num);

    // funPointer(&num); // Pass the address of num
    // or
    int* ptr = &num;
    funPointer(ptr);
    
    printf("After funPointer call: %d\n", num);

    funReference(num); // Pass the address of num
    printf("After funReference call: %d\n", num);

    return 0;
}


// In C and C++, both pass by reference and pass by pointer allow you to modify variables in a function and have those modifications reflected in the calling code. However, they differ in syntax and some behavior:

// 1. **Pass by reference**:
//    - In C++, pass by reference is achieved using references (`&` symbol in the function parameter).
//    - In C, there are no references, but you can simulate pass by reference behavior by passing pointers.
//    - Syntax in C++: `void fun(int& a)`
//    - Syntax in C (simulated): `void fun(int* a)`
//    - Example in C++:
//      ```cpp
//      void fun(int& a) {
//          a = 20; 
//      }
//      ```
//    - Example in C (simulated):
//      ```c
//      void fun(int* a) {
//          *a = 20; 
//      }
//      ```

// 2. **Pass by pointer**:
//    - In pass by pointer, you explicitly pass the address of a variable to the function.
//    - Syntax in both C and C++: `void fun(int* a)`
//    - Example:
//      ```cpp
//      void fun(int* a) {
//          *a = 20; 
//      }
//      ```

// Key differences:

// - **Syntax**: Pass by reference uses references (`&`) directly, while pass by pointer uses pointers (`*`).
// - **Pointer manipulation**: Pass by pointer allows direct manipulation of pointers (like reassigning the pointer to point to a different memory location), which is not possible with pass by reference.
// - **Nullability**: Pointers can be NULL, whereas references in C++ must always refer to a valid object (there's no direct equivalent concept in C).
// - **Explicitness**: Pass by pointer explicitly shows that you're working with addresses in your function call, whereas pass by reference hides this detail.

// Both techniques have their use cases, and the choice between them often depends on factors such as the specific requirements of the function, coding standards, and personal preference.