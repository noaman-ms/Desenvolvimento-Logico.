#include <stdio.h>
#include <string.h>

// Definindo uma estrutura para armazenar os dados de cada carta
struct Carta {
    // Letra de 'A' a 'H'
    char estado;
    // Ex: A01, B03
    char codigo[4];
    // Nome da cidade
    char nomeCidade[50];
    // Número de habitantes
    unsigned long int populacao;
    // Área em km²
    float area;
    // PIB em bilhões de reais
    float pib;
    // Quantidade de pontos turísticos
    int pontosTuristicos;
};

int main() {
    
    int atributo1 = 0, atributo2 = 0;
    float valor1_c1 = 0, valor1_c2 = 0, valor2_c1 = 0, valor2_c2 = 0;
    float soma_c1 = 0, soma_c2 = 0;
    
    // Declaração das duas cartas
    struct Carta carta1, carta2;

    // Leitura da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &carta1.estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);  // Lê até a quebra de linha

    printf("Digite a população: ");
    scanf("%lu", &carta1.populacao);

    printf("Digite a área em km²: ");
    scanf("%f", &carta1.area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Leitura da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &carta2.estado);

    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", carta2.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Digite a população: ");
    scanf("%lu", &carta2.populacao);

    printf("Digite a área em km²: ");
    scanf("%f", &carta2.area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    // Cálculo intermediários
        //Cálculo densidade para Carta 1 e 2 
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;
        //Cálculo pibPerCapita para Carta 1 e 2 
    float pibPerCapita1 = (carta1.pib * 1000000000) / carta1.populacao;
    float pibPerCapita2 = (carta2.pib * 1000000000) / carta2.populacao;
        //Cálculo superPoder para Carta 1 e 2
    float superPoder1 = (float)carta1.populacao + carta1.area + (carta1.pib * 1000000000.0) +
                        (float)carta1.pontosTuristicos + pibPerCapita1 + (1.0f / densidade1);

    float superPoder2 = (float)carta2.populacao + carta2.area + (carta2.pib * 1000000000.0) +
                        (float)carta2.pontosTuristicos + pibPerCapita2 + (1.0f / densidade2);

    // Mostra os Menu de atributo de escolha
void mostrarMenuAtributos(int jaEscolhido) {
    printf("\nEscolha um atributo para comparar:\n");
    if (jaEscolhido != 1) printf("1. Populacao\n");
    if (jaEscolhido != 2) printf("2. Area\n");
    if (jaEscolhido != 3) printf("3. PIB\n");
    if (jaEscolhido != 4) printf("4. Pontos Turisticos\n");
    if (jaEscolhido != 5) printf("5. Densidade Demografica\n");
    printf("Digite o numero do atributo: ");
}


    // Menu para escolher dois atributos diferentes
    do {
        mostrarMenuAtributos(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5) {
            printf("Atributo invalido!\n");
            atributo1 = 0;
        }
    } while (atributo1 == 0);

    do {
        mostrarMenuAtributos(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
            printf("Atributo invalido ou repetido!\n");
            atributo2 = 0;
        }
    } while (atributo2 == 0);

    // Função auxiliar para obter valor dos atributos
    float getValor(int atributo, struct Carta c, float densidade) {
        switch (atributo) {
            case 1: return (float)c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return (float)c.pontosTuristicos;
            case 5: return densidade;
            default: return 0;
        }
    }

    // Coletar os valores
    valor1_c1 = getValor(atributo1, carta1, densidade1);
    valor1_c2 = getValor(atributo1, carta2, densidade2);
    valor2_c1 = getValor(atributo2, carta1, densidade1);
    valor2_c2 = getValor(atributo2, carta2, densidade2);

    // Mostrar resultados dos atributos escolhidos
    printf("\n--- Comparacao ---\n");
    printf("Cidades: %s vs %s\n", carta1.nomeCidade, carta2.nomeCidade);

    printf("Atributo 1: %d\n", atributo1);
    printf(") -> %s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor1_c1, carta2.nomeCidade, valor1_c2);
    printf("Atributo 2: %d\n", atributo2);
    printf(") -> %s: %.2f | %s: %.2f\n", carta1.nomeCidade, valor2_c1, carta2.nomeCidade, valor2_c2);

    // Comparar os atributos
    float resultado1 = (atributo1 == 5) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    float resultado2 = (atributo2 == 5) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);

    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos Atributos:\n%s: %.2f\n%s: %.2f\n", carta1.nomeCidade, soma_c1, carta2.nomeCidade, soma_c2);

    if (soma_c1 > soma_c2) {
        printf("\nVencedora: %s\n", carta1.nomeCidade);
    } else if (soma_c2 > soma_c1) {
        printf("\nVencedora: %s\n", carta2.nomeCidade);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
