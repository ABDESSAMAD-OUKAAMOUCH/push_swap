*This project has been created as part of the 42 curriculum by aoukaamo.*

# Push Swap

## Description

Push Swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations, with the goal of doing so in the minimum number of moves possible.

The project consists of two programs:
- **push_swap**: Takes a list of integers as arguments and outputs the optimal sequence of operations to sort them
- **checker**: Verifies whether a given sequence of operations correctly sorts the stack

The challenge lies in implementing an efficient algorithm that minimizes the number of operations while handling stacks of various sizes.

## Instructions

### Compilation

```bash
make
make bonus
```

This will compile both `push_swap` and `checker` programs.

### Execution

**Push Swap:**
```bash
./push_swap 3 2 5 1 4
```

**Checker:**
```bash
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

### Available Operations

- `sa`: Swap the first two elements at the top of stack A.
- `sb`: Swap the first two elements at the top of stack B.
- `ss`: Perform `sa` and `sb` at the same time.
- `pa`: Take the top element from stack B and put it on top of stack A.
- `pb`: Take the top element from stack A and put it on top of stack B.
- `ra`: Rotate stack A up by one (the first element becomes the last).
- `rb`: Rotate stack B up by one (the first element becomes the last).
- `rr`: Perform `ra` and `rb` at the same time.
- `rra`: Reverse rotate stack A (the last element becomes the first).
- `rrb`: Reverse rotate stack B (the last element becomes the first).
- `rrr`: Perform `rra` and `rrb` at the same time.


## Algorithm Strategy
The implementation uses the **chunk algorithm** approach:
- Divides the stack into chunks/segments
- Pushes elements to stack B in organized chunks
- Rotates and optimizes placement within each chunk
- Pushes back to stack A in sorted order

## Resources

### Documentation & Tutorials
- [Push Swap Tutorial](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - Overview of sorting strategies
- [Sorting Algorithms Visualizations](https://visualgo.net/en/sorting) - Visual understanding of sorting concepts

### AI Usage
AI tools were used for:
- Finding and organizing resources for learning
