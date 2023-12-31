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
 * @file SHA1.hpp
 *
 * @brief SHA1 digest method implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Digest.hpp"
#include "DigestMethod.hpp"

#include <array>

namespace algorithms {

class SHA1 final : public DigestMethod {
public:
    SHA1();

    void
    reset() override;

    void
    update(const void* data, std::size_t size) override;

    [[nodiscard]] Digest
    finalize() override;

    [[nodiscard]] std::size_t
    length() const override;

private:
    static constexpr std::size_t DigestBytesCount = 20;
    static constexpr std::size_t BufferBytesCount = 64;

    using CountArray = std::array<std::uint32_t, 2>;
    using StateArray = std::array<std::uint32_t, 5>;
    using DigestArray = std::array<std::uint8_t, DigestBytesCount>;
    using BufferArray = std::array<std::uint8_t, BufferBytesCount>;

    static void
    transform(const BufferArray& buffer, StateArray& state);

private:
    std::size_t _index;
    StateArray _state;
    CountArray _count;
    BufferArray _buffer;
    DigestArray _digest;
};

} // namespace algorithms