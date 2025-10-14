# Bank Queue Simulation

A discrete event simulation system that models customer queuing in a bank environment with multiple tellers. This project implements a comprehensive simulation using priority queues, event-driven programming, and statistical analysis.

## ✨ Features

- **Discrete Event Simulation**: Event-driven architecture for accurate time modeling
- **Multiple Queuing Strategies**: Support for different customer assignment algorithms
- **Statistical Analysis**: Comprehensive metrics including average wait time, standard deviation, and maximum wait time
- **Multi-Teller Support**: Configurable number of tellers for load balancing analysis
- **Performance Comparison**: Side-by-side comparison of different queuing modes

### Core Components

- **Customer Management**: Individual customer tracking with arrival, service start, and completion times
- **Teller Queues**: FIFO queue implementation for each teller with dynamic load balancing
- **Event System**: Priority queue-based event scheduling for arrival and departure events
- **Simulation Engine**: Main simulation loop handling event processing and statistics

## 🚀 Getting Started

> **⚡ Quick Start**: Pre-compiled binaries are already included in the `bin/` directory! 
> 
> **If you just want to run the simulation**, skip directly to the [📖 Usage](#-usage) section.
> 
> **If you want to build from source** or modify the code, continue with the prerequisites below.

### Prerequisites

#### Linux (Ubuntu/Debian)
```bash
# Install build essentials
sudo apt update
sudo apt install build-essential cmake

# Verify installation
gcc --version
cmake --version
```

#### macOS
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Install CMake (using Homebrew)
brew install cmake

# Verify installation
gcc --version
cmake --version
```

#### Windows
**Option 1: MinGW-w64 (Recommended)**
```powershell
# Install using winget
winget install mingw-w64

# Or download from: https://www.mingw-w64.org/downloads/
# Add to PATH: C:\mingw64\bin
```

**Option 2: Visual Studio Build Tools**
```powershell
# Install Visual Studio Build Tools
winget install Microsoft.VisualStudio.2022.BuildTools

# Or download from: https://visualstudio.microsoft.com/downloads/
```

**Install CMake:**
```powershell
# Using winget
winget install Kitware.CMake

# Or download from: https://cmake.org/download/
```

### Building the Project

#### Option 1: Using CMake (Recommended)

**Linux/WSL/macOS:**
```bash
# Navigate to project directory
cd BankQueueSim

# Create and enter build directory
mkdir build && cd build

# Configure and build
cmake ..
cmake --build .
```

**Windows (PowerShell):**
```powershell
# Navigate to project directory
cd BankQueueSim

# Create and enter build directory
mkdir build; cd build

# Configure and build
cmake ..
cmake --build .
```

**Windows (Command Prompt):**
```cmd
# Navigate to project directory
cd BankQueueSim

# Create and enter build directory
mkdir build && cd build

# Configure and build
cmake ..
cmake --build .
```

#### Option 2: Manual Compilation

**Linux/WSL:**
```bash
gcc -o qSim src/*.c -Iinclude -lm
```

**macOS:**
```bash
gcc -o qSim src/*.c -Iinclude -lm
# or using clang
clang -o qSim src/*.c -Iinclude -lm
```

**Windows (MinGW):**
```powershell
gcc -o qSim.exe src/*.c -Iinclude -lm
```

**Windows (MSVC):**
```cmd
cl /Fe:qSim.exe src/*.c /Iinclude
```

### Installation

> **📦 Pre-built Binaries Available**: The executables are already compiled and ready to use!

The executable is located in the `bin/` directory:
- **Linux/WSL**: `bin/qSim` ✅ *Ready to run*
- **Windows**: `bin/qSim.exe` ✅ *Ready to run*

*Note: After building from source, new executables will replace these pre-built versions.*

## 📖 Usage

### Basic Syntax

**Linux/WSL/macOS:**
```bash
./qSim <numCustomers> <numTellers> <simulationTime> <averageServiceTime>
```

**Windows (PowerShell/Command Prompt):**
```powershell
.\qSim.exe <numCustomers> <numTellers> <simulationTime> <averageServiceTime>
```

### Parameters

| Parameter | Type | Description |
|-----------|------|-------------|
| `numCustomers` | integer | Total number of customers to simulate |
| `numTellers` | integer | Number of available tellers |
| `simulationTime` | double | Total simulation time (minutes) |
| `averageServiceTime` | double | Average service time per customer |

### Example Usage

**Linux/WSL/macOS:**
```bash
# Simulate 100 customers, 3 tellers, 80-minute period, 2-minute average service
./qSim 100 3 80 2

# High-load scenario
./qSim 200 2 60 3

# Low-load scenario  
./qSim 50 4 100 1.5
```

**Windows:**
```powershell
# Simulate 100 customers, 3 tellers, 80-minute period, 2-minute average service
.\qSim.exe 100 3 80 2

# High-load scenario
.\qSim.exe 200 2 60 3

# Low-load scenario  
.\qSim.exe 50 4 100 1.5
```

### Sample Output

```
Mode 0 Simulation Results:
Average wait time: 2.45 minutes
Standard deviation: 1.87 minutes
Maximum wait time: 8.32 minutes

Mode 1 Simulation Results:
Average wait time: 1.98 minutes
Standard deviation: 1.42 minutes
Maximum wait time: 6.75 minutes
```

## 🔧 Configuration

### Simulation Modes

The simulation supports two different queuing strategies:

- **Mode 0**: First available teller assignment
- **Mode 1**: Shortest queue assignment

### Customization

You can modify simulation parameters in the source code:

```c
// In sim.c - modify random arrival generation
double arrivalTime = rand()/(double)RAND_MAX * simTime;

// Adjust service time distribution
double serviceTime = /* your distribution function */;
```

## 📊 Performance Analysis

### Metrics Collected

- **Average Wait Time**: Mean time customers spend waiting in queues
- **Standard Deviation**: Measure of wait time variability
- **Maximum Wait Time**: Longest individual wait time
- **Queue Utilization**: Efficiency metrics for each teller

### Statistical Methods

The simulation uses mathematical analysis including:
- Variance calculation: `σ² = E[X²] - (E[X])²`
- Standard deviation: `σ = √variance`
- Real-time queue length monitoring

## 🛠️ Development

### Project Structure

```
BankQueueSim/
├── CMakeLists.txt           # Build configuration
├── README.md               # This file
├── include/               # Header files
│   ├── customer.h        # Customer data structure
│   ├── teller.h          # Teller and queue management
│   ├── event.h           # Event system
│   └── sim.h             # Main simulation interface
├── src/                  # Source files
│   ├── main.c            # Program entry point
│   ├── sim.c             # Simulation engine
│   ├── customer.c        # Customer operations
│   ├── teller.c          # Teller queue operations
│   └── event.c           # Event management
├── bin/                  # Compiled executables
└── build/                # Build artifacts
```

### Building from Source

1. **Configure CMake**:
   ```bash
   cmake -S . -B build
   ```

2. **Compile**:
   ```bash
   cmake --build build --parallel
   ```

3. **Run Tests**:
   
   **Linux/WSL/macOS:**
   ```bash
   cd bin && ./qSim 50 2 30 1.5
   ```
   
   **Windows:**
   ```powershell
   cd bin; .\qSim.exe 50 2 30 1.5
   ```

## 🐛 Troubleshooting

### Common Issues

**Linker Error with `sqrt` function:**
```
undefined reference to `sqrt'
```
**Solution**: Ensure math library is linked (`-lm` flag or `target_link_libraries(qSim m)` in CMake)

**Missing Executable Extension:**
```
File 'qSim' created instead of 'qSim.exe'
```
**Solution**: Build with Windows-native compiler (MinGW-w64 or Visual Studio)

### Platform-Specific Notes

#### Windows
- **Recommended**: MinGW-w64 for GCC compatibility
- **Alternative**: Visual Studio Build Tools for MSVC
- **Executable**: Creates `qSim.exe` in `bin/` directory
- **Path Separators**: Use `\` or `\\` in paths

#### Linux/WSL
- **Compiler**: GCC (usually pre-installed)
- **Executable**: Creates `qSim` (no extension) in `bin/` directory  
- **Math Library**: Automatically linked with `-lm` flag

#### macOS
- **Compiler**: Clang (via Xcode) or GCC (via Homebrew)
- **Executable**: Creates `qSim` (no extension) in `bin/` directory
- **Package Manager**: Homebrew recommended for additional tools

#### Cross-Platform Tips
- Use forward slashes `/` in CMake paths (works on all platforms)
- CMake automatically handles platform-specific compilation
- Environment variables: Use `$HOME` (Unix) or `%USERPROFILE%` (Windows)

## 📄 License

This project is developed for educational purposes as part of a Data Structures assignment.

## 🤝 Contributing

This is an academic project. For educational use and reference only.

## 📧 Support

For questions or issues related to building or running the simulation, please refer to the troubleshooting section above or consult your course materials.

---

*Built with C, CMake, and mathematical modeling principles for discrete event simulation.*