# Lego City Undercover Decompilation
**This repository does not contain game assets and cannot be used to play the game.**

## Resources
This project requires a `main` dumped from the latest *Lego City Undercover - EU* update, v1.0.3
(The US version 1.0.2 likely also works for decompilation, but is untested and has a different file hash).
The Japanese version isn't currently supported, because it was compiled with a different/unknown compiler version.

# How to help
If you want to help with the decompilation, then you can do either the todos below, check for possible todo comments in
the code, decompile functions/classes, improve readability of functions or fix non-matching functions.

# Todo
- improve README.md
- update BUILDING.md and CONTRIBUTING.md
- add setup guide, explaination for ./tools 
- verify compiler version
- update BUILDING.md
- add GitHub actions for linting and building
- fix lint.py
- Create Discord server(?)
- create a structure for the project based on the symbols
- Code style guidelines
- add progress tracking to description using GitHub actions
- Build project using GitHub actions and verify against binary
- file structure for functions/classes and the whole decompilation

## Why Nintendo Switch Edition?
The Nintendo Switch Edition has symbols, making it a good base for decompilation. The Wii U Edition doesn't have symbols
and the compiler toolchain GHS is abysmal. The chance that we find a matching compiler version is next to none, so our
assembly wouldn't be matching either way.

The Nintendo Switch Edition on the other hand was compiled with Clang where it's easier to find the compiler version just by the release date of the game.

## Building
See [BUILDING.md](docs/BUILDING.md).

## Contributing
See [CONTRIBUTING.md](docs/CONTRIBUTING.md).

---
This repository is based on the MinecraftLCE decomp ([GRAnimated/MinecraftLCE](https://github.com/GRAnimated/MinecraftLCE)) and
Super Mario Odyssey decomp ([MonsterDruide1/OdysseyDecomp](https://github.com/MonsterDruide1/OdysseyDecomp)).
