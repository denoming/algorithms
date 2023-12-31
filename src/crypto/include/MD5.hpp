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
 * @file MD5.hpp
 *
 * @brief MD5 digest method implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Digest.hpp"
#include "DigestMethod.hpp"

#include <array>

namespace algorithms {

class MD5 final : public DigestMethod {
public:
    MD5();

    void
    reset() override;

    void
    update(const void* data, std::size_t size) override;

    [[nodiscard]] Digest
    finalize() override;

    [[nodiscard]] std::size_t
    length() const override;

private:
    static constexpr std::size_t DigestBytesCount = 16;
    static constexpr std::size_t BufferBytesCount = 64;

    using CountArray = std::array<std::uint32_t, 2>;
    using StateArray = std::array<std::uint32_t, 4>;
    using DigestArray = std::array<std::uint8_t, DigestBytesCount>;
    using BufferArray = std::array<std::uint8_t, BufferBytesCount>;

    static void
    transform(const BufferArray& buffer, StateArray& state);

    template<std::size_t N>
    static void
    encode(const std::array<std::uint32_t, N>& input, std::array<std::uint8_t, N * 4>& output);

    template<std::size_t N>
    static void
    decode(const std::array<std::uint8_t, N * 4>& input, std::array<std::uint32_t, N>& output);

private:
    CountArray _count;
    StateArray _state;
    BufferArray _buffer;
    DigestArray _digest;
};

} // namespace algorithms
