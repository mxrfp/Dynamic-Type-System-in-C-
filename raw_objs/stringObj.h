#pragma once
#include "dtypes.h"
#include "basic_operations.h"
#include "intObj.h"
#include "sys_vars.h"
#include <stdexcept>

StringObj::StringObj(const std::string& d) {
    if (data.size() >= MAX_STRING_LENGTH) throw std::overflow_error("String length is greater than MAX_STRING_LENGTH.");
    data = d;
}

//-----------*FIRST DISPATCH IMPLEMENTATION*-----------

//ADD FIRST DISPATCH STRING.ADD

Object* StringObj::add(const Object* other) const {
    return other->radd(this);
}

//ADD FIRST DISPATCH STRING.SUB

Object* StringObj::sub(const Object* other) const {
    return other->rsub(this);
}

//ADD FIRST DISPATCH STRING.MUL

Object* StringObj::div(const Object* other) const {
    return other->rdiv(this);
}

//ADD FIRST DISPATCH STRING.DIV

Object* StringObj::mul(const Object* other) const {
    return other->rmul(this);
}


//-----------*SECOND DISPATCH IMPLEMENTATION*-----------

//ADD STRING, STRING

Object* StringObj::radd(const StringObj* other) const {
    return new StringObj{*(other->getString()) + data};
}

//ADD STRING, INT

Object* StringObj::radd(const IntObj* other) const {
    throw std::logic_error("Cannot add types 'int' and 'string'.");
    return nullptr;
}

//ADD STRING, FLOAT

Object* StringObj::radd(const FloatObj* other) const {
    throw std::logic_error("Cannot add types 'float' and 'string'.");
    return nullptr;
}

//SUB STRING, STRING

Object* StringObj::rsub(const StringObj* other) const {
    throw std::logic_error("Cannot subtract types 'string' and 'string'.");
    return nullptr;
}

//SUB STRING, INT

Object* StringObj::rsub(const IntObj* other) const {
    throw std::logic_error("Cannot subtract types 'int' and 'string'.");
    return nullptr;
}

// SUB STRING, FLOAT

Object* StringObj::rsub(const FloatObj* other) const {
    throw std::logic_error("Cannot subtract types 'float' and 'string'.");
    return nullptr;
}

//MUL STRING, STRING

Object* StringObj::rmul(const StringObj* other) const {
    throw std::logic_error("Cannot multiply types 'string' and 'string'.");
    return nullptr;
}

//MUL STRING, INT

Object* StringObj::rmul(const IntObj* other) const {
    return other->mul(this);
}

//MUL STRING, FLOAT

Object* StringObj::rmul(const FloatObj* other) const {
    if (*(other->getFloat()) == static_cast<long long int>(*(other->getFloat()))) {
        return IntObj{static_cast<long long int>(*(other->getFloat()))}.mul(this);
    } else {
        throw std::logic_error("Cannot multiply types 'float' and 'string'.");
        return nullptr;
    }
}

//DIV STRING, STRING

Object* StringObj::rdiv(const StringObj* other) const {
    throw std::logic_error("Cannot divide types 'string' and 'string'.");
    return nullptr;
}

//DIV STRING, INT

Object* StringObj::rdiv(const IntObj* other) const {
    throw std::logic_error("Cannot divide types 'int' and 'string'.");
    return nullptr;
}

//DIV STRING, FLOAT

Object* StringObj::rdiv(const FloatObj* other) const {
    throw std::logic_error("Cannot divide types 'float' and 'string'.");
    return nullptr;
}

//-----------*INVALID FUNCTIONS*-----------

const long long int* StringObj::getInt() const {
    throw std::logic_error("Cannot extract 'int' from 'string'.");
    return nullptr;
}

const long double* StringObj::getFloat() const {
    throw std::logic_error("Cannot extract 'float' from 'string'.");
    return nullptr;
}