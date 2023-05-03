#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    void Fraction::_simplify()
    {
        cout<<"_simplify()"<<endl;
        cout << "_nom = " << _nom << endl;
        cout << "_den = " << _den << endl;
        int gcd = std::gcd(_nom, _den);
        cout << "gcd = " << gcd << endl;
        if (gcd != 0)
        {
            _nom /= gcd;
            _den /= gcd;
        }
        cout << "_nom()= " << getNumerator() << endl;
        cout << "_den()= " << getDenominator() << endl;
    }

    Fraction::Fraction() : _nom(0), _den(1) {}
    Fraction::Fraction(int nom, int den) : _nom(nom), _den(den)
    {
        cout << "Fraction(int nom, int den)"<<endl;
        cout << "_nom = " << nom << endl;
        cout << "_den = " << den << endl;
        if (den == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        // exceedsIntMax(nom/den);
        _nom = nom;
        _den = den;
        cout << "Hello " << endl;
        _simplify();
    }
    // Fraction::Fraction(int nom) : _nom(nom), _den(1) {}
    Fraction::Fraction(float num)
    {
        // decimal_point(num);
        cout << "Fraction(float num)\nnum = " << num << endl;
        num = roundf(num * 1000) / 1000;
        cout << "num.3 = " << num << endl;
        cout << "(int)(num * 1000) = " << (int)(num * 1000) << endl;
        Fraction((int)(num * 1000), 1000);
        // _nom = num * 1000;
        // _den = 1000;
        // _simplify();
    }
    // Fraction::Fraction(const Fraction &other) // copy ctor
    // {
    // }

    // return 3 digits after the decimal point
    // void decimal_point(float &num)
    // {
    //     // cout.setf(ios::fixed, ios::floatfield);
    //     // cout.precision(3);
    //     num = roundf(num * 1000) / 1000;
    // }

    void exceedsIntMax(const long &value)
    {
        if (value > INT_MAX || value < INT_MIN)
        {
            throw overflow_error("invalid input");
        }
    }

    void exceedsTwoIntMax(const long &num_1, const long &num_2)
    {
        exceedsIntMax(num_1);
        exceedsIntMax(num_2);
        exceedsIntMax(num_1/num_2);
    }

    // Fraction Fraction::floatToFraction(float num)
    // {
    //     decimal_point(num);
    //     return Fraction(num*1000, 1000);
    // }

    // signFraction() return true if sign >= 0, false if sign < 0
    bool Fraction::signFraction() const 
    {
        if (getNumerator() >= 0 && getDenominator() >= 0 || getNumerator() < 0 && getDenominator() < 0)
            return true; //positive
        else
            return false; //negative
    }

    /*Arithmetic operations on a Fraction*/
    const Fraction Fraction::operator+(const Fraction &other) const
    {
        long nomL = getNumerator() * other.getDenominator() + other.getNumerator() * getDenominator();
        long denL = getDenominator() * other.getDenominator();
        exceedsTwoIntMax(nomL, denL);
        return Fraction((int)nomL, (int)denL); ////// (int) - ?
    }
    const Fraction Fraction::operator-(const Fraction &other) const
    {
        long nomL = getNumerator() * other.getDenominator() - other.getNumerator() * getDenominator();
        long denL = getDenominator() * other.getDenominator();
        exceedsTwoIntMax(nomL, denL);
        return Fraction(nomL, denL); ////// (int) - ?
    }
    const Fraction Fraction::operator*(const Fraction &other) const
    {
        long nomL = getNumerator() * other.getNumerator();
        long denL = getDenominator() * other.getDenominator();
        exceedsTwoIntMax(nomL, denL);
        return Fraction(nomL, denL); ////// (int) - ?
    }
    const Fraction Fraction::operator/(const Fraction &other) const
    {
        long nomL = getNumerator() * other.getDenominator();
        long denL = getDenominator() * other.getNumerator();
        exceedsTwoIntMax(nomL, denL);
        return Fraction(nomL, denL); ////// (int) - ?
    }

    /*Arithmetic operations on a float*/
    const Fraction Fraction::operator+(const float &num) const
    {
        return *this + Fraction(num);
    }
    const Fraction Fraction::operator-(const float &num) const
    {
        return *this - Fraction(num);
    }
    const Fraction Fraction::operator*(const float &num) const
    {
        return *this * Fraction(num);
    }
    const Fraction Fraction::operator/(const float &num) const
    {
        return *this / Fraction(num);
    }

    /*Friends arithmetic operations*/
    const Fraction operator+(const float &num, const Fraction &frac)
    {
        return Fraction(num) + frac;
    }
    const Fraction operator-(const float &num, const Fraction &frac)
    {
        return Fraction(num) - frac;
    }
    const Fraction operator*(const float &num, const Fraction &frac)
    {
        return Fraction(num) * frac;
    }
    const Fraction operator/(const float &num, const Fraction &frac)
    {
        return Fraction(num) / frac;
    }

    /*Equality check*/
    bool Fraction::operator==(const Fraction &other) const 
    {
        if (signFraction()!=other.signFraction())
            return false; 
        return (getNumerator() == other.getNumerator() && getDenominator() == other.getDenominator())
                || (getNumerator()*(-1) == other.getNumerator() && getDenominator()*(-1) == other.getDenominator());
    }
    bool Fraction::operator==(const float &other) const
    {
        return *this == Fraction(other);
    }
    bool operator==(const float &other, const Fraction &frac) // friend function
    {
        return Fraction(other) == frac;
    }
    bool Fraction::operator!=(const Fraction &other) const
    {
        return !(*this == other);
    }
    bool Fraction::operator!=(const float &other) const
    {
        return !(*this == Fraction(other));
    }
    bool operator!=(const float &other, const Fraction &frac) // friend function
    {
        return !(Fraction(other) == frac);
    }

    /*Ratio between Fractions*/
    bool Fraction::operator>(const Fraction &other) const
    {
        // if (!signFraction() && other.signFraction())
        //     return false; 
        // if (*this == other) // signFraction() return true if sign >= 0
        //     return false;
        return !((other-*this).signFraction()); // signFraction() return true if sign >= 0
    }
    bool Fraction::operator<(const Fraction &other) const
    {
        return !((*this-other).signFraction());
    }
    bool Fraction::operator>=(const Fraction &other) const
    {
        return (*this-other).signFraction();
    }
    bool Fraction::operator<=(const Fraction &other) const
    {
        return (other-*this).signFraction();
    }

    /*Ratio between Fraction and float*/
    bool Fraction::operator>(const float &other) const
    {
        return *this > Fraction(other);
    }
    bool Fraction::operator<(const float &other) const
    {
        return *this < Fraction(other); 
    }
    bool Fraction::operator>=(const float &other) const
    {
        return *this >= Fraction(other);
    }
    bool Fraction::operator<=(const float &other) const
    {
        return *this <= Fraction(other);
    }

    /*friend Ratio between Fraction and float*/
    bool operator>(const float &num, const Fraction &other)
    {
        return !((other-Fraction(num)).signFraction());
    }
    bool operator<(const float &num, const Fraction &other)
    {
        return !((Fraction(num)-other).signFraction());
    }
    bool operator>=(const float &num, const Fraction &other)
    {
        return (Fraction(num)-other).signFraction();
    }
    bool operator<=(const float &num, const Fraction &other)
    {
        return (other-Fraction(num)).signFraction();
    }

    ///////////////////// NOT IMPLEMENT START /////////////////////

    // /*Additional operations on fractions*/
    // Fraction &operator+=(Fraction &frac, const Fraction &other)
    // {
    //     return frac;
    // }
    // Fraction &operator-=(Fraction &frac, const Fraction &other)
    // {
    //     return frac;
    // }
    // Fraction &operator*=(Fraction &frac, const Fraction &other)
    // {
    //     return frac;
    // }
    // Fraction &operator/=(Fraction &frac, const Fraction &other)
    // {
    //     return frac;
    // }

    // Fraction &operator+=(Fraction &frac, const float &num)
    // {
    //     return frac;
    // }
    // Fraction &operator-=(Fraction &frac, const float &num)
    // {
    //     return frac;
    // }
    // Fraction &operator*=(Fraction &frac, const float &num)
    // {
    //     return frac;
    // }
    // Fraction &operator/=(Fraction &frac, const float &num)
    // {
    //     return frac;
    // }

    // const Fraction Fraction::operator+() const
    // {
    //     return Fraction();
    // }
    // const Fraction Fraction::operator-() const
    // {
    //     return Fraction();
    // }
    ///////////////////// NOT IMPLEMENT END /////////////////////

    Fraction &Fraction::operator++() // Prefix (++n)
    {
        *this = *this + 1.0;
        return *this;
    }
    Fraction &Fraction::operator--() // Prefix (--n)
    {
        *this = *this - 1.0;
        return *this;
    }
    const Fraction Fraction::operator++(int) // Postfix (n++)
    {
        Fraction temp(*this);
        *this = *this + 1.0;
        return temp;
    }
    const Fraction Fraction::operator--(int) // Postfix (n--)
    {
        Fraction temp(*this);
        *this = *this - 1.0;
        return temp;
    }

    /*output - input*/
    // std::ostream &operator<<(std::ostream &ost, const Fraction &frac)
    // {
    //     cout << "getNumerator = " << frac.getNumerator() << endl;
    //     cout << "getDenominator = " << frac.getDenominator() << endl;
    //     ost << frac._nom << "/" << frac._den;
    //     return ost;
    // }
    std::ostream &operator<<(std::ostream &ost, const Fraction &frac)
{
    ost << frac.getNumerator() << "/" << frac.getDenominator();
    return ost;
}

    istream &operator>>(istream &ist, Fraction &frac)
    {
        int nom, den;
        char delimiter;
    ist >> nom >> delimiter;

    if (delimiter != '/' || delimiter != ' ') {
        ist.setstate(ios_base::failbit);
        return ist;
    }

    ist >> den;

    frac = Fraction(nom, den);
    // frac.setNumerator(nom);
    // frac.setDenominator(den);

    return ist >> frac;
    }

}
