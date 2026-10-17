#pragma once
#include "dtypes.h"
#include "basic_operations.h"
#include "sys_vars.h"
#include <stdexcept>

//-----------*FIRST DISPATCH IMPLEMENTATION*-----------

//ADD FIRST DISPATCH INT.ADD

Object* IntObj::add(const Object* other) const {
    return other->radd(this);
}

//ADD FIRST DISPATCH INT.SUB

Object* IntObj::sub(const Object* other) const {
    return other->rsub(this);
}

//ADD FIRST DISPATCH INT.MUL

Object* IntObj::div(const Object* other) const {
    return other->rdiv(this);
}

//ADD FIRST DISPATCH INT.DIV

Object* IntObj::mul(const Object* other) const {
    return other->rmul(this);
}


//-----------*SECOND DISPATCH IMPLEMENTATION*-----------

//ADD INT, INT

Object* IntObj::radd(const IntObj* other) const {
    return new IntObj{*(other->getInt()) + data};
}

//ADD INT, FLOAT

Object* IntObj::radd(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() + static_cast<long double>(data)};
}

//ADD INT, STRING

Object* IntObj::radd(const StringObj* other) const {
    throw std::logic_error("Cannot add types 'string' and 'int'.");
    return nullptr;
}

//SUB INT, INT

Object* IntObj::rsub(const IntObj* other) const {
    return new IntObj{*other->getInt() - data};
}

//SUB INT, FLOAT

Object* IntObj::rsub(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() - static_cast<long double>(data)};
}

// SUB INT, STRING

Object* IntObj::rsub(const StringObj* other) const {
    throw std::logic_error("Cannot subtract types 'string' and 'int'.");
    return nullptr;
}

//MUL INT, INT

Object* IntObj::rmul(const IntObj* other) const {
    return new IntObj{*other->getInt() * data};
}

//MUL INT, FLOAT

Object* IntObj::rmul(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() * static_cast<long double>(data)};
}

//MUL INT, STRING

Object* IntObj::rmul(const StringObj* other) const {
    if ((*other->getString()).size() * data > MAX_STRING_LENGTH) throw std::overflow_error("String length is greater than MAX_STRING_LENGTH.");
    return new StringObj{mulString(*other->getString(), data)};
}

//DIV INT, INT

Object* IntObj::rdiv(const IntObj* other) const {
    return new FloatObj{static_cast<long double>(*other->getInt())
                         / static_cast<long double>(data)};
}

//DIV INT, FLOAT

Object* IntObj::rdiv(const FloatObj* other) const {
    return new FloatObj{*other->getFloat() / static_cast<long double>(data)};
}

//DIV INT, STRING

Object* IntObj::rdiv(const StringObj* other) const {
    throw std::logic_error("Cannot divide types 'string' and 'int'.");
    return nullptr;
}

//-----------*INVALID FUNCTIONS*-----------

const std::string* IntObj::getString() const {
    throw std::logic_error("Cannot extract 'string' from 'int'.");
    return nullptr;
}

const long double* IntObj::getFloat() const {
    throw std::logic_error("Cannot extract 'float' from 'int'.");
    return nullptr;
}