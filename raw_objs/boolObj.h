#pragma once
#include "dtypes.h"
#include "MemPool.h"
#include <stdexcept>
#include "pointer_wrapper.h"

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

//ADD FIRST DISPATCH BOOL.EQ

const Type& BoolObj::eq(const Object* other) const {
    return other->req(this);
}

//-----------*SECOND DISPATCH IMPLEMENTATION*-----------

//ADD BOOL, INT

Object* BoolObj::radd(const IntObj* other) const {
    return standardMemPool.push(IntObj{*(other->getInt()) + data});
}

//ADD BOOL, FLOAT

Object* BoolObj::radd(const FloatObj* other) const {
    return standardMemPool.push(FloatObj{*other->getFloat() + static_cast<double>(data)});
}

//ADD BOOL, STRING

Object* BoolObj::radd(const StringObj* other) const {
    throw std::logic_error("Cannot add types 'string' and 'bool'.");
    return nullptr;
}

//ADD BOOL, BOOL

Object* BoolObj::radd(const BoolObj* other) const {
    return standardMemPool.push(IntObj{*other->getBool() + data});
}

//SUB BOOL, INT

Object* BoolObj::rsub(const IntObj* other) const {
    return standardMemPool.push(IntObj{*other->getInt() - data});
}

//SUB BOOL, FLOAT

Object* BoolObj::rsub(const FloatObj* other) const {
    return standardMemPool.push(FloatObj{*other->getFloat() - static_cast<double>(data)});
}

// SUB BOOL, STRING

Object* BoolObj::rsub(const StringObj* other) const {
    throw std::logic_error("Cannot subtract types 'string' and 'bool'.");
    return nullptr;
}

//SUB BOOL, BOOL

Object* BoolObj::rsub(const BoolObj* other) const {
    return standardMemPool.push(IntObj{*other->getBool() - data});
}

//MUL BOOL, INT

Object* BoolObj::rmul(const IntObj* other) const {
    return standardMemPool.push(IntObj{*other->getInt() * data});
}

//MUL BOOL, FLOAT

Object* BoolObj::rmul(const FloatObj* other) const {
    return standardMemPool.push(FloatObj{*other->getFloat() * static_cast<double>(data)});
}

//MUL BOOL, STRING

Object* BoolObj::rmul(const StringObj* other) const {
    if (data) return standardMemPool.push(StringObj(*other->getString()));
    else return standardMemPool.push(StringObj(""));
}

//MUL BOOL, BOOL

Object* BoolObj::rmul(const BoolObj* other) const {
    return standardMemPool.push(BoolObj{static_cast<bool>(*other->getBool() * data)});
}

//DIV BOOL, INT

Object* BoolObj::rdiv(const IntObj* other) const {
    return standardMemPool.push(FloatObj{static_cast<double>(*other->getInt())
                         / static_cast<double>(data)});
}

//DIV BOOL, FLOAT

Object* BoolObj::rdiv(const FloatObj* other) const {
    return standardMemPool.push(FloatObj{*other->getFloat() / static_cast<double>(data)});
}

//DIV BOOL, STRING

Object* BoolObj::rdiv(const StringObj* other) const {
    throw std::logic_error("Cannot divide types 'string' and 'bool'.");
    return nullptr;
}

//DIV BOOL, BOOL

Object* BoolObj::rdiv(const BoolObj* other) const {
    return standardMemPool.push(IntObj{*other->getBool() / data});
}

//EQ BOOL, INT

const Type& BoolObj::req(const IntObj* other) const {
    if (data == *other->getInt()) return TRUE;
    return FALSE;
}

//EQ BOOL, FLOAT

const Type& BoolObj::req(const FloatObj* other) const {
    if (data == *other->getFloat()) return TRUE;
    return FALSE;
}

//EQ BOOL, STRING

const Type& BoolObj::req(const StringObj* other) const {
    if (str() == *other->getString()) return TRUE;
    return FALSE;
}

//EQ BOOL, BOOL

const Type& BoolObj::req(const BoolObj* other) const {
    if (data == *other->getBool()) return TRUE;
    return FALSE;
}

//-----------*OTHER*-----------

std::string BoolObj::str() const {
    if (data) return "True";
    return "False";
}

bool BoolObj::boolean() const {
    return data;
}

double BoolObj::floatD() const {
    return static_cast<double>(data);
}

long long int BoolObj::intD() const {
    return static_cast<long long int>(data);
}

//-----------*INVALID FUNCTIONS*-----------

const std::string* BoolObj::getString() const {
    throw std::logic_error("Cannot extract 'string' from 'bool'.");
    return nullptr;
}

const double* BoolObj::getFloat() const {
    throw std::logic_error("Cannot extract 'float' from 'bool'.");
    return nullptr;
}

const long long int* BoolObj::getInt() const {
    throw std::logic_error("Cannot extract 'int' from 'bool'.");
    return nullptr;
}