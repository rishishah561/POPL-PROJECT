#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <iostream>

namespace http = boost::beast::http;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

void handle_request(http::request<http::string_body>& req, asio::ip::tcp::socket& socket) {
    http::response<http::string_body> res;
    res.version(req.version());
    res.result(http::status::ok);
    res.set(http::field::server, "Boost.Beast HTTP Server");
    res.body() = "Hello, World!";
    res.prepare_payload();
    http::async_write(socket, res, [](const boost::system::error_code& ec, std::size_t) {});
}

int main() {
    asio::io_context io_context;

    tcp::acceptor acceptor(io_context, {asio::ip::address_v4::any(), 8080});
    tcp::socket socket(io_context);

    acceptor.async_accept(socket, [&](const boost::system::error_code& ec) {
        if (!ec) {
            http::request<http::string_body> req;
            http::async_read(socket, buffer, req, [&](const boost::system::error_code& ec, std::size_t) {
                if (!ec) {
                    handle_request(req, socket);
                }
            });
        }
    });

    io_context.run();
}