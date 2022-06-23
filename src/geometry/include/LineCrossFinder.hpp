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
 * @file LineCrossFinder.hpp
 *
 * @brief Line cross finder algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Points.hpp"
#include "LineSegment.hpp"

#include <PriorityQueue.hpp>

#include <numeric>

namespace algorithms {

/**
 * Find intersection points between orthogonal segments.
 *
 * Important: Segments have to be orthogonal. In other word
 *            each segment should be vertical or horizontal.
 */
class LineCrossFinder {
public:
    void
    add(const LineSegment& segment);

    void
    clear();

    Points
    find();

private:
    struct Event {
        Event(const LineSegment& s, float time)
            : segment{s}
            , time{time}
        {
        }

        [[nodiscard]] bool
        isLeft() const
        {
            return std::abs(time - segment.p1.x) < std::numeric_limits<float>::epsilon();
        }

        [[nodiscard]] bool
        isRight() const
        {
            return std::abs(time - segment.p2.x) < std::numeric_limits<float>::epsilon();
        }

        bool
        operator<(const Event& other) const
        {
            return time < other.time;
        }

        bool
        operator>(const Event& other) const
        {
            return time > other.time;
        }

        LineSegment segment;
        float time;
    };

private:
    MinPriorityQueue<Event> _events;
};

} // namespace algorithms
