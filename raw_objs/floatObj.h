#pragma once
#include "dtypes.h"
#include "basic_operations.h"
#include <stdexcept>

//-----------*FIRST DISPATCH IMPLEMENTATION*-----------

//ADD FIRST DISPATCH FLOAT.ADD

Object* FloatObj::add(const Object* other) const {
    return other->radd(this);
}

//ADD FIRST DISPATCH FLOAT.SUB

Object* FloatObj::sub(const Object* other) const {
    return other->rsub(this);
}

//ADD FIRST DISPATCH FLOAT.MUL

Object* FloatObj::div(const Object* other) const {
    return other->rdiv(this);
}

//ADD FIRST DISPATCH FLOAT.DIV

Object* FloatObj::mul(const Object* other) const {
    return other->rmul(this);
}

//-----------*SECOND DISPATCH IMPLEMENTATION*-----------

//ADD FLOAT, FLOAT

Object* FloatObj::radd(const FloatObj* other) const {
    return new FloatObj{*(other->getFloat()) + data};
}

//ADD FLOAT, INT

Object* FloatObj::radd(const IntObj* other) const {
    return new FloatObj{static_cast<long double>(*other->getInt()) + data};
}

//ADD FLOAT, STRING

Object* FloatObj::radd(const StringObj* other) const {
    throw std::logic_error("Cannot add types 'string' and 'float'.");
    return nullptr;
}

//SUB FLOAT, FLOAT

Object* FloatObj::rsub(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() - data};
}

//SUB FLOAT, INT

Object* FloatObj::rsub(const IntObj* other) const {
    return new FloatObj{static_cast<long double>(*other->getInt()) - data};
}

// SUB FLOAT, STRING

Object* FloatObj::rsub(const StringObj* other) const {
    throw std::logic_error("Cannot subtract types 'string' and 'float'.");
    return nullptr;
}

//MUL FLOAT, FLOAT

Object* FloatObj::rmul(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() * data};
}

//MUL FLOAT, INT

Object* FloatObj::rmul(const IntObj* other) const {
    return new FloatObj{static_cast<long double>(*other->getInt()) * data};
}

//MUL FLOAT, STRING

Object* FloatObj::rmul(const StringObj* other) const {
    long long int int_data{static_cast<long long int>(data)};
    if ((*other->getString()).size() * int_data > MAX_STRING_LENGTH) throw std::overflow_error("String length is greater than MAX_STRING_LENGTH.");
    return new StringObj{mulString(*other->getString(), int_data)};
}

//DIV FLOAT, FLOAT

Object* FloatObj::rdiv(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() / data};
}

//DIV FLOAT, INT

Object* FloatObj::rdiv(const IntObj* other) const {
    return new FloatObj{static_cast<long double>(*other->getInt()) / data};
}

//DIV FLOAT, STRING

Object* FloatObj::rdiv(const StringObj* other) const {
    throw std::logic_error("Cannot divide types 'string' and 'float'.");
    return nullptr;
}

//-----------*INVALID FUNCTIONS*-----------

const std::string* FloatObj::getString() const {
    throw std::logic_error("Cannot extract 'string' from 'float'.");
    return nullptr;
}

const long long int* FloatObj::getInt() const {
    throw std::logic_error("Cannot extract 'int' from 'float'.");
    return nullptr;
}