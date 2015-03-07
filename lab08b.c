/* 
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 08b - Processamento de imagens.
*/

#include <stdio.h>
#include <string.h>

/* Definindo tamanho maximo das imagens */
#define MAX_TAM 400

/* Le uma imagem em formato PGM a partir da entrada padrao.
 * Retorna 1 se a leitura for realmente de um arquivo PGM
 * e 0 caso contrario.
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO                       */
int ler_pgm(int img[][MAX_TAM], int *W, int *H, int *MaxV,
            int *F, double *Px, double *Py) {
    char nome_formato[3];
    char c;
    int i,j;

    /* Le o formato da imagem. P2 indica o formato PGM */
    scanf("%s ", nome_formato);
    if (strcmp(nome_formato, "P2") != 0)
        return 0;

    /* Le o '#', que indica um comentario, e os numeros indicando
    * o filtro e o parametro, se houver */
    scanf("%[#]c", &c);
    scanf("%d", F);
    if (*F == 4) {
        scanf("%lf %lf", Px, Py);
    } 
 
    /* Le dimensoes e intensidade maxima da imagem */
    scanf("%d", W);
    scanf("%d", H);
    scanf("%d", MaxV);
 
    /* Le o valor de cada pixel da imagem */
    for (i = 0; i < (*H); i++) {
        for (j = 0; j < (*W); j++) {
            scanf("%d", &img[i][j]);
        }
    }

    return 1;
}

/* Escreve a imagem em formato pgm na saida padrao 
 * VOCE NAO DEVE ALTERAR ESTA FUNCAO               */
void escrever_pgm(int img[][MAX_TAM], int W, int H, int MaxV) {
    int i, j;

    /* Escreve os atributos da imagem */
    /* Tipo da imagem: P2 significa pgm*/
    printf("P2\n");
    /* Dimensoes e intensidade maxima da imagem */
    printf("%d %d %d\n", W, H, MaxV);

    /* Escreve os pixels da imagem */
    for (i = 0; i < H; i++) {
        printf("%d", img[i][0]);
        for (j = 1; j < W; j++) {
            printf(" %d", img[i][j]);
        }
        printf("\n");
    }
}

/* Negativo */
void negativo(int img[][MAX_TAM], int W, int H, int MaxV) {
    
    /* I e J sao contadores que percorrem as linhas e as colunas da matriz. O 
       loop percorre todas as posicoes da matriz e realiza a subtracao que
       aplica o filtro. */
    
    int i, j;
	
	for(i = 0; i < H; i++)
		for(j = 0; j < W; j++)
			img[i][j] = MaxV - img[i][j];
			
}

/* Rotacao de 180 graus */
void rotacao180(int img[][MAX_TAM], int W, int H) {
   
  	/* AUX eh uma variavel que guarda o valor de uma intensidade para realizar a
  	   troca com outra intensidade. */
  
   int i, j, aux;
	
	/* As estruturas abaixo fazem as trocas dos valores e se a quantidade de
	   linhas for impar, tambem troca a posicao do valores da linha central. */
	
	for(i = 0; i < H/2; i++)
		for(j = 0; j < W; j++) {
			aux = img[i][j];
			img[i][j] = img[H - 1 - i][W - 1 - j];
			img[H - 1 - i][W - 1 - j] = aux;
		}
	if(H % 2)		
		for(j = 0; j < W/2; j++) {
			aux = img[H/2][j];
			img[H/2][j] = img[H/2][W - 1 - j];
			img[H/2][W - 1 - j] = aux;
		}
		
}

/* Deteccao de bordas */
void detectaBorda(int img[][MAX_TAM], int W, int H, int MaxV) {
    
    /* O vetor RESULTADO guarda os valores das novas intensidades calculadas.*/
    
    int i, j, resultado[398][398];
	
	/* As estruturas abaixo tem como funcao percorrer a matriz calculando os 
	   novos valores de intensidade e verificando estao entre 0 e MaxV. Por fim
	   a matriz resultado eh copiada na matriz IMG. */
	
	for(i = 1; i < H - 1; i++)
		for(j = 1; j < W - 1; j++) {
			resultado[i - 1][j - 1] = 20 * img[i][j];
			resultado[i - 1][j - 1] += (-1 * img[i - 1][j - 1]) + (-1 * img[i - 1][j + 1]) + (-1 * img[i + 1][j - 1]) + (-1 * img[i + 1][j + 1]);
			resultado[i - 1][j - 1] += (-4 * img[i - 1][j]) + (-4 * img[i][j - 1]) + (-4 * img[i + 1][j]) + (-4 * img[i][j + 1]);
			if(resultado[i - 1][j - 1] < 0)
				resultado[i - 1][j - 1] = 0;
			if(resultado[i - 1][j - 1] > MaxV)
				resultado[i - 1][j - 1] = MaxV;
		}
		
	for(i = 1; i < H - 1; i++)
		for(j = 1; j < W - 1; j++)
			img[i][j] = resultado[i - 1][j - 1];
	
}

/* Cisalhamento */
void cisalhamento(int img[][MAX_TAM], int W, int H, double Px, double Py) {  
    
    /* NI e NJ guardam os novos valores da linha e coluna de uma intensidade. */
    
    int i, j, ni, nj, resultado[400][400];
	
	/* As estruturas abaixo tem como funcao zerar a matriz RESULTADO, calcular
	   os novas coordenadas e aplica-las aa matriz RESULTADO, alem de copiar
	   a matriz resultado na matriz IMG. */
	
	for(i = 0; i < H; i++)
		for(j = 0; j < W; j++)
			resultado[i][j] = 0;
	
	for(i = 0; i < H; i++)
		for(j = 0; j < W; j++) {
			ni = i + (Py * j);
			nj = j + (Px * i);
			if(ni < H && nj < W)
				resultado[ni][nj] = img[i][j];
		}
		
	for(i = 0; i < H; i++)
		for(j = 0; j < W; j++)
			img[i][j] = resultado[i][j];
		
}


/* VOCE NAO DEVE ALTERAR A FUNCAO PRINCIPAL */
int main() {
    /* Matriz que armazena os pixels da imagem */
    int img[MAX_TAM][MAX_TAM]; 
    /* Atributos da imagem */
    int W, H, MaxV;
    /* Identificador do filtro a ser utilizado */
    int F;
    /* Parametro a ser passado para o cisalhamento */
    double Px, Py;

    /* Le a imagem */
    if (ler_pgm(img, &W, &H, &MaxV, &F, &Px, &Py) != 1) {
        printf("Error: nao foi possivel ler a imagem\n");
        return 0;
    }
 
    /* Seleciona o filtro */
    switch (F) {
        case 1:
            negativo(img, W, H, MaxV);
            break;
        case 2:
            rotacao180(img, W, H);
            break;
        case 3:
            detectaBorda(img, W, H, MaxV);
            break;
        case 4:
            cisalhamento(img, W, H, Px, Py);
            break;
    }

    /* Escreve a imagem */
    escrever_pgm(img, W, H, MaxV);

    return 0;
}
