#pragma once
#include "dtypes.h"
#include <vector>
#include <memory_resource>

class MemPool {
    private:
        std::pmr::unsynchronized_pool_resource pool;

    public:

        MemPool() = default;

        template<typename T>
        Object* push(const T& other) {
            
            void* rawMem = pool.allocate(sizeof(T), alignof(T));

            Object* pointer = new (rawMem) T(other);

            return pointer;
        }

        void delet(Object* ptr) {
            if (ptr != nullptr) {

                auto size{ptr->getSize()};
                auto align{ptr->getAllign()};

                ptr->~Object();
                pool.deallocate(ptr, size, align);
            }
        }
};

inline MemPool standardMemPool{};