#include "shape.hpp"
#include "problem_a.hpp"

Lingkaran *new_lingkaran(float jari_jari) {
  Lingkaran *circle = new Lingkaran;
  circle->jari = jari_jari;
  
  return circle;
}
Silinder *new_silinder(const Lingkaran &l, float tinggi) {
  Silinder *sil = new Silinder; 
  sil -> cir.jari = l.jari;
  sil -> t = tinggi;
  return sil;
}
void new_silinder(Silinder *s, float jari_jari, float tinggi) {
  s -> cir.jari = jari_jari;
  s -> t = tinggi;
}
void new_balok(Balok *b, float panjang, float lebar, float tinggi) {
  b->p = panjang;
  b->l = lebar;
  b->t = tinggi; 

}
float cari_diameter(const Lingkaran &l) {
  float diameter, jari;

  jari = l.jari;
  diameter = 2 * jari;
  return diameter;
}
float cari_diameter(const Silinder &s) {
  float jari, diameter;

  jari = s.cir.jari;
  diameter = 2 * jari;
  return diameter;
}
float cari_keliling(const Lingkaran &l) {
  float jari, kel;

  jari = l.jari;
  kel = 2 * pi * jari;
  return kel;
}
float cari_keliling(const Silinder &s) {
  float kel, jari;

  jari = s.cir.jari;
  kel = 2 * pi * jari;
  return kel;
}
float cari_luas(const Lingkaran &l) {
  float jari, luas;
  
  jari = l.jari;
  luas = pi * jari * jari;
  return luas;
}
float cari_luas(const Silinder &s) {
  float jari, luas;

  jari = s.cir.jari;
  luas = pi * jari * jari;
  return luas;
}
float cari_luas(const Balok &b) {
  float luas, p, l, t;

  p = b.p;
  l = b.l;
  t = b.t;

  luas = 2 * (p * l + p * t + l * t);
  return luas;
}
float cari_volume(const Silinder &s) {
  float jari, tinggi, vol, luas_ling;

  jari = s.cir.jari;
  tinggi = s.t;
  luas_ling = pi * jari * jari;
  vol = luas_ling * tinggi;
  return vol;
}
float cari_volume(const Balok &b) {
  float p, l, t, vol;

  p = b.p;
  l = b.l;
  t = b.t;

  vol = p * l * t;
  return vol;
}
