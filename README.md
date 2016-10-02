# Eel

``Eel`` is a acronym which means ``E``nigma's ``e``ngine ``l``ibrary.

It is about a *C* library that intends to help on abstracting ``Enigma machines`` implementations.

``Eel`` emulates the ``U-boat Enigma`` behavior, the enigma which was cracked by ``Alan Turing`` during the ``WWII``.

Of course that you should use it only for fun issues. In fact the ``Enigma`` machine nowadays is a
pencil-and-paper cipher. You should never protect sensible data with  the ``Enigma`` cipher.
Do not be naive.

Alternatively, ``Enigma`` has a strong historical value. Then here you can probe the library's source code
for looking inside the ``U-boat Enigma's`` entrails. For figuring out the problem imposed by this cipher
engine in the past and also for understanding how ``Rejewski & Turing Bombs`` worked in order to crack this
cipher. According to the historians the breakage of ``Enigma`` shortened the war and saved millions of lives.
A rare moment which the intellectual power saved the day, rather different from this
<a href="http://xkcd.com/208/" target="_blank">one</a>!

## How to build eel?

In order to build this library you need [Hefesto](https://github.com/rafael-santiago/hefesto). Once ``Hefesto``
installed and working on your system you should jump to the ``eel's src`` sub-directory and invoke ``Hefesto`` from
there. Something like:

```
agnes@Bleatchley:~/StationX/Hans-Thilo/Asché/leaks/eel/src# hefesto
```

After running ``Hefesto`` the library will be built and some tests will run. A sub-directory called ``lib`` will be created
too. Inside this sub-directory you should find the file ``libeel.a``. You will use it to link your future ``Enigma`` simulators.

## How does eel work?

I am assuming that you know (at least) the general idea of how ``Enigma`` machines work... okay?

As previously said ``Eel`` is a library which implements the ``M3`` (``Naval/U-boat``) ``Enigma``. However, it implements
a very simple embedded ``dsl`` in order to abstract the machine's setting and also its operation.

These are the basic steps to use ``Eel`` inside your code stuff:

- You need to get a enigma machine in the form of a (libeel_enigma_ctx *);
- You need to setting it up;
- You need to pass your settings to the ``init`` function;
- You need to set the machine input;
- You need to pass the current machine state to the ``type`` function;
- You need to get the output from the current machine state;

Now, all it "C-expressed" would be:

```c
#include <eel.h>
#include <stdio.h>

int main(int argc, char **argv) {
    libeel_enigma_ctx *e = libeel_new_enigma_ctx();
    int exit_code = 0;
    //  Setting up the rotors.
    e->left_rotor = i;
    e->middle_rotor = iv;
    e->right_rotor = vii;
    // Setting up the initial position of each rotor.
    libeel_rotor_at(e, l) = 'E';
    libeel_rotor_at(e, m) = 'E';
    libeel_rotor_at(e, r) = 'L';
    // Setting up the reflector.
    e->reflector = c;
    if (!libeel_init_machine(e)) {
        printf("Error during machine initialising...\n");
        exit_code = 1;
    } else {
        libeel_enigma_input(e) = 'E';
        libeel_type(e);
        printf("E->%c\n", libeel_enigma_output(e));
    }
    libeel_del_enigma_ctx(e);
    return exit_code;
}

```

## The Eel's embedded dsl

*to be continued... ;)*
