#include <stdio.h>

int main() {
    int A, A_hund, A_ten, A_one;
    int B, B_hund, B_ten, B_one;
    int reverse_A;
    int reverse_B;

    scanf("%d %d", &A, &B);
    
    A_hund = A/100;        // A의 백의 자리수
    A_ten = (A%100)/10;    // A의 십의 자리수
    A_one = (A%100)%10;    // A의 일의 자리수
    
    B_hund = B/100;        // B의 백의 자리수
    B_ten = (B%100)/10;    // B의 십의 자리수
    B_one = (B%100)%10;    // B의 일의 자리수    
    
    
    reverse_A = A_one *100 + A_ten *10 + A_hund; 
    reverse_B = B_one *100 + B_ten *10 + B_hund; 
    
    
    if(reverse_A > reverse_B)
        printf("%d",reverse_A);
    else
        printf("%d",reverse_B);
   
    
    return 0;
}
