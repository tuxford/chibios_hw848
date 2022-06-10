# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/HW_848_STM32F401CCU/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/HW_848_STM32F401CCU

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
