#pragma once
#include "raw_objs/sys_vars.h"
#include "raw_objs/pointer_wrapper.h"
#include "raw_objs/NoneObj.h"
#include <iostream>
#include <utility>

Type isinstance(const Type& other, const std::string& metadata) {
    return Type(new BoolObj(other.getType_() == metadata));
}

Type type(const Type& other) {
    return Type(new StringObj(other.getType_()));
}

Type str(const Type& other) {
    return Type(new StringObj(other.objPointer->str()));
}

Type boolean(const Type& other) {
    return Type(new BoolObj(other.objPointer->boolean()));
}

Type intT(const Type& other) {
    return Type(new IntObj(other.objPointer->intD()));
}

Type floatT(const Type& other) {
    return Type(new FloatObj(other.objPointer->floatD()));
}

const Type& print(const Type& other, const Type& end = Type(new StringObj("\n"))) {
    std::cout << str(other).getString() << str(end).getString();
    return None;
}

Type input(const Type& other = Type(new StringObj(""))) {
    std::string found{};
    print(other, Type(new StringObj("")));
    std::getline(std::cin, found);
    return Type(new StringObj(std::move(found)));
}

Type getMaxStringLenght() {return Type(new IntObj(MAX_STRING_LENGTH));}

const Type& setMaxStringLength(const Type& l) {
    MAX_STRING_LENGTH = l.objPointer->intD();
    return None;
}

