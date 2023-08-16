#ifndef _HELPERS_H
#define _HELPERS_H

#include <vector>
#include <array>
#include<exception>
#include<string>
#include<iostream>

template <typename T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
{
    std::vector<T> vr(std::begin(v1), std::end(v1));
    vr.insert(std::end(vr), std::begin(v2), std::end(v2));
    return vr;
}

std::string assertLength(std::string value, unsigned length)
{
    if (value.length() > length)
    {
        throw std::runtime_error("too long");
    }

    return value;
}

template <typename T>
std::vector<T>& assertLength(const std::vector<T>& value, unsigned length)
{
    if (value.length() > length)
    {
        throw std::runtime_error("too long");
    }

    return value;
}

double assertInRange(double value, double min, double max)
{
    if (value < min || value > max)
    {
        throw std::runtime_error("out of range");
    }

    return value;
}

#endif // !_HELPERS_H
