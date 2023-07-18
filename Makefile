# only test demo
$(info "MAKE START")

CC                := gcc
BIN               := main

MAKEFIILE_PATH                        := $(abspath $(lastword $(MAKEFILE_LIST)))
ROOT_DIR                              := $(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
BUILD_DIR                             := $(ROOT_DIR)/output
BUILD_ABS_DIR                         := $(abspath $(BUILD_DIR))
DEMO_DIR                              := $(ROOT_DIR)/demo
SRC_DIR                               := $(ROOT_DIR)/src
LIB_DIR                               := $(ROOT_DIR)/src/lib


INCLUDE_DIRS          := -I.
INCLUDE_DIRS          += -I$(SRC_DIR)
INCLUDE_DIRS          += -I$(DEMO_DIR)
INCLUDE_DIRS          += -I$(LIB_DIR)


SOURCE_FILES          := $(wildcard *.c)
SOURCE_FILES          += $(wildcard demo/*.c)
SOURCE_FILES          += $(wildcard src/lib/*.c)
SOURCE_FILES          += $(wildcard src/array/*.c)
SOURCE_FILES          += $(wildcard src/string/*.c)


CFLAGS                := -ggdb3
LDFLAGS               := -ggdb3 -pthread
CPPFLAGS              := $(INCLUDE_DIRS) -DBUILD_DIR=\"$(BUILD_ABS_DIR)\"
CPPFLAGS              += -D_WINDOWS_


CFLAGS                += -m32 # gcc 32bit
LDFLAGS               += -m32

LDFLAGS               += -lm # to link againt the math library (libm)
CPPFLAGS              += -Wall


ifdef SANITIZE_ADDRESS
  CFLAGS              += -fsanitize=address -fsanitize=alignment
  LDFLAGS             += -fsanitize=address -fsanitize=alignment
endif

ifdef SANITIZE_LEAK
  LDFLAGS             += -fsanitize=leak
endif

# user choose demo
ifeq ($(USER_DEMO),TEST_DEMO)
  CPPFLAGS            += -DUSER_DEMO=0
endif

ifeq ($(USER_DEMO),P_DEMO)
  CPPFLAGS            += -DUSER_DEMO=1
endif



OBJ_FILES             = $(SOURCE_FILES:%.c=$(BUILD_DIR)/%.o)
DEP_FILE              = $(OBJ_FILES:%.o=%.d)

${BIN} : $(BUILD_DIR)/$(BIN)

${BUILD_DIR}/${BIN} : ${OBJ_FILES}
	@-mkdir -p ${@D}
	@$(CC) $^ ${LDFLAGS} -o $@
	@echo "BIN $@"

-include ${DEP_FILE}

${BUILD_DIR}/%.o : %.c Makefile
	@-mkdir -p $(@D)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -c $< -o $@
	@echo "CC $<"

.PHONY : clean

clean:
	-rm -rf $(BUILD_DIR)
