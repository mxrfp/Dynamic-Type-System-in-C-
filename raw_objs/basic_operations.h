#pragma once
#include <string>
#include <stdexcept>

//function used for string multiplication

std::string mulString(const std::string& s, const long long int& n) {
    if (n <= 0) return "";
    std::string newS{};
    newS.reserve(s.size() * n);

    for (int i = 0; i < n; ++i) {
        newS += s;
    }

    return newS;
}