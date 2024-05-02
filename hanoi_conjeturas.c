#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char ** argv)
{
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
    
    int8_t * m;
    int movimientos;
    int mc;  // movimiento central
    int i;
    int j;
    
    if (nivel == 1) { printf("1: %c%c",inicio,fin); }
    else
    {
        movimientos = 0;
        m = (int8_t*) malloc ( sizeof(int8_t) * (potencia2(nivel)-1) );
        m[0] = IF;
    
        for (i=2; i<=nivel ; i++)
        {
            // conjeturas 2 y 3
            for (j=0 ; j<=movimientos ; j++)
            {
                switch( m[j] )
                {
                    case IA: m[j] = IF; break;
                    case IF: m[j] = IA; break;
                    case AI: m[j] = FI; break;
                    case AF: m[j] = FA; break;
                    case FI: m[j] = AI; break;
                    case FA: m[j] = AF; break;
                }
            }// conjeturas 2 y 3
            
            movimientos = potencia2(i)-1-1;
            mc = potencia2(i-1)-1 ;
            m[mc] = IF ;
                
            // conjetura 4                
            for (j=0 ; j<mc ; j++)
            {
                switch( m[j] )
                {
                    case IA: m[2*mc - j] = AF; break;
                    case IF: m[2*mc - j] = IF; break;
                    case AI: m[2*mc - j] = FA; break;
                    case AF: m[2*mc - j] = IA; break;
                    case FI: m[2*mc - j] = FI; break;
                    case FA: m[2*mc - j] = AI; break;
                }
            }// conjetura 4
        }
        
        printf("%d: ",nivel);
        for (i=0 ; i<=movimientos ; i++)
        {
            switch(m[i])
            {
                case IA: printf("%c%c ",inicio,auxiliar); break;
                case IF: printf("%c%c ",inicio,fin); break;
                case AI: printf("%c%c ",auxiliar,inicio); break;
                case AF: printf("%c%c ",auxiliar,fin); break;
                case FI: printf("%c%c ",fin,inicio); break;
                case FA: printf("%c%c ",fin,auxiliar); break;
            }
        }

    }
    
    putchar('\n');
    free(m);
    return 0;
}
