/*
Nome: Mateus de Carvalho Coelho
RA: 156675
Turma: R
*/

#include <stdio.h>

int main () {
    
    /* 
    Lista de variáveis:
    i - contador
    n - número de rodadas (limite do loop)
    js - número que representa a jogada de Sheldon
    jl - número que representa a jogada de Leonard
    ps - pontuação de Sheldon
    pl - pontuação de Leonard
    */    
    	
	int i, n, js, jl, ps, pl;
	
	i = 1;
	ps = 0;
	pl = 0;
	
	/* Entrada do número de RODADAS */
	
	scanf("%d", &n);

    /* Enquanto o contador for menor ou igual ao número de rodadas, o trecho 
    que lê as jogadas de Sheldon e Leonard e que testa os resultados se repetirá */
    
    while (i <= n) {
    
        /* Entrada dos números das JOGADAS */
        
        scanf("%d %d", &js, &jl);
        
        /* Os if's abaixo testarão cada rodada possível, imprimindo o resultado e adicionando
        uma unidade ao contador e à variável que conta a pontução do jogador ganhador */
        
        if ((js == 1) && (jl == 2)) {
        
            printf("Leonard: Papel embrulha Pedra\n");
            
            i += 1;
            pl += 1;
        
        }
    
        else if ((js == 2) && (jl == 1)) {
        
            printf("Sheldon: Papel embrulha Pedra\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 1) && (jl == 3)) {
        
            printf("Sheldon: Pedra quebra Tesoura\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 3) && (jl == 1)) {
        
            printf("Leonard: Pedra quebra Tesoura\n");
            
            i += 1;
            pl += 1;
        
        }
        
        else if ((js == 1) && (jl == 4)) {
        
            printf("Sheldon: Pedra amassa Lagarto\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 4) && (jl == 1)) {
        
            printf("Leonard: Pedra amassa Lagarto\n");
            
            i += 1;
            pl += 1;
        
        }
        
        else if ((js == 1) && (jl == 5)) {
        
            printf("Leonard: Spock vaporiza Pedra\n");
            
            i += 1;
            pl += 1;
        
        }
        
        else if ((js == 5) && (jl == 1)) {
        
            printf("Sheldon: Spock vaporiza Pedra\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 2) && (jl == 3)) {
        
            printf("Leonard: Tesoura corta Papel\n");
            
            i += 1;
            pl += 1;
        
        }
        
        else if ((js == 3) && (jl == 2)) {
        
            printf("Sheldon: Tesoura corta Papel\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 2) && (jl == 4)) {
        
            printf("Leonard: Lagarto come Papel\n");
            
            i += 1;
            pl += 1;
        
        }
        
        else if ((js == 4) && (jl == 2)) {
        
            printf("Sheldon: Lagarto come Papel\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 2) && (jl == 5)) {
        
            printf("Sheldon: Papel refuta Spock\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 5) && (jl == 2)) {
        
            printf("Leonard: Papel refuta Spock\n");
            
            i += 1;
            pl += 1;
        
        }
        
        else if ((js == 3) && (jl == 4)) {
        
            printf("Sheldon: Tesoura decepa Lagarto\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 4) && (jl == 3)) {
        
            printf("Leonard: Tesoura decepa Lagarto\n");
            
            i += 1;
            pl += 1;
        
        }
        
        else if ((js == 3) && (jl == 5)) {
        
            printf("Leonard: Spock quebra Tesoura\n");
            
            i += 1;
            pl += 1;
        
        }
        
        else if ((js == 5) && (jl == 3)) {
        
            printf("Sheldon: Spock quebra Tesoura\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 4) && (jl == 5)) {
        
            printf("Sheldon: Lagarto envenena Spock\n");
            
            i += 1;
            ps += 1;
        
        }
        
        else if ((js == 5) && (jl == 4)) {
        
            printf("Leonard: Lagarto envenena Spock\n");
            
            i += 1;
            pl += 1;
        
        }
        
        /* Em caso de empate, apenas será adicionado uma unidade ao contador */
        
        else {
                
            printf("Empate\n");
            
            i += 1;
                   
        }
        
    
    }	
	
	/* Saída do resultado da partida */
	
	printf("Sheldon %d x %d Leonard\n", ps, pl);
		
	return 0;
	
}


