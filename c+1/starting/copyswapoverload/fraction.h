


class Fraction{
  public:
    Fraction(int num,int den);
    ~Fraction();
    Fraction(Fraction &source);
    //without idiom
    // Fraction & operator=(Fraction & frac);
    //with idiom added & to differentiate between l and r values
    Fraction & operator=(Fraction  frac);
    friend void swap(Fraction &frac, Fraction &fractwo);
    // Fraction & operator=(Fraction && frac);
  private:
    int num;
    int den;
};
