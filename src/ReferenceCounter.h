#ifndef REFERENCE_COUNTER_H
#define REFERENCE_COUNTER_H

class ReferenceCounter {
public:
        ReferenceCounter() { num_ = 0; }
        void increment() { num_++; }
        void decrement() { num_--; }
        void operator++() { num_++; }
        void operator--() { num_--; }
        void operator++(int) { num_++; }
        void operator--(int) { num_--; }
        unsigned int operator*() { return num_; }
        bool operator==(int num) { return num_ == num; }
        bool operator==(const ReferenceCounter& other) { return num_ == other.num_; }

private:
        unsigned int num_;
};

#endif
