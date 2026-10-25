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
            if (metadata == "bool") return new BoolObj{*(objPointer)->getBool()};
            
            return nullptr;
        }
        std::string getType_() const {return *(objPointer->getType_());}
        
    public:
        friend Type isinstance(const Type& other, const std::string& metadata);
        friend Type type(const Type& other);
        friend Type str(const Type& other);
        friend Type boolean(const Type& other);
        friend Type intT(const Type& other);
        friend Type floatT(const Type& other);
        friend const Type& setMaxStringLength(const Type& l);

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
        Type operator==(const Type& other) const;
        Type operator>(const Type& other) const;
        Type operator<(const Type& other) const;
        Type operator>=(const Type& other) const;
        Type operator<=(const Type& other) const;
        operator bool() const;

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

Type Type::operator==(const Type& other) const {
    Type o = other;
    Type s = *this;
    if (*other.objPointer->getType_() == "int" || *s.objPointer->getType_() == "int") {
        o = Type(new FloatObj(other.objPointer->floatD()));
        s = Type(new FloatObj(objPointer->floatD()));
    }
    return Type(new BoolObj(o.objPointer->str() == s.objPointer->str()));
}

Type Type::operator>(const Type& other) const {
    return Type(new BoolObj(objPointer->floatD() > other.objPointer->floatD())); 
}

Type Type::operator<(const Type& other) const {
    return Type(new BoolObj(objPointer->floatD() < other.objPointer->floatD())); 
}

Type Type::operator>=(const Type& other) const {
    return Type(new BoolObj(objPointer->floatD() >= other.objPointer->floatD())); 
}

Type Type::operator<=(const Type& other) const {
    return Type(new BoolObj(objPointer->floatD() <= other.objPointer->floatD())); 
}

Type::operator bool() const {return objPointer->boolean();}