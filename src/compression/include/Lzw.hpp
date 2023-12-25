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
 * @file Lzw.hpp
 *
 * @brief LZW algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <string>
#include <vector>
#include <string_view>

#include <cstdint>

namespace algorithms::lzw {

constexpr std::size_t R = 256;
constexpr std::size_t L = 4096;
constexpr std::size_t W = 12;

using Byte = std::uint8_t;
using Bytes = std::vector<Byte>;

[[nodiscard]] Bytes
encode(std::string_view input);

[[nodiscard]] std::string
decode(Bytes bytes);

} // namespace algorithms::lzw