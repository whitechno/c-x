MKDIR := mkdir -p
RMDIR := rm -rf
TARGET_EXT := out

.PHONY: read_env
read_env:
	@echo "RM is '$(RM)'"
	@echo "CC is '$(CC)' `which $(CC)`"
	@echo "CFLAGS is '$(CFLAGS)'"
	@echo "TEX is '$(TEX)' `which $(TEX)`"
	@echo "PATHU: $(PATHU)"
	@echo "PATHS: $(PATHS)"
	@echo "PATHT: $(PATHT)"
	@echo "PATHB: $(PATHB)"
	@echo "PATHD: $(PATHD)"
	@echo "PATHO: $(PATHO)"
	@echo "PATHR: $(PATHR)"
	@echo "MAIN_OBJS:   $(MAIN_OBJS)"
	@echo "MAIN_TARGET: $(MAIN_TARGET)"
	@echo "SRC_TEST: $(SRC_TEST)"
	@echo "TEST_RESULTS: $(TEST_RESULTS)"
	@echo "DEP_RULES: $(DEP_RULES)"

PATHU := Unity/src/
PATHS := src/
PATHT := test/
PATHB := build/
PATHD := build/deps/
PATHO := build/objs/
PATHR := build/results/

# -DTEST flag is used to define a preprocessor macro TEST 
# when compiling test files in the Unity testing framework
TEST_CFLAGS := -I$(PATHU) -I$(PATHS) -DTEST

$(PATHB):
	$(MKDIR) $@

$(PATHO):
	$(MKDIR) $@

# '|' is for order-only prerequisites
# Order-only prerequisites are not considered when checking
# if the target is up to date.
# They are only used to ensure that the target is built
# after the order-only prerequisites are built.
# This is useful for creating directories or files that are needed
# for the target to be built, but are not part of the target itself.

$(PATHO)%.o: $(PATHS)%.c | $(PATHO)
	$(CC) -c $< -o $@

$(PATHO)%.o: $(PATHU)%.c | $(PATHO)
	$(CC) -c $< -o $@

$(PATHO)%.o: $(PATHT)%.c | $(PATHO)
	$(CC) $(TEST_CFLAGS) -c $< -o $@

#
# Compile and run main calc
#

SRC_MAIN := $(wildcard $(PATHS)*.c)
MAIN_OBJS := $(patsubst $(PATHS)%.c,$(PATHO)%.o,$(SRC_MAIN))
MAIN_TARGET := $(PATHB)mainCalc.$(TARGET_EXT)

$(MAIN_TARGET): $(MAIN_OBJS)
	$(CC) $^ -o $@

.PHONY: main
main: $(MAIN_TARGET)
	./$<

#
# Compile and run all tests
#

SRC_TEST := $(wildcard $(PATHT)*.c)
TEST_RESULTS := $(patsubst $(PATHT)Test%.c,$(PATHR)Test%.txt,$(SRC_TEST))

$(PATHB)Test%.$(TARGET_EXT): $(PATHO)Test%.o $(PATHO)%.o $(PATHO)unity.o | $(PATHB)
	$(CC) $^ -o $@

$(PATHR):
	$(MKDIR) $@

# The `-` before a command in a Makefile recipe tells Make to ignore any 
# errors (non-zero exit status) from that command and continue execution. 
# Without the -, if the command fails (returns non-zero), Make would stop 
# the build with an error.
# `-./$< > $@ 2>&1`
# The alternative is the `|| true` at the end of the command,
# which is a shell construct that
# ensures that the command always returns a success status (0),
# regardless of whether the command before it succeeded or failed.
# `./$< > $@ 2>&1 || true`
# The `2>&1` part redirects the standard error (file descriptor 2)
# to the same place as standard output (file descriptor 1),
# so that both the output and error messages are captured in the same file.
# The choice between using - or || true is mostly a matter of style:
#   `|| true` is more explicit about what we're doing - ignoring failures
#   `-` is more concise but less obvious about its purpose
# However, we don't need to ignore errors in our case, because our tests
# always `return 0;` rather than `return UNITY_END();`.

# The `@` before the command suppresses the command output.
# $(PATHR)%.txt: $(PATHB)%.$(TARGET_EXT) | $(PATHR)
# 	@if [ ! -f $@ ] || [ $< -nt $@ ]; then \
# 		echo "Running test $<..."; \
# 		./$< > $@ 2>&1 || true; \
# 	fi

# We decided to `return UNITY_END();` in `Testadd.c`,
# so we need to use `-` to ignore the error.
$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXT) | $(PATHR)
	-./$< > $@ 2>&1

FAIL = `grep -s :FAIL $(PATHR)*.txt`

.PHONY: test
test: $(PATHO) $(PATHR) $(TEST_RESULTS)
	@echo "Test results:"
	@echo "===================="
	@cat $(PATHR)*.txt
	@echo "===================="
	@echo "Test results end"
	@echo "-----------------------FAILURES:-----------------------"
	@echo "$(FAIL)"

#
# generate Makefile dependency rules
#

DEPEND := gcc -MM -MG -MF
# -MM: Generates dependency rules for Makefiles, 
#      listing header file dependencies, but skips system header files
# -MG: Treats missing header files as generated files 
#      instead of producing an error
# -MF <file>: Specifies the output file where the dependency rules 
#             should be written instead of stdout
# Example: gcc -MM -MG -MF deps.mk main.c

DEP_RULES := $(patsubst $(PATHT)Test%.c,$(PATHD)Test%.mk,$(SRC_TEST))

$(PATHD):
	$(MKDIR) $@

$(PATHD)%.mk: $(PATHT)%.c | $(PATHD)
	$(DEPEND) $@ $<

.PHONY: deps
deps: $(DEP_RULES)
	@echo "Dependency rules:"
	@echo "===================="
	@cat $(PATHD)*.mk
	@echo "===================="
	@echo "Dependency rules end"

.PHONY: clean
clean:
	$(RM) $(PATHO)*.o
	$(RMDIR) $(PATHO)
	$(RM) $(PATHR)*.txt
	$(RMDIR) $(PATHR)
	$(RM) $(PATHD)*.mk
	$(RMDIR) $(PATHD)
	$(RM) $(PATHB)*.$(TARGET_EXT)
	$(RMDIR) $(PATHB)

.PRECIOUS: $(PATHB)Test%.$(TARGET_EXT)
.PRECIOUS: $(PATHO)%.o
# .PRECIOUS: $(PATHR)%.txt

$(info .DEFAULT_GOAL is $(.DEFAULT_GOAL))
