#pragma once
#include "raw_objs/sys_vars.h"
#include "raw_objs/pointer_wrapper.h"
#include <iostream>

bool isinstance(const Type& other, const std::string& metadata) {
    return other.getType_() == metadata;
}

std::string type(const Type& other) {
    return other.getType_();
}

void setMaxStringLength(long long int l) {
    MAX_STRING_LENGTH = l;
}

long long int getMaxStringLenght() {return MAX_STRING_LENGTH;}

