#include <stdio.h>
#include <stdlib.h>

static double ler_valor_positivo(const char *mensagem) {
    double valor;

    while (1) {
        printf("%s", mensagem);

        if (scanf("%lf", &valor) == 1 && valor > 0.0) {
            return valor;
        }

        printf("Valor invalido. Digite um numero maior que zero.\n");

        int caractere;
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
    }
}

static void calcular_gravidade(void) {
    printf("\n--- Calculo da gravidade atraves de dinamometro ---\n");

    double massa = ler_valor_positivo("Digite a massa do corpo (kg): ");
    double peso = ler_valor_positivo("Digite a forca medida no dinamometro (N): ");
    double gravidade = peso / massa;

    printf("Gravidade calculada: %.4f m/s^2\n", gravidade);
}

static void calcular_constante_elastica(void) {
    printf("\n--- Calculo da constante elastica da mola ---\n");

    double forca = ler_valor_positivo("Digite a forca aplicada na mola (N): ");
    double deformacao = ler_valor_positivo("Digite a deformacao da mola (m): ");
    double constante = forca / deformacao;

    printf("Constante elastica da mola: %.4f N/m\n", constante);
}

static void calcular_atrito_estatico(void) {
    printf("\n--- Calculo do coeficiente de atrito estatico ---\n");

    double forca_atrito = ler_valor_positivo("Digite a forca maxima de atrito estatico (N): ");
    double forca_normal = ler_valor_positivo("Digite a forca normal entre as superficies (N): ");
    double coeficiente = forca_atrito / forca_normal;

    printf("Coeficiente de atrito estatico: %.4f\n", coeficiente);
}

static void mostrar_menu(void) {
    printf("\nEscolha uma opcao de experimento:\n");
    printf("1 - Calculo de gravidade atraves de dinamometro\n");
    printf("2 - Calculo da constante elastica da mola\n");
    printf("3 - Calculo do coeficiente de atrito estatico entre 2 superficies\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

int main(void) {
    int opcao;

    do {
        mostrar_menu();

        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida. Digite um numero.\n");

            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF) {
            }

            continue;
        }

        switch (opcao) {
            case 1:
                calcular_gravidade();
                break;
            case 2:
                calcular_constante_elastica();
                break;
            case 3:
                calcular_atrito_estatico();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Escolha uma opcao de 0 a 3.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
