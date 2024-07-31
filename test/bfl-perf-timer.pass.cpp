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


#include <fstream>
#include <gtest/gtest.h>
#include <bfl-perf-timer.hpp>
#include <thread>
#include <chrono>

// ---------------------------------------------------------------------------------------------------------------------
TEST(PerfTimer, TimeTest)
{
    using namespace std::chrono_literals;

    bfl::perf_timer<> pt{};
    pt.begin();
    std::this_thread::sleep_for(500ms);
    pt.end();
    
    const auto result{ pt.get_result().count() };

    std::cout << result << '\n';
    ASSERT_TRUE(result >= 400 && result <= 600);
}

// ---------------------------------------------------------------------------------------------------------------------
TEST(AutoPerfTimer, AutoTimeTest)
{
    using namespace std::chrono_literals;
    {
        std::ofstream fout{ "test_timer.txt", std::ios::app | std::ios::out };
        bfl::auto_perf_timer<> apt{ fout };
        bfl::auto_perf_timer<> apt1{ std::cout };
        ASSERT_TRUE(fout.is_open());
        std::this_thread::sleep_for(500ms);
    } 
}
