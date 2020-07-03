[![Build Status](https://travis-ci.org/ktbarrett/hello.svg?branch=master)](https://travis-ci.org/ktbarrett/hello)
[![Documentation Status](https://readthedocs.org/projects/hello-pybind11-2/badge/?version=latest)](https://hello-pybind11-2.readthedocs.io/en/latest/?badge=latest)

# Hello

This project exists to act as an example project with a novel features set and structure.
Meanwhile it also uses mature tools for the elements of the project like packaging and documentation;
and tries to follow best practices where it can.
This project is fundamentally a simple C++ project with two "Hello, World!" type functions.
We also create a Python binding for this C++ libraries using pybind11.

This example project has it's commits broken up following a natural evolution to the project.
The commit messages contain detailed explanations and justifications for each step, which you can use to follow along and learn.

Or... feel free to copy, hack and slash!

## Build System

The C++ project will be built using [CMake](https://cmake.org/); a powerful and popular build system for C++ projects.
CMake might be called an expert's build system (much like C++ is an expert's language),
but the changes in 3.0 and the latest releases (3.17 at the time of this writing) have made large strides in usability.

To build the Python extension the project will use [pybind11](https://github.com/pybind/pybind11).
pybind11 is a modern C++ header-only library that generates Python bindings to C++ code.
It's very straightfoward and easy to use.

## Packaging

There are two end use points on the project, one C++ and the other Python; so we have two co-existing packaging solutions.

We use CMake to package the pure C++ code.
Once a CMake package is installed, a user can call a single function to import the project into their own.
This step can be done separately of the building and packaging of the Python wrapper.

The Python wrapper will be packaged with [setuptools](https://github.com/pypa/setuptools) with the help of [scikit-build](https://scikit-build.readthedocs.io/en/latest/).
Setuptools is the de-facto package manager of Python; however, our C++ library and pybind11 library are not pleasantly supported by distutils (the library setuptools uses to compile C code).
And we would like to reuse our CMake build scripts.
So, we use scikit-build to tie our cmake project into the setuptools packaging step.

The Python package will contain the built extension library, the compiled shared C++ library, the library's public headers, and the cmake package.
So it will contain everything needed to use the library in Python *or* C++.

## Distribution

CMake packages are typically distrubuted by the operating system package managers, however [conan](https://conan.io/) is becoming more popular.
Despite that, there is no distribution of the CMake project through conan at this time.

The sole means of distribution currently is via [pypi](https://pypi.org/).
This will distribute the Python package, which contains the CMake package as well; so it distributes for both at the same time.

## Testing

Testing will be done at both the C++ level and the Python level.
This is necessary because we need to test the implementation for correctness, as well as the correctness of the binding.
There may also be features in just the C++ (like templated classes) or just the Python (convenience wrappers) that need to be tested separately.

To test the Python wrapper, we will use [pytest](https://docs.pytest.org/en/stable/).
pytest is the most popular Python testing framework available right now; it allows tests to be described easily, alongside of the source if desired.

To accomplish testing in C++, we will use the [Catch2](https://github.com/catchorg/Catch2) framework. It's popular and easy to use.
The C++ tests will also act as an example project that consumes the Hello library.
This will also test the CMake packaging inside the Python package scheme we have designed.

## Documentation

Documentation is written in source in C++ and documentation is generated using [doxygen](https://www.doxygen.nl/index.html).
Doxygen has been around forever, and while it has it's limitations, it works well.
It will also play well with the solution to Python documentation so documentation for both the C++ and Python are co-located.

The Python will be documented in source and generated using [Sphinx](https://www.sphinx-doc.org/en/master/#).
Sphinx is packed with features and very popular for Python projects.
Sphinx also is one of the supported tools by our documentation distribution platforms: [ReadTheDocs](https://readthedocs.org/).

We can tie the C++ and Python documentation together with [breathe](https://breathe.readthedocs.io/en/stable/), which beings doxygen documentation into Sphinx.
Sphinx has better support for documentation layout and support for arbitrary non-code documentation, so it improves the C++ documentation as well.

## Other

[tox](https://tox.readthedocs.io/en/stable/) is used for project automation: testing in both Python and C++ and building documentation, and potentially other tasks as well.

## CI

[Travis CI](https://travis-ci.org/) is used for automated testing of both the C++ and Python tests in multiple isolated environment.
Travis is free for open source projects, integrates with Github very easily, and has many useful features/available environments.

[ReadTheDocs](https://readthedocs.org/) is used to automatically build documentation for the project.
ReadTheDocs is also free for open source projects and integrates with Github very easily.
