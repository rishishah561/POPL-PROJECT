#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <hiredis/hiredis.h>

void handleRequest(const char* method, const char* path, const char* body) {
    if (strcmp(method, "GET") == 0) {
        // Handle GET request
        std::cout << "Received GET request on path: " << path << std::endl;
    } else if (strcmp(method, "POST") == 0) {
        // Handle POST request
        std::cout << "Received POST request on path: " << path << std::endl;

        // Example: Set the received data in Redis
        if (body != nullptr) {
            if (setRedisKey("mykey", body)) {
                std::cout << "Data stored in Redis: " << body << std::endl;
            } else {
                std::cerr << "Error storing data in Redis" << std::endl;
            }
        }
    } else {
        std::cerr << "Unsupported HTTP method: " << method << std::endl;
    }
}

bool setRedisKey(const char* key, const char* value) {
    redisContext *context = redisConnect("127.0.0.1", 6379);

    if (context == nullptr || context->err) {
        if (context) {
            fprintf(stderr, "Connection error: %s\n", context->errstr);
            redisFree(context);
        } else {
            fprintf(stderr, "Connection error: can't allocate redis context\n");
        }
        return false;  // Return false for an unsuccessful operation
    }

    redisReply *reply = (redisReply *)redisCommand(context, "SET %s %s", key, value);

    if (reply == nullptr || reply->type == REDIS_REPLY_ERROR) {
        fprintf(stderr, "Redis SET error: %s\n", reply ? reply->str : "Unknown error");
        freeReplyObject(reply);
        redisFree(context);
        return false;
    }

    freeReplyObject(reply);
    redisFree(context);
    return true;
}

int main() {
    // Basic HTTP server listening on port 8080
    const int PORT = 8080;

    std::cout << "Starting HTTP server on port " << PORT << "..." << std::endl;

    while (true) {
        // Simulate receiving a request (replace this with actual socket handling)
        const char* method = "GET";
        const char* path = "/";
        const char* body = "Example data";

        handleRequest(method, path, body);

        // Simulate a delay (replace this with actual event handling)
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}