#pragma once
#include "dtypes.h"
#include "MemPool.h"
#include <string>

struct Type {
    private:
        Object* objPointer{};

        Object* makeCopy() const {
            std::string metadata{objPointer->getType_()};
            
            if (metadata == "int") return standardMemPool.push(IntObj{*(objPointer)->getInt()});
            if (metadata == "string") return standardMemPool.push(StringObj{*(objPointer)->getString()});
            if (metadata == "float") return standardMemPool.push(FloatObj{*(objPointer)->getFloat()});
            if (metadata == "bool") return standardMemPool.push(BoolObj{*(objPointer)->getBool()});
            
            return nullptr;
        }
        std::string getType_() const {return objPointer->getType_();}
        
    public:
        friend Type isinstance(const Type& other, const std::string& metadata);
        friend Type type(const Type& other);
        friend Type str(const Type& other);
        friend Type boolean(const Type& other);
        friend Type intT(const Type& other);
        friend Type floatT(const Type& other);
        friend const Type& setMaxStringLength(const Type& l);

        Type(Object* o) : objPointer{o} {}

        Type(const Type& other) : objPointer{other.makeCopy()} {}

        Type& operator=(const Type& other) noexcept {
            if (this == &other) return *this;
            
            if (objPointer != nullptr) {
                standardMemPool.delet(objPointer); 
            }

            objPointer = other.makeCopy();

            return *this;
        }

        Type& operator=(Type&& other) noexcept {
            if (this == &other) return *this;

            if (objPointer != nullptr) {
                standardMemPool.delet(objPointer);
            }

            objPointer = other.objPointer;
            
            other.objPointer = nullptr;

            return *this;
        }

        Type(Type&& other) noexcept : objPointer{other.objPointer} {
            other.objPointer = nullptr;
        }

        ~Type() {if (objPointer != nullptr) standardMemPool.delet(objPointer);}

        Type operator+(const Type& other) const;
        Type operator-(const Type& other) const;
        Type operator*(const Type& other) const;
        Type operator/(const Type& other) const;
        const Type& operator==(const Type& other) const;
        const Type& operator>(const Type& other) const;
        const Type& operator<(const Type& other) const;
        const Type& operator>=(const Type& other) const;
        const Type& operator<=(const Type& other) const;
        operator bool() const;

        long long int getInt() const {
            return *(objPointer->getInt());
        }
        double getFloat() const {
            return *(objPointer->getFloat());
        }
        std::string getString() const {
            return *(objPointer->getString());
        }
};

inline const Type None{standardMemPool.push(StringObj("None"))};

inline const Type TRUE{standardMemPool.push(BoolObj(true))};
inline const Type FALSE{standardMemPool.push(BoolObj(false))};

Type Type::operator+(const Type& other) const {
    return Type{objPointer->add(other.objPointer)};
}

Type Type::operator-(const Type& other) const {
    return Type{objPointer->sub(other.objPointer)};
}

Type Type::operator*(const Type& other) const {
    return Type{objPointer->mul(other.objPointer)};
}

Type Type::operator/(const Type& other) const {
    return Type{objPointer->div(other.objPointer)};
}

const Type& Type::operator==(const Type& other) const {
    return objPointer->eq(other.objPointer);
}

const Type& Type::operator>(const Type& other) const {
    if (objPointer->floatD() > other.objPointer->floatD()) return TRUE; 
    return FALSE;
}

const Type& Type::operator<(const Type& other) const {
    if (objPointer->floatD() < other.objPointer->floatD()) return TRUE;
    return FALSE;
}

const Type& Type::operator>=(const Type& other) const {
    if (objPointer->floatD() >= other.objPointer->floatD()) return TRUE; 
    return FALSE;
}

const Type& Type::operator<=(const Type& other) const {
    if (objPointer->floatD() <= other.objPointer->floatD()) return TRUE;
    return FALSE; 
}

Type::operator bool() const {return objPointer->boolean();}