#include <stdio.h>

int main () {

	/* n - numero de linhas e colunas.
	   u - numero da linha a ser analisada.
	   j - contador das colunas da matriz.
	   i - contador das linhas da matriz e da linha do vetor resultado.
	   p - outro contador de colunas da matriz.
	   k - conta quantas flag=0 existem no vetor resultado. 
	   matriz- matriz com os valores da entrada.
	   resultado - matriz que contem varias flags que indicam se se a pessoa da 
	               posicao I do vetor eh amigo do amigo de U. */
	
	int n, u, j, i, p, k = 0, matriz[100][100], resultado[100];
	
	/* Abaixo eh feita a leitura da entrada do programa e a matriz resultado eh
	   zerada. */
	
	scanf("%d %d", &n, &u);
	
	for(i = 0; i < n; i++)
		resultado[i] = 0;
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &matriz[i][j]);
			
	/* A estrutura abaixo tem como obejtivo encontrar os amigos dos amigos de U.
	   Para isso, primeiro o loop percorre a linha U em procura de amigos. Quando um 
	   amigo eh achado, a linha do amigo encontrado tambem eh percorrida
	   procurando por amigos. Quando um amigo eh achado, eh colocado o valor 1 no
	   vetor resultado, o qual indica que para essa posicao existe um amigo do
	   amigo de U. O valor 0 indica que a pessoa nao eh amigo do amigo de U.*/
	
	for (j = 0; j < n; j++)
		if (matriz[u][j] == 1 && j != u)
			for(p = 0; p < n; p++)
				if(matriz[j][p] == 1 && p != j && p != u && matriz[u][p] == 0)
					resultado[p] = 1;
				
	/* O loop abaixo conta quantas pessoas nao sao amigos dos amigos de U. */
	
	for(i = 0; i < n; i++)
		if (resultado[i] == 0)
			k++;
	
	/* As estruturas condicionais abaixo tem como objetivo imprimir a saida
	   dependendo do valor de k. Se ninguem for amigo do amigo de U, entao a
	   mensagem "Sem sugestao de novos amigos" sera impressa. Se houverem amigos
	   de amigos de U (k > 0), entao estes serao impressos. */
	
	if(k == n)
		printf("Sem sugestao de novos amigos\n");
	else {
		printf("Sugestao de amigos:");
		for(i = 0; i < n; i++)
			if(resultado[i] == 1)
				printf(" %d", i);
		printf("\n");
	}
		

return 0;
}
