use serde::Deserialize;

#[derive(Debug, Deserialize)]
struct WebTrafficData {
    timestamp: String,
    source_ip: String,
    destination_url: String,
    response_code: u16,
    bytes_transferred: u64,
}

fn main() {
    // Sample JSON data representing web traffic
    let json_str = r#"
        {
            "timestamp": "2023-11-20T12:30:45",
            "source_ip": "192.168.1.1",
            "destination_url": "https://example.com/page",
            "response_code": 200,
            "bytes_transferred": 1024
        }
    "#;

    // Parse JSON using Serde
    let result: Result<WebTrafficData, serde_json::Error> = serde_json::from_str(json_str);

    match result {
        Ok(web_traffic_data) => {
            // Perform analysis or further processing
            println!("Web Traffic Analysis:");
            println!("Timestamp: {}", web_traffic_data.timestamp);
            println!("Source IP: {}", web_traffic_data.source_ip);
            println!("Destination URL: {}", web_traffic_data.destination_url);
            println!("Response Code: {}", web_traffic_data.response_code);
            println!("Bytes Transferred: {}", web_traffic_data.bytes_transferred);
        }
        Err(e) => eprintln!("Error parsing JSON: {}", e),
    }
}