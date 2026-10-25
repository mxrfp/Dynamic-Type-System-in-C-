#pragma once
#include "dtypes.h"
#include <stdexcept>

//-----------*FIRST DISPATCH IMPLEMENTATION*-----------

//ADD FIRST DISPATCH BOOL.ADD

Object* BoolObj::add(const Object* other) const {
    return other->radd(this);
}

//ADD FIRST DISPATCH BOOL.SUB

Object* BoolObj::sub(const Object* other) const {
    return other->rsub(this);
}

//ADD FIRST DISPATCH BOOL.MUL

Object* BoolObj::div(const Object* other) const {
    return other->rdiv(this);
}

//ADD FIRST DISPATCH BOOL.DIV

Object* BoolObj::mul(const Object* other) const {
    return other->rmul(this);
}

//-----------*SECOND DISPATCH IMPLEMENTATION*-----------

//ADD BOOL, INT

Object* BoolObj::radd(const IntObj* other) const {
    return new IntObj{*(other->getInt()) + data};
}

//ADD BOOL, FLOAT

Object* BoolObj::radd(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() + static_cast<long double>(data)};
}

//ADD BOOL, STRING

Object* BoolObj::radd(const StringObj* other) const {
    throw std::logic_error("Cannot add types 'string' and 'bool'.");
    return nullptr;
}

//ADD BOOL, BOOL

Object* BoolObj::radd(const BoolObj* other) const {
    return new IntObj{*other->getBool() + data};
}

//SUB BOOL, INT

Object* BoolObj::rsub(const IntObj* other) const {
    return new IntObj{*other->getInt() - data};
}

//SUB BOOL, FLOAT

Object* BoolObj::rsub(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() - static_cast<long double>(data)};
}

// SUB BOOL, STRING

Object* BoolObj::rsub(const StringObj* other) const {
    throw std::logic_error("Cannot subtract types 'string' and 'bool'.");
    return nullptr;
}

//SUB BOOL, BOOL

Object* BoolObj::rsub(const BoolObj* other) const {
    return new IntObj{*other->getBool() - data};
}

//MUL BOOL, INT

Object* BoolObj::rmul(const IntObj* other) const {
    return new IntObj{*other->getInt() * data};
}

//MUL BOOL, FLOAT

Object* BoolObj::rmul(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() * static_cast<long double>(data)};
}

//MUL BOOL, STRING

Object* BoolObj::rmul(const StringObj* other) const {
    if (data) return new StringObj(*other->getString());
    else return new StringObj("");
}

//MUL BOOL, BOOL

Object* BoolObj::rmul(const BoolObj* other) const {
    return new BoolObj{static_cast<bool>(*other->getBool() * data)};
}

//DIV BOOL, INT

Object* BoolObj::rdiv(const IntObj* other) const {
    return new FloatObj{static_cast<long double>(*other->getInt())
                         / static_cast<long double>(data)};
}

//DIV BOOL, FLOAT

Object* BoolObj::rdiv(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() / static_cast<long double>(data)};
}

//DIV BOOL, STRING

Object* BoolObj::rdiv(const StringObj* other) const {
    throw std::logic_error("Cannot divide types 'string' and 'bool'.");
    return nullptr;
}

//DIV BOOL, BOOL

Object* BoolObj::rdiv(const BoolObj* other) const {
    return new IntObj{*other->getBool() / data};
}

//-----------*OTHER*-----------

std::string BoolObj::str() const {
    if (data) return "True";
    return "False";
}

bool BoolObj::boolean() const {
    return data;
}

long double BoolObj::floatD() const {
    return static_cast<long double>(data);
}

long long int BoolObj::intD() const {
    return static_cast<long long int>(data);
}

//-----------*INVALID FUNCTIONS*-----------

const std::string* BoolObj::getString() const {
    throw std::logic_error("Cannot extract 'string' from 'bool'.");
    return nullptr;
}

const long double* BoolObj::getFloat() const {
    throw std::logic_error("Cannot extract 'float' from 'bool'.");
    return nullptr;
}

const long long int* BoolObj::getInt() const {
    throw std::logic_error("Cannot extract 'int' from 'bool'.");
    return nullptr;
}