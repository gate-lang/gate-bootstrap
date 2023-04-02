# Hello World!

First things first, let's do the simplest code every programmer does when learning a new language, the famous `"Hello World!"`.

## Printing stuff

Gate's standard output function is `std::Print` or its variants, like `std::PrintLn`.

We start by importing our standard library:

```gate
use std
```

then instantiate our entry point (generally called as the main function):

```gate
i32 Entry ()
  |> progn
    | std::Print "Hello, World!"
    |> std::sys::ExitCode:OK
```

And that's all. Don't worry right now if you didn't understand most of it, we'll explain everything you see on the code throughout this tutorial.
I want you to just pay attention to the third line, where we can read:

```gate
std::Print "Hello, World!"
```

You can find the complete code right here: https://github.com/gate-lang/gate-bootstrap/blob/main/docs/examples/hello_world/entry.gate