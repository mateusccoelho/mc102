/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
Lab 10a - LSCrypto
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    /*
    texto - matriz que armazena o texto.
    letras - vetor que armazena os caracteres do alfabeto
    I, J e P - sao contadores.
    alfabeto - vetor que armazena a quantidade de ocorrencias de cada letra.
    */
    
    char texto[15][501], letras[26];
    int i, j, n, p, alfabeto[26], indice_escolhido, aux, indice_letra;
    
    /* Abaixo os vetores sao incializados, a leitura da matriz texto eh feita e
       o numero de linhas eh lido. */
    
    scanf("%d\n", &n);
    
    for(i = 0; i < 26; i++)
        alfabeto[i] = 0;
        
    for(i = 0; i < 26; i++)
        letras[i] = 97 + i;
    
    for(i = 0; i < n; i++) {
        fgets(texto[i], 501, stdin);
    
        /* No trecho abaixo, o programa conta a ocorrencia das letras no vetor
           alfabeto. */
        
        for(j = 0; texto[i][j]; j++) {
            if (texto[i][j] >= 65 && texto[i][j] <= 90)
                alfabeto[texto[i][j] - 65]++;
                if(texto[i][j] >= 97 && texto[i][j] <= 122)
                alfabeto[texto[i][j] - 97]++;    
        }        
    }

    /* Apos contar as ocorrencias, o vetor alfabeto eh ordenado de forma
       crescente, ao mesmo tempo que as os caracteres do vetor letras, sao mudados
       tambem. Assim pode-se ter uma correspondencia entre o numero de ocorrencia
       a letra. */
    
    for (i = 0; i < 25; i++) { 
        indice_escolhido = i;
        for (j = (i + 1); j < 26; j++) {
              if(alfabeto[j] > alfabeto[indice_escolhido])
                   indice_escolhido = j;
            else if(alfabeto[j] == alfabeto[indice_escolhido])
                if(letras[j] < letras[indice_escolhido])
                    indice_escolhido = j;
        }
        if (i != indice_escolhido) {
              aux = alfabeto[i];
             alfabeto[i] = alfabeto[indice_escolhido];
            alfabeto[indice_escolhido] = aux;
            aux = letras[i];
             letras[i] = letras[indice_escolhido];
            letras[indice_escolhido] = aux;
          }
      }
    
   	/* Essa parte do codigo faz a mudanca das letras no texto, para deixa-lo
   	   criptogrado. Para isso, o codigo ve se a letra a ser trocada eh maiuscula
   	   ou minuscula e se a mudancao da letra tem de ser feita pra esquerda ou pra
   	   direita. */
   
    for(i = 0; i < n; i++)
        for(j = 0; texto[i][j] ; j++) {
            if(texto[i][j] >= 97 && texto[i][j] <= 122) {
                for(p = 0; p < 26; p++)
                    if(texto[i][j] == letras[p])
                        indice_letra = p;
                if(indice_letra % 2)
                    texto[i][j] = letras[indice_letra - 1];
                else
                    texto[i][j] = letras[indice_letra + 1];
            }        
            else if (texto[i][j] >= 65 && texto[i][j] <= 90) {
                for(p = 0; p < 26; p++)
                    if(texto[i][j] + 32 == letras[p])
                        indice_letra = p;
                if(indice_letra % 2)
                    texto[i][j] = letras[indice_letra - 1] - 32;
                else
                    texto[i][j] = letras[indice_letra + 1] - 32;
            }
        }
        
    /* Finalmente, a parte abaixo do codigo imprime o texto. */
    
    for(i = 0; i < n; i++)
        printf("%s", texto[i]);
        
        

return 0;
}
