#pragma once
#include <string>
#include <stdexcept>

struct Type;
struct FloatObj;
struct StringObj;
struct IntObj;
struct BoolObj;

struct Object {
    private:
        virtual std::string getType_() const {return "";}
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
        virtual const Type& eq(const Object* other) const {throw std::runtime_error("Invalid operation.");}
        //end fist dispatch

        //second dispatch
        virtual Object* radd(const IntObj* other) const {return nullptr;} //int add
        virtual Object* rsub(const IntObj* other) const {return nullptr;} //int sub
        virtual Object* rmul(const IntObj* other) const {return nullptr;} //int mul
        virtual Object* rdiv(const IntObj* other) const {return nullptr;} //int div
        virtual const Type& req(const IntObj* other) const {throw std::runtime_error("Invalid operation.");} //int eq

        virtual Object* radd(const FloatObj* other) const {return nullptr;} //float add
        virtual Object* rsub(const FloatObj* other) const {return nullptr;} //float sub
        virtual Object* rmul(const FloatObj* other) const {return nullptr;} //float mul
        virtual Object* rdiv(const FloatObj* other) const {return nullptr;} //float div
        virtual const Type& req(const FloatObj* other) const {throw std::runtime_error("Invalid operation.");} //float eq

        virtual Object* radd(const StringObj* other) const {return nullptr;} //string add
        virtual Object* rsub(const StringObj* other) const {return nullptr;} //string sub
        virtual Object* rmul(const StringObj* other) const {return nullptr;} //string mul
        virtual Object* rdiv(const StringObj* other) const {return nullptr;} //string div
        virtual const Type& req(const StringObj* other) const {throw std::runtime_error("Invalid operation.");} //string eq
        
        virtual Object* radd(const BoolObj* other) const {return nullptr;} //bool add
        virtual Object* rsub(const BoolObj* other) const {return nullptr;} //bool sub
        virtual Object* rmul(const BoolObj* other) const {return nullptr;} //bool mul
        virtual Object* rdiv(const BoolObj* other) const {return nullptr;} //bool div
        virtual const Type& req(const BoolObj* other) const {throw std::runtime_error("Invalid operation.");} //bool eq

        //IDENTITIES
        
        virtual std::string str() const {return "";}
        virtual bool boolean() const {return false;} 
        virtual double floatD() const {return 0.;}
        virtual long long int intD() const {return 0;}

        //GET

        virtual const long long int* getInt() const {return nullptr;} //get int
        virtual const double* getFloat() const {return nullptr;} //get float
        virtual const std::string* getString() const {return nullptr;} //get string
        virtual const bool* getBool() const {return nullptr;} //get bool

        //OTHER

        virtual ~Object() = default;
        virtual unsigned int getSize() const {return sizeof(Object);}
        virtual unsigned int getAllign() const {return alignof(Object);}

};

struct IntObj : Object {
    private:
        long long int data{};
        virtual std::string getType_() const override {return "int";}
    public:

        IntObj() = default;
        IntObj(long long int data) : data{data} {}
        IntObj(const IntObj& other) : data{other.data} {}
        virtual Object* add(const Object* other) const override;
        virtual Object* sub(const Object* other) const override;
        virtual Object* mul(const Object* other) const override;
        virtual Object* div(const Object* other) const override;
        virtual const Type& eq(const Object* other) const override;
        
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

        //EQ
        virtual const Type& req(const IntObj* other) const override;
        virtual const Type& req(const FloatObj* other) const override;
        virtual const Type& req(const StringObj* other) const override;
        virtual const Type& req(const BoolObj* other) const override;

        //IDENTITIES
        virtual std::string str() const override;
        virtual bool boolean() const override;
        virtual double floatD() const override;
        virtual long long int intD() const override;

        //GET
        virtual const long long int* getInt() const override {return &data;} //get int
        virtual const std::string* getString() const override;
        virtual const double* getFloat() const override;
        virtual const bool* getBool() const override;

        virtual unsigned int getSize() const {return sizeof(IntObj);}
        virtual unsigned int getAllign() const {return alignof(IntObj);}
};


struct FloatObj : Object {
    private:
        double data{};
        virtual std::string getType_() const override {return "float";}
    public:

        FloatObj() = default;
        FloatObj(double data) : data{data} {}
        FloatObj(const FloatObj& other) : data{other.data} {}
        virtual Object* add(const Object* other) const override;
        virtual Object* sub(const Object* other) const override;
        virtual Object* mul(const Object* other) const override;
        virtual Object* div(const Object* other) const override;
        virtual const Type& eq(const Object* other) const override;
        
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

        //EQ
        virtual const Type& req(const IntObj* other) const override;
        virtual const Type& req(const FloatObj* other) const override;
        virtual const Type& req(const StringObj* other) const override;
        virtual const Type& req(const BoolObj* other) const override;

        //IDENTITIES
        virtual std::string str() const override;
        virtual bool boolean() const override;
        virtual double floatD() const override;
        virtual long long int intD() const override;

        //GET
        virtual const double* getFloat() const override {return &data;} //get float
        virtual const std::string* getString() const override;
        virtual const long long int* getInt() const override;
        virtual const bool* getBool() const override;

        virtual unsigned int getSize() const {return sizeof(FloatObj);}
        virtual unsigned int getAllign() const {return alignof(FloatObj);}
};

struct StringObj : Object {
    private:
        std::string data{};
        virtual std::string getType_() const override {return "string";}
    public:

        StringObj() = default;
        StringObj(const std::string& data);
        StringObj(const StringObj& other) : data{other.data} {}
        virtual Object* add(const Object* other) const override;
        virtual Object* sub(const Object* other) const override;
        virtual Object* mul(const Object* other) const override;
        virtual Object* div(const Object* other) const override;
        virtual const Type& eq(const Object* other) const override;
        
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

        //EQ
        virtual const Type& req(const IntObj* other) const override;
        virtual const Type& req(const FloatObj* other) const override;
        virtual const Type& req(const StringObj* other) const override;
        virtual const Type& req(const BoolObj* other) const override;

        //IDENTITIES
        virtual std::string str() const override;
        virtual bool boolean() const override;
        virtual double floatD() const override;
        virtual long long int intD() const override;

        //GET
        virtual const std::string* getString() const override {return &data;} //get string
        virtual const long long int* getInt() const override;
        virtual const double* getFloat() const override;
        virtual const bool* getBool() const override;

        virtual unsigned int getSize() const {return sizeof(StringObj);}
        virtual unsigned int getAllign() const {return alignof(StringObj);}
};

struct BoolObj : Object {
    private:
        bool data{};
        virtual std::string getType_() const override {return "bool";}
    public:

        BoolObj() = default;
        BoolObj(bool data) : data{data} {}
        BoolObj(const BoolObj& other) : data{other.data} {}
        
        virtual Object* add(const Object* other) const override;
        virtual Object* sub(const Object* other) const override;
        virtual Object* mul(const Object* other) const override;
        virtual Object* div(const Object* other) const override;
        virtual const Type& eq(const Object* other) const override;
        
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

        //EQ
        virtual const Type& req(const IntObj* other) const override;
        virtual const Type& req(const FloatObj* other) const override;
        virtual const Type& req(const StringObj* other) const override;
        virtual const Type& req(const BoolObj* other) const override;

        //IDENTITIES
        virtual std::string str() const override;
        virtual bool boolean() const override;
        virtual double floatD() const override;
        virtual long long int intD() const override;

        //GET
        virtual const std::string* getString() const override;
        virtual const long long int* getInt() const override;
        virtual const double* getFloat() const override;
        virtual const bool* getBool() const override {return &data;} //get bool

        virtual unsigned int getSize() const {return sizeof(BoolObj);}
        virtual unsigned int getAllign() const {return alignof(BoolObj);}
};