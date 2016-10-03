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
A rare moment which the intellectual power really saved the day, rather different from this [one](http://xkcd.com/208/)!

If you want to know more about the internal details of Enigma [here is a good source](http://www.codesandciphers.org.uk/enigma).

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

Well, basically the dsl exists in order to make the operations over the ``Eel's Enigma context`` easier. In fact, if you
want to be a user of ``libeel`` there are few statements from this embedded dsl to worry about. However, here I will describe
each one, because maybe someone can want to extend the possibilities here... Giving more support to another ``Enigma`` types
besides the ``M3``, for example.

If you take a look inside the ``src/types.h`` you will find something like:

```c
typedef struct _libeel_enigma_ctx {
    libeel_rotor_t left_rotor, middle_rotor, right_rotor;
    libeel_reflector_t reflector;
    libeel_rotor_wiring_t keyboard;
    libeel_plugboard_ctx plugboard;
    libeel_rotor_wiring_t gears_lr, gears_mr, gears_rr;
    libeel_rotor_wiring_t gears_lr_1, gears_mr_1, gears_rr_1;
    libeel_notch_t gears_mn, gears_rn;
    libeel_rotor_display_t gears_ld, gears_md, gears_rd;
    libeel_rotor_wiring_t gears_rf;
    libeel_rotor_wiring_t gears_l_off, gears_m_off, gears_r_off;
    libeel_rotor_display_t gears_l_at, gears_m_at, gears_r_at;
    libeel_ring_t gears_l_ring, gears_m_ring, gears_r_ring;
    libeel_rotor_display_t l_in, l_out;
}libeel_enigma_ctx;
```

Of course that you can operate the context shown above without any ``plushy macro`` but frankly you can lose your sanity
doing the things on this way. Bear in mind that the context have built on this way for accessing abstraction. Then if you
are hooked on ``Enigma`` ciphering the embedded dsl is a piece of pretty obvious thing...

All dsl statements must be done over a well-allocated context. You can acquire it by using:

```c
    (...)
    libeel_enigma_ctx *M3 = libeel_new_enigma_ctx();
    (...)
```

If all ok the ``libeel_new_enigma_ctx()`` function will spit to you a valid memory place (non-NULL) where you can make your
mess.

Facts about your just allocated machine:

- Any reflector is picked as default.
- Any rotor is picked as default.
- All rotor rings are set to ``1`` (e.g.: ``A-A-A``).

Okay kids, if we allocated something is important to release it. Even if your software does not stay running by hours.
Programming good manners! So, for dealloc the enigma's context we should:

```c
    (...)
    libeel_del_enigma_ctx(M3);
```

### The libeel_enigma_ctx's fields which are non-sanity hazard

There are four fields which you can access directly with ``plain C``. Take a look in **Table 1** in order to know more
about it.

**Table 1**: Non-sanity hazard fields.

| **Non-sanity hazard struct field** |      **It represents**       |
|:----------------------------------:|:----------------------------:|
|            ``left_rotor``          |         Guess what?          |
|            ``middle_rotor``        |         Guess what?          |
|            ``right_rotor``         |         Guess what?          |
|             ``reflector``          |         Guess what?          |


**Beware**: All other fields accessing is by your own risk. I also think that you think that ``protected`` are for sissies. So...

The rotors can be set with: ``i``, ``ii``, ``iii``, ``iv``, ``v``, ``vi``, ``vii``, ``viii``. I really find roman numerals a
monument in the name of Human stupidity but commonly the ``Enigma's rotors`` are expressed on this way. So it is what we get!

The reflectors can assume two values (all here at least until now is about U-boats, remember?): ``b`` and ``c``.

After allocating the memory slice for placing your ``Enigma`` you should initialise it by setting the rotors, the reflector,
rotor positions, rotor rings, etc. Once all done you should confirm your new setting by calling ``libeel_init_machine``:

```c
    (...)
    if (libeel_init_machine(M3)) {
        printf("Initialised!\n");
    } else {
        printf("Error!\n");
    }
    (...)
```

### Accessing the machine components by its position

If you know something about the ``Enigma`` maybe you should know that the current position of some component is meaningful.
These components can assume three positions which are: ``left``, ``middle``, ``right``. In the ``Eel's embedded dsl``
these positions are: ``l``eft, ``m``iddle, ``r``ight.

#### How to access the rotor rings?

```c
    (...)
    libeel_ring(M3, l) = 2;
    libeel_ring(M3, m) = 6;
    libeel_ring(M3, r) = 20;
```

I have decided not use letters for expressing the rings positions, so you can use values between ``1`` and ``26``.

#### How to swap a plugboard linkage?

```c
    (...)
    //  A/Z
    libeel_plugboard(M3, 1).l = 'A';
    libeel_plugboard(M3, 1).r = 'Z';
```

As you should know, according to the ``U-boat`` specs there are six swaps pairs.

#### How to change a rotor position?

```c
    (...)
    libeel_rotor(M3, l) = 'E';
    libeel_rotor(M3, m) = 'E';
    libeel_rotor(M3, r) = 'L';
```

#### How to set the input signal?

```c
    (...)
    libeel_enigma_input(M3) = 'T';
```

#### How to get the last processed output signal?

```c
    (...)
    printf("%c", libeel_enigma_output(M3));
```

#### How to effectively type thing on the machine?

One the input signal defined:

```c
    (...)
    libeel_type(M3);
```

Now all you should do is to read the output signal (e.g.: the lamp On). However, the ``libeel_type()`` also
returns its result besides "turn-on" the output lamp.

### Another dsl statements which final users should not worry about

The **Table 2** gathers these statements. They were exposed in order to allow future extensions by everyone interested.
For this reason I will avoid detailing why and for what it should be used.

**Table 2**: The ``Eel's Enigma geek embedded dsl statements``.

|      **Statement**           |                **Used for**                      |          **Usage sample**             |
|:----------------------------:|:------------------------------------------------:|:-------------------------------------:|
| ``libeel_rotor(e, p)``       |        Accessing the internal rotor wiring       |       ``libeel_rotor(M3, l)``         |
| ``libeel_rotor_inv(e, p)``   |       Accessing the inverse rotor wiring's path  |       ``libeel_rotor_inv(M3, m)``     |
| ``libeel_notch(e, p)``       |       Accessing the rotor notch                  |       ``libeel_notch(M3, r)``         |
| ``libeel_display(e, p)``     |       Accessing the rotor display (labeling)     |       ``libeel_display(M3, l)``       |
| ``libeel_keyboard(e)``       |       Accessing the machine keyboard             |       ``libeel_keyboard(M3)``         |
| ``libeel_reflector(e)``      |       Accessing the reflector wiring             |       ``libeel_reflector(M3)``        |
| ``libeel_rotor_offset(e,p)`` |          Accessing the rotor offset              |       ``libeel_rotor_offset(M3, l)``  |

