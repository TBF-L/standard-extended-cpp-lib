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
