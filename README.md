## OmniServe

OmniServe is a versatile, high-performance C++ server framework designed to handle complex data operations. Built with Qt, Drogon, and gRPC, it provides a reliable, secure, and scalable solution for managing, distributing, and processing data across various services. OmniServe supports bidirectional communication, allowing clients and servers to exchange data efficiently in real-time using DTOs.

### Features
- **Comprehensive Data Management**: OmniServe handles a wide range of data tasks, including distribution, real-time processing, and service interactions.
- **Service-to-Server API Calls**: External services can interact with the server, requesting data and triggering operations via gRPC.
- **Bidirectional gRPC Communication**: Facilitates efficient communication between the server and clients across various platforms and languages supporting gRPC.
- **Authorization & Authentication**: Ensures secure data exchange and integrates authentication mechanisms for safe interactions.
- **Role-Based Access Control (RBAC)**: Allows fine-grained access control to restrict resources based on roles.
- **ORM Support**: OmniServe supports ORM features for efficient database connections and management.
- **Frontend Rendering**: Supports rendering of HTML-based frontends for integration with web-based UIs.
- **gRPC and JSON Support**: Uses gRPC for high-performance data encoding/decoding, and also supports seamless JSON conversion for compatibility with different clients.
- **Enhanced Logging and Monitoring**: Provides robust logging and monitoring capabilities to track system performance and errors.
- **Encryption and Secure Data Transfer**: Ensures all communications are encrypted, safeguarding data in transit.

### Getting Started

#### Prerequisites
To start building and running OmniServe, you'll need to have the following tools installed:

- **C++ Compiler**: Ensure compatibility with C++17 or later.
- **Qt Framework**: Version 5.15 or above.
- **Drogon Framework**: A C++ framework for building asynchronous HTTP applications.
- **gRPC**: For high-performance RPC connections and bidirectional communication.
- **vcpkg** (Package Manager): Recommended for managing dependencies and libraries.
- **pkg-config**: Used to help locate libraries and dependencies on Linux-based systems.
- **CMake**: Version 3.15 or above, used for building the project.

#### Installation

To get started with OmniServe, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/OmniServe.git
   cd OmniServe

2. . **Install required dependencies:**
   ```bash
   ./vcpkg install qt5-base drogon grpc libuuid

3. . **Set up CMake with vcpkg toolchain:**
   ```bash
   cmake -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake .

4. . **Build the project:**
   ```bash
   cmake --build .

5. . **Run OmniServe:**
   ```bash 
   ./OmniServe
