
//file Color.cpp

#include <iostream>
#include <string>
#include <stdlib.h>

#include "color.h"

Color::Color(int red, int green, int blue){

  if(red > 255)
    red = 255;

  if(green > 255)
    green = 255;

  if(blue > 255)
    blue = 255;

  if(red < 0)
    red = 0;

  if(green < 0)
    green = 0;

  if(blue < 0)
    blue = 0;

  r = red;
  g = green;
  b = blue;

}//costruttore

Color::Color(const Color& c){
  r = c.r;
  g = c.g;
  b = c.b;
}//costruttore di copia

int Color::getR() const{
    return r;
}

int Color::getG() const{
    return g;
}

int Color::getB() const{
    return b;
}

double Color::avg() const {
    return (r+g+b)/3;
}

void Color::setColor(int r1, int g1, int b1){
    if(r1 > 255)
      r1 = 255;

    if(g1 > 255)
      g1 = 255;

    if(b1 > 255)
      b1 = 255;

    if(r1 < 0)
      r1 = 0;

    if(g1 < 0)
      g1 = 0;

    if(b1 < 0)
      b1 = 0;

    r = r1;
    g = g1;
    b = b1;
}

std::string Color::rgbToHex() const{

    std::string d = "0123456789ABCDEF";
    std::string hex;

    int r_temp = r, g_temp = g, b_temp = b;

    while(b_temp > 0){
        hex = d[b_temp % 16] + hex;
        b_temp /= 16;
    }//while

    if(b < 16)
        hex = "0" + hex;

    while(g_temp > 0){
        hex = d[g_temp % 16] + hex;
        g_temp /= 16;
    }//while

    if(g < 16)
        hex = "0" + hex;

    while(r_temp > 0){
        hex = d[r_temp % 16] + hex;
        r_temp /= 16;
    }//while

    if(r < 16)
        hex = "0" + hex;

    return "#" + hex;

}//rgbToHex

Color* Color::operator+(const Color c) const {
    return new Color(r + c.r, g + c.g, b + c.b);
}//operator+

Color* Color::operator-(const Color c) const {
    return new Color(r - c.r, g - c.g, b - c.b);
}//operator+

Color* Color::operator*(int i) const {
  return new Color(r * i, g * i, b * i);
}//operator*

Color* Color::operator/(int i) const {
  return new Color(r / i, g / i, b / i);
}//operator/

Color* Color::operator%(int i) const {
  return new Color(r % i, g % i, b % i);
}//operator%

bool Color::operator==(const Color c) const {
  return (r == c.r) && (g == c.g) && (b == c.b);
}//operator==

bool Color::operator<(const Color c) const {
    return avg() < c.avg();
    //return (r < c.r) && (g < c.g) && (b < c.b);
}//operator<

bool Color::operator>(const Color c) const {
    return avg() > c.avg();
    //return (r > c.r) && (g > c.g) && (b > c.b);
}//operator>

void Color::operator!(){
  r = 255 - r;
  g = 255 - g;
  b = 255 - b;
}//operator!

std::string Color::print() const {

    std::string rgb = "rgb(";
    rgb += std::to_string(r);
    rgb += ", ";
    rgb += std::to_string(g);
    rgb += ", ";
    rgb += std::to_string(b);
    rgb += ")";

    return rgb;

}//print

std::ostream& operator<<(std::ostream& os, const Color& c) {
  os<<"RGB("<<c.r<<" , "<<c.g<<" , "<<c.b<<") ";
  return os;
}//operator<<

std::istream& operator>>(std::istream& is, Color& c){

  /*
    How to move the cursor in the bash:
    http://www.tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html
  */

  int r_temp, g_temp, b_temp;

  std::cout<<"\nInserire i valori (0 - 255) in ordine C(r , g , b): C( \033[s";
  is>>r_temp;

  while(is.fail()){
    is.clear ();
    is.ignore (100,'\n');
    std::cout<<"\033[u";
    is>>r_temp;
  }//while

  std::cout<<"\033[u\033["<<std::to_string(r_temp).length()<<"C , \033[s";
  is>>g_temp;

  while(is.fail()){
    is.clear ();
    is.ignore (100,'\n');
    std::cout<<"\033[u";
    is>>g_temp;
  }//while

  std::cout<<"\033[u\033["<<std::to_string(g_temp).length()<<"C , \033[s";
  is>>b_temp;

  while(is.fail()){
    is.clear ();
    is.ignore (100,'\n');
    std::cout<<"\033[u";
    is>>b_temp;
  }//while

  std::cout<<"\033[u\033["<<std::to_string(b_temp).length()<<"C );\n";

  c = Color(r_temp, g_temp, b_temp);

  return is;

}//operator>>
