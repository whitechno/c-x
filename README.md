C Programming Experiments
=========================

A workspace for C programming experiments and learning.

Code formatting
---------------

### `clang-format`

[ClangFormat](https://clang.llvm.org/docs/ClangFormat.html)

On macOS, you can install clang-format using Homebrew. However, VS Code's C/C++
Extension Pack comes with integrated clang-format.

[Clang-Format Style Options](
https://clang.llvm.org/docs/ClangFormatStyleOptions.html
)

[LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html)

The code between a comment `// clang-format off` or `/* clang-format off */` up
to a comment `// clang-format` on or `/* clang-format on */` will not be
formatted. The comments themselves will be formatted (aligned) normally. Also,
a colon (`:`) and additional text may follow `// clang-format off` or
`// clang-format on` to explain why clang-format is turned off or back on.

I really like this section: [Use Early Exits and `continue` to Simplify Code](
https://llvm.org/docs/CodingStandards.html#use-early-exits-and-continue-to-simplify-code
)

### `indent`

Using linux `indent` command:

```text
format:
 indent -linux $(PATHS)*.c $(PATHS)*.h $(PATHT)*.c
 $(CLEANUP) $(PATHS)*~ $(PATHS)*~ $(PATHT)*~
```

VS Code setup
-------------

### C/C++

C/C++ Extension Pack from Microsoft:

- C/C++ IntelliSense
- C/C++ Themes
- CMake Tools

In "Manage->Settings" (`⌘,`) search for "C_Cpp" (162 Settings Found).

See [Editing and Navigating C++ Code](
https://code.visualstudio.com/docs/cpp/cpp-ide
) and [Customizing default settings](
https://code.visualstudio.com/docs/cpp/customize-default-settings-cpp
).

You can format an entire file with Format Document (⇧⌥F) or just the current
selection with Format Selection (⌘K ⌘F) in right-click context menu.

See [Formatting](
https://code.visualstudio.com/docs/editing/codebasics#_formatting
).

The Visual Studio style is similar to:

```yaml
BasedOnStyle: LLVM, 
UseTab: Never, 
IndentWidth: 4, 
TabWidth: 4, 
BreakBeforeBraces: Allman, 
AllowShortIfStatementsOnASingleLine: false, 
IndentCaseLabels: false, 
ColumnLimit: 0, 
AccessModifierOffset: -4, 
NamespaceIndentation: All, 
FixNamespaceComments: false 
```

### Markdown lint

<!-- #region -->

[markdownlint by David Anson](
https://marketplace.visualstudio.com/items/?itemName=DavidAnson.vscode-markdownlint
): Markdown linting and style checking for Visual Studio Code.

[Configure](https://github.com/DavidAnson/vscode-markdownlint#configure)

[MD003 - Heading style](
https://github.com/DavidAnson/markdownlint/blob/v0.37.4/doc/md003.md
)

[MD013/line-length : Line length :](
https://github.com/DavidAnson/markdownlint/blob/v0.37.4/doc/md013.md
)

Add in `~/Library/Application Support/Code/User/settings.json`:

```json
    "markdownlint.config": {
        "MD003": { // Heading style
            "style": "setext_with_atx"
        },
        "MD013": { // Line length
            "code_blocks": false,
            "tables": false
        }
    },
```

<!-- #endregion -->

VS Code March 2025 new features
-------------------------------

[VS Code March 2025 (version 1.99)](https://code.visualstudio.com/updates/v1_99)

### Agent Mode

- Agent mode is available in VS Code Stable. Enable it by setting `chat.agent.enabled`
- Extend agent mode with Model Context Protocol (MCP) server tools
- Try the new built-in tools in agent mode for fetching web content, finding
  symbol references, and deep thinking

### Code Editing

- Next Edit Suggestions is now generally available
- Benefit from fewer distractions such as diagnostics events while AI edits are
  applied in the editor

### Chat Features

- Use your own API keys to access more language models in chat (preview)
- Easily switch between ask, edit, and agent mode from the unified chat experience
- Experience improved workspace search speed and accuracy with instant remote
  workspace indexing

### Notebook Editing

- Create and edit notebooks as easily as code files with support for edit and
  agent mode
