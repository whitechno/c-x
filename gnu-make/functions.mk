# make -f functions.mk

start: ; @echo $@

#
# Two Flavors of Variables
#

# 1. Recursive Variables
# Recursive variables are defined with the `=` operator
# Recursive variables are evaluated when they are used
Recursive_Variable = $(X)
# Note: X is not defined yet
# 2. Simple Variables
# Simple variables are defined with the `:=` or `::=` operators
# Simple variables are evaluated when they are defined
Simple_Variable := $(X)
# Note: X is not defined yet
X=42
# Note: X is now defined
# Recursive_Variable is '42':
$(info Recursive_Variable is '$(Recursive_Variable)') # '42'
# Simple_Variable is '':
$(info Simple_Variable is '$(Simple_Variable)') # ''
two_flavors:
	@echo $@:
	@echo "X is '$(X)'" # '43'
	@echo "Recursive_Variable is '$(Recursive_Variable)'" # '43'
	@echo "Simple_Variable is '$(Simple_Variable)'" # ''
X=43
# Note: X is changed and Recursive_Variable is re-evaluated 
# when we call `two_flavors` target:
# $ make -f functions.mk two_flavors
# Simple_Variable is not re-evaluated.

# you can include leading spaces in a variable value
# by protecting them with variable references:
nullstring :=
space := $(nullstring) # end of the line
tab := $(nullstring)	# end of the line
with_leading_space := $(space)ABC
$(info with_leading_space is '$(with_leading_space)') # ' ABC'

#
# shell function
#

which_cc := $(shell which $(CC) 2>/dev/null)
$(info which_cc is '$(which_cc)') # which_cc is '/usr/bin/cc'
which_xx := $(shell which $(XX) 2>&1)
$(info which_xx is '$(which_xx)') # which_xx is 'usage: which [-as] program ...'

# != is similar to `shell` and is supposed 
# to be supported in GNU Make 4.0 and later
# but it is not supported in GNU Make 3.81
# (check your version with `make -v`)
which_cc_2 != which $(CC)
$(info which_cc_2 is '$(which_cc_2)') # which_cc_2 is ''

end: ; @echo $@
