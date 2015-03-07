#include <stdio.h>
#include <stdlib.h>

int verificarBarra(int *flag) {
	int i, barra[4];
	
	/* O for abaixo le os pesos e a distancia de uma barra e os grava num vetor. */
	for(i = 0; i < 4; i++)
		scanf("%d", &barra[i]);
	
	/* Se o peso da esquerda for 0, isto eh, se na extremidade de uma
	   barra existir uma outra barra, a funcao vai ser executada
	   ate o peso ser determinado. */
	if(barra[0] == 0)
		barra[0] = verificarBarra(flag);
	
	/* A estrutura abaixo faz o mesmo que a anterior, mas para o lado
	   direito. */
	if(barra[2] == 0)
		barra[2] = verificarBarra(flag);

	/* O codigo abaixo sera executado quando os pesos dos dois lados forem
	   determinados. Sera verificado se a barra esta equilibrada e a massa
	   dos pesos da barra sera determinado. Flag sera igual a 0 quando o 
	   mobile estiver equilibrado e sera igual a 1 quando o mobile estiver
	   desequilibrado.*/
	if(barra[0] * barra[1] != barra[2] * barra[3])
		*flag = 1;
	return barra[0] + barra[2];	
}

/* A funcao main sera responsavel por imprimir a saida e executar a funcao
   verificarBarra pela primeira vez. */
int main () {
	int flag = 0, peso;
	
	peso = verificarBarra(&flag);
	 
 	if(flag == 0)
 		printf("Mobile equilibrado\n");
 	else
 		printf("Mobile desequilibrado\n");
 	
 	printf("Peso total: %d\n", peso);
 	
 return 0;	
}
