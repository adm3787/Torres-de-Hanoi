#include <stdio.h>
#include <stdint.h>

#define IA 1
#define IF 2
#define AI 3
#define AF 4
#define FI 5
#define FA 6

int potencia2(int n)
{
    int resultado = 1;
    
    while (n-- > 0) resultado *= 2;
    
    return resultado;
}

uint8_t movimiento_i(int nivel, int i)
{
    int mc = potencia2(nivel - 1);   //  mc: movimiento central
    uint8_t m;                       //  m : movimiento devuelto
    
    if (i == mc)
        m = IF;
    else
    {
        if (i < mc)
        {
            m = movimiento_i(nivel - 1, i);
            switch( m )
            {// conjeturas 2 y 3
                case IA: m = IF ; break;
                case IF: m = IA ; break;
                case AI: m = FI ; break;
                case AF: m = FA ; break;
                case FI: m = AI ; break;
                case FA: m = AF ; break;
            }// conjeturas 2 y 3
        }
        else
        {
            m = movimiento_i(nivel, potencia2(nivel) - i);
            switch ( m )
            {//  conjetura 4
                case IA: m = AF ; break;
//              case IF: m = IF ; break;   no se usa porque m no cambia 
                case AI: m = FA ; break;
                case AF: m = IA ; break;
//              case FI: m = FI ; break;   no se usa porque m no cambia
                case FA: m = AI ; break;
            }//  conjetura 4
        }
    }

    return m ;
}

int main(int argc, char ** argv)
{
    int  nivel;
    char inicio;
    char fin;
    char auxiliar;
    int i;
    
    if (argc < 5){
        printf("\n   %s <nivel> <inicio> <fin> <auxiliar>\n\n",argv[0]);
        return 0;
    }
    
    sscanf(argv[1],"%d",&nivel);
    sscanf(argv[2],"%c",&inicio);
    sscanf(argv[3],"%c",&fin);
    sscanf(argv[4],"%c",&auxiliar);

    printf("%d: ",nivel);
    for (i=1 ; i<=potencia2(nivel)-1 ; i++)
    {
        switch( movimiento_i(nivel, i) )
        {
            case IA: printf("%c%c ",inicio,auxiliar); break;
            case IF: printf("%c%c ",inicio,fin); break;
            case AI: printf("%c%c ",auxiliar,inicio); break;
            case AF: printf("%c%c ",auxiliar,fin); break;
            case FI: printf("%c%c ",fin,inicio); break;
            case FA: printf("%c%c ",fin,auxiliar); break;
        }
    }
    putchar('\n');

    return 0;
}
