/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 */

//#include "shape.hpp"
//#include "problem_a.hpp"

Silinder *new_silinder(const Lingkaran &l, float tinggi) {
  Silinder *sil = new Silinder; 
  sil -> circle.jari = l.jari;
  sil -> t = tinggi;
  return sil;
}

struct Lingkaran{
  int jari;
};

struct Silinder{
  Lingkaran circle;
  int t;
};

int main(int argc, char const *argv[]) {

  Silinder a;
  
  a.circle.jari = 7;
  a.t = 12;


  return 0;
}
