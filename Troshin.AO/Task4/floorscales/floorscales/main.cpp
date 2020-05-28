#include "FloorScales.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  
 Nabludenie c(4, 5, 2020, 45);
  
  FloorScales s(c, "Lena1");
  Pers s1(s);
  s1.vibor();
  getchar();
  getchar();
  return 0;
}