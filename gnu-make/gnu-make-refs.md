GNU Make references
===================

<https://www.gnu.org/software/make/>

<https://www.gnu.org/software/make/manual/>

[Automatic-Variables](
https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html#Automatic-Variables
)
For example, consider the following declaration:
`all: library.cpp main.cpp`
In this case:

- `$@` evaluates to `all`
- `$<` evaluates to `library.cpp`
- `$^` evaluates to `library.cpp main.cpp`

[Implicit-Rules](
https://www.gnu.org/software/make/manual/html_node/Implicit-Rules.html
)

Two Flavors of Variables
------------------------

[The Two Flavors of Variables](
https://www.gnu.org/software/make/manual/html_node/Flavors.html
)

Recursively expanded variable are defined by lines using ‘=’. If it contains
references to other variables, these references are expanded whenever this
variable is substituted (in the course of expanding some other string).
In other words, it is expanded later - when it is used, not when it is defined.

A major disadvantage of Recursive Variables is that you
cannot append something on the end of a variable, as in
`Recursive_Variable = $(Recursive_Variable) Append`
because it will cause an infinite loop in the variable expansion.
Actually make detects the infinite loop and reports an error:

```text
functions.mk:38: 
*** Recursive variable `Recursive_Variable' references itself (eventually).  Stop.
```

Another disadvantage of Recursive Variables is that any functions
referenced in the definition will be executed every time
the variable is expanded.
This makes make run slower; worse, it causes the wildcard and
shell functions to give unpredictable results because you cannot
easily control when they are called, or even how many times.

Simply expanded variables are defined by lines using ‘:=’ or ‘::=’. The value
of a simply expanded variable is scanned once, expanding any references to
other variables and functions, when the variable is defined. Once that
expansion is complete the value of the variable is never expanded again: when
the variable is used the value is copied verbatim as the expansion. If the
value contained variable references the result of the expansion will contain
their values as of the time this variable was defined.

Simply expanded variables generally make complicated makefile programming more
predictable because they work like variables in most programming languages.
They allow you to redefine a variable using its own value (or its value processed
in some way by one of the expansion functions) and to use the expansion functions
much more efficiently.

### Conditional Variable Assignment ‘?='

This statement:
`FOO ?= bar`
is exactly equivalent to this:

```makefile
ifeq ($(origin FOO), undefined)
  FOO = bar
endif
```

Note that a variable set to an empty value is still defined, so ‘?=’ will not
set that variable.

Footnote: CMake
---------------

To get started learning CMake check out:

<https://cliutils.gitlab.io/modern-cmake/>

<https://cmake.org/cmake/help/latest/guide/tutorial/index.html>

The book: <https://crascit.com/professional-cmake>

reddit:
<https://www.reddit.com/r/cpp_questions/comments/12kowb4/what_does_something_like_cmake_do_and_what_is_its/>
