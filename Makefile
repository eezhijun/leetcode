# only test demo
CC                    := gcc
EXEC                  := main

MK_PATH               := $(abspath $(lastword $(MAKEFILE_LIST)))
ROOT_DIR              := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
BUILD_DIR             := $(ROOT_DIR)/out
BUILD_ABS_DIR         := $(abspath $(BUILD_DIR))



INCLUDE_DIRS          := -I.
INCLUDE_DIRS          += -I$(ROOT_DIR)/demo
INCLUDE_DIRS          += -I$(ROOT_DIR)/src
INCLUDE_DIRS          += -I$(ROOT_DIR)/src/utils
INCLUDE_DIRS          += -I$(ROOT_DIR)/src/lib/uthash/include


SOURCE_FILES          := $(wildcard *.c)
SOURCE_FILES          += $(wildcard demo/*.c)
SOURCE_FILES          += $(wildcard demo/array/*.c)
SOURCE_FILES          += $(wildcard demo/string/*.c)
SOURCE_FILES          += $(wildcard src/utils/*.c)
SOURCE_FILES          += $(wildcard src/test/*.c)


CFLAGS                += -m32 # gcc 32bit

CPPFLAGS              := $(INCLUDE_DIRS) -DBUILD_DIR=\"$(BUILD_ABS_DIR)\"
CPPFLAGS              += -ggdb3

LDFLAGS               := -pthread
LDFLAGS               += -lm # to link againt the math library (libm)
LDFLAGS               += -m32


# user choose demo
ifeq ($(demo),?)
run:
	@echo "tt"
	@echo "lc"
endif

ifeq ($(demo),tt)
  CPPFLAGS            += -DTEST_DEMO
else ifeq ($(demo),lc)
  CPPFLAGS            += -DLC_DEMO
endif



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

.PHONY: all
all: $(BUILD_DIR)/$(EXEC)

# Clean build and bin directories for all platforms
.PHONY: clean
clean:
	-rm -rf $(BUILD_DIR)

# Run clang-format on source code
.PHONY: format
format:
	@echo "Running clang-format"
	@clang-format -i \
	$(wildcard demo/*.c) \
	$(wildcard src/test/*.c) \
	$(wildcard src/utils/*.c)

# Build and run
.PHONY: run
run: all
	@echo "Starting program: $(BUILD_DIR)/$(EXEC)"
	@cd $(BUILD_DIR) && ./$(EXEC)
