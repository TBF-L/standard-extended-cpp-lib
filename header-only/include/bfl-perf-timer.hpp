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
 * @file bfl-perf-timer.hpp
 */

#pragma once

#include <chrono>
#include <iostream>
#include <ostream>

namespace bfl 
{
    template <typename Duration = std::chrono::milliseconds>
    class perf_timer
    {
    public:
        using clock = std::chrono::high_resolution_clock;
        using time_point = std::chrono::time_point<clock>;

    public:
        /**
         * @brief default ctor 
         */ 
        perf_timer() = default;

        /**
         * @brief default dtor
         */ 
        ~perf_timer() = default;

        /** 
         * @brief set the initial time point
         */  
        void begin()
        {
            Begin = clock::now();
        }
        
        /**
         * @brief set the end time point 
         */ 
        void end()
        {
            End = clock::now();
        }
        
        /**
         * @brief get the difference between the final and initial time points
         */ 
        Duration get_result() const 
        {
            return std::chrono::duration_cast<Duration>(End - Begin);
        }

    private:
        time_point Begin;
        time_point End;
    };

    template <typename PerfTimer = perf_timer<>, typename CharType = char, typename OutStream = std::basic_ostream<CharType>>
    class auto_perf_timer
    {
    public:
        /**
         * @brief set output stream, call PerfTimer::begin()
         */ 
        auto_perf_timer(OutStream& out_stream) :
            OS{ out_stream }
        {
            Perf_Timer.begin();
        }
        
        /**
         * @brief call PerfTimer::end(), write result to the output stream 
         */ 
        ~auto_perf_timer()
        {
            Perf_Timer.end();
            OS << Perf_Timer.get_result() << '\n';
        }

    private:
        PerfTimer Perf_Timer;
        OutStream& OS;
    };
}
