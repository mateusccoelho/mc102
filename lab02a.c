/* 
   Nome: Mateus de Carvalho Coelho
   RA: 156675
 */
 
#include <stdio.h>
 
int main () {
 
    /* 
    Lista de variaveis
    d - numero de dependentes[
    s - salario bruto 
    base - base para calculo do irpf
    inss - valor do imposto do inss
    base_irpf_trib1 - valor de base para o calculo do irpf no ultimo intervalo
    base_irpf_trib2 - valor de base para o calculo do irpf no penultimo intervalo
    base_irpf_trib3 - valor de base para o calculo do irpf no segundo intervalo
    base_irpf_trib4 - valor de base para o calculo do irpf no primeiro intervalo
    tributo1 - valor do imposto irpf do ultimo intervalo
    tributo2 - valor do imposto irpf do penultimo intervalo
    tributo3 - valor do imposto irpf do segundo intervalo
    tributo4 - valor do imposto irpf do primeiro intervalo
    tributo_total - valor total do imposto irpf a ser descontado
     */
 
    int d;
    double s, base, inss;
    double base_irpf_trib1, base_irpf_trib2, base_irpf_trib3, base_irpf_trib4;
    double tributo1, tributo2, tributo3, tributo4, tributo_total;
    
    /* Entrada de dados */
 
    scanf("%lf %d", &s, &d);
    
      /* Calculo do valor do imposto inss. para cada intervalo o valor eh diferente */
      
      if (s <= 1317.07) {
    
        inss = 0.08 * s;
    
    }
    
    else if ((s >= 1317.08) && (s <= 2195.12)) {
    
        inss = 0.09 * s;
    
    }
    
    else if ((s >= 2195.13) && (s <= 4390.24)) {
    
        inss = 0.11 * s;    
    
    }
    
    else {
    
        inss = 482.93;
    
    }
    
    /* calculo da base */
    
    base = s - inss - (d * 179.71);
    
    /* calculo do imposto do irpf se o salario eh maior que 4463,81 */
    
    if (base > 4463.81) {
    
        base_irpf_trib1 = base - 4463.81;
    
        tributo1 = base_irpf_trib1 * 0.275;
    
        base_irpf_trib2 = 4463.81 - 3572.44;
        
        tributo2 = base_irpf_trib2 * 0.225;
        
        base_irpf_trib3 = 3572.43 - 2679.30;
        
        tributo3 = base_irpf_trib3 * 0.15;
        
        base_irpf_trib4 = 2679.29 - 1787.78;
        
        tributo4 = base_irpf_trib4 * 0.075;
        
        tributo_total = tributo1 + tributo2 + tributo3 + tributo4;
        
    }
 
     /* calculo do imposto do irpf se o salario eh entre 3572,44 e 4463,81 */
    
     else if ((base >= 3572.44) && (base <= 4463.81)) {
     
        base_irpf_trib2 = base - 3572.44;
        
        tributo2 = base_irpf_trib2 * 0.225;
        
        base_irpf_trib3 = 3572.43 - 2679.30;
        
        tributo3 = base_irpf_trib3 * 0.15;
        
        base_irpf_trib4 = 2679.29 - 1787.78;
        
        tributo4 = base_irpf_trib4 * 0.075;
     
        tributo_total = tributo2 + tributo3 + tributo4;
     
     }
 
    /* calculo do imposto do irpf se o salario eh entre 2679,30 e 3572,43 */
   
    else if ((base >= 2679.30) && (base <= 3572.43)) {
    
        base_irpf_trib3 = base - 2679.30;
        
        tributo3 = base_irpf_trib3 * 0.15;
        
        base_irpf_trib4 = 2679.29 - 1787.78;
        
        tributo4 = base_irpf_trib4 * 0.075;
    
        tributo_total = tributo3 + tributo4;
    
    }
    
    /* calculo do imposto do irpf se o salario eh entre 1787,78 e 2679,29 */
    
    else if ((base >= 1787.78) && (base <= 2679.29)) {
 
        base_irpf_trib4 = base - 1787.78;
        
        tributo4 = base_irpf_trib4 * 0.075;
    
        tributo_total = tributo4;
 
    }
    
    /* calculo do imposto do irpf se o salario eh menor que 1787,77 */
    
    else {
    
       tributo_total = 0.00; 
    
    }
 
 
    /* saida de dados */
 
    printf("INSS: R$ %.2f\n", inss);
    printf("Base: R$ %.2f\n", base);
    printf("IRPF: R$ %.2f\n", tributo_total);
 
 
 
 
 
 
 
 
 
return 0;
 
}



