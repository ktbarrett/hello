#include <pybind11/pybind11.h>
#include "hello/hello.hpp"

namespace py = pybind11;


PYBIND11_MODULE(_hello, m)
{
    m.doc() = "Example module";

    m.def("hello", &hello::hello, "Says hello", py::arg("your_name") = "World");
    m.def("return_answer_to_life", &hello::return_answer_to_life, "Come back in 7.5 million years to learn the answer to everything");
}
