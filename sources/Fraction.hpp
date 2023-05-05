#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric>
#include <limits.h>
#include <cmath>

namespace ariel
{

    class Fraction
    {
    private:
        int _nom;
        int _den;

        void _simplify();

    public:
        /* constructors */
        Fraction();
        Fraction(int nom, int den);
        Fraction(float num);

        /* Getter & Setter */
        int getNumerator() const { return _nom; };

        int getDenominator() const { return _den; }

        void setNumerator(int nom) { _nom = nom; }

        void setDenominator(int den)
        {
            if (den == 0)
            {
                throw std::invalid_argument("Denominator cannot be zero.");
            }
            _den = den;
        }

        /* Auxiliary functions */
        friend void exceedsIntMax(const long &value);
        friend void exceedsTwoIntMax(const long &num_1, const long &num_2);
        bool signFraction() const;

        /*Arithmetic operations on a Fraction*/
        const Fraction operator+(const Fraction &other) const;
        const Fraction operator-(const Fraction &other) const;
        const Fraction operator*(const Fraction &other) const;
        const Fraction operator/(const Fraction &other) const;

        /*Arithmetic operations on a float*/
        const Fraction operator+(const float &num) const;
        const Fraction operator-(const float &num) const;
        const Fraction operator*(const float &num) const;
        const Fraction operator/(const float &num) const;

        /*Friends arithmetic operations*/
        friend const Fraction operator+(const float &num, const Fraction &frac);
        friend const Fraction operator-(const float &num, const Fraction &frac);
        friend const Fraction operator*(const float &num, const Fraction &frac);
        friend const Fraction operator/(const float &num, const Fraction &frac);

        /*Equality check*/
        bool operator==(const Fraction &other) const;
        bool operator==(const float &other) const;
        friend bool operator==(const float &other, const Fraction &frac);
        bool operator!=(const Fraction &other) const;
        bool operator!=(const float &other) const;
        friend bool operator!=(const float &other, const Fraction &frac);

        /*Ratio between Fractions*/
        bool operator>(const Fraction &other) const;
        bool operator<(const Fraction &other) const;
        bool operator>=(const Fraction &other) const;
        bool operator<=(const Fraction &other) const;

        /*Ratio between Fraction and float*/
        bool operator>(const float &other) const;
        bool operator<(const float &other) const;
        bool operator>=(const float &other) const;
        bool operator<=(const float &other) const;

        /*friend Ratio between Fraction and float*/
        friend bool operator>(const float &num, const Fraction &other);
        friend bool operator<(const float &num, const Fraction &other);
        friend bool operator>=(const float &num, const Fraction &other);
        friend bool operator<=(const float &num, const Fraction &other);

        /* Prefix & Postfix */
        Fraction &operator++();         // Prefix (++n)
        Fraction &operator--();         // Prefix (++n)
        const Fraction operator++(int); // Postfix (n++)
        const Fraction operator--(int); // Postfix (n++)

        /* Output & Input */
        friend std::ostream &operator<<(std::ostream &ost, const Fraction &frac);
        friend std::istream &operator>>(std::istream &ist, Fraction &frac);
    };
}

#endif