push_swap is an algorithmic challenge focused on sorting data on a stack with a limited set of instructions and the smallest number of moves possible.

Algorithmic Efficiency: Developed a sorting algorithm optimized for different dataset sizes, prioritizing the reduction of instruction counts to meet strict performance benchmarks.

Data Structure Rigor: Utilized doubly linked lists or arrays to represent stacks, ensuring that push/swap/rotate operations are performed with O(1) complexity where possible.

Input Validation: Engineered a robust parsing system to handle edge cases, including integer overflows and duplicate values, ensuring the program's stability in "unsafe" input environments.

Compilation: Run make to generate the push_swap binary.

Execution: ./push_swap [list_of_numbers] (e.g., ./push_swap 2 1 3 6 5 8).

Visualization: To check the move count, run: ./push_swap 3 2 1 | wc -l.
