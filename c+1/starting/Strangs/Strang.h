

class Strang {
    public:
        Strang();
        Strang(const char *strange);
        ~Strang();
        Strang(Strang &source);
        Strang(Strang &&source);
        //with copy swap idiom
        // Strang & operator=(Strang source);
        Strang & operator=(Strang &other);
        Strang & operator=(Strang &&other);
        char * getStrang();
    private:
        char * str;
};
