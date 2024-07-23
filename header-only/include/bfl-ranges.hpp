#pragma once

#include <concepts>
#include <ranges>
#include <utility>

namespace bfl
{
    namespace ranges 
    {
        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename T>
        auto push_back_range(T&&) = delete;

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename Container, typename... Values> requires (std::same_as<typename Container::value_type, Values> && ...)
        inline auto push_back_range(Container& container, Values&&... values) -> decltype(std::declval<Container>().push_back(typename Container::value_type{}))
        {
            (container.push_back(values), ...);
        }

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename T>
        auto push_front_range(T&&) = delete;

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename Container, typename... Values> requires (std::same_as<typename Container::value_type, Values> && ...)
        inline auto push_front_range(Container& container, Values&&... values) -> decltype(std::declval<Container>().push_front(typename Container::value_type{}))
        {
            (container.push_front(values), ...);
        }

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename T>
        auto push_range(T&&) = delete;

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename Container, typename... Values> requires (std::same_as<typename Container::value_type, Values> && ...)
        inline auto push_range(Container& container, Values&&... values) -> decltype(std::declval<Container>().push(typename Container::value_type{}))
        {
            (container.push(values), ...);
        }

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename Container, typename Value>
        inline bool contains(const Container& container, const Value& value)
        {
            return std::find(std::ranges::cbegin(container), std::ranges::cend(container), value) != std::ranges::end(container);
        }

        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename Container, typename... Values>
        inline bool contains_all(const Container& container, Values&&... values)
        {
            return (contains(container, values) && ...);
        }
        
        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename Container, typename... Values>
        inline bool contains_any(const Container& container, Values&&... values)
        {
            return (contains(container, values) || ...);
        }
        
        // ----------------------------------------------------------------------------------------------------------------------------------------------
        template <typename Container, typename... Values>
        inline bool contains_none(const Container& container, Values&&... values)
        {
            return !contains_any(container, std::forward<Values>(values)...);
        }
    }
}
