#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <iostream>
#include <vector>

int main() {
    // Create a logger with both console and file sinks
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/app.log", true);
    std::vector<spdlog::sink_ptr> sinks { console_sink, file_sink };
    auto logger = std::make_shared<spdlog::logger>("app_logger", sinks.begin(), sinks.end());
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::debug);

    // Log some messages
    spdlog::info("Starting application...");

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    spdlog::debug("Vector size: {}", numbers.size());

    int sum = 0;
    for (int num : numbers) {
        sum += num;
        spdlog::trace("Adding {} to sum", num);
    }
    spdlog::info("Sum of numbers: {}", sum);

    try {
        // Simulate an error condition
        throw std::runtime_error("Something went wrong!");
    } catch (const std::exception& e) {
        spdlog::error("Error occurred: {}", e.what());
    }

    // Log a custom message with formatting
    spdlog::warn("Application finished with status: {:.2f}", 0.75);

    // Flush and clean up
    spdlog::drop_all();

    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();

    return 0;
}