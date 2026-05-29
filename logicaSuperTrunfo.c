#include <stdio.h>

// Desafio Super Trunfo - Paises
// Nivel mestre - Comparacao avancada com dois atributos
// Objetivo: permitir que o jogador escolha dois atributos diferentes,
// comparar as cartas individualmente por atributo e decidir o vencedor pela
// soma dos valores escolhidos.

int main() {
  // Dados fixos da carta 1. No nivel mestre, as cartas continuam
  // pre-cadastradas para que o foco fique na logica de comparacao.
  char estado1 = 'A';
  char codigo_carta1[] = "A01";
  char nome_pais1[] = "Brasil";
  unsigned long int populacao1 = 203080756;
  float area1 = 8515767.00f;
  float pib1 = 2173.67f;
  int pontos_turisticos1 = 45;
  float densidade_demografica1;

  // Dados fixos da carta 2, que sera comparada com a primeira carta.
  char estado2 = 'B';
  char codigo_carta2[] = "B01";
  char nome_pais2[] = "Argentina";
  unsigned long int populacao2 = 46654581;
  float area2 = 2780400.00f;
  float pib2 = 641.10f;
  int pontos_turisticos2 = 38;
  float densidade_demografica2;

  // Opcoes escolhidas pelo jogador nos dois menus.
  int primeiro_atributo;
  int segundo_atributo;

  // Variaveis que guardam os nomes e valores dos atributos selecionados.
  char nome_atributo1[30];
  char nome_atributo2[30];
  double valor1_atributo1;
  double valor2_atributo1;
  double valor1_atributo2;
  double valor2_atributo2;

  // Variaveis usadas para armazenar o resultado das comparacoes individuais e
  // da comparacao final pela soma.
  int vencedor_atributo1;
  int vencedor_atributo2;
  int vencedor_final;
  double soma_carta1;
  double soma_carta2;

  // Calculo da densidade demografica das cartas. Esse atributo e calculado a
  // partir da populacao e da area.
  densidade_demografica1 = (float)populacao1 / area1;
  densidade_demografica2 = (float)populacao2 / area2;

  // Exibicao inicial das cartas para o jogador saber quais paises estao sendo
  // comparados antes de escolher os atributos.
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

  // Primeiro menu: mostra todos os atributos numericos disponiveis.
  printf("\n===== PRIMEIRO ATRIBUTO =====\n");
  printf("Escolha o primeiro atributo para comparacao:\n");
  printf("1 - Populacao\n");
  printf("2 - Area\n");
  printf("3 - PIB\n");
  printf("4 - Pontos turisticos\n");
  printf("5 - Densidade demografica\n");
  printf("Digite sua opcao: ");

  if (scanf("%d", &primeiro_atributo) != 1) {
    printf("\nEntrada invalida! Digite apenas numeros no menu.\n");
    return 1;
  }

  // O switch valida a primeira escolha e carrega os valores do primeiro
  // atributo para cada carta.
  switch (primeiro_atributo) {
  case 1:
    sprintf(nome_atributo1, "Populacao");
    valor1_atributo1 = (double)populacao1;
    valor2_atributo1 = (double)populacao2;
    break;
  case 2:
    sprintf(nome_atributo1, "Area");
    valor1_atributo1 = area1;
    valor2_atributo1 = area2;
    break;
  case 3:
    sprintf(nome_atributo1, "PIB");
    valor1_atributo1 = pib1;
    valor2_atributo1 = pib2;
    break;
  case 4:
    sprintf(nome_atributo1, "Pontos turisticos");
    valor1_atributo1 = pontos_turisticos1;
    valor2_atributo1 = pontos_turisticos2;
    break;
  case 5:
    sprintf(nome_atributo1, "Densidade demografica");
    valor1_atributo1 = densidade_demografica1;
    valor2_atributo1 = densidade_demografica2;
    break;
  default:
    printf("\nOpcao invalida! Execute novamente e escolha uma opcao de 1 a 5.\n");
    return 1;
  }

  // Segundo menu dinamico: a opcao escolhida no primeiro menu nao aparece de
  // novo, impedindo que o mesmo atributo seja escolhido duas vezes.
  printf("\n===== SEGUNDO ATRIBUTO =====\n");
  printf("Escolha um atributo diferente do primeiro:\n");

  if (primeiro_atributo != 1) {
    printf("1 - Populacao\n");
  }
  if (primeiro_atributo != 2) {
    printf("2 - Area\n");
  }
  if (primeiro_atributo != 3) {
    printf("3 - PIB\n");
  }
  if (primeiro_atributo != 4) {
    printf("4 - Pontos turisticos\n");
  }
  if (primeiro_atributo != 5) {
    printf("5 - Densidade demografica\n");
  }

  printf("Digite sua opcao: ");

  if (scanf("%d", &segundo_atributo) != 1) {
    printf("\nEntrada invalida! Digite apenas numeros no menu.\n");
    return 1;
  }

  // Esta verificacao reforca a regra do menu dinamico, caso o usuario digite
  // manualmente a mesma opcao que ja tinha sido escolhida antes.
  if (segundo_atributo == primeiro_atributo) {
    printf("\nOpcao invalida! O mesmo atributo nao pode ser escolhido duas vezes.\n");
    return 1;
  }

  // O switch valida a segunda escolha e carrega os valores do segundo atributo.
  switch (segundo_atributo) {
  case 1:
    sprintf(nome_atributo2, "Populacao");
    valor1_atributo2 = (double)populacao1;
    valor2_atributo2 = (double)populacao2;
    break;
  case 2:
    sprintf(nome_atributo2, "Area");
    valor1_atributo2 = area1;
    valor2_atributo2 = area2;
    break;
  case 3:
    sprintf(nome_atributo2, "PIB");
    valor1_atributo2 = pib1;
    valor2_atributo2 = pib2;
    break;
  case 4:
    sprintf(nome_atributo2, "Pontos turisticos");
    valor1_atributo2 = pontos_turisticos1;
    valor2_atributo2 = pontos_turisticos2;
    break;
  case 5:
    sprintf(nome_atributo2, "Densidade demografica");
    valor1_atributo2 = densidade_demografica1;
    valor2_atributo2 = densidade_demografica2;
    break;
  default:
    printf("\nOpcao invalida! Execute novamente e escolha uma opcao de 1 a 5.\n");
    return 1;
  }

  // Comparacao individual do primeiro atributo. A densidade demografica tem
  // regra invertida: menor valor vence. Os demais atributos vencem pelo maior.
  if (primeiro_atributo == 5) {
    if (valor1_atributo1 < valor2_atributo1) {
      vencedor_atributo1 = 1;
    } else {
      if (valor2_atributo1 < valor1_atributo1) {
        vencedor_atributo1 = 2;
      } else {
        vencedor_atributo1 = 0;
      }
    }
  } else {
    if (valor1_atributo1 > valor2_atributo1) {
      vencedor_atributo1 = 1;
    } else {
      if (valor2_atributo1 > valor1_atributo1) {
        vencedor_atributo1 = 2;
      } else {
        vencedor_atributo1 = 0;
      }
    }
  }

  // Comparacao individual do segundo atributo, usando a mesma regra aplicada ao
  // primeiro atributo.
  if (segundo_atributo == 5) {
    if (valor1_atributo2 < valor2_atributo2) {
      vencedor_atributo2 = 1;
    } else {
      if (valor2_atributo2 < valor1_atributo2) {
        vencedor_atributo2 = 2;
      } else {
        vencedor_atributo2 = 0;
      }
    }
  } else {
    if (valor1_atributo2 > valor2_atributo2) {
      vencedor_atributo2 = 1;
    } else {
      if (valor2_atributo2 > valor1_atributo2) {
        vencedor_atributo2 = 2;
      } else {
        vencedor_atributo2 = 0;
      }
    }
  }

  // Soma dos valores dos dois atributos escolhidos. A carta com a maior soma
  // vence a rodada final.
  soma_carta1 = valor1_atributo1 + valor1_atributo2;
  soma_carta2 = valor2_atributo1 + valor2_atributo2;

  // Operador ternario usado para definir o vencedor final de forma compacta.
  // O valor 0 representa empate.
  vencedor_final = soma_carta1 > soma_carta2 ? 1 : (soma_carta2 > soma_carta1 ? 2 : 0);

  // Saida organizada com todos os dados pedidos no desafio: paises, atributos,
  // valores de cada carta, soma e vencedor.
  printf("\n===== RESULTADO DA COMPARACAO =====\n");
  printf("Carta 1: %s\n", nome_pais1);
  printf("Carta 2: %s\n\n", nome_pais2);

  printf("Atributo 1: %s\n", nome_atributo1);
  printf("%s: %.2f\n", nome_pais1, valor1_atributo1);
  printf("%s: %.2f\n", nome_pais2, valor2_atributo1);
  printf("Vencedor no atributo 1: %s\n\n",
         vencedor_atributo1 == 1
             ? nome_pais1
             : (vencedor_atributo1 == 2 ? nome_pais2 : "Empate"));

  printf("Atributo 2: %s\n", nome_atributo2);
  printf("%s: %.2f\n", nome_pais1, valor1_atributo2);
  printf("%s: %.2f\n", nome_pais2, valor2_atributo2);
  printf("Vencedor no atributo 2: %s\n\n",
         vencedor_atributo2 == 1
             ? nome_pais1
             : (vencedor_atributo2 == 2 ? nome_pais2 : "Empate"));

  printf("Soma dos atributos - %s: %.2f\n", nome_pais1, soma_carta1);
  printf("Soma dos atributos - %s: %.2f\n\n", nome_pais2, soma_carta2);

  if (vencedor_final == 1) {
    printf("Resultado final: Carta 1 (%s) venceu!\n", nome_pais1);
  } else {
    if (vencedor_final == 2) {
      printf("Resultado final: Carta 2 (%s) venceu!\n", nome_pais2);
    } else {
      printf("Resultado final: Empate!\n");
    }
  }

  return 0;
}
