\ install hardware abstractions in flash

\ cr eraseflash
cr
compiletoflash

4 constant io-ports  \ A..D

include ../flib/mecrisp/cond.fs
include ../flib/mecrisp/hexdump.fs
include ../flib/stm32f1/io.fs
include ../flib/pkg/pins36.fs
include ../flib/stm32f1/hal.fs
include ../flib/stm32f1/timer.fs
include ../flib/stm32f1/pwm.fs
include ../flib/stm32f1/adc.fs
include ../flib/any/ring.fs
include ../flib/stm32f1/uart2.fs
include ../flib/stm32f1/uart2-irq.fs
include ../flib/stm32f1/spi.fs
include ../flib/any/i2c-bb.fs

\ board definitions for Hy-TinySTM103T

\ PA1 constant LED
\ blue pill PC 13
2 13 io constant LED


: init ( -- )  \ board initialisation
  jtag-deinit  \ disable JTAG, we only need SWD
  OMODE-PP LED io-mode!
  72MHz
  flash-kb . ." KB <rnw> " hwid hex. ." ok." cr
  1000 systick-hz
;

include cornerstone.fs

cornerstone <<<hal-rnw>>>
\ vim: set ft=forth :
