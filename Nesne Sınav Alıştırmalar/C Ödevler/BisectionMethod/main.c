// Emre Özdemir 340824
// Assignment 2: Bisection metod ile kök bulma

#include <stdio.h>
#include <math.h>

int main() {
	float x1,x2,x3;								//Burada deðiþkenleri tanýmlýyoruz.
	float hata_payi,sabit;
	float sayi=0,a,toplam=0;
	float f,f2;
	float b,c;
	float min,max;
	min=0;
	max=0;
	printf("Gireceginiz denklem asagidaki gibi 3. dereceden bir denklem olmali.\n");
	printf("Ax^3 + Bx^2 + Cx+ D\n\n");
	printf("A,B,C denklemin kat sayilari ve D sabit olup asagida girmeniz istenecektir!\n\n");
	printf("Simdi kat sayilari giriniz.\n\n");

	printf("X'in 3. dereceden katsayisi:"); 	//Tanýmlanan deðiþkenlere kullanýcýdan denklemin katsayýlarýný ve sabit sayýyý istiyoruz.
	scanf("%f",&x3);
	printf("X'in 2. dereceden katsayisi:");
	scanf("%f",&x2);
	printf("X'in 1.dereceden katsayisini:");
	scanf("%f",&x1);
	printf("Sabit sayi:");						//Kullanýcýdan hata payý, minimum ve maximum aralýklarý kullanýcýdan istiyoruz.
	scanf("%f",&sabit);
	printf("Hata payini giriniz:");
	scanf("%f",&hata_payi);
	if(hata_payi==0) //hata payýnýn 0 girilmesinin engelliyoruz.
				{
					printf("Hata payi 0 olamaz");
				}
				else
				{
	printf("maximum deger: ");
	scanf("%f",&max);
	printf("minimum deger: ");
	scanf("%f",&min);
			if(min>=max)							//Minimum ve maximum aralýklarýnýn doðru bir þekilde girilmesinin kontrolünü gerçekleþtiriyoruz.
			{
				printf("max ve min degerleri ters girilmistir.");
			}
			else
			{
				a=max-min;							// a sayýsý max-min olarak tanýmlanýyor aralýðý küçükltmek açýsýndan
				sayi=(max+min)/2;					//Bisection metodunda verilen max ve min deðerlerin toplamýnýn ortalamasý alýnýyor.
			int i;
			for(i=0;i<=1;i++)						//Girilen deðerlerin aralýðýnda kökler mevcut olup olmadýðýnýn kontrolü yapýlýyor.
			{
				if(i==0)
				{
					f2=x3*(pow(min,3))+x2*(pow(min,2))+x1*min+sabit;	// Girilen sayý aralýklarýnýn fonksiyonda ki sonuçlarýný alýyoruz.
					b=f2;

				}
				else if(i==1)
				{
					f2=x3*(pow(max,3))+x2*(pow(max,2))+x1*max+sabit;
					c=f2;
				}
			}
			if(b*c>0)					// Bu aldýðýmýz sonuçlarýn çarpýmý sýfýrdan büyük yani pozitif ise girilen aralýkta kök olmadýðý anlamý taþýyor.
			{
				printf("Bu aralikta kok yoktur.");
			}
			else
			{
				for(;a>hata_payi;)			//Kökün belirli bir hata payý ile hesaplanmasý iþlemi burada gerçekleþtiriliyor.
				{
					f=x3*(pow(sayi,3))+x2*(pow(sayi,2))+x1*sayi+sabit;
					if(f<0)
					{
						min=sayi;
						a=max-min;		// Fonksiyonda min deðeri girildiðinde sonuç negatif çýkýyor ise onu sayýya'ya atýyoruz.
					}					// ve a=max-min yaparak kök aralýðýný daraltýp sonuca varmaya çalýþýyoruz.
					else if(f>0)
					{
						max=sayi;
						a=max-min;			// Fonksiyonda max deðeri girildiðinde sonuç pozitif çýkýyor ise max deðerini sayýya atýyoruz.
					}						// burada da ayný þekilde a'ý küçülterek sonuca varmaya çalýþýyoruz.
						sayi=(min+max)/2;	// sayi her iþlem sonunda maximum ve minimum deðerinin yarýsýný alýr.
				}

    	printf("Denkleminizin koku: %.2f",sayi);		// Bulunan kökün ekrana çýktýsý
    		}
		}
	}
	return 0;
}
