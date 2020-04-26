#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi=543,temp,nsayi=0;
    while(sayi>0){
        temp=sayi%10;
        nsayi=nsayi*10+temp;
        sayi-=temp;
        sayi/=10;
    }
      return 0;
}
