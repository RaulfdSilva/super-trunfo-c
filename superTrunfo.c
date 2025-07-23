#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[20];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
};

struct Carta cadastrar_carta() {
    struct Carta c;
    printf("Estado: ");
    scanf(" %[^\n]", c.estado);
    printf("Código da Carta: ");
    scanf(" %[^\n]", c.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c.nome);
    printf("População: ");
    scanf("%d", &c.populacao);
    printf("Área (km²): ");
    scanf("%f", &c.area);
    printf("PIB (em milhões): ");
    scanf("%f", &c.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &c.pontos_turisticos);
    c.densidade = c.populacao / c.area;
    return c;
}

void exibir_carta(struct Carta c) {
    printf("\nCidade: %s (%s)\n", c.nome, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f milhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
}

void comparar(struct Carta c1, struct Carta c2, int opcao) {
    switch (opcao) {
        case 1:
            if (c1.populacao > c2.populacao)
                exibir_carta(c1);
            else if (c2.populacao > c1.populacao)
                exibir_carta(c2);
            else
                printf("\nEmpate na População.\n");
            break;
        case 2:
            if (c1.area > c2.area)
                exibir_carta(c1);
            else if (c2.area > c1.area)
                exibir_carta(c2);
            else
                printf("\nEmpate na Área.\n");
            break;
        case 3:
            if (c1.pib > c2.pib)
                exibir_carta(c1);
            else if (c2.pib > c1.pib)
                exibir_carta(c2);
            else
                printf("\nEmpate no PIB.\n");
            break;
        case 4:
            if (c1.pontos_turisticos > c2.pontos_turisticos)
                exibir_carta(c1);
            else if (c2.pontos_turisticos > c1.pontos_turisticos)
                exibir_carta(c2);
            else
                printf("\nEmpate nos Pontos Turísticos.\n");
            break;
        case 5:
            if (c1.densidade < c2.densidade)
                exibir_carta(c1);
            else if (c2.densidade < c1.densidade)
                exibir_carta(c2);
            else
                printf("\nEmpate na Densidade Populacional.\n");
            break;
        default:
            printf("\nOpção inválida.\n");
    }
}

int main() {
    struct Carta carta1, carta2;
    int opcao;

    printf("Cadastro da Carta 1:\n");
    carta1 = cadastrar_carta();

    printf("\nCadastro da Carta 2:\n");
    carta2 = cadastrar_carta();

    printf("\nCartas cadastradas:");
    exibir_carta(carta1);
    exibir_carta(carta2);

    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\nCarta vencedora:\n");
    comparar(carta1, carta2, opcao);

    return 0;
}
