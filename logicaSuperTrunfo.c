#include <stdio.h>

// Desafio Super Trunfo - Paises
// Nivel aventureiro - Menu interativo e comparacao de atributos
// Objetivo: comparar duas cartas ja cadastradas, permitindo que o usuario
// escolha o atributo numerico por meio de um menu com switch.

int main()
{
  // Dados fixos da carta 1. Neste nivel, o cadastro nao precisa ser refeito;
  // por isso as cartas ficam preenchidas diretamente no codigo.
  char estado1 = 'A';
  char codigo_carta1[] = "A01";
  char nome_pais1[] = "Brasil";
  unsigned long int populacao1 = 203080756;
  float area1 = 8515767.00f;
  float pib1 = 2173.67f;
  int pontos_turisticos1 = 45;
  float densidade_demografica1;

  // Dados fixos da carta 2, usados para comparar com a primeira carta.
  char estado2 = 'B';
  char codigo_carta2[] = "B01";
  char nome_pais2[] = "Argentina";
  unsigned long int populacao2 = 46654581;
  float area2 = 2780400.00f;
  float pib2 = 641.10f;
  int pontos_turisticos2 = 45;
  float densidade_demografica2;

  // A opcao guarda a escolha feita pelo jogador no menu interativo.
  int opcao;

  // Calculo da densidade demografica das duas cartas. Esse atributo tem uma
  // regra especial: vence quem tiver o menor valor.
  densidade_demografica1 = (float)populacao1 / area1;
  densidade_demografica2 = (float)populacao2 / area2;

  // Exibicao das cartas antes do menu. O nome do pais e mostrado para
  // identificacao, mas nao e comparado diretamente.
  printf("===== CARTAS DISPONIVEIS =====\n\n");

  printf("Carta 1\n");
  printf("Pais: %s\n", nome_pais1);
  printf("Estado: %c\n", estado1);
  printf("Codigo: %s\n", codigo_carta1);
  printf("Populacao: %lu habitantes\n", populacao1);
  printf("Area: %.2f km2\n", area1);
  printf("PIB: %.2f bilhoes de dolares\n", pib1);
  printf("Pontos turisticos: %d\n", pontos_turisticos1);
  printf("Densidade demografica: %.2f hab/km2\n\n", densidade_demografica1);

  printf("Carta 2\n");
  printf("Pais: %s\n", nome_pais2);
  printf("Estado: %c\n", estado2);
  printf("Codigo: %s\n", codigo_carta2);
  printf("Populacao: %lu habitantes\n", populacao2);
  printf("Area: %.2f km2\n", area2);
  printf("PIB: %.2f bilhoes de dolares\n", pib2);
  printf("Pontos turisticos: %d\n", pontos_turisticos2);
  printf("Densidade demografica: %.2f hab/km2\n", densidade_demografica2);

  // Menu interativo. O usuario escolhe o atributo numerico usado na comparacao.
  printf("\n===== MENU DE COMPARACAO =====\n");
  printf("Escolha o atributo para comparar as cartas:\n");
  printf("1 - Populacao\n");
  printf("2 - Area\n");
  printf("3 - PIB\n");
  printf("4 - Pontos turisticos\n");
  printf("5 - Densidade demografica\n");
  printf("Digite sua opcao: ");
  scanf("%d", &opcao);

  printf("\n===== RESULTADO DA COMPARACAO =====\n");
  printf("Carta 1: %s\n", nome_pais1);
  printf("Carta 2: %s\n\n", nome_pais2);

  // O switch direciona o programa para a comparacao correta de acordo com a
  // escolha do usuario. Cada case usa if-else para decidir vencedor ou empate.
  switch (opcao)
  {
  case 1:
    printf("Atributo escolhido: Populacao\n");
    printf("%s: %lu habitantes\n", nome_pais1, populacao1);
    printf("%s: %lu habitantes\n\n", nome_pais2, populacao2);

    // Para populacao, vence a carta com o maior valor.
    if (populacao1 > populacao2)
    {
      printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
    }
    else
    {
      if (populacao2 > populacao1)
      {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
      }
      else
      {
        printf("Resultado: Empate!\n");
      }
    }
    break;

  case 2:
    printf("Atributo escolhido: Area\n");
    printf("%s: %.2f km2\n", nome_pais1, area1);
    printf("%s: %.2f km2\n\n", nome_pais2, area2);

    // Para area, vence a carta com o maior territorio.
    if (area1 > area2)
    {
      printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
    }
    else
    {
      if (area2 > area1)
      {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
      }
      else
      {
        printf("Resultado: Empate!\n");
      }
    }
    break;

  case 3:
    printf("Atributo escolhido: PIB\n");
    printf("%s: %.2f bilhoes de dolares\n", nome_pais1, pib1);
    printf("%s: %.2f bilhoes de dolares\n\n", nome_pais2, pib2);

    // Para PIB, vence a carta com o maior valor economico.
    if (pib1 > pib2)
    {
      printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
    }
    else
    {
      if (pib2 > pib1)
      {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
      }
      else
      {
        printf("Resultado: Empate!\n");
      }
    }
    break;

  case 4:
    printf("Atributo escolhido: Pontos turisticos\n");
    printf("%s: %d pontos turisticos\n", nome_pais1, pontos_turisticos1);
    printf("%s: %d pontos turisticos\n\n", nome_pais2, pontos_turisticos2);

    // Para pontos turisticos, vence a carta com a maior quantidade.
    if (pontos_turisticos1 > pontos_turisticos2)
    {
      printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
    }
    else
    {
      if (pontos_turisticos2 > pontos_turisticos1)
      {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
      }
      else
      {
        printf("Resultado: Empate!\n");
      }
    }
    break;

  case 5:
    printf("Atributo escolhido: Densidade demografica\n");
    printf("%s: %.2f hab/km2\n", nome_pais1, densidade_demografica1);
    printf("%s: %.2f hab/km2\n\n", nome_pais2, densidade_demografica2);

    // Na densidade demografica, a regra e invertida: vence o menor valor.
    if (densidade_demografica1 < densidade_demografica2)
    {
      printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
    }
    else
    {
      if (densidade_demografica2 < densidade_demografica1)
      {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
      }
      else
      {
        printf("Resultado: Empate!\n");
      }
    }
    break;

  default:
    // O default trata escolhas fora do menu e evita uma comparacao incorreta.
    printf("Opcao invalida! Execute o programa novamente e escolha uma opcao de 1 a 5.\n");
    break;
  }

  return 0;
}
