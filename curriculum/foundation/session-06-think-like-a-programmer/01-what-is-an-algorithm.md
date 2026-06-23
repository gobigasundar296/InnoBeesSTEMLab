# Chapter 1: What Is an Algorithm?

## Definition

An **algorithm** is a step-by-step set of instructions to solve a problem
or complete a task. It must be:

1. **Clear:** Each step is unambiguous.
2. **Ordered:** Steps happen in a specific sequence.
3. **Finite:** It ends after a definite number of steps.
4. **Effective:** Each step can actually be carried out.

## Algorithms in daily life

You already follow algorithms every day without realizing it:

### Making a cup of tea

```text
1. Fill kettle with water
2. Turn on kettle
3. Wait until water boils
4. Put tea bag in cup
5. Pour hot water into cup
6. Wait 2-3 minutes
7. Remove tea bag
8. Add milk/sugar if desired
9. Stir and serve
```

### Crossing a road

```text
1. Walk to the edge of the road
2. Look left
3. Look right
4. Look left again
5. IF road is clear THEN cross
6. ELSE wait and go back to step 2
```

### Finding the largest number in a list

```text
1. Set "largest" to the first number
2. Look at the next number
3. IF this number is bigger than "largest"
     THEN set "largest" to this number
4. IF there are more numbers, go to step 2
5. "largest" now holds the answer
```

## Algorithms in Arduino

Every Arduino program is an algorithm! The computer follows instructions
exactly, step by step.

### Blink LED algorithm

```text
1. Set pin 8 as OUTPUT
2. Turn pin 8 HIGH (LED on)
3. Wait 500 milliseconds
4. Turn pin 8 LOW (LED off)
5. Wait 500 milliseconds
6. Go back to step 2 (loop forever)
```

### Smart street light algorithm

```text
1. Read light level from sensor
2. IF light level is below 300
     THEN turn LED on
     ELSE turn LED off
3. Wait 200 milliseconds
4. Go back to step 1
```

## Properties of a good algorithm

| Property | Bad example | Good example |
|---|---|---|
| Clear | "Heat it up" | "Heat to 100°C" |
| Ordered | Steps in random order | Logical sequence |
| Finite | "Keep checking forever" | "Check 10 times then stop" |
| Effective | "Read the person's mind" | "Read button state" |

## Algorithm vs. Program

| Algorithm | Program |
|---|---|
| Written in human language | Written in programming language |
| Describes the logic | Implements the logic |
| Can be on paper | Must be in a computer |
| Language-independent | Language-specific (C++, Python, etc.) |

An algorithm is the **plan**. A program is the **execution** of that plan.

## Writing algorithms: pseudocode

**Pseudocode** is a way to write algorithms that looks like code but uses
plain English. It helps plan before coding.

```text
BEGIN
  SET threshold TO 300
  REPEAT FOREVER:
    READ lightLevel FROM sensor
    IF lightLevel < threshold THEN
      TURN LED ON
    ELSE
      TURN LED OFF
    END IF
    WAIT 200ms
  END REPEAT
END
```

## Practice: write an algorithm

### Challenge 1: Automatic door

Write step-by-step instructions for an automatic sliding door:

```text
1. ___________________________________
2. ___________________________________
3. ___________________________________
4. ___________________________________
5. ___________________________________
```

### Challenge 2: Vending machine

Write an algorithm for a vending machine that accepts coins and gives a drink:

```text
1. ___________________________________
2. ___________________________________
3. ___________________________________
4. ___________________________________
5. ___________________________________
6. ___________________________________
```

## Key takeaway

Before writing any code, **think about the algorithm first.** If you can't
explain the steps in plain English, you're not ready to code it yet.

> "If you can't explain it simply, you don't understand it well enough."
