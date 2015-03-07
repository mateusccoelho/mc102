/* Laboratorio 01b
Nome: Mateus de Carvalho Coelho
RA: 156675
*/

#include <stdio.h>

int main () {
	
	/* 
	Lista de Variaveis 
	
	a - Area do andidato
	nmo - Nota minima de opcao
	pcg - Peso Conhecimentos Gerais e Redação (1ª fase)
    pin - Peso Língua Inglesa
    ppo - Peso Língua Portuguesa
    pma	- Peso Matemática
    pch	- Peso Ciências Humanas e Artes
    pcn - Peso Ciências da Natureza
	ncg - Nota conhecimentos gerais
	mcg - Media conhecimentos gerais
	dpcg - Desvio padrao conhecimentos gerais
	nin - Nota ingles
	min - Media ingles
	dpin - Desvio padrao ingles
	npo - Nota portugues
	mpo - Media portugues
	dppo - Desvio padrao portugues
	nma - Nota matematica
	mma - Media matematica
	dpma - Desvio padrao matematica
	nch - Nota ciencias humanas
	mch - Media ciencias humanas
	dpch - Desvio padrao ciencias humanas
	ncn - Nota ciencias da natureza
	mcn - Media ciencias da natureza
	dpcn - Desvio padrao ciencias da natureza
	npcg - Nota padronizada conhecimentos gerais
	npin - Nota padronizada ingles
	nppo - Nota padronizada portugues
	npma - Nota padronizada matematica
	npch - Nota padronizada ciencias humanas
	npcn - Nota padronizada ciencias da natureza
	nf - Nota final (segunda fase)
	
	*/
	
	int a, nmo;
	double pcg, pin, ppo, pma, pch, pcn, ncg, mcg, dpcg;
	double nin, min, dpin, npo, mpo, dppo, nma, mma, dpma, nch, mch, dpch, ncn, mcn, dpcn;
	double npcg, npin, nppo, npma, npch, npcn;
	double nf;
	
	/* Entrada de dados inicial */
	
	scanf("%d %d", &a, &nmo);
	scanf("%lf %lf %lf %lf %lf %lf", &pcg, &pin, &ppo, &pma, &pch, &pcn);
	scanf("%lf %lf %lf", &ncg, &mcg, &dpcg);
	
	/* Calculo da nota padronizada de conhecimentos gerais */
	
	npcg = ( ( (ncg - mcg) * 100) / dpcg ) + 500;
	
	/* Estrutura condicional: passou ou nao */
	
	if (npcg >= 550.0) {
		
		/* Entrada das notas, medias e desvios da segunda fase */
	
		scanf("%lf %lf %lf", &nin, &min, &dpin);	
		scanf("%lf %lf %lf", &npo, &mpo, &dppo);
		scanf("%lf %lf %lf", &nma, &mma, &dpma);
		scanf("%lf %lf %lf", &nch, &mch, &dpch);
		scanf("%lf %lf %lf", &ncn, &mcn, &dpcn);
		
		/* Calculo das notas padronizadas da segunda fase */
		
		npin = ( ( (nin - min) * 100) / dpin ) + 500;
		nppo = ( ( (npo - mpo) * 100) / dppo ) + 500;
		npma = ( ( (nma - mma) * 100) / dpma ) + 500;
		npch = ( ( (nch - mch) * 100) / dpch ) + 500;
		npcn = ( ( (ncn - mcn) * 100) / dpcn ) + 500;
		
		
		/* Calculo da nota final (segunda fase) do vestibular */
		
		nf = ( (pcg * npcg) + (pin * npin) + (ppo * nppo) + (pma * npma) + (pch * npch) +  (pcn * npcn) ) / (pcg + pin + ppo + pma + pch + pcn);
		
		/* Saída do resultado final*/
		
		printf("Primeira Fase: %.1f\n", npcg);
		printf("Segunda Fase: %.1f\n", nf);
		
			/* Verificacao do grupo */
			
			if (a == 1) {
				if ( (npma >= nmo) && (npcn >= nmo) ) {
					
					printf("Grupo 1\n");
					
				}
				else {
					
					printf("Grupo 2\n");
					
				}
			}
			else if (a == 2) {
				if ( (nppo >= nmo) && (npch >= nmo) ) {
					
					printf("Grupo 1\n");
					
				}
				else {
					
					printf("Grupo 2\n");
					
				}
			}
			else {
				if (npcn >= nmo) {
					
					printf("Grupo 1\n");
					
				}
				else {
					
					printf("Grupo 2\n");
					
				}
				
			}
	
	
	}
	
	else {
		
		printf("Primeira Fase: %.1f\n", npcg);
	} 
	
	
return 0;
		
}
