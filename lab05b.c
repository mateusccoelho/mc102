/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 05b - Killing the messenger
*/


#include <stdio.h>

int main () {
    
    int r, o, aux, i, j, flag, primeirabase;
    char rna[101], oligo[26];
    
    i = 0;
    j = 0;
    flag = 0;
	
	/* Leitura de variaveis */
    
    scanf ("%d %d", &r, &o);
    scanf ("%s %s", rna, oligo);
    
    /* Na estrutura condicional abaixo verificaremos se a quantidade de bases do oligonucleotidio eh par ou impar,
	   Com base nisso, trocaremos a ordem das bases. */
    
    /* Se o oligonucleotidio tiver um numero impar de bases: */
    
    if (o % 2) {
    
        for (j = 0; j < (o / 2); j++) {
        
            aux = oligo[j];
            oligo[j] = oligo[o - 1 - j];
            oligo[o - 1 - j] = aux;  
        
		}
        
    }
    
    /* Se o oligonucleotidio tiver um numero par de bases: */
    
    else {
    
        for(j = 0; j <= ((o / 2) - 1); j++) {
        
            aux = oligo[j];
            oligo[j] = oligo[o - 1 - j];
            oligo[o - 1 - j] = aux;
        
        }
    
    }
    
    /* Agora, o codigo abaixo convertera o oligonucleotidio invertido com o seu correspondente, trocando as bases. */
    
    for (j = 0; j < o; j++) {
    
        switch (oligo[j]) {
            case 'A':
            
                oligo[j] = 'U';
            	break;
            
            
            case 'U':
            
                oligo[j] = 'A';
            	break;
            
            
            case 'G':
            
                oligo[j] = 'C';
            	break;
            
            
            case 'C':
            
                oligo[j] = 'G';
            	break;
        
		}
    
    } 
    
    /* O bloco de comandos abaixo verificara se o mRNA pode ser silenciado. A variavel flag sera 0 enquanto a verificacao estiver 
	   sendo feita e sera 1 quando houver um resultado. */
    
    i = 0;
    j = 0;
	
	while (flag == 0) {
    
        /* O condicional abaixo limitara ate que ponto a leitura do mRNA pode ser feita. Se o contador i for maior que (r - o), pode-se
		   considerar que nao ha silenciamento. */
		
		if (i <= r - o) {
        
        	/* No codigo abaixo, a primeira base do mRNA e do oligonucleotidio serao verificadas. Caso nao seja igual,
			   os contadores serao modificados para dar sequcnia aa verificacao do mRNA. A variavel primeirabase gravara a posicao
			   da primeira base do mRNA igual aa do oligonucleotidio. */
			
			if (rna[i] == oligo[j]) {
        	
        		primeirabase = i;
        		
        		/* O loop abaixo verificara o se o resto do oligonucleotidio eh igual ao mRNA*/
				
				do {
        		
        			i++;
        			j++;
        			
        		} while (rna[i] == oligo[j] && j < o);
        	
        		/* O condicional abaixo verificara se o oligonucleotidio foi totalmente analisado. Caso nao seja igual,
			       os contadores serao modificados para dar sequcnia aa verificacao do mRNA. */
				
				if (j == o) {
        		
        			printf("Silenciado em %d\n", primeirabase + 1);
        			flag = 1;
        		
        		}
        		
        		else {
        		
        			j = 0;
        			i = primeirabase + 1;
        				
        		}
        	
        	}
        	
        	else {
        	
        		i++;
        		j = 0;
        	
        	}
        
        }
        
        else {
        
        	printf("Nao silenciado\n");
        	flag = 1;

        }
		    
    }

	return 0;

}

