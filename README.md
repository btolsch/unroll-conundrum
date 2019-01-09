# Unroll Optimization Example

## Overview

This is a simple example of unrolling a loop to eliminate a branch.  It is taken
from the [first optimization manual by Agner
Fog](https://www.agner.org/optimize).

The interesting thing about this example isn't actually about branch prediction,
though, but rather that the unrolling results in 1000x fewer instructions (when
compiled with `-O2`) than even clang optimizing the original loop.

Rough timings from my laptop are:
```
-O0, original: 1.2 s
-O0, unrolled: 1.0 s
-O2, original: 125 ms
-O2, unrolled: 250 us
```

When first poking around with `perf stat`, the unrolled version turned out to
only be faster because of the sheer instruction count reduction.  It turns out
that clang can eliminate the loop and directly compute a result from the inputs
with `-O2` in the unrolled version.  It seems to get very confused when
optimizing the original version with `-O2` though, and ends up with very
complicated code.  This supports the 1000x instruction count difference I
measured because there should be 2000 loop iterations each time one of the
functions is called, so eliminating that loop would produce that scaling.

## Building

`build.sh` will build a `test_O0` that runs both loops with `-O0` and a
`test_O2` that runs both loops with `-O2`.  These executables will print out the
time taken for many iterations of each loop type, as well as the integer result
(in case correctness due to optimizations is in question).  It will also output
the assembly of both loops for both `-O0` and `-O2`.
