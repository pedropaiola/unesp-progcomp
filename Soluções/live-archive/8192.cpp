/*
Problema: E - Enigma
Categorias:
	dynamic programming
  maratona > nacional 2017
Dificuldade: dificil
Descricao:
Dica:
Autor: Rene
*/
/* retirando os comentarios do mostra, tres matrizes serão mostradas
 *
 * a primeira matriz tem os restos obtidos com o digito seguido pelos zeros para
 * colocá-lo na posição, -1 indica que não é possivel encontrar este resto
 * usando apenas um algarismo na coluna.
 * por exemplo 43?1 dividido por 7
 * ---------------
 * -1 -1  0 -1
 * -1 -1  5  1
 * -1 -1  3 -1
 *  4 -1  1 -1
 * -1 -1  6 -1
 * -1 -1  4 -1
 * -1  3  2 -1
 * Cada linha indica o valor do resto para o dado algarismo, por exemplo 300
 * (algarismo 3) dá resto 6 (sétima linha)
 *
 * a segunda matriz, soma os restos da direita para a esquerda, a partir da
 * última linha, a linha com a anterior, os restos construindo a nova matriz
 * por exemplo
 * ---------------
 *  4  3  2 -1
 *  4  3  0  1
 *  4  3  5 -1
 *  4  3  3 -1
 *  4  3  1 -1
 *  4  3  6 -1
 *  4  3  4 -1
 *  por exemplo com o algarismo 3 é possivel se conseguir qualquer resto entre 0
 *  e 6, por isso ele aparece na coluna toda. Outro exemplo, o algorismo 2, só
 *  pode gerar resto 0 (primeira linha)
 *
 *  A última matriz indica a origem que formou o resto na coluna, por exemplo os
 *  "1"s que aparecem na coluna, indicam que todos os restos de 0 a 6 vieram da
 *  coluna 1 da coluna anterior
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

const int DIM = 1001;

int resto(int x, int exp10, int d) {
  int r = x;
  while (exp10 > 0 || r >= d) {
    while (r < d && exp10 > 0) {
      r *= 10;
      exp10--;
    }
    if (r >= d) {
      r %= d;
    }
  }
  return r;
}

template<class tipo>
void mostra(tipo memo[DIM][DIM], int n, int m) {
  cout << "---------------\n";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << memo[i][j] << "\t";
    }
    cout << endl;
  }
}

int main(int argc, char **argv) {
  int divisor;
  string num;

  cin >> num;
  cin >> divisor;

  int tam = num.size();
  signed char memoParcial[DIM][DIM];
  signed char memo[DIM][DIM];
  short memoOrig[DIM][DIM];

  memset(memoParcial, -1, sizeof(memoParcial));
  memset(memo, -1, sizeof(memo));

  for (int i = tam - 1; i >= 0; i--) {
    if (num[i] == '?') {
      char dig;
      if (i == 0) {
        dig = '1'; // na primeira coluna começa com um
      } else {
        dig = '0'; // nas outras colunas começa com zero
      }
      for (; dig <= '9'; dig++) {
        int r = resto(dig - '0', tam - 1 - i, divisor);
        if (memoParcial[r][i] < 0) {
          memoParcial[r][i] = dig;
        }
      }
    } else {
      int r = resto(num[i] - '0', tam - 1 - i, divisor);
      memoParcial[r][i] = num[i];
    }
  }

  //mostra(memoParcial, tam, divisor);

  for (int i = 0; i < divisor; i++) {
    memo[i][tam - 1] = memoParcial[i][tam - 1];
    memoOrig[i][tam - 1] = i;
  }
  for (int i = tam - 2; i >= 0; i--) {
    for (int j = 0; j < divisor; j++) {
      for (int k = 0; k < divisor; k++) {
        if (memoParcial[j][i] >= 0 && // testa se ainda está vazio
            memo[k][i + 1] >= 0) { // testa se o valor já colocado é maior que o atual encontrado
          int r = (j + k) % divisor;
          if (memo[r][i] < 0 || memo[r][i] > memoParcial[j][i]) {
            memo[r][i] = memoParcial[j][i];
            memoOrig[r][i] = k;
          }
        }
      }
    }
  }

  //mostra(memo, tam, divisor);
  //mostra(memoOrig, tam, divisor);

  int r = 0;
  string saida;

  if (memo[r][0] < 0) {
    saida = "*";
  } else {
    for (int i = 0; i < tam; i++) {
      saida += memo[r][i];
      r = memoOrig[r][i];
    }
  }

  cout << saida << endl;

  return 0;
}

