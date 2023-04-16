<div align="center">
  <img alt="GitHub Contributors" src="https://img.shields.io/github/contributors/Gate-lang/Gate-bootstrap?style=for-the-badge">
  <img alt="GitHub Forks" src="https://img.shields.io/github/forks/Gate-lang/Gate-bootstrap?style=for-the-badge">
  <img alt="GitHub Stars" src="https://img.shields.io/github/stars/Gate-lang/Gate-bootstrap?style=for-the-badge">
  <img alt="GitHub Issues" src="https://img.shields.io/github/issues/Gate-lang/Gate-bootstrap?style=for-the-badge">
  <img alt="GitHub License" src="https://img.shields.io/github/license/Gate-lang/Gate-bootstrap?style=for-the-badge">
</div>

# GATE

A functional programming language that combines the concise syntax of C with explicit memory management. Its functional paradigm emphasizes functions as building blocks, offering improved code readability and the ability to use powerful concepts like recursion and higher-order functions. GATE is a versatile tool suitable for small scripts or large-scale applications.

<div align="center">
  <a href="https://github.com/Gate-lang/Gate-bootstrap/tree/main/docs"><strong>Explore the docs and learn GATE »</strong></a>
  <br/>
  <a href="https://github.com/Gate-lang/Gate-bootstrap/issues">Report Bug</a>
  ·
  <a href="https://github.com/Gate-lang/Gate-bootstrap/issues">Request Feature</a>
</div>

This is a to-be-legacy repository. As soon as Gate gets mature enough, we'll stop using C, and Gate will be written entirely in itself.

## Building

Gate uses CMake as its default package manager, so you just need it if you want to compile Gate by yourself.
But first, remember to clone Gate's submodules.

```sh
git submodule init
git submodule update
```

Now, you can build it.

```sh
mkdir bin
cd bin
cmake -S .. -B .
cmake --build .
```

## Testing

Since Gate uses CMake, everything's done already, but you'll need to compile Gate using a different flag.

```
cd bin
cmake -S .. -B . -DCMAKE_DEBUG=ON
ctest
```

## Running

After building, a binary named gate will be in the directory you told CMake to build at.

```
cd bin
./gate --help
```

Designed and written by [Josué Teodoro Moreira](https://j0suetm.com).
