# Philosophers Project Readme

## Overview

Welcome to the Philosophers project! This project is part of the 42 school curriculum, designed to explore parallel computing and synchronization. In this project, you will implement the dining philosophers problem, a classic synchronization and concurrency problem in computer science.

## Project Objectives

The main objectives of the Philosophers project are as follows:

1. **Concurrency**: Implement a solution for the dining philosophers problem using threads or processes to represent philosophers.

2. **Synchronization**: Use synchronization mechanisms, such as mutexes or semaphores, to ensure that philosophers can only eat when both the left and right forks are available.

3. **Prevention of Deadlock and Starvation**: Implement a solution that prevents both deadlock (where no philosopher can finish) and starvation (where a philosopher may never get a chance to eat).

4. **Visualization (Optional)**: Optionally, implement a visualization of the philosophers and their states to aid in understanding the execution flow.

## Usage

To use the Philosophers program, follow the format below:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
number_of_philosophers: The number of philosophers at the dining table.
time_to_die: The time in milliseconds that a philosopher can survive without eating.
time_to_eat: The time in milliseconds that a philosopher takes to eat.
time_to_sleep: The time in milliseconds that a philosopher takes to sleep.
[number_of_times_each_philosopher_must_eat]: (Optional) The number of times each philosopher must eat before the program exits. If not provided, the program should run indefinitely.
Example:

```bash
./philo 5 800 200 200
```
This will simulate a dining table with 5 philosophers, a time to die of 800 milliseconds, a time to eat of 200 milliseconds, and a time to sleep of 200 milliseconds.

Building and Running
To build the Philosophers program, use the provided Makefile:

```bash
make
```
This will generate the philo executable.

To run the program, use the following command format:

```bash
./philo [arguments]
```

## Resources

[Vizualizer](https://nafuka11.github.io/philosophers-visualizer/)
<br>[Videos explaining multithreading](https://www.youtube.com/results?search_query=codevault)
