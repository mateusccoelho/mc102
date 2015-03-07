/* Laboratorio 12b - Whiteworse
 * Autor: Mateus de Carvalho Coelho
 * RA: 156675
 * Turma: R
 * e-mail: ra156675@ic.unicamp.br
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNOME 21
#define MAXNOMEARQ 101
#define MAXCONTAS 20
#define MAXTRANS 40
#define TAXA 5.00

struct Conta {
    int ag;
    int cc;
    char titular[MAXNOME];
    double saldo;
};

typedef struct Conta Conta;

struct Transacao {
    char tipo;
    int ag;
    int cc;
    double valor;
};

typedef struct Transacao Transacao;

int main(int argc, char **argv) {
    char nomeArqConta[MAXNOMEARQ];
    char nomeArqTrans[MAXNOMEARQ];
    char nomeArqSaida[MAXNOMEARQ];
    int n_contas, n_trans, i, j, flag;    
    Conta *contas;
    Transacao *transacoes;
    FILE *entrada, *trans, *saida;
    strcpy(nomeArqConta, argv[1]);
    strcpy(nomeArqTrans, argv[2]);
    strcpy(nomeArqSaida, argv[3]);
    
    entrada = fopen(nomeArqConta, "rb");
    trans = fopen(nomeArqTrans, "rb");
    saida = fopen(nomeArqSaida, "wb");
    
    /* Leitura da quantidade de contas do arquivo de entrada. */
    fread(&n_contas, sizeof(int), 1, entrada);

    /* Alocacao do vetor de contas. */
    contas = malloc(n_contas * sizeof(Conta));
    
    /* Leitura e armazenamento das informacoes do arquivo contas nos registros. */
    for(i = 0; i < n_contas; i++)
    	fread(&contas[i], sizeof(Conta), 1, entrada);
   	
   	/* Leitura da quantidade de transacoes realizadas. */
   	fread(&n_trans, sizeof(int), 1, trans);
    
    /* Alocacao do vetor de transacoes */
    transacoes = malloc(n_trans * sizeof(Transacao));
    
    /* Leitura e armazenamento das informacoes do arquivo transacoes nos registros. */
    for(i = 0; i < n_trans; i++) 
    	fread(&transacoes[i], sizeof(Transacao), 1, trans);
    
    /* O trecho abaixo roda todas as transacoes realizando as operacoes. */
    for(i = 0; i < n_trans; i++) {
    	/* O trecho abaixo eh executado quando a transacao eh um deposito. O valor da transacao
    	   eh somado ao saldo da conta e eh impressa a transacao na entrada padrao, caso seja 
    	   valida. */
    	if(transacoes[i].tipo == 'D')
    		for(j = 0, flag = 0; j < n_contas && flag == 0 ; j++) {
    			if(contas[j].ag == transacoes[i].ag && contas[j].cc == transacoes[i].cc) {
    				contas[j].saldo += transacoes[i].valor;
    				printf("T%d: %c %d %d %.2f\n", i, transacoes[i].tipo, transacoes[i].ag, transacoes[i].cc, transacoes[i].valor);
    				flag = 1;	
    			}
    		}
    	else
    		/* O trecho abaixo eh executado quando a transacao eh um saque. Caso as condicoes
    		   para o saque sejam respeitadas, o valor do saldo sera decrescido no valor da transacao. 
    		   Caso a transacao seja valida, sera impressa na saida padrao as informacoes da transacao. */
    		for(j = 0, flag = 0; j < n_contas && flag == 0; j++)
    			if(contas[j].ag == transacoes[i].ag && contas[j].cc == transacoes[i].cc)
    				if(contas[j].saldo > 0 && contas[j].saldo - transacoes[i].valor > -100.0) {
    					contas[j].saldo -= transacoes[i].valor;
    					if(contas[j].saldo < 0)
    						contas[j].saldo -= TAXA;
    					printf("T%d: %c %d %d %.2f\n", i, transacoes[i].tipo, transacoes[i].ag, transacoes[i].cc, transacoes[i].valor);
    					flag = 1; 
    				}
    }
    
    /* Impressao dos registros das contas bancarias no arquivo binario de saida. */
    fwrite(&n_contas, sizeof(int), 1, saida);
    for(i = 0; i < n_contas; i++)
    	fwrite(&contas[i], sizeof(Conta), 1, saida);
    	    
	free(contas);
	free(transacoes);
	fclose(entrada);
	fclose(trans);
	fclose(saida);

    return 0;
}
