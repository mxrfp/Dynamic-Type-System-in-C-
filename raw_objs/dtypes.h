#pragma once
#include <string>

struct Type;
struct FloatObj;
struct StringObj;
struct IntObj;
struct BoolObj;

struct Object {
    private:
        std::string type_{""};
        virtual const std::string* getType_() const {return &type_;}
    public:
        //for functions.h
        friend bool isinstance(const Object* other, const std::string& metadata);
        friend std::string type(const Object* other);
        friend Type;

        //first dispatch methods
        virtual Object* add(const Object* other) const {return nullptr;}
        virtual Object* sub(const Object* other) const {return nullptr;}
        virtual Object* mul(const Object* other) const {return nullptr;}
        virtual Object* div(const Object* other) const {return nullptr;}
        //end fist dispatch

        //second dispatch
        virtual Object* radd(const IntObj* other) const {return nullptr;} //int add
        virtual Object* rsub(const IntObj* other) const {return nullptr;} //int sub
        virtual Object* rmul(const IntObj* other) const {return nullptr;} //int mul
        virtual Object* rdiv(const IntObj* other) const {return nullptr;} //int div

        virtual Object* radd(const FloatObj* other) const {return nullptr;} //float add
        virtual Object* rsub(const FloatObj* other) const {return nullptr;} //float sub
        virtual Object* rmul(const FloatObj* other) const {return nullptr;} //float mul
        virtual Object* rdiv(const FloatObj* other) const {return nullptr;} //float div

        virtual Object* radd(const StringObj* other) const {return nullptr;} //string add
        virtual Object* rsub(const StringObj* other) const {return nullptr;} //string sub
        virtual Object* rmul(const StringObj* other) const {return nullptr;} //string mul
        virtual Object* rdiv(const StringObj* other) const {return nullptr;} //string div
        
        virtual Object* radd(const BoolObj* other) const {return nullptr;} //bool add
        virtual Object* rsub(const BoolObj* other) const {return nullptr;} //bool sub
        virtual Object* rmul(const BoolObj* other) const {return nullptr;} //bool mul
        virtual Object* rdiv(const BoolObj* other) const {return nullptr;} //bool div

        //IDENTITIES
        
        virtual std::string str() const {return "";}
        virtual bool boolean() const {return false;} 
        virtual long double floatD() const {return 0.;}
        virtual long long int intD() const {return 0;}

        //GET

        virtual const long long int* getInt() const {return nullptr;} //get int
        virtual const long double* getFloat() const {return nullptr;} //get float
        virtual const std::string* getString() const {return nullptr;} //get string
        virtual const bool* getBool() const {return nullptr;} //get bool

        //OTHER

        virtual ~Object() = default;

};

struct IntObj : Object {
    private:
        long long int data{};
        std::string type_{"int"};
        virtual const std::string* getType_() const override {return &type_;}
    public:

        IntObj() = default;
        IntObj(long long int data) : data{data} {}
        virtual Object* add(const Object* other) const override;
        virtual Object* sub(const Object* other) const override;
        virtual Object* mul(const Object* other) const override;
        virtual Object* div(const Object* other) const override;
        
        //ADD
        virtual Object* radd(const IntObj* other) const override;
        virtual Object* radd(const FloatObj* other) const override;
        virtual Object* radd(const StringObj* other) const override;
        virtual Object* radd(const BoolObj* other) const override;

        //SUB 
        virtual Object* rsub(const IntObj* other) const override;
        virtual Object* rsub(const FloatObj* other) const override;
        virtual Object* rsub(const StringObj* other) const override;
        virtual Object* rsub(const BoolObj* other) const override;

        //MUL
        virtual Object* rmul(const IntObj* other) const override;
        virtual Object* rmul(const FloatObj* other) const override;
        virtual Object* rmul(const StringObj* other) const override;
        virtual Object* rmul(const BoolObj* other) const override;

        //DIV
        virtual Object* rdiv(const IntObj* other) const override;
        virtual Object* rdiv(const FloatObj* other) const override;
        virtual Object* rdiv(const StringObj* other) const override;
        virtual Object* rdiv(const BoolObj* other) const override;

        //IDENTITIES
        virtual std::string str() const override;
        virtual bool boolean() const override;
        virtual long double floatD() const override;
        virtual long long int intD() const override;

        //GET
        virtual const long long int* getInt() const override {return &data;} //get int
        virtual const std::string* getString() const override;
        virtual const long double* getFloat() const override;
        virtual const bool* getBool() const override;
};


struct FloatObj : Object {
    private:
        long double data{};
        std::string type_{"float"};
        virtual const std::string* getType_() const override {return &type_;}
    public:

        FloatObj() = default;
        FloatObj(long double data) : data{data} {}
        virtual Object* add(const Object* other) const override;
        virtual Object* sub(const Object* other) const override;
        virtual Object* mul(const Object* other) const override;
        virtual Object* div(const Object* other) const override;
        
        //ADD
        virtual Object* radd(const IntObj* other) const override;
        virtual Object* radd(const FloatObj* other) const override;
        virtual Object* radd(const StringObj* other) const override;
        virtual Object* radd(const BoolObj* other) const override;

        //SUB 
        virtual Object* rsub(const IntObj* other) const override;
        virtual Object* rsub(const FloatObj* other) const override;
        virtual Object* rsub(const StringObj* other) const override;
        virtual Object* rsub(const BoolObj* other) const override;

        //MUL
        virtual Object* rmul(const IntObj* other) const override;
        virtual Object* rmul(const FloatObj* other) const override;
        virtual Object* rmul(const StringObj* other) const override;
        virtual Object* rmul(const BoolObj* other) const override;

        //DIV
        virtual Object* rdiv(const IntObj* other) const override;
        virtual Object* rdiv(const FloatObj* other) const override;
        virtual Object* rdiv(const StringObj* other) const override;
        virtual Object* rdiv(const BoolObj* other) const override;

        //IDENTITIES
        virtual std::string str() const override;
        virtual bool boolean() const override;
        virtual long double floatD() const override;
        virtual long long int intD() const override;

        //GET
        virtual const long double* getFloat() const override {return &data;} //get float
        virtual const std::string* getString() const override;
        virtual const long long int* getInt() const override;
        virtual const bool* getBool() const override;
};

struct StringObj : Object {
    private:
        std::string data{};
        std::string type_{"string"};
        virtual const std::string* getType_() const override {return &type_;}
    public:

        StringObj() = default;
        StringObj(const std::string& data);
        virtual Object* add(const Object* other) const override;
        virtual Object* sub(const Object* other) const override;
        virtual Object* mul(const Object* other) const override;
        virtual Object* div(const Object* other) const override;
        
        //ADD
        virtual Object* radd(const IntObj* other) const override;
        virtual Object* radd(const FloatObj* other) const override;
        virtual Object* radd(const StringObj* other) const override;
        virtual Object* radd(const BoolObj* other) const override;

        //SUB 
        virtual Object* rsub(const IntObj* other) const override;
        virtual Object* rsub(const FloatObj* other) const override;
        virtual Object* rsub(const StringObj* other) const override;
        virtual Object* rsub(const BoolObj* other) const override;

        //MUL
        virtual Object* rmul(const IntObj* other) const override;
        virtual Object* rmul(const FloatObj* other) const override;
        virtual Object* rmul(const StringObj* other) const override;
        virtual Object* rmul(const BoolObj* other) const override;

        //DIV
        virtual Object* rdiv(const IntObj* other) const override;
        virtual Object* rdiv(const FloatObj* other) const override;
        virtual Object* rdiv(const StringObj* other) const override;
        virtual Object* rdiv(const BoolObj* other) const override;

        //IDENTITIES
        virtual std::string str() const override;
        virtual bool boolean() const override;
        virtual long double floatD() const override;
        virtual long long int intD() const override;

        //GET
        virtual const std::string* getString() const override {return &data;} //get string
        virtual const long long int* getInt() const override;
        virtual const long double* getFloat() const override;
        virtual const bool* getBool() const override;
};

struct BoolObj : Object {
    private:
        bool data{};
        std::string type_{"bool"};
        virtual const std::string* getType_() const override {return &type_;}
    public:

        BoolObj() = default;
        BoolObj(bool data) : data{data} {}
        
        virtual Object* add(const Object* other) const override;
        virtual Object* sub(const Object* other) const override;
        virtual Object* mul(const Object* other) const override;
        virtual Object* div(const Object* other) const override;
        
        //ADD
        virtual Object* radd(const IntObj* other) const override;
        virtual Object* radd(const FloatObj* other) const override;
        virtual Object* radd(const StringObj* other) const override;
        virtual Object* radd(const BoolObj* other) const override;

        //SUB 
        virtual Object* rsub(const IntObj* other) const override;
        virtual Object* rsub(const FloatObj* other) const override;
        virtual Object* rsub(const StringObj* other) const override;
        virtual Object* rsub(const BoolObj* other) const override;

        //MUL
        virtual Object* rmul(const IntObj* other) const override;
        virtual Object* rmul(const FloatObj* other) const override;
        virtual Object* rmul(const StringObj* other) const override;
        virtual Object* rmul(const BoolObj* other) const override;

        //DIV
        virtual Object* rdiv(const IntObj* other) const override;
        virtual Object* rdiv(const FloatObj* other) const override;
        virtual Object* rdiv(const StringObj* other) const override;
        virtual Object* rdiv(const BoolObj* other) const override;

        //IDENTITIES
        virtual std::string str() const override;
        virtual bool boolean() const override;
        virtual long double floatD() const override;
        virtual long long int intD() const override;

        //GET
        virtual const std::string* getString() const override;
        virtual const long long int* getInt() const override;
        virtual const long double* getFloat() const override;
        virtual const bool* getBool() const override {return &data;} //get bool
};