
//file Color.h

#ifndef Color_H
#define Color_H

#include <string>

class Color {

private:

  int r, g, b;

  friend std::ostream& operator<<(std::ostream&, const Color&);

public:

  Color(int =0, int =0, int =0);
  Color(const Color& c);

  int getR() const;
  int getG() const;
  int getB() const;
  double avg() const;
  std::string rgbToHex() const;
  std::string print() const ;

  void setColor(int =0, int =0, int =0);

  Color* operator+(const Color) const ;
  Color* operator-(const Color) const ;

  Color* operator*(int i) const;
  Color* operator/(int i) const;
  Color* operator%(int i) const;

  bool operator==(const Color) const;
  bool operator>(const Color) const;
  bool operator<(const Color) const;

  void operator!();

  virtual ~Color() =default;

};//class Color

  std::ostream& operator<<(std::ostream&, const Color&) ;
  std::istream& operator>>(std::istream&, Color&);

#endif
