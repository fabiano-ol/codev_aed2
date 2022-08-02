#include <stdio.h>
#include <stdlib.h>

/* Hint 1:
- Note que os d elementos de b[0..d-1] devem pertencer a todas as permutações 
  escritas pela função. Se d=k, então há somente uma permutação a ser escrita.
  Qual é ela?

- Caso d<k, então é necessário escolher mais um elemento para compor a 
  permutação junto com b[0..d-1]. Quais elementos de {1,...,n} que podem ser
  escolhidos?
  
- Ao escolheremos um i possível, como podemos escrever todas as permutações todas 
  as permutações de {1,...,n} de tamanho k que contenha os d elementos b[0..d-1], 
  e mais o i?

- De posse do item anterior, como fazer o que se pede: escrever todas as permutações 
  de {1,...,n} de tamanho k que contenha os d elementos b[0..d-1]?
*/

/* Hint 2:
- Note que os d elementos de b[0..d-1] devem pertencer a todas as permutações 
  escritas pela função. Se d=k, então há somente uma permutação a ser escrita,
  que é precisamente b[0]b[1]...b[k-1].

- Caso d<k, então é necessário escolher mais um elemento para compor a 
  permutação junto com b[0..d-1]. Os elementos que podem ser escolhidos são
  aqueles de {1,...,n} que não pertencem a b[0..d-1]. Note que, se i pode ser
  escolhido, então fazer
  
  b[d] = i
  
  e, em seguida, executar 
  
  Perm(n, k, b, d+1)
  
  fará com que o programa escreva todas as permutações de {1,...,n} de tamanho k
  que contenha os d elementos b[0..d-1], além de i.
  
  Se o procedimento acima for feito para cada possível valor de i, então ao final,
  teremos escrito todas as permutações de {1,...,n} de tamanho k
  que contenha os d elementos b[0..d-1].
*/

/* 
Assume:  n >= k, 0 <= d <= k
Garante: Escrita de todas as permutações de {1,...,n} de tamanho k
         que contenha os d elementos b[0..d-1]
*/
void Arranjo(int n, int k, int b[], int d){
    if (k == d) {
        for (int i = 0; i < k; i++){ // escrevendo b[0..k-1]
            printf("%d", b[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n; i++){
            bool enc = false;
            for (int j = 0; j < d; j++){ 
                if(b[j] == i){
                    enc = true; break;
                }
            }
            if(! enc){
                b[d] = i;
                Arranjo(n, k, b, d+1);
            }
        } 
    }
}

int main() {
	int n, k;
	while (scanf("%d %d", &n, &k)>0) {
        int b[k];
        int d = 0;
        Arranjo(n, k, b, d);
	}
}
