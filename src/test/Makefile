CC                    := gcc
EXEC                  := main

MK_PATH               := $(abspath $(lastword $(MAKEFILE_LIST)))
ROOT_DIR              := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
BUILD_DIR             := $(ROOT_DIR)/out
BUILD_ABS_DIR         := $(abspath $(BUILD_DIR))

# $(info $(ROOT_DIR))

INCLUDE_DIRS          += -I$(ROOT_DIR)
INCLUDE_DIRS          += -I../utils
INCLUDE_DIRS          += -I../lib/uthash/include


SOURCE_FILES          := $(wildcard *.c)
SOURCE_FILES          += $(wildcard ../utils/*.c)


CFLAGS                += -m32 # gcc 32bit

CPPFLAGS              := $(INCLUDE_DIRS) -DBUILD_DIR=\"$(BUILD_ABS_DIR)\"
CPPFLAGS              += -ggdb3
CPPFLAGS              += -Wall
CPPFLAGS              += -O0

LDFLAGS               := -pthread
LDFLAGS               += -lm # to link againt the math library (libm)
LDFLAGS               += -m32

OBJ_FILES             = $(SOURCE_FILES:%.c=$(BUILD_DIR)/%.o)
DEP_FILE              = $(OBJ_FILES:%.o=%.d)

$(EXEC) : $(BUILD_DIR)/$(EXEC)

$(BUILD_DIR)/$(EXEC) : $(OBJ_FILES)
	@-mkdir -p $(@D)
	@$(CC) $^ $(LDFLAGS) -o $@
	@echo "EXEC $@"
	@echo "MAKE DONE!"

-include $(DEP_FILE)

$(BUILD_DIR)/%.o : %.c Makefile
	@-mkdir -p $(@D)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -c $< -o $@
	@echo "CC $<"

# Clean build and bin directories for all platforms
.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR)