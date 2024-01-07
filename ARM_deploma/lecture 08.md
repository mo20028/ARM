#ARM #embedded #lesson 

# Reset Sequence

## Types of Reset

### System Reset
> Reset all memory and peripheral except RCC and [Back up domain] Registers.

1. Reset Button
2. Watch dog timer and Brown out detector.
3. [software reset]
### Power Reset
> Reset all memory and peripheral except [Back up domain] Registers.

1. Power off, on cycle.

### Back up Reset
> Reset all memory and peripheral.


## What happen when Reset MCU

1. PC load with value [0x0000 0000]
2. The processor load value @ memory location [0x0000 0000] in MSP (main stack pointer).
3. The processor load value @ memory location [0x0000 0004] in PC (this value is address for Reset handler) in other word start up code.
4. PC jump to reset handler and start execution.
5. in the end of reset handler PC jump to main function.



