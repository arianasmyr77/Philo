# 🧠 Philosophers

**Philosophers** is a classic **concurrency** project from the 42 curriculum. It’s based on the **Dining Philosophers Problem**, a well-known example in computer science to illustrate problems of **deadlocks**, **race conditions**, and **resource sharing** in multithreaded environments.

The goal is to implement a simulation where philosophers sit at a table, eat, think, and sleep — without starving or causing a deadlock.

---

## 📁
> This project uses **pthreads** (POSIX threads) for concurrency.

---

## 🛠️ Compilation

🚀 How to Run

make

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] 

---

| Argument                                    | Description                                                                  |
| ------------------------------------------- | ---------------------------------------------------------------------------- |
| `number_of_philosophers`                    | Total number of philosophers and forks                                       |
| `time_to_die`                               | Time before a philosopher dies if they don’t eat                             |
| `time_to_eat`                               | Time a philosopher spends eating                                             |
| `time_to_sleep`                             | Time a philosopher spends sleeping                                           |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* Stop simulation once each philosopher has eaten this many times |

---
💡 Example->

make

./philo 5 800 200 200

5 philosophers
Each dies if they don’t eat within 800ms
Takes 200ms to eat
Sleeps for 200ms
This will run indefinitely unless one philosopher dies.

---
With Optional Argument->

./philo 5 800 200 200 7

This will stop the simulation when all philosophers have eaten at least 7 times.

---
🔄 How It Works


Each philosopher is a thread.

Each fork is a mutex (mutual exclusion).

A philosopher needs two forks (left and right) to eat.

After eating, they sleep, then think, and repeat.

A separate monitor checks if any philosopher has died.

Key Concepts:
Mutexes prevent multiple threads from accessing forks simultaneously.
Thread synchronization is crucial to avoid deadlocks or starvation.
Accurate timekeeping using gettimeofday or clock_gettime
