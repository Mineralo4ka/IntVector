#include <stdio.h>

int main()
{
    char a;
    int N, i;

    printf("Xotite repair all labs po vsem lessions?(y or n?)\nAnswer: ");
    scanf("%c", &a);
    printf("Ckolko tebe age? ");
    scanf("%d", &N);
    
    if (a == 'y'){
	printf("You vibral right! Your labs bydyt cdelani :3(no eto ne tocho)");
    }else{
	printf("You are axyel tam? Ebanyi pidrila, poshla naxyu otcyda pcina!\n");
	for (i = 0; i < N; i++){
	    printf("%d\n", i);
	}
	    printf("Vot imenno stolko raz ti pidrila))00)00)0");
    }

    return 0;
}