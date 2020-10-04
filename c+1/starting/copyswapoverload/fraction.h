class Fraction{
    public:
      Fraction(int num,int den);
      ~Fraction();
      //copy assignment operator overload
      Fraction &operator=(Fraction &frac);
      //move assignment operator overload
      Fraction &operator=(Fraction &&frac);
      //move constructor
      Fraction(Fraction &&source);
      //copy constructor
      Fraction(Fraction &source);
      Fraction operator+(Fraction &frac);
      double toDouble(){
        return (double)num/den;
      }
      int getDen(){return den;};
      int getNum(){return num;};
      Fraction();
    private:
      int num;
      int den;
};
