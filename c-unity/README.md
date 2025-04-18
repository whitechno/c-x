C unit testing with Unity
=========================

Examples of unit tests in C using [Unity](https://github.com/ThrowTheSwitch/Unity)
framework.

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
