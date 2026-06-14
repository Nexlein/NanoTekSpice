# NanoTekSpice

NanoTekSpice is a logic gate simulator built in C++. The core objective of this project is to model digital electronic components (such as logic gates, clocks, and memory units) using pure Object-Oriented Programming principles.

## The Goal

The project consists of creating a software simulation of an electronic circuit board. It parses a configuration file (`.nts`) that describes various electronic components and their interconnections, then simulates the logical state of the system over time. This requires a robust architecture utilizing interfaces, abstract classes, and the Factory design pattern.

## Core Features

- **Component Simulation**: Implements various standard logic gates (AND, OR, XOR, NOT, NAND, NOR) and complex chips (adders, decoders, flip-flops).
- **Circuit Parsing**: A custom parser reads `.nts` files to instantiate components and link their pins together dynamically.
- **State Evaluation**: Evaluates the output of specific pins by recursively computing the state of connected input pins using lazy evaluation.
- **Clock and Time**: Simulates a system clock that updates the state of the circuit on each "tick".

## Object-Oriented Architecture

The simulator relies heavily on OOP concepts:

- **`IComponent` Interface**: Every electronic chip, pin, and gate implements a standard interface with methods like `compute(pin)` and `setLink(pin, component, other_pin)`.
- **Factory Pattern**: A dynamic component factory is used to instantiate chips based on string identifiers read from the parsing stage.
- **Polymorphism**: The core engine treats all components as generic `IComponent` objects, allowing the simulation loop to remain completely agnostic of the underlying logic.

## Usage

```bash
# Build the project
cmake -B build
cmake --build build

# Run the simulator
./nanotekspice circuit.nts
```

Once running, the simulator provides an interactive prompt to inspect variables, trigger clock ticks, and simulate the circuit.
