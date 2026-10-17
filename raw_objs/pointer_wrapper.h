#pragma once
#include "dtypes.h"
#include <string>
#include <memory>

struct Type {
    private:
        std::unique_ptr<const Object> objPointer{};

        Object* makeCopy() const {
            std::string metadata{*(objPointer->getType_())};
            
            if (metadata == "int") return new IntObj{*(objPointer)->getInt()};
            if (metadata == "string") return new StringObj{*(objPointer)->getString()};
            if (metadata == "float") return new FloatObj{*(objPointer)->getFloat()};
            
            return nullptr;
        }
        std::string getType_() const {return *(objPointer->getType_());}
        
    public:
        friend bool isinstance(const Type& other, const std::string& metadata);
        friend std::string type(const Type& other);

        Type(const Object* o) : objPointer{o} {}

        Type(const Type& other) : objPointer{other.makeCopy()} {}

        Type& operator=(const Type& other) {
            if (this == &other) return *this;
            
            objPointer.reset(other.makeCopy());

            return *this;
        }

        Type operator+(const Type& other) const;
        Type operator-(const Type& other) const;
        Type operator*(const Type& other) const;
        Type operator/(const Type& other) const;

        long long int getInt() const {
            return *(objPointer->getInt());
        }
        long double getFloat() const {
            return *(objPointer->getFloat());
        }
        std::string getString() const {
            return *(objPointer->getString());
        }
};

Type Type::operator+(const Type& other) const {
    return Type{objPointer->add(other.objPointer.get())};
}

Type Type::operator-(const Type& other) const {
    return Type{objPointer->sub(other.objPointer.get())};
}

Type Type::operator*(const Type& other) const {
    return Type{objPointer->mul(other.objPointer.get())};
}

Type Type::operator/(const Type& other) const {
    return Type{objPointer->div(other.objPointer.get())};
}