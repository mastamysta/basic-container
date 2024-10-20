#pragma once

#include <algorithm>
#include <initializer_list>

template <typename T>
class BreadbinIterator
{
public:

    using iterator_category = std::forward_iterator_tag;
    using difference_type = unsigned int;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    explicit BreadbinIterator() {}
    explicit BreadbinIterator(pointer start_addr, difference_type ind) : start_addr(start_addr), ind(ind) {}

    explicit BreadbinIterator(const BreadbinIterator& other) : ind(other.ind) {}

    reference operator*() const
    {
        return *(start_addr + ind);
    }

    pointer operator->() const
    {
        return start_addr + ind;
    }

    BreadbinIterator& operator++()
    {
        ind++;
        return *this;
    }

    BreadbinIterator operator++(T)
    {
        BreadbinIterator tmp = *this;
        ++(this);
        return tmp;
    }

    friend bool operator==(const BreadbinIterator& lhs, const BreadbinIterator& rhs)
    {
        return lhs.ind == rhs.ind;
    }

    friend bool operator!=(const BreadbinIterator& lhs, const BreadbinIterator& rhs)
    {
        return lhs.ind != rhs.ind;
    }

private:

    difference_type ind;
    pointer start_addr;

};

template <typename ValueType>
class Breadbin
{
public:
    using value_type = ValueType;
    using reference = value_type&;
    using const_reference = const value_type&;
    using difference_type = int;
    using size_type = unsigned int;
    using iterator = BreadbinIterator<value_type>;
    using const_iterator = const BreadbinIterator<value_type>;

    static constexpr size_type capacity()
    {
        return 10;
    }

    // TODO: Maybe nodiscard??
    explicit Breadbin() { /* Do nothing! */ }

    explicit Breadbin(const Breadbin& other) : _size(other._size)
    {
        std::copy(other.data, other.data + other.capacity(), data);
    }

    explicit Breadbin(std::initializer_list<value_type> vals) : _size(vals.size())
    {
        std::copy(std::begin(vals), std::end(vals), data);
    }

    Breadbin operator=(const Breadbin& other)
    {
        _size = other._size;
        std::copy(other.data, other.data + other.capacity(), data);
    }

    Breadbin operator=(Breadbin&& other)
    {
        _size = other._size;
        std::copy(other.data, other.data + other.capacity(), data);
    }

    iterator begin()
    {
        return BreadbinIterator<value_type>(data, 0);
    }

    iterator end()
    {
        return BreadbinIterator<value_type>(data, _size);
    }

    size_type size()
    {
        return _size;
    }

private:
    value_type data[10]; // The breadbin always contains 10 elements
    size_type _size;
};
