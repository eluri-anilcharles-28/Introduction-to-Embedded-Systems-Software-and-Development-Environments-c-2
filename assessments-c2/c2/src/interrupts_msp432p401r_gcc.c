/* Minimal interrupt stubs for MSP432 build - weak handlers */
void Default_Handler(void) __attribute__ ((weak));
void Default_Handler(void) { while (1); }

/* If the toolchain or linker expects specific IRQ names, define common ones */
void NMI_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
