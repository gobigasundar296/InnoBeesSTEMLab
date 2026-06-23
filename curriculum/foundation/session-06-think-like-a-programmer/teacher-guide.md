# Teacher Guide: Think Like a Programmer

## Why this module matters

Students have been writing and modifying code since Session 1, but mostly by
following templates. This session makes them conscious of the programming
concepts they've been using — variables, conditions, loops, functions — and
teaches them to think systematically about problem-solving and debugging.

This is the "learn to fish" session: once students understand these concepts
abstractly, they can write any program, not just copy examples.

## Recommended delivery

### Block 1 - Computational thinking (50 minutes)

- Activity: "Explain how to make a sandwich" (algorithm exercise): 10 min
- What is an algorithm? Real-life → Arduino examples: 10 minutes
- Flowchart symbols and drawing practice: 15 minutes
- Variables: what they are, types, naming: 15 minutes

### Block 2 - Code structures and debugging (70 minutes)

- Conditions: if/else with live Arduino demo: 15 minutes
- Loops: for and while with LED exercises: 15 minutes
- Functions: why and how to write them: 10 minutes
- Debugging exercise: find bugs in printed code: 15 minutes
- Coding challenge: Reaction Time Game: 15 minutes

### Extended Block (optional 60 minutes)

- Advanced challenges: pattern generator, password lock: 20 minutes
- Logic puzzles and problem-solving exercises: 20 minutes
- Team competition: debug race: 20 minutes

## Teaching method

This session is different — more thinking, less wiring. Methods:

1. **Unplugged activities:** Algorithm and flowchart exercises use paper,
   not computers.
2. **Code reading:** Students read and trace existing code before writing.
3. **Predict-then-test:** Students predict what code will do, then run it.
4. **Bug hunts:** Given buggy code, find and fix errors.
5. **Pair programming:** One drives (types), one navigates (thinks).

## Ice breaker: The Sandwich Algorithm (10 minutes)

1. Ask one student to come to the front.
2. Class must give verbal instructions to "make a sandwich" (or draw a star).
3. The student follows instructions LITERALLY (like a computer).
   - "Put the cheese on the bread" → puts the cheese bag on the bread bag.
   - Class learns: computers need EXACT, COMPLETE instructions.
4. Discuss: What made instructions fail? Ambiguity, missing steps, wrong order.

## Key demonstrations

### Variables — the changing value

1. Write a variable on the whiteboard: `count = 0`.
2. "Every time I clap, add 1." Clap three times. Update: 1, 2, 3.
3. "The variable changed! Its value is now 3."
4. Show Arduino: `count++` in a loop with Serial Monitor.

### Conditions — the decision maker

1. Upload a sensor program that prints values.
2. Ask: "At what value should the LED turn on?"
3. Students choose a threshold.
4. Add the `if` statement live. Test it.
5. "The condition lets the program DECIDE."

### Loops — the repeater

1. Ask a student to blink 10 times.
2. Ask: "Was that tiring? What if I said 1000 times?"
3. Show `for` loop: changes `10` to `1000` with one number change.
4. Demo: LED chaser with for loop over an array of pins.

### Debugging — the detective

1. Show a program on screen with 3 deliberate bugs.
2. "This program should blink an LED when a button is pressed. It doesn't work."
3. Students identify bugs one at a time.
4. Fix each bug. Test after each fix.
5. "Debugging is detective work. One clue at a time."

## Common misconceptions to correct

- **The computer understands what I mean.** No — it does exactly what you
  write, not what you intend. Be precise.
- **If it compiles, it works.** Compilation only checks syntax. Logic errors
  compile fine but produce wrong behavior.
- **More code = better.** Often less code (using loops and functions) is
  cleaner and less error-prone.
- **Debugging means rewriting everything.** Usually it's a small fix — a
  `<` instead of `>`, a missing semicolon, a wrong pin number.
- **Programming is memorizing commands.** It's about understanding patterns
  and logic. Commands can be looked up.

## Safety briefing

This session is primarily about thinking and typing, but Arduino hardware
is still on the table:

> I will not change wiring while code is uploading. I will save my code
> before testing hardware changes.

## Assessment evidence

Students should be able to:

- write a simple algorithm in plain English for a given problem;
- draw a flowchart with correct symbols for a decision-based system;
- declare variables with appropriate types and meaningful names;
- write an `if/else if/else` structure for multiple conditions;
- write a `for` loop that repeats an action a specified number of times;
- explain what a function does and why it's useful;
- identify at least 2 bugs in a given buggy program;
- trace code execution and predict output.

## Suggested team roles

- **Algorithm designer:** writes the step-by-step plan.
- **Flowchart artist:** draws the visual logic diagram.
- **Coder:** translates the design into Arduino code.
- **Tester/Debugger:** runs the code and identifies issues.
- **Presenter:** explains the team's solution logic to the class.

## Coding challenges (in order of difficulty)

1. **Traffic light with timer** — uses loops and timing.
2. **Temperature alarm** — uses conditions with multiple thresholds.
3. **Pattern generator** — uses nested loops.
4. **Reaction time game** — uses variables, timing, conditions.
5. **Password lock** — uses arrays, loops, conditions.
6. **Debug challenge** — find and fix intentional bugs.

## Final challenge: Problem Solving

Give teams a problem to solve from scratch:

1. Write the algorithm in plain English.
2. Draw a flowchart.
3. Identify variables needed.
4. Write the code.
5. Test and debug.
6. Present the solution.

Example problems:

- Count how many times a button is pressed in 10 seconds.
- Make a number guessing game via Serial Monitor.
- Create a quiz with 3 questions that tracks the score.
- Build a countdown timer that beeps at zero.
