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
 * @file KdTreeEx.hpp
 *
 * @brief KdTree with improvements algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <tuple>

#include "Points.hpp"

namespace algorithms {

/**
 * Optimized k-d tree implementation
 */
class KdTreeEx {
public:
    static const int K = 2; /** The number of dimensions to work with */

    /** The best point and distance to it from query point */
    using BestPointAndDistance = std::tuple<Point, float>;

public:
    KdTreeEx();

    ~KdTreeEx();

    void
    create(Points points);

    [[nodiscard]] BestPointAndDistance
    nearestTo(const Point& queryPoint);

    void
    clear();

    [[nodiscard]] bool
    empty() const;

public:
    /**
     * The list of possible directions of split line according to possible directions.
     */
    enum class Directions {
        vertical,  /// Split line perpendicular to the X axis
        horizontal /// Split line perpendicular to the Y axis
    };

    /**
     * The node data struct.
     */
    struct Node {
        Node()
            : direction{Directions::vertical}
            , value{0.0}
            , lh{nullptr}
            , rh{nullptr}
        {
        }

        Directions direction;
        float value;
        Points points;
        Node* lh;
        Node* rh;
    };

private:
    void
    clear(Node* node);

    static float
    getMedian(Points points, Directions direction);

    static Directions
    getDirection(int depth);

    static std::tuple<Points::iterator, Points::iterator>
    partitionBy(float median, Points& points, Directions direction);

    static void
    findBestPoint(const Point& queryPoint,
                  const Points& points,
                  Point& bestPoint,
                  float& bestDistance);

private:
    Node* _root;
};

} // namespace algorithms
