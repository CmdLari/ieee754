#include <stdio.h>

void conversion(float input){

    // Split input into front and back
    int front = input; // anything in front of the floating point
    if (front < 0){
        front = front*(-1);
    }
    float back = input; // anything after the floating point (in a moment)
    if (back <0) {
        back = back*(-1);
    }
    back = back - front; // should reduce the float to what is after the floating point

    // future return
    int converted[32] = {0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0,0,0,0,0,0,0,0,0,
                         0,0};

////// [0]/[B31] (ZERO-FLAG)
    if (input < 0){
        converted[0] = 1;
    }
//////////////////////////////

    // [1-8]/[B30-23] (EXPONENT)-
    int expBinInv[256] = {};
    int cutoff;
    int placementBack = 0;
    //converting to binary (result is inverse)
    while (back!=0){
        back = back*2;
        cutoff = back;
        back -= cutoff;
        expBinInv[placementBack] = cutoff;
        placementBack++;
    }

    //rectifying result order
    int expBin[8] = {};
    for (int i=0; i<placementBack; i++){
        expBin[i] = expBinInv[placementBack-i-1];
    }

    int expConv = 127;
    if (input < 0) {
        expConv -= placementBack;
    }
    else {
        expConv += placementBack;
    }

    int rest;
    int index = 0;
    int expInv[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    while (expConv > 0) {
        rest = expConv%2;
        expConv = expConv/2;
        expInv[index] = rest;
        index++;
    }

    int exp[8];
    for (int i=0; i<8; i++) {
        exp[i] = expInv[8-1-i];
    }

    int k= 0;
    for (int i=1; i<=8; i++) {
        converted[i] = exp[k];
        k++;
    }


//////////////////////////////


////// [9-31]/[B22-0] (MANTISSE) 1st part
    int r;
    int placement = 0;
    int mantisseFrontInv[23]= {};
    //converting to binary (result is inverse)
    while (front > 0){
        r = front%2;
        front = front/2;
        mantisseFrontInv[placement] = r;
        placement++;
    }
    printf("\n\n");

    //rectifying result order
    int mantisseFront[placement]= {};
    for (int i=0; i<placement; i++){
        mantisseFront[i] = mantisseFrontInv[placement - i - 1];
    }

    //adding exponent to mantisse
    for (int i=0; i<placementBack; i++){
        mantisseFront[placement+i]=expBin[i];
    }
    //Mantisse length = placement + placement back
    //Number of needed zeros in front: 23-length of Mantisse
    int startingpoint = 9+(23-placement-placementBack);
    int j= 0;
    for (int i=startingpoint; i<=31; i++) {
        converted[i] = mantisseFront[j];
        j++;
    }


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
