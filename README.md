C1M2 — Build System Using GNU Make & GCC

University of Colorado Boulder — Introduction to Embedded Systems Software and Development Environments
This project implements the Week-2 Application Assignment: building a cross-platform command-line build system capable of compiling and linking an embedded application for both a native HOST environment and an MSP432 ARM Cortex-M platform. The build workflow is implemented using GNU Make, GCC, and arm-none-eabi-gcc.

🎯 Assignment Objectives

This build system supports:
Native (HOST) builds using gcc
ARM Cortex-M4 (MSP432) builds using arm-none-eabi-gcc
Preprocessing, assembly, object, dependency, and final executable generation
Platform-specific compiler, linker, and architecture flags
Automatic map file output (c1m2.map)
Code size reporting
Clean separation of HOST vs MSP432 source and include paths


* **HOST (gcc)**
* **MSP432 (arm-none-eabi-gcc)**

The Makefile generates:

* `c1m2.out` (executable)
* `c1m2.map` (map file)
* `.o`, `.d`, `.i`, `.asm` build artifacts

## **Build Commands**

**HOST:**
```
make build PLATFORM=HOST
```

**MSP432:**
```
make build PLATFORM=MSP432
```

**Run HOST executable:**
```
./c1m2.out
```

**Clean:**
```
make clean
```

Expected HOST output:

```
aXy72_L+R
```

