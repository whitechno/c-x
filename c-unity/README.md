C unit testing with Unity
=========================

Examples of unit tests in C using [Unity](
https://github.com/ThrowTheSwitch/Unity
) framework from ThrowTheSwitch.org

Unity Test is a unit testing framework specifically designed for C, with a focus
on working with embedded toolchains. It was developed to test code targeting
micro controllers of all sizes. The core project consists of a single C file and
a pair of headers, making it easy to integrate into your existing build setup.

Read their article [Building with Make](
https://www.throwtheswitch.org/build/make).

Project structure
-----------------

There are three important directories:

* `src` - source code
* `test` - test cases
* `Unity` - Unity test framework source

The `Unity` directory is added as a `git` submodule.

Using Git Submodules
--------------------

Using [Git Submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) for
the Unity framework source.

```text
$ git submodule add git@github.com:ThrowTheSwitch/Unity.git
Cloning into 'c-x/c-unity/Unity'...
remote: Enumerating objects: 7120, done.
remote: Counting objects: 100% (467/467), done.
remote: Compressing objects: 100% (153/153), done.
remote: Total 7120 (delta 354), reused 314 (delta 314), pack-reused 6653 (from 3)
Receiving objects: 100% (7120/7120), 7.03 MiB | 2.68 MiB/s, done.
Resolving deltas: 100% (4388/4388), done.
```

New `Unity` subproject directory and new `.gitmodules` file:

```text
[submodule "c-unity/Unity"]
    path = c-unity/Unity
    url = git@github.com:ThrowTheSwitch/Unity.git
```

```text
$ git commit -am "Added 'Unity' module."
[main ce8f6d0] Added 'Unity' module.
 4 files changed, 35 insertions(+), 1 deletion(-)
 create mode 100644 .gitmodules
 create mode 100644 c-unity/README.md
 create mode 160000 c-unity/Unity
```

When you clone a project with a submodule in it, by default you get the
directories that contain submodules, but none of the files within them yet.

```text
git clone git@github.com:whitechno/c-x.git
```

The `c-unity/Unity` directory is there, but empty. You must run two commands
from the main project: `git submodule init` to initialize your local
configuration file, and `git submodule update` to fetch all the data from that
project and check out the appropriate commit listed in your superproject.

```text
$ git submodule init && git submodule update --recursive
or
$ git submodule update --init --recursive
```

To update for changes in the upstream branch:

```text
git submodule update --remote
```

Unity Test Structure
--------------------

All tests should be placed under the `test` directory, and the default Unity
naming convention for test files is `Test*.c`. For example, to test our `add.c`
file, we need to create a file named `/test/Testadd.c`.

How to run
----------

To run tests:

```shell
make test
```

To run main:

```shell
make main
```

To generate dependency rules:

```shell
make deps
```

To clean:

```shell
make clean
```

To read environment vars in Makefile:

```shell
make read_env
```

Footnote
--------

See [Introduction to C Unit Testing with the Unity Framework](
https://medium.com/@kasra_mp/introduction-to-c-unit-testing-with-the-unity-framework-15903823ce8a
) and [c-unit-testing](
https://github.com/kasramp/c-unit-testing
) by Kasra Madadipouya.
