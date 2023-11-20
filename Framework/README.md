# VTune Comparison betweeen Actix-Web and Boost-Beast

Comparing the two codes in the context of profiling with Intel VTune for a web traffic analyzer:

1. *Concurrency Model:*
   - *Boost.Asio Code:* Utilizes Boost.Asio for asynchronous operations with a callback-based approach. The asynchronous nature allows handling multiple connections simultaneously.
   - *Actix Web Code:* Utilizes Actix Web, a framework built on top of Tokio, for asynchronous handling. It also leverages async/await syntax for readability and conciseness.

2. *Framework Features:*
   - *Boost.Asio Code:* Primarily focuses on low-level networking, requiring explicit handling of HTTP protocol details.
   - *Actix Web Code:* Provides a higher-level HTTP framework with built-in abstractions for handling requests, routes, and responses, reducing the need for manual protocol handling.

3. *Profiling with VTune:*
   - *Boost.Asio Code:* VTune can be used to analyze asynchronous operations, threading, and potential bottlenecks in low-level network handling.
   - *Actix Web Code:* VTune can profile asynchronous execution, identify hotspots, and analyze the performance of high-level abstractions provided by Actix Web.

4. *Concurrency and Scalability:*
   - *Boost.Asio Code:* Provides explicit control over concurrency with callbacks, allowing fine-grained tuning but potentially requiring more effort.
   - *Actix Web Code:* Benefits from Tokio's underlying asynchronous runtime, offering a high level of concurrency and scalability with less manual intervention.

In the context of a web traffic analyzer, the Actix Web code is likely to be more advantageous due to its higher-level abstractions, expressive syntax, and the built-in features of the Actix Web framework, which can simplify development and maintenance. The use of async/await syntax also enhances the readability of asynchronous code. However, the final choice depends on specific requirements and the expertise of the development team.



## VTune: Actix-Web
![WhatsApp Image 2023-11-20 at 22 44 03_362a89fe](https://github.com/rishishah561/POPL-PROJECT/assets/105542232/109dfca7-e0c4-43b7-84a8-d135387a8892)


## VTune: Boost-Beast 
![WhatsApp Image 2023-11-20 at 22 44 11_5be7b54c](https://github.com/rishishah561/POPL-PROJECT/assets/105542232/f8bb7d1a-1f68-4254-8dc0-f302c65a5700)
