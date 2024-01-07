#lesson #ARM 
# Reset and Clock Control (RCC)

> RCC mange the clock for all peripheral in the MCU


## SESSION ONE





## SESSION TWO


> in modern MCU to used any peripheral like ADC,
> first should enable the clock for this peripheral, than should enable this peripheral.

> [! warning] if you don't enable clock for peripheral,
>  it will not response for any event you will do.

### RCC REGISTER

> [!info]- 
> stm32f103 have 10 registers in RCC peripheral you could see in refence manual
> of the micro, I will talk about some bits in these registers.

#### Clock Control Register(RCC_CR)


##### CSSON: Clock security system enable

> enable the Clock security system (CSS) that  detector ON if the HSE oscillator is ready , OFF if not
> if any fail happen in the clock CSS will make HSI  system clock

#### HSICAL (7:0): Internal high-speed clock calibration

> Calibration is process to ensure the accuracy and stability of the internal clock source,
> this bits is read only, the hardware make this process.

#### HSITRIM(4:0): Internal high-speed clock trimming

> These bits provide an additional user-programmable trimming value that is added to the HSICAL(7:0) bits, the default value in this bit is 16, if add one this mean the clock increase by 40KHz, if you decrement one this mean the clock decrease by 40KHz.