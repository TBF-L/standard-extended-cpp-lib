// MIT License

// Copyright (c) 2024 TBF-L

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/**
 * @file bfl-ranges.hpp
 * */

#pragma once

#include <concepts>
#include <ranges>
#include <utility>
#include <algorithm>

namespace bfl
{
    namespace ranges 
    {
        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename T>
        auto push_back_range(T&&) = delete;

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        /**
         * @param[out] container - container which have push_back method
         * @param[in] values - values to be added
         * */
        template <typename Container, typename... Values> requires (std::same_as<typename Container::value_type, Values> && ...)
        inline auto push_back_range(Container& container, Values&&... values) -> decltype(std::declval<Container>().push_back(typename Container::value_type{}))
        {
            (container.push_back(values), ...);
        }

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename T>
        auto push_front_range(T&&) = delete;

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        /**
         * @param[out] container - container which have push_front method
         * @param[in] values - values to be added
         * */
        template <typename Container, typename... Values> requires (std::same_as<typename Container::value_type, Values> && ...)
        inline auto push_front_range(Container& container, Values&&... values) -> decltype(std::declval<Container>().push_front(typename Container::value_type{}))
        {
            (container.push_front(values), ...);
        }

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename T>
        auto push_range(T&&) = delete;

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        /**
         * @param[out] container - container which have push method
         * @param[in] values - values to be added
         * */
        template <typename Container, typename... Values> requires (std::same_as<typename Container::value_type, Values> && ...)
        inline auto push_range(Container& container, Values&&... values) -> decltype(std::declval<Container>().push(typename Container::value_type{}))
        {
            (container.push(values), ...);
        }

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        /**
         * @param[in] container - some kind of container 
         * @param[in] value - any value
         * */
        template <typename Container, typename Value>
        inline bool contains(const Container& container, const Value& value)
        {
            return std::find(std::ranges::cbegin(container), std::ranges::cend(container), value) != std::ranges::end(container);
        }

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        /**
         * @param[in] container - some kind of container 
         * @param[in] values - any values
         * */
        template <typename Container, typename... Values>
        inline bool contains_all(const Container& container, Values&&... values)
        {
            return (contains(container, values) && ...);
        }
        
        // ----------------------------------------------------------------------------------------------------------------------------------------------
        /**
         * @param[in] container - some kind of container 
         * @param[in] values - any values
         * */
        template <typename Container, typename... Values>
        inline bool contains_any(const Container& container, Values&&... values)
        {
            return (contains(container, values) || ...);
        }
        
        // ----------------------------------------------------------------------------------------------------------------------------------------------
        /**
         * @param[in] container - some kind of container 
         * @param[in] values - any values
         * */
        template <typename Container, typename... Values>
        inline bool contains_none(const Container& container, Values&&... values)
        {
            return !contains_any(container, std::forward<Values>(values)...);
        }
    }
}
