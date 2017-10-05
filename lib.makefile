###############################################################################
# Invoked by module build makefile which exports few variables.
# Setting up anything required to compile.
# Rarely needs to be changed.
CC=gcc
AR=ar
CPP=g++
SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,obj/%.o,$(SOURCES))
CFLAGS+=$(addprefix -D,$(DEFINES))
LIB=../../lib/libcod4x_$(MODULE).a
###############################################################################
# OS-specific stuff.
ifeq ($(OS),Windows_NT)
RM=del obj\\*.o $(subst /,\\,$(LIB))
else
RM=rm -r obj/*.o $(LIB)
endif
###############################################################################
# Rules itself.
# Entry point.
all: $(LIB)
	@echo Done

# Target
$(LIB): $(OBJECTS)
	@echo  $(AR) $(notdir $@)
	@$(AR) rcs -o $@ $^ $(ADDITIONAL_OBJ)

# C rule.
obj/%.o: %.c
	@echo  $(CC) $(notdir $@)
	@$(CC) $(CFLAGS) -o $@ $<

# Clean rule.
clean:
	@$(RM)
	@echo Done