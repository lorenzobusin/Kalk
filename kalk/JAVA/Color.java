
public class Color{

  private int r, g, b;

  Color(int red, int green, int blue){

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

  }//Color Constructor

  Color(Color c){
    this(c.r, c.g, c.b);
  }//Copy Constructor

  Color(){
    this(0, 0, 0);
  }//Color Constructor

  int value(){
    return r + g + b;
  }//value

  double avg(){
      return (r+g+b)/3;
  }//avg
  
  Color sum( Color c){
      return new Color(r + c.r, g + c.g, b + c.b);
  }//addition
  
  Color substract(Color c){
      return new Color(r - c.r, g - c.g, b - c.b);
  }//substract
  
  Color division(int i){
      return new Color(r / i, g / i, b / i);
  }//division
  
  Color multiplication(int i){
      return new Color(r * i, g * i, b * i);
  }//multiplication
  
  Color mod(int i){
      return new Color(r % i, g % i, b % i);
  }//mod
  
  void negation(){
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
  }//negation
  
  boolean greaterThan( Color c){
      return avg() > c.avg();
  }//greaterThan
  
  boolean lessThan( Color c){
      return avg() < c.avg();
  }//lesserThan
  
  boolean equalTo( Color c){
      return (r == c.r) && (g == c.g) && (b == c.b);
  }//equalTo
  
  void print(){
      System.out.println("RGB(" + r + ", " + g + ", " + b + ")");
      System.out.println();
  }//print

}//Color
