
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "../gorilla_compression.h" // Assuming this is the header for gorilla compression

int main() {
    // Generate datasets
    const size_t dataSize = 100000;
    std::vector<double> randomData(dataSize), zeroData(dataSize), slowIncData(dataSize);

    // Fill in randomData
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (size_t i = 0; i < dataSize; ++i) {
        randomData[i] = dis(gen);
    }

    // Fill in zeroData
    std::fill(zeroData.begin(), zeroData.end(), 0.0);

    // Fill in slowIncData
    for (size_t i = 0; i < dataSize; ++i) {
        slowIncData[i] = static_cast<double>(i) / dataSize;
    }

    // Function to measure compression time
    auto measureCompress = [&](const std::vector<double>& data) {
        auto start = std::chrono::high_resolution_clock::now();
        auto compressedData = gorilla::compress(data.data(), data.size()); 
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return std::make_pair(duration.count(), compressedData);
    };

    // Function to measure decompression time
    auto measureDecompress = [&](const std::vector<bool>& compressedData) {
        auto start = std::chrono::high_resolution_clock::now();
        auto decompressedData = gorilla::decompress(compressedData);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    };

    // Repeat compression & decompression 100 times, track average times
    const int repetitions = 100;
    double totalCompressTimeRandom = 0.0, totalDecompressTimeRandom = 0.0;
    double totalCompressTimeZero = 0.0, totalDecompressTimeZero = 0.0;
    double totalCompressTimeSlowInc = 0.0, totalDecompressTimeSlowInc = 0.0;

    for (int i = 0; i < repetitions; ++i) {
        auto [compressTimeRandom, compressedRandom] = measureCompress(randomData);
        totalCompressTimeRandom += compressTimeRandom;
        totalDecompressTimeRandom += measureDecompress(compressedRandom);

        auto [compressTimeZero, compressedZero] = measureCompress(zeroData);
        totalCompressTimeZero += compressTimeZero;
        totalDecompressTimeZero += measureDecompress(compressedZero);

        auto [compressTimeSlowInc, compressedSlowInc] = measureCompress(slowIncData);
        totalCompressTimeSlowInc += compressTimeSlowInc;
        totalDecompressTimeSlowInc += measureDecompress(compressedSlowInc);
    }

    // Print performance metrics
    std::cout << "Average compression time for random data: " << totalCompressTimeRandom / repetitions << " seconds\n";
    std::cout << "Average decompression time for random data: " << totalDecompressTimeRandom / repetitions << " seconds\n";
    std::cout << "Average compression time for zero data: " << totalCompressTimeZero / repetitions << " seconds\n";
    std::cout << "Average decompression time for zero data: " << totalDecompressTimeZero / repetitions << " seconds\n";
    std::cout << "Average compression time for slowly incrementing data: " << totalCompressTimeSlowInc / repetitions << " seconds\n";
    std::cout << "Average decompression time for slowly incrementing data: " << totalDecompressTimeSlowInc / repetitions << " seconds\n";

    return 0;
}