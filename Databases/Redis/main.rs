use redis::Commands;
use std::{thread, time};

fn handle_request(method: &str, path: &str, body: Option<&str>, redis_client: &redis::Client) {
    if method == "GET" {
        // Handle GET request
        println!("Received GET request on path: {}", path);
    } else if method == "POST" {
        // Handle POST request
        println!("Received POST request on path: {}", path);

        // Example: Set the received data in Redis
        if let Some(data) = body {
            let _: () = redis_client.set("mykey", data).unwrap();
            println!("Data stored in Redis: {}", data);
        }
    } else {
        eprintln!("Unsupported HTTP method: {}", method);
    }
}

fn main() {
    // Basic HTTP server listening on port 8080
    const PORT: u16 = 8080;

    println!("Starting HTTP server on port {}...", PORT);

    let redis_client = redis::Client::open("redis://127.0.0.1:6379/").unwrap();

    // Simulate receiving a request (replace this with actual socket handling)
    let method = "GET";
    let path = "/";
    let body = Some("Example data");

    handle_request(method, path, body, &redis_client);

    // Simulate server running
    thread::sleep(time::Duration::from_secs(1));
}