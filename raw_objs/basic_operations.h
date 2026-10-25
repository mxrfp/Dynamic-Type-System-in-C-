#pragma once
#include <string>
#include <charconv>
#include <optional>


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

std::optional<float> parseFloat(const std::string& sv) {
    float f = 0.0f;
    auto [ptr, ec] = std::from_chars(sv.data(), sv.data() + sv.size(), f);
    if (ec != std::errc{} || ptr != sv.data() + sv.size())
        return std::nullopt;
    return f;
}

