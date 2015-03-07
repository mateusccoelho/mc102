/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
*/


#include <stdio.h>

/* Declaracao de constantes. Para cada letra ha um numero correspondente. */

#define A 1
#define B 0.5
#define C 0.25
#define D 0.125
#define E 0.0625
#define F 0.03125
#define G 0.015625
#define H 0.0078125

int main () {

    /*
    Lista de variaveis
    c - caractere
    letras - somas das letras em cada linha
    soma - soma do valor das letras em cada linha
    */
    
    char c;
    int letras;
    double soma;
    
    soma = 0;
    letras = 0;
    
    do {
    
        /* Leitura do caractere, soma do valor do caractere na variavel "soma" e soma do digito na variavel "letras". */
        
        do {
    
            scanf("%c", &c);
        
            if (c == 'A') {
        
                soma = soma + A;
            
            }               
        
            else if (c == 'B') {
        
                soma = soma + B;

            }
        
            else if (c == 'C') {
        
                soma = soma + C;

            }
        
            else if (c == 'D') {
        
                soma = soma + D;

            }
        
            else if (c == 'E') {
        
                soma = soma + E;
        
            }
        
            else if (c == 'F') {
        
                soma = soma + F;
            
            }
        
            else if (c == 'G') {
        
                soma = soma + G;

            }
        
            else if (c == 'H') {
        
                soma = soma + H;
            
            }
                
            if (c != '\n') {
            
            letras = letras + 1;
            
            }       
                
                               
        } while ((c != '\n') && (c != '*'));
        
        
        /* Caso a soma seja 1, sera impresso a quantidade de caracteres na linha. Caso a  soma seja diferente de 0, sera impresso o numero 0. */
        
        if (soma == 1) {
        
            printf("%d", letras);
        
        }
        
        else {
        
            if (c != '*') {
               
                printf("0");
                
            }
        
        }
        
        soma = 0;
        letras = 0;
        
   } while (c != '*');  

   printf("\n");  
                  
return 0;

}
