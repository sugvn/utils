#pragma once
#include <cassert>
#include <stdexcept>
#include <vector>

template <typename T>
class ring_buffer{
        public:
                ring_buffer(size_t capacity) : buffer(capacity), capacity(capacity),
                              head(0), tail(0), size(0) {
                                      if(capacity==0) 
                                              throw std::invalid_argument("Buffer cannot be empty");
                              }
                T pop(){
                        assert(this->size > 0);
                        T val = this->buffer[head];
                        head = (head+1) % capacity;
                        this->size -= 1;
                        return val;
                }
                void push(T val){
                        assert((this->capacity - this->size) > 0);
                        this->buffer[tail] = val;
                        this->size += 1;
                        this->tail = (tail+1) % capacity;
                }
                T at(size_t index){
                        assert(index < this->size);
                        return this->buffer[(this->head + index) % this->capacity];

                }
        private:
                std::vector<T> buffer;
                size_t capacity;
                size_t size;
                size_t head,tail;
};
