/**
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT WARRANTY OF ANY KIND; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * MIT License for more details.
 */

/**
 * @file List.hpp
 *
 * @brief List implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <memory_resource>
#include <list>

namespace algorithms {

namespace details {

struct ListNodeBase {
    void
    transfer(ListNodeBase* beg, ListNodeBase* end) noexcept;

    void
    hook(ListNodeBase* base) noexcept;

    void
    unhook() noexcept;

    ListNodeBase* next{nullptr};
    ListNodeBase* prev{nullptr};
};

struct ListHeader : public ListNodeBase {
    ListHeader() noexcept
    {
        reset();
    }

    ListHeader(ListHeader&& other) noexcept;

    void
    reset() noexcept;

    void
    move(ListHeader&& other) noexcept;

private:
    [[nodiscard]] ListNodeBase*
    base() noexcept
    {
        return this;
    }

public:
    std::size_t size{0};
};

template<typename T>
struct ListNode : public ListNodeBase {
    using Storage = std::aligned_storage_t<sizeof(T), alignof(T)>;

    [[nodiscard]] void*
    address() noexcept
    {
        return static_cast<void*>(&_storage);
    }

    [[nodiscard]] const void*
    address() const noexcept
    {
        return static_cast<const void*>(&_storage);
    }

    [[nodiscard]] T*
    data() noexcept
    {
        return static_cast<T*>(address());
    }

    [[nodiscard]] T const*
    data() const noexcept
    {
        return static_cast<const T*>(address());
    }

    [[nodiscard]] T&
    reference() noexcept
    {
        return *data();
    }

    [[nodiscard]] const T&
    reference() const noexcept
    {
        return *data();
    }

private:
    Storage _storage;
};

template<typename T>
struct ListIterator {
public:
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::bidirectional_iterator_tag;

public:
    using Self = ListIterator<T>;
    using NodeType = ListNode<T>;
    using NodeBaseType = ListNodeBase;

    ListIterator() noexcept
        : _node{nullptr}
    {
    }

    explicit ListIterator(NodeBaseType* node) noexcept
        : _node{node}
    {
    }

    Self
    constCast() const noexcept
    {
        return *this;
    }

    Self // NOLINT(cert-dcl21-cpp)
    operator--(int) noexcept
    {
        Self tmp = *this;
        _node = _node->prev;
        return tmp;
    }

    Self&
    operator--() noexcept
    {
        _node = _node->prev;
        return *this;
    }

    Self // NOLINT(cert-dcl21-cpp)
    operator++(int) noexcept
    {
        Self tmp = *this;
        _node = _node->next;
        return tmp;
    }

    Self&
    operator++() noexcept
    {
        _node = _node->next;
        return *this;
    }

    reference
    operator*() noexcept
    {
        return static_cast<NodeType*>(_node)->reference();
    }

    pointer
    operator->() noexcept
    {
        return static_cast<NodeType*>(_node)->data();
    }

    friend bool
    operator==(const Self& lhs, const Self& rhs) noexcept
    {
        return (lhs._node == rhs._node);
    }

public:
    [[nodiscard]] NodeType*
    node() const noexcept
    {
        return static_cast<NodeType*>(_node);
    }

private:
    NodeBaseType* _node;
};

template<typename T>
struct ListConstIterator {
public:
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;
    using iterator_category = std::bidirectional_iterator_tag;

public:
    using Self = ListConstIterator<T>;
    using NodeType = const ListNode<T>;
    using NodeBaseType = ListNodeBase;

    ListConstIterator() noexcept
        : _node{nullptr}
    {
    }

    explicit ListConstIterator(const NodeBaseType* node) noexcept
        : _node{node}
    {
    }

    Self // NOLINT(cert-dcl21-cpp)
    operator--(int) noexcept
    {
        Self tmp = *this;
        _node = _node->prev;
        return tmp;
    }

    Self&
    operator--() noexcept
    {
        _node = _node->prev;
        return *this;
    }

    Self // NOLINT(cert-dcl21-cpp)
    operator++(int) noexcept
    {
        Self tmp = *this;
        _node = _node->next;
        return tmp;
    }

    Self&
    operator++() noexcept
    {
        _node = _node->next;
        return *this;
    }

    reference
    operator*() const noexcept
    {
        return static_cast<const NodeType*>(_node)->reference();
    }

    pointer
    operator->() const noexcept
    {
        return static_cast<const NodeType*>(_node)->pointer();
    }

    friend bool
    operator==(const Self& lhs, const Self& rhs) noexcept
    {
        return (lhs._node == rhs._node);
    }

public:
    [[nodiscard]] NodeType*
    node() const noexcept
    {
        return static_cast<NodeType*>(_node);
    }

private:
    const NodeBaseType* _node;
};

} // namespace details

template<typename T>
class List {
public:
    using ValueType = T;
    using Reference = ValueType&;
    using ConstReference = ValueType const&;
    using SizeType = size_t;
    using AllocatorType = std::pmr::polymorphic_allocator<std::byte>;
    using Iterator = details::ListIterator<T>;
    using ConstIterator = details::ListConstIterator<T>;

public:
    explicit List(const AllocatorType& alloc = {})
        : _impl{alloc}
    {
    }

    template<typename InputIt>
    List(InputIt first, InputIt last, const AllocatorType& alloc)
        : List{alloc}
    {
        initialize(first, last);
    }

    List(const List& other, const AllocatorType& alloc = {})
        : List{alloc}
    {
        initialize(other.begin(), other.end());
    }

    List(List&& other) noexcept
        : _impl{std::move(other._impl)}
    {
    }

    List(List&& other, AllocatorType alloc)
        : List{alloc}
    {
        move(std::move(other));
    }

    ~List()
    {
        _impl.clear();
    }

    List&
    operator=(const List& other)
    {
        if (this != &other) {
            assign(other.begin(), other.end());
        }
        return *this;
    }

    List&
    operator=(List&& other) // NOLINT(performance-noexcept-move-constructor)
    {
        if (this != &other) {
            move(std::move(other));
        }
        return *this;
    }

    Iterator
    begin() noexcept
    {
        return Iterator{_impl.base.next};
    }

    ConstIterator
    begin() const noexcept
    {
        return ConstIterator{_impl.base.next};
    }

    Iterator
    end() noexcept
    {
        return Iterator{&_impl.base};
    }

    ConstIterator
    end() const noexcept
    {
        return ConstIterator{&_impl.base};
    }

    Reference
    front() noexcept
    {
        return *begin();
    }

    ConstReference
    front() const noexcept
    {
        return *begin();
    }

    Reference
    back() noexcept
    {
        Iterator tmp = end();
        --tmp;
        return *tmp;
    }

    ConstReference
    back() const noexcept
    {
        ConstIterator tmp = end();
        --tmp;
        return *tmp;
    }

    template<typename InputIt>
    void
    assign(InputIt first, InputIt last)
    {
        auto beg1 = begin();
        auto end1 = end();

        for (; beg1 != end1 && first != last; ++beg1, ++first) {
            *beg1 = *first;
        }

        if (first == last) {
            erase(beg1, end1);
        } else {
            insert(end1, first, last);
        }
    }

    template<typename InputIt>
    void
    insert(Iterator position, InputIt first, InputIt last)
    {
        List temp{first, last, _impl.allocator()};
        if (!temp.empty()) {
            splice(position, std::move(temp));
        }
    }

    template<typename... Args>
    Reference
    emplaceFront(Args&&... args)
    {
        return emplace(begin(), std::forward<Args>(args)...);
    }

    template<typename... Args>
    Reference
    emplaceBack(Args&&... args)
    {
        return emplace(end(), std::forward<Args>(args)...);
    }

    template<typename... Args>
    Reference
    emplace(Iterator position, Args&&... args)
    {
        auto* node = _impl.template createNode(std::forward<Args>(args)...);
        node->hook(position.node());
        _impl.incSize(1);
        return node->reference();
    }

    Reference
    pushBack(const ValueType& value)
    {
        return emplace(end(), value);
    }

    Reference
    pushFront(const ValueType& value)
    {
        return emplace(begin(), value);
    }

    void
    popBack() noexcept(std::is_nothrow_destructible_v<ValueType>)
    {
        erase(--end());
    }

    void
    popFront() noexcept(std::is_nothrow_destructible_v<ValueType>)
    {
        erase(begin());
    }

    Iterator
    erase(Iterator position)
    {
        Iterator next{position.node()->next};
        _impl.decSize(1);
        position.node()->unhook();
        _impl.deleteNode(position.node());
        return next;
    }

    void
    erase(Iterator first, Iterator last)
    {
        while (first != last) {
            first = erase(first);
        }
    }

    [[nodiscard]] SizeType
    size() const noexcept
    {
        return _impl.size();
    }

    [[nodiscard]] bool
    empty() const noexcept
    {
        return _impl.empty();
    }

    void
    clear()
    {
        _impl.clear();
        _impl.reset();
    }

private:
    using NodeType = details::ListNode<ValueType>;
    using NodeBaseType = details::ListNodeBase;

    struct Impl : public AllocatorType {
        Impl() = default;

        Impl(Impl&& other) noexcept
            : AllocatorType{other.resource()}
            , base{std::move(other.base)}
        {
        }

        explicit Impl(const AllocatorType& alloc)
            : AllocatorType{alloc}
        {
        }

        template<typename... Args>
        [[nodiscard]] NodeType*
        createNode(Args&&... args)
        {
            NodeType* node = new_object<NodeType>();
            try {
                construct<ValueType>(node->data(), std::forward<Args>(args)...);
            } catch (...) {
                delete_object(node);
                throw;
            }
            return node;
        }

        void
        deleteNode(NodeType* node)
        {
            std::destroy_at(node->data());
            delete_object(static_cast<NodeType*>(node));
        }

        void
        incSize(std::size_t n) noexcept
        {
            base.size += n;
        }

        void
        decSize(std::size_t n) noexcept
        {
            base.size -= n;
        }

        [[nodiscard]] std::size_t
        size() const noexcept
        {
            return base.size;
        }

        void
        size(std::size_t newSize) noexcept
        {
            base.size = newSize;
        }

        [[nodiscard]] bool
        empty() const noexcept
        {
            return (base.size == 0);
        }

        void
        clear()
        {
            auto* cur = base.next;
            while (cur != &base) {
                auto* next = cur->next;
                deleteNode(static_cast<NodeType*>(cur));
                cur = next;
            }
        }

        void
        reset() noexcept
        {
            base.reset();
        }

        [[nodiscard]] AllocatorType&
        allocator() noexcept
        {
            return *this;
        }

        [[nodiscard]] const AllocatorType&
        allocator() const noexcept
        {
            return *this;
        }

        details::ListHeader base;
    };

private:
    template<typename InputIt>
    void
    initialize(InputIt first, InputIt last)
    {
        while (first != last) {
            emplaceBack(*first++);
        }
    }

    void
    move(List&& other)
    {
        /** Polymorphic allocators can be not equal (different memory resources) */
        if (_impl.allocator() == other._impl.allocator()) {
            clear();
            _impl.base.move(std::move(other._impl.base));
        } else {
            /** In that case we copy elements on top of exists elements */
            assign(other.begin(), other.end());
        }
    }

    void
    splice(Iterator position, List&& other) noexcept
    {
        assert(_impl.allocator() == other._impl.allocator());
        position.node()->transfer(other.begin().node(), other.end().node());
        _impl.incSize(other.size());
        other._impl.size(0);
    }

private:
    Impl _impl;
};

} // namespace algorithms
