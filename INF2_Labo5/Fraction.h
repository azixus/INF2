/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : Fraction.cpp
 Auteur(s)   : Robin Müller
 Date        : 20.03.2019

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

/**
 * Classe fraction générique permettant de stocker deux nombres sous forme d'une fraction.
 * @tparam T type de numérateur et du dénominateur de la fraction.
 */
template<typename T> class Fraction;

/**
 * Surcharge de l'opérateur + pour pouvoir additoner 2 fractions
 * @tparam T défini le type de l'opérateur
 * @param lhs Fraction de type T 
 * @param rhs Fraction de type T pour 
 * @return
 */
template<typename T>
Fraction<T> operator+(Fraction<T> lhs, const Fraction<T>& rhs);

/**
 *
 * @tparam T
 * @param lhs
 * @param rhs
 * @return
 */
template<typename T>
Fraction<T> operator*(Fraction<T> lhs, const Fraction<T>& rhs);

/**
 *
 * @tparam T
 * @param os
 * @param fraction
 * @return
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, Fraction<T> fraction);

template<typename T>
class Fraction {
    friend std::ostream& operator<< <T>(std::ostream& os, Fraction<T> fraction);
    friend Fraction<T> operator+ <T>(Fraction<T> lhs, const Fraction<T>& rhs);
    friend Fraction<T> operator* <T>(Fraction<T> lhs, const Fraction<T>& rhs);

public:
    /**
     *
     * @param numerateur
     * @param denominateur
     */
    Fraction(T numerateur, T denominateur);

    /**
     *
     * @param rhs
     * @return
     */
    bool operator==(const Fraction<T>& rhs) const;

    /**
     *
     * @param rhs
     * @return
     */
    Fraction<T>& operator+=(Fraction<T> rhs);

    /**
     *
     * @param rhs
     * @return
     */
    Fraction<T>& operator*=(const Fraction<T>& rhs);

    /**
     *
     * @return
     */
    operator float() const;

    /**
     *
     * @return
     */
    operator double() const;

    /**
     *
     * @param rhs
     * @return
     */
    bool identite(const Fraction<T>& rhs) const;

    /**
     *
     * @return
     */
    Fraction<T> simplifier();

private:
    T numerateur;
    T denominateur;

    static T pgcd(T a, T b);

    /**
     *
     * @param a
     * @param b
     * @return
     */
    static T ppcm(T a, T b);
};

#include "FractionImpl.h"

#endif //FRACTION_H
