# Dynamic Type System in C++

## Overview
This project implements a dynamic typing system in C++, allowing variables of different data types to interact and perform mathematical operations at runtime. Inspired by dynamically typed languages like Python, this project leverages advanced Object-Oriented Programming (OOP) principles to resolve cross-type operations safely and efficiently. 

Through operator overloading and a smart wrapper class, the library provides a high-level, Python-like syntax while maintaining native C++ performance and strict memory safety.

## Core Architecture

### 1. Double Dispatch (Visitor Pattern)
The core of the mathematical engine relies on the **Double Dispatch** design pattern. To perform operations between two unknown dynamic types, the project implements a two-step resolution mechanism:
* **First Dispatch:** The operation is called on the first object, passing the second object as an argument (e.g., `ObjectA->add(ObjectB)`).
* **Second Dispatch:** The first object calls a reverse operation on the second object, passing itself as a specific type (e.g., `ObjectB->radd(this)`).

This eliminates the need for expensive and unsafe type-checking (`dynamic_cast`), delegating the type resolution directly to the objects' virtual tables (V-Tables).

### 2. RAII & Polymorphic Wrapper (`Type`)
To hide raw pointers and manage memory automatically, the system uses a polymorphic wrapper class (`Type`). 
The wrapper takes ownership of the dynamically allocated objects using `std::unique_ptr`. This entirely eliminates memory leaks and the need for manual `delete` operations.

## Features
* **Python-like Syntax:** Seamless operations using standard C++ operators (`+`, `-`, `*`, `/`) via operator overloading.
* **Automatic Memory Management:** Zero memory leaks and no manual pointer management thanks to `std::unique_ptr`.
* **Dynamic Resolution:** Cross-type mathematical operations (e.g., Int + Float returns Float, String * Int returns repeated String).
* **Type Introspection:** Built-in Python-like functions such as `isinstance()` and `type()` to inspect dynamic metadata at runtime.
* **Type Safety & Exceptions:** Invalid operations (e.g., String + Float) throw explicit standard C++ exceptions (`std::logic_error`, `std::overflow_error`).

## Project Structure
* `TypeAll.h` / `pointer_wrapper.h`: Contains the `Type` wrapper class managing memory and operator overloading.
* `dtypes.h`: Contains the abstract base class `Object` and the forward declarations.
* `intObj.h` / `floatObj.h` / `stringObj.h`: Implementations of the specific data types and dispatch logic.
* `functions.h`: Contains high-level helper functions like `isinstance()` and `type()`.
* `basic_operations.h`: Contains pure functional logic decoupled from objects.

## Usage Example
```cpp
#include <iostream>
#include "TypeAll.h"
#include "functions.h"

int main() {
    // 1. Variable initialization (No raw pointers visible!)
    Type varInt = new IntObj{10};
    Type varFloat = new FloatObj{2.5};
    Type varStr = new StringObj{"C++ "};

    // 2. Dynamic Mathematics
    Type sum = varInt + varFloat; 
    std::cout << "10 + 2.5 = " << sum.getFloat() << std::endl; // Output: 12.5

    // 3. String Operations
    Type multipliedText = varStr * new FloatObj{3.0}; 
    std::cout << "'C++ ' * 3.0 = " << multipliedText.getString() << std::endl; // Output: C++ C++ C++

    // 4. Metadata and Introspection
    if (isinstance(varStr, "string")) {
        std::cout << "varStr is dynamically recognized as a string!" << std::endl;
    }
    std::cout << "Type of sum: " << type(sum) << std::endl; // Output: float

    // 5. Automatic Memory Cleanup
}
```

Current Status and Roadmap

According to the current tracking configuration:

- [x] Int: Support for add, sub, mul, div.
- [x] Float: Support for add, sub, mul, div.
- [x] String: Full implementation (including multiplication by non-decimal
  floats).
- [x] Memory Management: Migrated to std::unique_ptr wrapper.
- [ ] Bool: Planned.


