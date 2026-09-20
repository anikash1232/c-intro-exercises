# Intro C Exercises

Three small command-line programs in C, working up from a first compile to character-level
stream processing.

## The programs

**`0-hello-world/hello.c`** — the minimal C program, verifying the toolchain compiles and
links.

**`1-bash-comments/strip-comments.c`** — reads a shell script and strips comments, printing
the remaining code. Needs to distinguish a real `#` comment from a `#` inside a string
literal, so it tracks whether it's currently inside quotes rather than blindly cutting at
the first `#`.

**`2-char-count/char-count.c`** — counts characters, words and lines in its input, in the
spirit of `wc`. Word counting is the tricky part: it's a state machine over the stream,
transitioning between in-word and in-whitespace, since "a word" is a transition rather than
a character you can count directly.

## Usage

```bash
./hello
./strip-comments < script.sh
./char-count < file.txt
```

## Building

```bash
gcc -Wall -Wextra -o hello 0-hello-world/hello.c
gcc -Wall -Wextra -o strip-comments 1-bash-comments/strip-comments.c
gcc -Wall -Wextra -o char-count 2-char-count/char-count.c
```

All three read from standard input a character at a time with `getchar`, using no buffering
beyond what the standard library provides.
