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
 * @file Traverse.hpp
 *
 * @brief Tree traverse aggregate file
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "traverse/DepthPreOrderTraverse.hpp"
#include "traverse/DepthPreOrderNoRecTraverse.hpp"
#include "traverse/DepthInOrderTraverse.hpp"
#include "traverse/DepthInOrderNoRecTraverse.hpp"
#include "traverse/DepthPostOrderTraverse.hpp"
#include "traverse/DepthPostOrderNoRecTraverse.hpp"
#include "traverse/BreadthOrderTraverse.hpp"

namespace algorithms {

enum class TraverseOrder { DepthPreOrder, DepthInOrder, DepthPostOrder, BreadthOrder };

} // namespace algorithms
