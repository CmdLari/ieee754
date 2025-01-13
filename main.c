#include <stdio.h>

void conversion(float input){

    // Split input into front and back
    int front = input; // anything in front of the floating point
    if (front < 0){
        front = front*(-1);
    }
    float back = input; // anything after the floating point (in a moment)
    back = back - front; // should reduce the float to what is after the floating point

    // future return
    int converted[32] = {0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0};

    // [0]/[B31] (ZERO-FLAG)
    if (input < 0){
        converted[0] = 1;
    }

//    // [1-8]/[B30-23] (EXPONENT)
//    int expBinInv[] = {};
//    int cutoff;
//    int placementBack = 0;
//    //converting to binary (result is inverse)
//    while (back-1!=0){
//        back = back*2;
//        cutoff = back;
//        expBinInv[placementBack] = cutoff;
//        placementBack++;
//    }
//
//    printf("\n\n");
//
//
//    //rectifying result order
//    int expBin[] = {};
//    for (int i=0; i<placementBack; i++){
//        expBin[i] = expBinInv[placementBack-i-1];
//        printf("%d", expBin[i]);
//    }
//
//
    // [9-31]/[B22-0] (MANTISSE) 1st part
    int r;
    int placement = 0;
    int mantisseFrontInv[]= {};
    //converting to binary (result is inverse)
    while (front > 0){
        r = front%2;
        front = front/2;
        mantisseFrontInv[placement] = r;
        placement++;
    }
    printf("\n\n");

    //rectifying result order
    printf("Mantisse without exponent: ");
    int mantisseFront[placement]= {};
    for (int i=0; i<placement; i++){
        mantisseFront[i] = mantisseFrontInv[placement - i - 1];
        printf("%d", mantisseFront[i]);
    }
//
//    //adding exponent to mantisse
//    for (int i=0; i<placementBack; i++){
//        mantisseFront[placement+i]=expBin[i];
//    }
//
//    printf("\n\n Mantisse with exponent: ");
//    //Mantisse with exponent
//    for (int i=0; i<placement+placementBack; i++){
//        printf("%d", mantisseFront[i]);
//    }

    printf("\n\n");
    for (int i=0; i<32;i++){
        printf("%d", converted[i]);
    }
}

int main() {
    float input;
    printf("Please enter the number you want the IEEE 754 32-bit representation of:\n");
    scanf("%f", &input);
    conversion(input);

    return 0;
}
