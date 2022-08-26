#include <cstdio>

using namespace std;

const int MAX = 100;
const char LIVRE = '.';
const char OCUPADO = 'C';

char lab[MAX + 2][MAX + 4];
int nLab;

void leLab() {
  char c;
  scanf("%d\n", &nLab);
  for (int i = 0; i < nLab + 2; i++) {
    scanf("%s\n", lab[i]);
    // printf("%s\n", lab[i]);
  }
}

void procuraInicio(int &xInicio, int &yInicio) {
  for (int y = 0; y < nLab; y++) {
    for (int x = 1; x <= nLab + 1; x++) {
      if (lab[y][x] == 'I') {
        xInicio = x;
        yInicio = y;
        return;
      }
    }
  }
}

bool posicaoValida(int x, int y) {
  return lab[y][x] != '#' && lab[y][x] != OCUPADO;
}

bool procuraCaminho(int x, int y, int nivel) {
  bool ret;
  if (lab[y][x] == 'S') {
    return true;
  }
  if (!posicaoValida(x, y)) {
    return false;
  }
  if (lab[y][x] == LIVRE) {
    lab[y][x] = OCUPADO;
  }

  if (procuraCaminho(x + 1, y, nivel + 1)) {
    return true;
  }
  if (procuraCaminho(x - 1, y, nivel + 1)) {
    return true;
  }
  if (procuraCaminho(x, y + 1, nivel + 1)) {
    return true;
  }
  if (procuraCaminho(x, y - 1, nivel + 1)) {
    return true;
  }
  if (lab[y][x] == OCUPADO) {
    lab[y][x] = LIVRE;
  }
  return false;
}

void mostra() {
  for (int y = 0; y < nLab + 2; y++) {
    for (int x = 0; x < nLab + 2; x++) {
      if (lab[y][x] == '#') {
        printf(".");
      } else {
        printf("%c", lab[y][x]);
      }
    }
    printf("\n");
  }
}

int main() {
  int xInicio;
  int yInicio;
  leLab();
  procuraInicio(xInicio, yInicio);
  procuraCaminho(xInicio, yInicio, 0);
  mostra();
  return 0;
}