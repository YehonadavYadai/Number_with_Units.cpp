//
// Created by yehonadav2 on 18/04/2021.
//
#include <iostream>

#include <string>
using namespace std;

namespace ariel {
    class NumberWithUnits{

    private:
        double value;
        string unit;

    public:
        NumberWithUnits(double value,const string &unit);
      

        static void read_units(ifstream& units_file);
        friend int compare(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend ostream& operator<<(ostream& out, const NumberWithUnits& t);
        friend istream& operator>>(istream& in, NumberWithUnits& t);
        friend NumberWithUnits operator+(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator+(const NumberWithUnits& n, double a);
        friend NumberWithUnits operator+=(NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator-(const NumberWithUnits& n) ;
        friend NumberWithUnits operator-(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator-(const NumberWithUnits& n ,double a);
        friend NumberWithUnits operator-=(NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator++(NumberWithUnits& n);
        friend NumberWithUnits operator++(NumberWithUnits& n, int);
        friend NumberWithUnits operator--(NumberWithUnits& n);
        friend NumberWithUnits operator--(NumberWithUnits& n, int);
        friend NumberWithUnits operator*(NumberWithUnits& n, double num);
        friend NumberWithUnits operator*(double num, NumberWithUnits& n);
        friend NumberWithUnits operator*=(NumberWithUnits& n, double num);
        friend NumberWithUnits operator*=(double num, NumberWithUnits& n);
        friend bool operator>(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator>=(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator<(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator<=(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator==(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator!=(const NumberWithUnits& n1, const NumberWithUnits& n2);
    };
}