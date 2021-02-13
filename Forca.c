#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int encontrarLetra(char letra_x, char letra_y) {
    int a, b;

    a = toupper(letra_x);
    b = toupper(letra_y);

    if(a == b) {
        return 1;
    }
    else {
        return 0;
    }
}

void exibir(int espaco, char letra) {
    if(espaco || letra == ' ' || letra == '-') { // Exibindo espaços vazios ou letras
        printf(" %c ", letra);
    }
    else {
        printf(" _ ");
    }
}

int escreverPalavra(char *palavra, int *espacos, char letra) {
    int i, errou = 1;

    for(i = 0; palavra[i]; i++) {
        if(!espacos[i]) { // Verificar somente os espaços vazios
            espacos[i] = encontrarLetra(palavra[i], letra);

            if(espacos[i])
                errou = 0;
        }
    }

    printf("\n");

    return errou;
}

void criarForca(int chances) {
    switch (chances) {
        case 0:
            printf("----------\n");
            printf("|\t O\n");
            printf("|\t|||\n");
            printf("|\t |\n");
            printf("|\t| |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 1:
            printf("----------\n");
            printf("|\t O\n");
            printf("|\t|||\n");
            printf("|\t |\n");
            printf("|\t|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 2:
            printf("----------\n");
            printf("|\t O\n");
            printf("|\t|||\n");
            printf("|\t |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 3:
            printf("----------\n");
            printf("|\t O\n");
            printf("|\t||\n");
            printf("|\t |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 4:
            printf("----------\n");
            printf("|\t O\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 5:
            printf("----------\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
    }
}

int main() {
    char palavra[255], letra = '\0', letras_tentadas[26];
    int *verificacao, i, jogada = 0, totalChances = 5, cont_tentadas = 0, repetidas, vencedor;

    letras_tentadas[0] = '\0';

    // Definir o vencedor

    printf("Digite a palavra desejada: ");
    setbuf(stdin, 0);
    fgets(palavra, 255, stdin);
    palavra[strlen(palavra)-1] = '\0'; // Retirando o enter

    verificacao = (int*) malloc(sizeof(int) * strlen(palavra));

    for(i = 0; i < strlen(palavra); i++) {
        if(palavra[i] == ' ' || palavra[i] == '-') {
            verificacao[i] = 1;
        }
        else {
            verificacao[i] = 0;
        }
    }

    system("cls");

    while(1) {
        vencedor = 1;

        totalChances -= jogada;

        printf("\nTotal de chances: %d\n", totalChances);

        criarForca(totalChances);

        for(i = 0; i < strlen(palavra); i++) {
            if(!verificacao[i]) {
                vencedor = 0;
                break;
            }
        }

        for(i = 0; palavra[i]; i++) {
            exibir(verificacao[i], palavra[i]); // Exibindo a palavra
        }

        if(!totalChances || vencedor) {
            printf("\n\nFIM DE JOGO");
            if(!totalChances) {
                printf("\nA palavra era *%s*\n", palavra);
            }
            break;
        }

        printf("\n\nLetras utilizadas: ");
        for(i = 0; letras_tentadas[i]; i++) {
            printf("%c ", letras_tentadas[i]);
        }

        do {
            repetidas = 0;

            printf("\n\nDigite alguma letra: ");
            scanf(" %c", &letra);

            for(i = 0; letras_tentadas[i]; i++) {
                if(letra == letras_tentadas[i]) {
                    repetidas = 1;
                    printf("\nLetra *%c* ja utilizada. Tenta uma diferente...", letras_tentadas[i]);
                    break;
                }
            }
        } while(repetidas);

        letras_tentadas[cont_tentadas] = letra;

        cont_tentadas++;

        for(i = cont_tentadas; i < 26; i++) {
            letras_tentadas[i] = 0;
        }

        jogada = escreverPalavra(palavra, verificacao, letra);

        system("cls");
    }

    return 0;
}
