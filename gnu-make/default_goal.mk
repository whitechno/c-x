# Query the default goal.

# no default goal is yet set
ifeq ($(.DEFAULT_GOAL),)
  $(warning default goal is $(.DEFAULT_GOAL))
endif

.PHONY: foo
foo: ; @echo $@

# default goal is foo
$(warning default goal is $(.DEFAULT_GOAL))

# Reset the default goal.
.DEFAULT_GOAL :=

.PHONY: bar
bar: ; @echo $@

# default goal is bar
$(warning default goal is $(.DEFAULT_GOAL))

# Set our own.
.DEFAULT_GOAL := foo

#	make -f default_goal.mk
#	Output:
#	default_goal.mk:5: default goal is
#	default_goal.mk:12: default goal is foo
#	default_goal.mk:21: default goal is bar
#	foo
