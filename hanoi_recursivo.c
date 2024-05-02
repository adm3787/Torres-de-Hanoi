#include <stdio.h>

//   n : nivel
//   i : inicio
//   f : fin
//   a : auxiliar 
void hanoi_recursivo(int n, char i, char f, char a){
    if (n == 1)
        printf("%c%c ", i, f);
    else{
        hanoi_recursivo(n-1, i, a, f);
        printf("%c%c ", i, f);
        hanoi_recursivo(n-1, a, f, i);
    }
}

int main(int argc, char ** argv){
    
    int  nivel;
    char inicio;
    char fin;
    char auxiliar;
    
    if (argc < 5){
        printf("\n   %s <nivel> <inicio> <fin> <auxiliar>\n\n",argv[0]);
        return 0;
    }
    
    sscanf(argv[1],"%d",&nivel);
    sscanf(argv[2],"%c",&inicio);
    sscanf(argv[3],"%c",&fin);
    sscanf(argv[4],"%c",&auxiliar);
    
    printf("%d: ",nivel);
    hanoi_recursivo(nivel,inicio,fin,auxiliar);
    printf("\n");
    
    return 0;
}
