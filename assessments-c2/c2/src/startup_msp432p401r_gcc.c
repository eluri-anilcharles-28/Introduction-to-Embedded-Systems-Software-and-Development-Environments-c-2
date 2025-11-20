/* Minimal startup: define Reset_Handler expected by linker script */
extern int main(void);
void Reset_Handler(void);

void Reset_Handler(void)
{
    /* In real MCU startup: copy .data, zero .bss, call SystemInit, etc. */
    main();

    /* If main returns, loop */
    while (1) { }
}

/* Provide vector table symbol (simple) */
void (* const g_pfnVectors[])(void) __attribute__ ((section(".isr_vector"))) = {
    Reset_Handler,
    /* other entries could follow */
};
