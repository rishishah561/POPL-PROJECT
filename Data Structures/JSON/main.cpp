#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Sample JSON data representing web traffic
    std::string jsonStr = R"(
        {
            "timestamp": "2023-11-20T12:30:45",
            "source_ip": "192.168.1.1",
            "destination_url": "https://example.com/page",
            "response_code": 200,
            "bytes_transferred": 1024
        }
    )";

    try {
        // Parse JSON
        json jsonData = json::parse(jsonStr);

        // Extract information
        std::string timestamp = jsonData["timestamp"];
        std::string sourceIP = jsonData["source_ip"];
        std::string destinationURL = jsonData["destination_url"];
        int responseCode = jsonData["response_code"];
        int bytesTransferred = jsonData["bytes_transferred"];

        // Perform analysis or further processing
        std::cout << "Web Traffic Analysis:" << std::endl;
        std::cout << "Timestamp: " << timestamp << std::endl;
        std::cout << "Source IP: " << sourceIP << std::endl;
        std::cout << "Destination URL: " << destinationURL << std::endl;
        std::cout << "Response Code: " << responseCode << std::endl;
        std::cout << "Bytes Transferred: " << bytesTransferred << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}