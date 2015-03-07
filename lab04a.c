/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
*/


#include <stdio.h>

int main () {

    int i, n, posicao, soma, j; 
    int senha[15];
    
    /* Lista de variaveis
       senha[15] - vetor que armazena os digitos da senha.
       soma - soma dos valores das multiplicacoes.
       posicao - posicao do digito na senha. 
       n - quantidade de numeros dados inicialmente.
       i - contador
       j - contador   
    */
   
    /* Declaracao inicial de variaveis. */
    
    i = 0;
    j = 0;
    soma = 0;
    posicao = 1;
   
    /* No loop abaixo o vetor senha tem seus valores zerados. */   
   
    while (i < 15) {
        
        senha[i] = 0;
        
        i += 1;
        
    }
    
    i = 0;
    
    /* Leitura da quantidade de valores iniciais dados. */
    
    scanf ("%d", &n);
    
    /* O loop abaixo faz a leitura dos digitos da senha inicialmente dados. */
    
    while (i < n) {
        
        scanf ("%d", &senha[i]);
        
        i += 1;
        
    }
    
    i = 0;
    
    /* O loop do-while abaixo engloba as operacoes matematicas responsaveis por calcular o valor do proximo digito da senha. Ele acaba quando o decimo quinto valor for encontrado e o contador j for igual a 15. */
    
    do {   
        
        /* O bloco a seguir faz a soma das multiplicacoes de cada digito. A variavel posicao serve para dizer qual a posicao do numero na senha. EX: 657. O digito 5 esta no posicao 2. */
        
        while (i < (n + j)) {
        
            soma = soma + (posicao * (n + j) * senha[i]);

            i += 1;
        
            posicao += 1;
        
        }
  
    
        /* A estrutura condicional abaixo calcula o resto da divisao de soma por 11 e atribui um valor para o proximo digito da senha. */
        
        if ((soma % 11) == 10) {
        
            senha[n + j] = 0;
        
        }
    
        else {
        
            senha[n + j] = soma % 11;
            
        }
        
        /* Abaixo algumas variaveis sao atualizadas para o prosseguimento do loop. */
        
        i = 0;
        
        j += 1;
        
        soma = 0;
        
        posicao = 1;
        
    
    } while ((n + j) < 15);
    
    
    /* Imprime a senha completa.  */
    
    while (i < 15) {
    
        printf("%d", senha[i]);
        
        i += 1;
    
    }
    
    printf("\n");

return 0;

}

