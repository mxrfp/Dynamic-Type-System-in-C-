#pragma once
#include "dtypes.h"
#include "basic_operations.h"
#include "sys_vars.h"
#include "MemPool.h"
#include <stdexcept>
#include "pointer_wrapper.h"

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

//ADD FIRST DISPATCH INT.EQ

const Type& IntObj::eq(const Object* other) const {
    return other->req(this);
}

//-----------*SECOND DISPATCH IMPLEMENTATION*-----------

//ADD INT, INT

Object* IntObj::radd(const IntObj* other) const {
    return standardMemPool.push(IntObj{*(other->getInt()) + data});
}

//ADD INT, FLOAT

Object* IntObj::radd(const FloatObj* other) const {
    return standardMemPool.push(FloatObj{*other->getFloat() + static_cast<double>(data)});
}

//ADD INT, STRING

Object* IntObj::radd(const StringObj* other) const {
    throw std::logic_error("Cannot add types 'string' and 'int'.");
    return nullptr;
}

//ADD INT, BOOL

Object* IntObj::radd(const BoolObj* other) const {
    return standardMemPool.push(IntObj{*other->getInt() + data});
}

//SUB INT, INT

Object* IntObj::rsub(const IntObj* other) const {
    return standardMemPool.push(IntObj{*other->getInt() - data});
}

//SUB INT, FLOAT

Object* IntObj::rsub(const FloatObj* other) const {
    return standardMemPool.push(FloatObj{*other->getFloat() - static_cast<double>(data)});
}

// SUB INT, STRING

Object* IntObj::rsub(const StringObj* other) const {
    throw std::logic_error("Cannot subtract types 'string' and 'int'.");
    return nullptr;
}

//SUB INT, BOOL

Object* IntObj::rsub(const BoolObj* other) const {
    return standardMemPool.push(IntObj{*other->getInt() - data});
}

//MUL INT, INT

Object* IntObj::rmul(const IntObj* other) const {
    return standardMemPool.push(IntObj{*other->getInt() * data});
}

//MUL INT, FLOAT

Object* IntObj::rmul(const FloatObj* other) const {
    return standardMemPool.push(FloatObj{*other->getFloat() * static_cast<double>(data)});
}

//MUL INT, STRING

Object* IntObj::rmul(const StringObj* other) const {
    if ((*other->getString()).size() * data > MAX_STRING_LENGTH) throw std::overflow_error("String length is greater than MAX_STRING_LENGTH.");
    return standardMemPool.push(StringObj{mulString(*other->getString(), data)});
}

//MUL INT, BOOL

Object* IntObj::rmul(const BoolObj* other) const {
    return standardMemPool.push(IntObj{*other->getBool() * data});
}

//DIV INT, INT

Object* IntObj::rdiv(const IntObj* other) const {
    return standardMemPool.push(FloatObj{static_cast<double>(*other->getInt())
                         / static_cast<double>(data)});
}

//DIV INT, FLOAT

Object* IntObj::rdiv(const FloatObj* other) const {
    return standardMemPool.push(FloatObj{*other->getFloat() / static_cast<double>(data)});
}

//DIV INT, STRING

Object* IntObj::rdiv(const StringObj* other) const {
    throw std::logic_error("Cannot divide types 'string' and 'int'.");
    return nullptr;
}

//DIV INT, BOOL

Object* IntObj::rdiv(const BoolObj* other) const {
    return standardMemPool.push(IntObj{*other->getInt() / data});
}

//EQ INT, INT

const Type& IntObj::req(const IntObj* other) const {
    if (data == *other->getInt()) return TRUE;
    return FALSE;
}

//EQ INT, FLOAT

const Type& IntObj::req(const FloatObj* other) const {
    if (data == *other->getFloat()) return TRUE;
    return FALSE;
}

//EQ INT, STRING

const Type& IntObj::req(const StringObj* other) const {
    if (data == other->intD()) return TRUE;
    return FALSE;
}

//EQ INT, BOOL

const Type& IntObj::req(const BoolObj* other) const {
    if (data == *other->getBool()) return TRUE;
    return FALSE;
}

//-----------*OTHER*-----------

std::string IntObj::str() const {
    return std::to_string(data);
}

bool IntObj::boolean() const {
    return data != 0;
}

double IntObj::floatD() const {
    return static_cast<double>(data);
}

long long int IntObj::intD() const {
    return data;
}

//-----------*INVALID FUNCTIONS*-----------

const std::string* IntObj::getString() const {
    throw std::logic_error("Cannot extract 'string' from 'int'.");
    return nullptr;
}

const double* IntObj::getFloat() const {
    throw std::logic_error("Cannot extract 'float' from 'int'.");
    return nullptr;
}

const bool* IntObj::getBool() const {
    throw std::logic_error("Cannot extract 'bool' from 'int'.");
    return nullptr;
}