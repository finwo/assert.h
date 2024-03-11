assert.h
========

Single-file unit-testing library for C

Features
--------

- Single header file, no other library dependencies
- Simple ANSI C. The library should work with virtually every C(++) compiler on
  virtually any playform
- Reporting of assertion failures, including the expression and location of the
  failure
- Stops test on first failed assertion
- ANSI color output for maximum visibility
- Easily embeddable in applications for runtime tests or separate testing
  applications

Todo
----

- Disable assertions on definition, to allow production build without source modifications

Example Usage
-------------

```C
#include "finwo/assert.h"
#include "mylib.h"

void test_sheep() {
  ASSERT("Sheep are cool", are_sheep_cool());
  ASSERT_EQUALS(4, sheep.legs);
}

void test_cheese() {
  ASSERT("Cheese is tangy", cheese.tanginess > 0);
  ASSERT_STRING_EQUALS("Wensleydale", cheese.name);
}

int main() {
  RUN(test_sheep);
  RUN(test_cheese);
  return TEST_REPORT();
}
```

To run the tests, compile the tests as a binary and run it.

API
---


### Macros

<details>
  <summary>ASSERT(msg, expression)</summary>

  Perform an assertion

```C
#define ASSERT(msg, expression) if (!tap_assert(__FILE__, __LINE__, (msg), (#expression), (expression) ? 1 : 0)) return
```

</details>
<details>
  <summary>ASSERT_EQUALS(expected, actual)</summary>

  Perform an equal assertion

```C
/* Convenient assertion methods */
/* TODO: Generate readable error messages for assert_equals or assert_str_equals */
#define ASSERT_EQUALS(expected, actual) ASSERT((#actual), (expected) == (actual))
```

</details>
<details>
  <summary>ASSERT_STRING_EQUALS(expected, actual)</summary>

  Perform an equal string assertion

```C
#define ASSERT_STRING_EQUALS(expected, actual) ASSERT((#actual), strcmp((expected),(actual)) == 0)
```

</details>
<details>
  <summary>RUN(fn)</summary>

  Run a test suite/function containing assertions

```C
#define RUN(test_function) tap_execute((#test_function), (test_function))
```

</details>
<details>
  <summary>TEST_REPORT()</summary>

  Report on the tests that have been run

```C
#define TEST_REPORT() tap_report()
```

</details>

Extras
------

### Disable color

If you want to disable color during the assertions, because you want to
interpret the output for example (it is "tap" format after all), you can
define `NO_COLOR` during compilation to disable color output.

```sh
cc -D NO_COLOR source.c -o test
```

### Silent assertions

You can also fully disable output for assertions by defining the
`ASSERT_SILENT` macro. This will fully disable the printf performed after
the assertion is performed.

```sh
cc -D ASSERT_SILENT source.c -o test
```

### Silent reporting

If you do not want the report to be displayed at the end, you can define the
`REPORT_SILENT` macro. This will disable the printf during reporting and
only keep the return code.

```sh
cc -D REPORT_SILENT source.c -o test
```


Credits
-------

This library was heavily based on the [tinytest][tinytest] library by
[Joe Walnes][joewalnes]. A license reference to his library could not be
found, which is why this reference is in this file. Should I be contacted
about licensing issues, I'll investigate further.

[joewalnes]: https://github.com/joewalnes
[tinytest]: https://github.com/joewalnes/tinytest
