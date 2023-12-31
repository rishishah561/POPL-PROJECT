# POPL-PROJECT README

## Real-Time Web Traffic Analysis and Comparative Evaluation in Rust & C++

### Project Overview

This project presents a systematic approach to implementing real-time web traffic analyzers in both Rust and C++, emphasizing the significance of language-specific features and design principles. The comparison involves key libraries such as:
1) Actix-Web vs. Boost.Beast  
2) Redis-Rs vs. Hiredis 
3) SerDe vs JSON 
   
thus shedding light on how language-specific principles influence the development of high-performance systems. Concepts explored include concurrency models, memory management, type systems, and error handling strategies in Rust and C++. The analysis extends to performance metrics, reliability, safety, and security evaluations, providing practical insights for deploying real-time data systems.

### Differentiation in Approach

This project stands out as the first to utilize Rust and/or C++ libraries for real-time web traffic analysis and presents a unique comparative analysis. Notably, no external hardware or architectural components are required, focusing solely on software-based comparisons. The integration of VTUNE, an Intel-developed performance profiling tool, enhances the efficiency of performance analysis without the need for external databases.

### PoPL Aspects
[Actix-Web](https://github.com/rishishah561/POPL-PROJECT/blob/main/Framework/actix-web/README.md) \
[Boost-Beast](https://github.com/rishishah561/POPL-PROJECT/blob/main/Framework/boost-beast/README.md) \
[Hiredis](https://github.com/rishishah561/POPL-PROJECT/blob/main/Databases/Hiredis/README.md) \
[Redis](https://github.com/rishishah561/POPL-PROJECT/blob/main/Databases/Redis/README.md) \
[SerDe](https://github.com/rishishah561/POPL-PROJECT/blob/main/Data%20Structures/SerDe/README.md) \
[JSON](https://github.com/rishishah561/POPL-PROJECT/blob/main/Data%20Structures/JSON/README.md)

### Testing Component: VTUNE

VTUNE, a performance profiling tool from Intel, is seamlessly integrated into our codebase, contributing significantly to comprehensive and efficient performance analysis. This tool aids in identifying bottlenecks and areas for improvement in our software implementation.

### Future Potential

Given more time, the project could be extended to design a custom web framework for real-time traffic analysis on the college's official website. This expansion would involve incorporating language-specific principles, such as concurrency, performance optimizations, and safety features, into the development of the web framework. Collaboration with the developers' society and contribution to the college's technology infrastructure align with principles of community engagement and the practical application of programming language concepts in a real-world setting.

