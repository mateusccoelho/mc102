/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 05a - Caca ao tesouro.  
 */
 
#include <stdio.h>
 
int main () {
    
    int vetor[100], repeticoes[100];
    int tamanho, i, flag;
    
    /* Lista de variaveis
        vetor[100] - guarda os valores da sequencia de pistas.
        repeticoes[100] - guarda quantas vezes um dica foi utilizada.
        tamanho - numero de termos da sequencia de pistas.
        i - contador.
        flag - bandeira. 
    */
    
    /* Abaixo as variaveis sao zeradas. */ 
    
    i = 0;
    flag = 0;
    
    while (i < 100) {
    
        repeticoes[i] = 0;
        vetor[i] = 0;
        
        i++;
    
    }
    
    i = 0;
    
    /* Leitura de dados. */
    
    scanf ("%d", &tamanho);
    
    while (i < tamanho) {
    
        scanf ("%d", &vetor[i]); 
        
        i++;   
    
    }
    
    i = 0;
    
    /* Loop principal. Se a pista foi encontrada ou ela nao existe, flag = 1. Enquanto nao houver uma definicao sobre isso, flag = 0.*/
    
    while (flag == 0) {
    
        /* Se a posicao for igual ao valor da pista,flag sera 1 e sera impressa a posicao do tesouro. */
        
        if (i + 1 == vetor[i]) {
        
            flag = 1;
            
            printf ("Tesouro existe em %d\n", i + 1);
                        
        }

		/* Caso isso nao aconteca, o vetor que conta quantas vezes uma pista se repetiu sera acrescido em uma unidade. Se o numero
		   de repeticoes for maior do que 1, isto eh, se os indices estiverem sendo repetidos, isso indica que nao ha tesouro. 
		*/

        else {
        
            repeticoes[i]++;
            
            if (repeticoes[i] > 1) {
            
                printf ("Nao existe tesouro\n");
                
                flag = 1;
            
            }
            
            /* Mas, caso as pistas ainda estiverem se repetindo, o novo valor de i sera calculado para o proceguimento do loop. */
            
            else {
            	
            	i = vetor[i] - 1;        
            	
        	}
        
        }
    
    }
    
    /* Fim do loop principal. */
     
    return 0;
 
}
