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
        int gcd = (_nom != 0) ? std::gcd(_nom, _den) : _den;
        if (gcd != 0)
        {
            _nom /= gcd;
            _den /= gcd;
        }
    }

    /* constructors */
    Fraction::Fraction() : _nom(0), _den(1) {}

    Fraction::Fraction(int nom, int den) : _nom(nom), _den(den)
    {
        if (den == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        _nom = nom;
        _den = den;
        _simplify();
    }

    Fraction::Fraction(float num) : _nom((int)(num * 1000)), _den(1000)
    {
        Fraction((int)(num * 1000), 1000);
        _simplify();
    }

    /* Auxiliary functions */
    // exceeds INT_MAX
    void exceedsIntMax(const long &value)
    {
        if (value > INT_MAX || value < INT_MIN)
        {
            throw overflow_error("invalid input");
        }
    }
    // Send 2 floats to exceedsIntMax()
    void exceedsTwoIntMax(const long &num_1, const long &num_2)
    {
        exceedsIntMax(num_1);
        exceedsIntMax(num_2);
    }
    // Return true for fraction >= 0, return false for fraction < 0
    bool Fraction::signFraction() const
    {
        if (getNumerator() >= 0 && getDenominator() >= 0)
            return true; // positive
        else
            return false; // negative
    }

    /*Arithmetic operations on a Fraction*/
    const Fraction Fraction::operator+(const Fraction &other) const
    {
        long nomL = (long)getNumerator() * other.getDenominator() + (long)other.getNumerator() * getDenominator();
        long denL = (long)getDenominator() * other.getDenominator();
        exceedsTwoIntMax(nomL, denL);
        return Fraction(nomL, denL);
    }

    const Fraction Fraction::operator-(const Fraction &other) const
    {
        long nomL = (long)getNumerator() * other.getDenominator() - (long)other.getNumerator() * getDenominator();
        long denL = (long)getDenominator() * other.getDenominator();
        exceedsTwoIntMax(nomL, denL);
        return Fraction(nomL, denL);
    }

    const Fraction Fraction::operator*(const Fraction &other) const
    {
        long nomL = (long)getNumerator() * other.getNumerator();
        long denL = (long)getDenominator() * other.getDenominator();
        exceedsTwoIntMax(nomL, denL);
        return Fraction(nomL, denL);
    }

    const Fraction Fraction::operator/(const Fraction &other) const
    {
        if (other == 0)
        {
            throw runtime_error("Denominator cannot be zero.");
        }
        long nomL = (long)getNumerator() * other.getDenominator();
        long denL = (long)getDenominator() * other.getNumerator();
        exceedsTwoIntMax(nomL, denL);
        return Fraction(nomL, denL);
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
        if (signFraction() != other.signFraction())
            return false;
        return getNumerator() == other.getNumerator() && getDenominator() == other.getDenominator();
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

    /* Prefix & Postfix */
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

    /* Output & Input */
    std::ostream &operator<<(std::ostream &ost, const Fraction &frac)
    {
        ost << frac.getNumerator() << "/" << frac.getDenominator();
        return ost;
    }

    istream &operator>>(istream &ist, Fraction &frac)
    {
        int nom = 0, den = 0;
        ist >> nom >> den;
        if (ist.fail())
        {
            throw runtime_error("ilegal input");
        }

        if (den == 0)
        {
            throw runtime_error("ilegal input");
        }

        frac.setNumerator(nom);
        frac.setDenominator(den);
        frac._simplify();
        return ist;
    }

}
