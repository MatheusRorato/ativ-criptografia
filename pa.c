#include <stdio.h>
#include <string.h>
int calcularpa(int a1, int r, int n){
    return a1 + (n - 1) * r;
}

int main()
{
    char alfabeto[26]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char palavra[100];
    int shift_inicial, razao_pa, i;
    int posicao_letra = 1;
    printf("Escolha uma palavra: ");
    scanf("%s", palavra);
    printf("Escolha um shift: ");
    scanf("%d", &shift_inicial);
    printf("Escolha a razão do shift (r da PA, ex: 1, 2, -1): ");
    scanf("%d", &razao_pa);
    printf("Palavra codificada (PA: a1=%d, r=%d): ", shift_inicial, razao_pa);
   for(i = 0; palavra[i] != '\0'; i++) {
       char letra = palavra[i];
       if (letra >= 'A' && letra <= 'Z') {
           int shift_atual = calcularpa(shift_inicial, razao_pa, posicao_letra);
           int shift_positivo = (shift_atual % 26 + 26) % 26;
           int indice_original = letra - 'A';
            int indice_codificado = (indice_original + shift_positivo) % 26;
           char letra_codificada = 'A' + indice_codificado;
           printf("%c", letra_codificada);
        } else {
            printf("%c", letra);
        }
        posicao_letra++;
    }
    printf("\n");
    return 0;
}