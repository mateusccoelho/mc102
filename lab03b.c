/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab03b - Fringe
*/

#include <stdio.h>

int main () {

    int conta, contb, repeticoes, num, s, m, pt, padrao, df;
    
    /* Lista de variaveis: 
		conta - contador A.
		contb - contador B (vai receber sempre o valor de A).
		repeticoes - numero de vezes que uma fase se repete.
		num - numero da sequencia.
		pt - primeiro termo de uma fase.
		padrao - duracao de uma fase.
		df - duracao de uma fase.
		s - numero de vezes que as fases iguais tem de repetir seguidamente
		m - numero de mols por segundo
	*/
    
    contb = 0;
	repeticoes = 0;
    
	/* Leitura de dados inicial */  
    
	scanf("%d %d", &m, &s);
    scanf("%d", &num);
    
    /* Devemos atribuir o valor do primeiro termo da sequencia a "pt" para comparar com os proximos numeros da sequencia. */    
    
    pt = num;
    
    /* Para ignorar a primeira fase de 0s ou 1s, se o numero atual for igual ao primeiro termo da sequencia, eh solicitado mais valores */   

	while (num == pt) {
   	
   		scanf("%d", &num);
   	
   	}
   	
   	/* Se o valor for diferente, um loop sera iniciado, o qual acaba quando o numero lido "num" for igual a -1. */
	
	while (num != -1) {
		
		/* Se o numero lido for igual ao primeiro termo, o contador A é aumentado em 1 unidade */
		
		if (num == pt) {
			
			conta += 1;
			
		}
		
		/* Se o numero lido for diferente do primeiro termo, eh verificado se o contador atual (conta) eh igual ao contador da fase anterior (contb).
		   A variavel padrao ira sempre guardar a duracao da fase, para que apenas fases de mesma duracao possam ser computadas na variavel repeticoes.
		   Se a sequencia tiver fases seguidas iguais, mas de duracao diferente, o padrao sera mudado e a variavel repeticoes tera o valor 1. 
		 */
		
		else {
				
			if (contb == conta) {
				
				if (repeticoes > 0) {
									
					if (conta == padrao) {
						
						repeticoes += 1;
						
					}
					
					else {
						
						repeticoes = 1;
						padrao = conta;
						
					}
						
				}
				
				else {
					
					repeticoes = 1;
					padrao = conta;
					
				}
				
		}
			
			/* O if abaixo salva a duracao das fases iguais. */
			
			if ((repeticoes + 1) == s) {
				
				df = conta;
				
			}
 		
			/* Abaixo os contadores e o primeiro termo sao atualizados para o prosseguimento do loop caso aconteca uma mudanca de fase. */
		
			contb = conta;
			
			pt = num;
			
			conta = 1;
			
		}
	
		/* Leitua do proximo numero da sequencia. */
		
		scanf("%d", &num);
	
	}
    
	/* Abaixo eh adicionada uma unidade a variavel repeticoes porque sempre na primeira comparacao de duracao de fases, a primeira fase nunca eh considerada. */
	    
    repeticoes += 1;
    
    /* Eh feita a verificacao se o numero de repeticoes foi igual a s. Caso seja igual, o numero de mols transportado eh calculado. */
	
	if (repeticoes >= s) {
    	
    	printf ("%d mols\n", m * df);    	
    	
    }
    
    else {
    	
    	printf ("Portal nao abriu\n");
    	
    }

return 0;

}
