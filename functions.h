#pragma once
#include "raw_objs/sys_vars.h"
#include "raw_objs/pointer_wrapper.h"
#include <iostream>
#include <utility>

Type isinstance(const Type& other, const std::string& metadata) {
    return Type(standardMemPool.push(BoolObj(other.getType_() == metadata)));
}

Type type(const Type& other) {
    return Type(standardMemPool.push(StringObj(other.getType_())));
}

Type str(const Type& other) {
    return Type(standardMemPool.push(StringObj(other.objPointer->str())));
}

Type boolean(const Type& other) {
    return Type(standardMemPool.push(BoolObj(other.objPointer->boolean())));
}

Type intT(const Type& other) {
    return Type(standardMemPool.push(IntObj(other.objPointer->intD())));
}

Type floatT(const Type& other) {
    return Type(standardMemPool.push(FloatObj(other.objPointer->floatD())));
}

const Type& print(const Type& other, const Type& end = Type(standardMemPool.push(StringObj("\n")))) {
    std::cout << str(other).getString() << str(end).getString();
    return None;
}

Type input(const Type& other = Type(standardMemPool.push(StringObj("")))) {
    std::string found{};
    print(other, Type(standardMemPool.push(StringObj(""))));
    std::getline(std::cin, found);
    return Type(standardMemPool.push(StringObj(std::move(found))));
}

Type getMaxStringLenght() {return Type(standardMemPool.push(IntObj(MAX_STRING_LENGTH)));}

const Type& setMaxStringLength(const Type& l) {
    MAX_STRING_LENGTH = l.objPointer->intD();
    return None;
}

