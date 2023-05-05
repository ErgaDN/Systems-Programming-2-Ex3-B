#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    void Fraction::_simplify()
    {
        if (_den < 0)
        {
            _nom *= (-1);
            _den *= (-1);
        }
        
        // cout<<"_simplify()"<<endl;
        // cout << "_nom = " << _nom << endl;
        // cout << "_den = " << _den << endl;
        int gcd = (_nom != 0) ? std::gcd(_nom, _den) : _den;
        // cout << "gcd = " << gcd << endl;
        
        if (gcd != 0)
        {
            _nom /= gcd;
            _den /= gcd;
        }
        // cout << "_nom()= " << getNumerator() << endl;
        // cout << "_den()= " << getDenominator() << endl;
    }

    Fraction::Fraction() : _nom(0), _den(1) {}
    Fraction::Fraction(int nom, int den) : _nom(nom), _den(den)
    {
        // cout << "Fraction(int nom, int den)"<<endl;
        // cout << "_nom = " << nom << endl;
        // cout << "_den = " << den << endl;
        if (den == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        // exceedsIntMax(nom/den);
        _nom = nom;
        _den = den;
        // cout << "Send to _simplify" << endl;
        _simplify();
    }
    Fraction::Fraction(float num) : _nom((int)(num * 1000)), _den(1000)
    {
        Fraction((int)(num * 1000), 1000);
        _simplify();
    }
    // Fraction::Fraction(const Fraction &other) : _nom(other.getNumerator()), _den(other.getDenominator())
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
        // cout << "555" << endl;
        // cout << "value = " << value << endl;
        if (value > numeric_limits<int>::max() || value < numeric_limits<int>::min())
        {
            throw overflow_error("invalid input");
        }
        // cout << "666" << endl;
    }

    void exceedsTwoIntMax(const long &num_1, const long &num_2)
    {
        // cout << "444" << endl;
        exceedsIntMax(num_1);
        exceedsIntMax(num_2);
        // exceedsIntMax(num_1 / num_2);
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
            return true; // positive
        else
            return false; // negative
    }

    /*Arithmetic operations on a Fraction*/
    const Fraction Fraction::operator+(const Fraction &other) const
    {
        long nomL = (long)getNumerator() * other.getDenominator() + (long)other.getNumerator() * getDenominator();
        long denL = (long)getDenominator() * other.getDenominator();
        // cout << "nomL = " << nomL << endl;
        // cout << "denL = " << denL << endl;
        exceedsTwoIntMax(nomL, denL);
        return Fraction((int)nomL, (int)denL); ////// (int) - ?
    }
    const Fraction Fraction::operator-(const Fraction &other) const
    {
        long nomL = (long)getNumerator() * other.getDenominator() - (long)other.getNumerator() * getDenominator();
        long denL = (long)getDenominator() * other.getDenominator();
        exceedsTwoIntMax(nomL, denL);
        return Fraction(nomL, denL); ////// (int) - ?
    }
    const Fraction Fraction::operator*(const Fraction &other) const
    {
        long nomL = (long)getNumerator() * other.getNumerator();
        long denL = (long)getDenominator() * other.getDenominator();
        // cout << "111" << endl;
        exceedsTwoIntMax(nomL, denL);
        // cout << "222" << endl;
        // exceedsIntMax(nomL);
        // exceedsIntMax(denL);
        return Fraction(nomL, denL); ////// (int) - ?
    }
    const Fraction Fraction::operator/(const Fraction &other) const
    {
        // cout << "111" << endl;
        if (other == 0)
        {
            throw runtime_error("Denominator cannot be zero.");
        }
        long nomL = (long)getNumerator() * other.getDenominator();
        long denL = (long)getDenominator() * other.getNumerator();
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
        // cout << "222" << endl;
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
        // cout << "333" << endl;
        return Fraction(num) / frac;
    }

    /*Equality check*/
    bool Fraction::operator==(const Fraction &other) const
    {
        if (signFraction() != other.signFraction())
            return false;
        return (getNumerator() == other.getNumerator() && getDenominator() == other.getDenominator()) || (getNumerator() * (-1) == other.getNumerator() && getDenominator() * (-1) == other.getDenominator());
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
        return !((other - *this).signFraction()); // signFraction() return true if sign >= 0
    }
    bool Fraction::operator<(const Fraction &other) const
    {
        return !((*this - other).signFraction());
    }
    bool Fraction::operator>=(const Fraction &other) const
    {
        return (*this - other).signFraction();
    }
    bool Fraction::operator<=(const Fraction &other) const
    {
        return (other - *this).signFraction();
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
        return !((other - Fraction(num)).signFraction());
    }
    bool operator<(const float &num, const Fraction &other)
    {
        return !((Fraction(num) - other).signFraction());
    }
    bool operator>=(const float &num, const Fraction &other)
    {
        return (Fraction(num) - other).signFraction();
    }
    bool operator<=(const float &num, const Fraction &other)
    {
        return (other - Fraction(num)).signFraction();
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
        
        int nom = 0, den = 0;
        // char delimiter = ' ';
        ist >> nom >> den;
        
        // cout << "delimiter = " << delimiter << endl;
        if (ist.fail())
        {
            throw runtime_error("ilegal input");
        }

        // if (delimiter != '/' || delimiter != ' ')
        // {
        //     // ist.setstate(ios_base::failbit);
        //     // return ist;
        //     throw runtime_error("ilegal input_2");
        // }
        // cout << "nom = " << nom << endl;
        // cout << "den = " << den << endl;
        
        // ist >> den;
        if (den == 0)
        {
            throw runtime_error("ilegal input");
        }

        // frac = Fraction(nom, den);
        frac.setNumerator(nom);
        frac.setDenominator(den);
        frac._simplify();

        return ist;
    }

}
