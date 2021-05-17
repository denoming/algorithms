#include "List.hpp"

namespace algorithms::details {

void
ListNodeBase::transfer(ListNodeBase* beg, ListNodeBase* end) noexcept
{
    // Remove [beg, end) range of elements from old position
    end->prev->next = this;
    beg->prev->next = end;

    // Paste [beg, end) range of elements to the new position
    prev->next = beg;
    auto* const temp = prev;
    prev = end->prev;
    end->prev = beg->prev;
    beg->prev = temp;
}

void
ListNodeBase::hook(ListNodeBase* base) noexcept
{
    // Attach this element before base
    prev = base->prev;
    next = base;
    base->prev->next = this;
    base->prev = this;
}

void
ListNodeBase::unhook() noexcept
{
    // Detach this element
    prev->next = next;
    next->prev = prev;
    prev = nullptr;
    next = nullptr;
}

ListHeader::ListHeader(ListHeader&& other) noexcept
    : ListNodeBase{other.next, other.prev}
    , size{other.size}
{
    if (other.base()->next == other.base() /* List is empty (loop on itself) */) {
        reset();
    } else {
        // Make neighbor elements to point out of this element
        next->prev = base();
        prev->next = base();
        other.reset();
    }
}

void
ListHeader::reset() noexcept
{
    // Make loop on itself
    next = base();
    prev = base();
    size = 0;
}

void
ListHeader::move(ListHeader&& other) noexcept
{
    auto* const thisBase = base();
    auto* const thatBase = other.base();
    if (thatBase->next == thatBase /* Other list is empty (loop on itself) */) {
        reset();
    } else {
        // Make loop on itself with elements from other list
        thisBase->next = thatBase->next;
        thisBase->prev = thatBase->prev;
        thisBase->next->prev = thisBase;
        thisBase->prev->next = thisBase;
        size = other.size;
        other.reset();
    }
}

} // namespace algorithms::details