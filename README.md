# Dumb Template Library

`dtl` is a learning project aiming to offer a working standard library for C++.

Its aims are:

- to be unique, `dtl` is not a re-implementation of libc++ or libstdc++, rather a re-imagination.
- to be modern, `dtl` uses the newest compiler versions as they're released and tries to
use the newest features where feasible
- to be idiomatic, `dtl`'s code should be clean, readable & safe
- to be comprehensive, `dtl` doesn't only provide a few useful templates,
but tries to cover everything from meta programming to cryptography & networking
- to do as much as possible itself, `dtl` tries to minimize the amount & size of its dependencies
- to be compiler agnostic, `dtl` should compile on any conforming up-to-date C++ compiler

Its aims are **NOT**:

- to be used in production, the purpose of this project is to learn
- to be the fastest, while the code itself aims to be performant,
this isn't a google library where 10 $150/h engineers micro-optimize every
little detail.
- to be cross-platform, this library relies on a lot of platform-specific APIs,
and my platform of choice is linux. `dtl`'s interface itself, however, is relatively platform
agnostic, so if someone would like to, they should be able to implement most of it on e.g. Windows
- to have good build times

## Dependencies

`dtl` uses glibc, and may use some standard C++ library features (mostly to access features that require compiler support).
All other dependencies are managed by conan.

## Philosophy

`dtl` is heavily inspired by the C++ Standard library, the Rust standard library, and functional programming patterns.
<!--TODO: expand>
