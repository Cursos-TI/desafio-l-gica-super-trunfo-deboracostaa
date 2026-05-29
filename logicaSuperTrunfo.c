#include <stdio.h>

// Desafio Super Trunfo - Paises
// Nivel novato - Comparacao de cartas
// Objetivo: cadastrar duas cartas, calcular densidade populacional e PIB per
// capita, comparar um unico atributo numerico escolhido no codigo e informar a
// carta vencedora.

int main() {
  // Variaveis da carta 1: armazenam os dados informados pelo usuario para a
  // primeira cidade.
  char estado1;
  char codigo_carta1[4];
  char nome_cidade1[30];
  unsigned long int populacao1;
  float area1;
  float pib1;
  int pontos_turisticos1;
  float densidade_populacional1;
  float pib_per_capita1;

  // Variaveis da carta 2: armazenam os dados informados pelo usuario para a
  // segunda cidade.
  char estado2;
  char codigo_carta2[4];
  char nome_cidade2[30];
  unsigned long int populacao2;
  float area2;
  float pib2;
  int pontos_turisticos2;
  float densidade_populacional2;
  float pib_per_capita2;

  // Variaveis usadas na comparacao. O atributo foi escolhido diretamente no
  // codigo, como solicitado no nivel novato do desafio.
  const char atributo_comparado[] = "Populacao";

  // Entrada dos dados da primeira carta. O formato " %[^\n]" permite ler nomes
  // de cidades com espacos, como "Rio de Janeiro".
  printf("===== CADASTRO DA CARTA 1 =====\n");

  printf("Digite o estado (letra de A a H): ");
  scanf(" %c", &estado1);

  printf("Digite o codigo da carta (ex: A01): ");
  scanf(" %3s", codigo_carta1);

  printf("Digite o nome da cidade: ");
  scanf(" %29[^\n]", nome_cidade1);

  printf("Digite a populacao: ");
  scanf("%lu", &populacao1);

  printf("Digite a area em km2: ");
  scanf("%f", &area1);

  printf("Digite o PIB em bilhoes de reais: ");
  scanf("%f", &pib1);

  printf("Digite o numero de pontos turisticos: ");
  scanf("%d", &pontos_turisticos1);

  // Calculos derivados da carta 1. O PIB foi informado em bilhoes, por isso e
  // convertido para reais antes do calculo do PIB per capita.
  densidade_populacional1 = (float)populacao1 / area1;
  pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1;

  // Entrada dos dados da segunda carta.
  printf("\n===== CADASTRO DA CARTA 2 =====\n");

  printf("Digite o estado (letra de A a H): ");
  scanf(" %c", &estado2);

  printf("Digite o codigo da carta (ex: B02): ");
  scanf(" %3s", codigo_carta2);

  printf("Digite o nome da cidade: ");
  scanf(" %29[^\n]", nome_cidade2);

  printf("Digite a populacao: ");
  scanf("%lu", &populacao2);

  printf("Digite a area em km2: ");
  scanf("%f", &area2);

  printf("Digite o PIB em bilhoes de reais: ");
  scanf("%f", &pib2);

  printf("Digite o numero de pontos turisticos: ");
  scanf("%d", &pontos_turisticos2);

  // Calculos derivados da carta 2.
  densidade_populacional2 = (float)populacao2 / area2;
  pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2;

  // Exibicao dos dados cadastrados e dos atributos calculados para facilitar a
  // conferencia das duas cartas antes do resultado da comparacao.
  printf("\n===== DADOS DAS CARTAS =====\n\n");

  printf("Carta 1 - %s (%c)\n", nome_cidade1, estado1);
  printf("Codigo: %s\n", codigo_carta1);
  printf("Populacao: %lu habitantes\n", populacao1);
  printf("Area: %.2f km2\n", area1);
  printf("PIB: %.2f bilhoes de reais\n", pib1);
  printf("Pontos turisticos: %d\n", pontos_turisticos1);
  printf("Densidade populacional: %.2f hab/km2\n", densidade_populacional1);
  printf("PIB per capita: %.2f reais\n\n", pib_per_capita1);

  printf("Carta 2 - %s (%c)\n", nome_cidade2, estado2);
  printf("Codigo: %s\n", codigo_carta2);
  printf("Populacao: %lu habitantes\n", populacao2);
  printf("Area: %.2f km2\n", area2);
  printf("PIB: %.2f bilhoes de reais\n", pib2);
  printf("Pontos turisticos: %d\n", pontos_turisticos2);
  printf("Densidade populacional: %.2f hab/km2\n", densidade_populacional2);
  printf("PIB per capita: %.2f reais\n", pib_per_capita2);

  // Comparacao das cartas pelo atributo escolhido. Para populacao, area, PIB e
  // PIB per capita, vence o maior valor. A densidade populacional seria a
  // excecao, pois nesse atributo venceria o menor valor.
  printf("\n===== COMPARACAO DE CARTAS =====\n");
  printf("Atributo escolhido: %s\n\n", atributo_comparado);
  printf("Carta 1 - %s (%c): %lu habitantes\n", nome_cidade1, estado1,
         populacao1);
  printf("Carta 2 - %s (%c): %lu habitantes\n\n", nome_cidade2, estado2,
         populacao2);

  if (populacao1 > populacao2) {
    printf("Resultado: Carta 1 (%s) venceu!\n", nome_cidade1);
  } else if (populacao2 > populacao1) {
    printf("Resultado: Carta 2 (%s) venceu!\n", nome_cidade2);
  } else {
    printf("Resultado: Empate! As duas cartas possuem a mesma populacao.\n");
  }

  return 0;
}
