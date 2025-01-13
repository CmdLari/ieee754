#include <stdio.h>

void conversion(float input){

    // Split input into front and back
    int front = input; // anything in front of the floating point
    if (front < 0){
        front = front*(-1);
    }
    float back = input; // anything after the floating point (in a moment)
    back -= front; // should reduce the float to what is after the floating point

    // future return
    int converted[32] = {0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0};

    // [0]/[B31] (Zero-Flag)
    if (input < 0){
        converted[0] = 1;
    }

    // [1-8]/[B30-23] (Exponent)
    for (int i=0; i<32; i++)

    // [9-31]/[B22-0] (Mantisse)


        printf("%d", converted[i]);

}

int main() {
    float input;
    printf("Please enter the number you want the IEEE 754 32-bit representation of:\n");
    scanf("%f", &input);
    conversion(input);

    return 0;
}
