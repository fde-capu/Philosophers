# Philosophers
### @ 42 Sao Paulo

- A number of philosophers is sitting at a round table doing one of three things:
eating, thinking or sleeping.

- While eating, they are not thinking or sleeping, while sleeping, they are not eating
or thinking and of course, while thinking, they are not eating or sleeping.

- The philosophers sit at a circular table with a large bowl of spaghetti in the center.

- There are some forks on the table.

- As spaghetti is difficult to serve and eat with a single fork, it is assumed that a
philosopher must eat with two forks, one for each hand.

- The philosophers must never be starving.

- Every philosopher needs to eat.

- Philosophers don't speak with each other.

- Philosophers don't know when another philosopher is about to die.

- Each time a philosopher has finished eating, he will drop his forks and start sleeping.

- When a philosopher is done sleeping, he will start thinking.

- The simulation stops when a philosopher dies.

---

#### Scenarios:

There are three scenarios:

`philo_one`: all philosophers are threads and forks are protected by mutual exclusion. Forks are positioned between every philosopher.

`philo_two`: all philosophers are threads and forks are positioned at the center of the table, and must be represented by a semaphore.

`philo_three`: all philosophers are processes and forks are at center of the table, represented by a semaphore.

---

#### Usage:

Each program should have the same options:

```number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]```

- `number_of_philosophers`: is the number of philosophers and also the number
of forks

- `time_to_die`: is in milliseconds, if a philosopher doesn't start eating `time_to_die`
milliseconds after starting his last meal or the beginning of the simulation, it
dies

- `time_to_eat`: is in milliseconds and is the time it takes for a philosopher to
eat. During that time he will need to keep the two forks.

- `time_to_sleep`: is in milliseconds and is the time the philosopher will spend
sleeping.

- `number_of_times_each_philosopher_must_eat`: argument is optional, if all
philosophers eat at least `number_of_times_each_philosopher_must_eat` the
simulation will stop. If not specified, the simulation will stop only at the death
of a philosopher.

---

#### Defense:

Note:
At left of philosopher *N* sits philosopher *N + 1*. At right is philosopher *N - 1*.
For `philo_one`, *N + 1*'s right fork is *N*'s left fork; *N*'s right fork is *N - 1*'s
left, in clockwise order:
_(...) PN+1 N+1RF=NLF PN NRF=N-1LF PN-1 (...)_

## `philo_one`

- `main.c`: one thread per philosopher.
- `forks.c`: mutex locks.
- ``strategy.c` and `forks.c`. Every time something changes, it quickly enter the
  logging line.
- I have set `time_to_die == 0` as invalid argument.
  `g_a_m_e_o_v_e_r` is a global that whenever set to `1`, the thread
  `free`s itself and exit gracefully. This variable will never
  be reset to zero. Therefore, there is no reason for mutexing it.
  Using `philo_one 2 300 100 200` will show that when a philosopher
  eats and dies at the same time, it will instead only die.
- `philo_one 5 800 200 200` ok with leaks (see notes below).
- `philo_one 5 800 200 200 7` ok.
- `philo_one 4 410 200 200` ok with leaks.
- `philo_one 4 310 200 100`
  To prevent exceptions, all `philo_one` odd id philosophers start thinking and
  even ones start in deep sleeping state.

## `philo_two`

- `main.c`: one thread per philosopher.
- `strategy.c` and `forks.c`: semaphores.
- `grep -rnC 5 g_lock_print`. No scrambled view.

## `philo_three`

- `main.c`: one fork for each id; note `exit ()` for `if (fork() == 0)`: main process waits for any termination.
- `strategy.c` and `forks.c`: semaphores.
- `grep -rnC 5 g_lock_print`. No scrambled view.

---

#### Notes:

- Whenever no one dies and the program is `Ctrl+C` `SIGINT`
interrupted, there should be leaks from the abruption.

- Since `kill` is used on `philo_three`, to properly `free` the
allocated memory, `sigaction` was implemented to avoid leaks
(`<signal.h>` was already included).

- Using Valgrind will interfere with timing speed, so false fails my happen.

- Time is registered in machine time. This means that one
milisecond is however long the CPU thinks it is.

- Many approaches were experimented, none of which solved the CPU clock
  assinchrony betweet threads when running under virtual enrironment:
  measuring time precisely, avoiding excessive `write` syscalls (or none
  at all), reducing the use of `gettimeofday`, and using independent
  clock tickers even if slower than real time.
  My research shows that `gettimeofday()` is obsolescent, though `clock_gettime(2)` is not allowed.

- Starving death may also occur while the philosopher
  is eating (seen this happen occasionally with `philo_one 4 100 300 200`):
  strict interpretation of `time_to_die`. I find this odd, starving 
  should start counting only when someone finishes the meal.

- These situations are not predicted by the `subject.pdf` file, but at evaluation time we find they can not happen:

  - On `philo_one`, if all get the left fork simultaneously, no one eats and everybody dies.
  - On `philo_one`, if one gets two forks and eveyone else the left fork (and one gets no forks), in turns, someone may die.
  	- Solution: for the first round, odd philosophers get the privilege to have both forks upahead even ids.

  - On `philo_two` and `philo_three`, if all get a fork each, no one eats and all die.
    This also happens when only one philosopher get two forks.
    - Solution: philosophers are only alowed to take two forks simultaneously.

- As for covid-19 pandemic, there have been notice of authorization that Philosophers can be tested on Guacamole.
  See: [https://www.notion.so/philosophers-VM-c60be9c836084edfbcd9c07e29b429c4]

---

Copyright (c) fde-capu

This is a study and should not be copied without understanding of the code. There is no practical use for this software. None permission for doing anything is authorized.
