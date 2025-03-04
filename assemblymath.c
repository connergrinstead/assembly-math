#include <stdio.h>

// ADDITION //
int add_numbers(int a, int b) {
    int result;
    __asm__(
        "movl %1, %%eax;"
        "addl %2, %%eax;"
        "movl %%eax, %0;"
        : "=r" (result)
        : "r" (a), "r" (b)
        : "%eax"
    );
    return result;
}

// SUBTRACTION //
int subtract_numbers(int a, int b) {
    int result;
    __asm__(
        "movl %1, %%eax;"
        "subl %2, %%eax;"
        "movl %%eax, %0;"
        : "=r" (result)
        : "r" (a), "r" (b)
        : "%eax"
    );
    return result;
}

// MULTIPLICATION //
int multiply_numbers(int a, int b) {
    int result;
    __asm__(
        "movl %1, %%eax;"
        "imull %2, %%eax;"
        "movl %%eax, %0;"
        : "=r" (result)
        : "r" (a), "r" (b)
        : "%eax"
    );
    return result;
}

// DIVISION //
int divide_numbers(int a, int b) {
    int result;
    __asm__(
        "movl %1, %%eax;"
        "cltd;"
        "idivl %2;"
        "movl %%eax, %0;"
        : "=r" (result)
        : "r" (a), "r" (b)
        : "%eax", "%edx"
    );
    return result;
}

// FACTORIAL //
int factorial(int n) {
    int result = 1;
    __asm__(
        "movl %1, %%ecx;"
        "movl $1, %%eax;"
        "cmp $1, %%ecx;"
        "jle end_factorial;"
        "factorial_loop:"
        "imull %%ecx, %%eax;"
        "loop factorial_loop;"
        "end_factorial:"
        "movl %%eax, %0;"
        : "=r" (result)
        : "r" (n)
        : "%eax", "%ecx"
    );
    return result;
}

// POWER //
int power(int base, int exp) {
    int result;
    __asm__(
        "movl $1, %%eax;"       // result = 1
        "movl %2, %%ecx;"       // exp into ecx
        "test %%ecx, %%ecx;"    // if exp == 0, skip loop
        "jz end_power;"
        "power_loop:"
        "imull %1, %%eax;"      // result *= base
        "loop power_loop;"
        "end_power:"
        "movl %%eax, %0;"
        : "=r" (result)
        : "r" (base), "r" (exp)
        : "%eax", "%ecx"
    );
    return result;
}

// MODULUS //
int modulus(int a, int b) {
    int result;
    __asm__(
        "movl %1, %%eax;"
        "cltd;"
        "idivl %2;"
        "movl %%edx, %0;"
        : "=r" (result)
        : "r" (a), "r" (b)
        : "%eax", "%edx"
    );
    return result;
}

int main() {
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    printf("Addition: %d\n", add_numbers(num1, num2));
    printf("Subtraction: %d\n", subtract_numbers(num1, num2));
    printf("Multiplication: %d\n", multiply_numbers(num1, num2));
    printf("Division: %d\n", divide_numbers(num1, num2));
    printf("Factorial of %d: %d\n", num2, factorial(num2));
    printf("Power: %d^%d = %d\n", num1, num2, power(num1, num2));
    printf("Modulus: %d %% %d = %d\n", num1, num2, modulus(num1, num2));
    
    return 0;
}
