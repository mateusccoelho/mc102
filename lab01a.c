/* nome: mateus de carvalho coelho */
/* ra: 156675 */

#include <stdio.h>
#include <math.h>

int main () {

	/* declarando variaveis */
    double p1, p2, p3, l, mp, ma, mg, mh;  

	/* entrada das notas */
    scanf("%lf %lf %lf %lf", &p1, &p2, &p3, &l); 
        
	/* contas */        
        
            mp = ((3 * p1) + (3 * p2) + (4 * p3)) / 10;
        
            ma = (mp + l) / 2;
            
            mh = (2 * mp * l) / (mp + l);

            mg = sqrt(mp * l);
            
/* saida */       
       
       printf("Media aritmetica: %.1f\nMedia harmonica: %.1f\nMedia geometrica: %.1f\n", ma, mh, mg);


return 0;

}
