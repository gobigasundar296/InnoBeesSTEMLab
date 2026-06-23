# Chapter 2: Flowcharts — Visualizing Logic

## What is a flowchart?

A flowchart is a visual diagram that represents the steps of an algorithm
using standard shapes connected by arrows.

Flowcharts help you:
- **See** the logic before coding.
- **Communicate** your design to others.
- **Find errors** in logic before writing code.
- **Debug** by tracing the path step by step.

## Standard flowchart symbols

| Shape | Name | Used for |
|---|---|---|
| Oval / Rounded rectangle | Terminal | Start and End |
| Rectangle | Process | Actions, calculations |
| Diamond | Decision | Yes/No questions |
| Parallelogram | Input/Output | Read sensor, display data |
| Arrow | Flow line | Direction of execution |

## Drawing rules

1. Every flowchart starts with a **Start** oval.
2. Every flowchart ends with an **End** oval (or loops back).
3. Arrows show the direction of flow (top to bottom, left to right).
4. A **decision diamond** always has exactly two outputs: Yes and No.
5. Every path must eventually reach End or loop back to a previous step.

## Example 1: Blink LED

```text
    ┌───────┐
    │ START │
    └───┬───┘
        ↓
    ┌───────────┐
    │ Set pin   │
    │ as OUTPUT │
    └─────┬─────┘
        ↓
    ┌───────────┐ ←──────────┐
    │ LED ON    │            │
    └─────┬─────┘            │
        ↓                    │
    ┌───────────┐            │
    │ Wait      │            │
    │ 500ms     │            │
    └─────┬─────┘            │
        ↓                    │
    ┌───────────┐            │
    │ LED OFF   │            │
    └─────┬─────┘            │
        ↓                    │
    ┌───────────┐            │
    │ Wait      │            │
    │ 500ms     │            │
    └─────┬─────┘            │
        │                    │
        └────────────────────┘
        (loop forever)
```

## Example 2: Smart street light (with decision)

```text
    ┌───────┐
    │ START │
    └───┬───┘
        ↓
    ┌─────────────┐
    │ Setup pins  │
    └──────┬──────┘
        ↓
    ╔═══════════════╗ ←────────────┐
    ║ Read light    ║              │
    ║ sensor value  ║              │
    ╚══════╤════════╝              │
        ↓                          │
      ◇─────────────◇              │
     ╱ Is light    ╲              │
    ╱  below 300?   ╲             │
    ╲               ╱             │
     ╲─────────────╱              │
      │Yes      │No               │
      ↓         ↓                  │
  ┌────────┐ ┌────────┐           │
  │LED ON  │ │LED OFF │           │
  └───┬────┘ └───┬────┘           │
      │          │                 │
      └────┬─────┘                 │
           ↓                       │
      ┌─────────┐                  │
      │Wait 200ms│                 │
      └────┬────┘                  │
           │                       │
           └───────────────────────┘
```

## Example 3: Button-controlled LED

```text
    START
      │
      ↓
    Setup pins
      │
      ↓
    ┌──────────────┐ ←───┐
    │Read button   │     │
    └──────┬───────┘     │
           ↓              │
    ◇ Button pressed? ◇  │
    │Yes            │No   │
    ↓               ↓     │
  LED ON         LED OFF  │
    │               │     │
    └───────┬───────┘     │
            │             │
            └─────────────┘
```

## Flowchart for loops

### Counted loop (for)

```text
    Set counter = 0
         │
         ↓
    ◇ counter < 5? ◇ ──No──→ Continue
         │ Yes
         ↓
    Do something
         │
         ↓
    counter = counter + 1
         │
         └───→ (back to check)
```

### Conditional loop (while)

```text
    ◇ Condition true? ◇ ──No──→ Continue
         │ Yes
         ↓
    Do something
         │
         └───→ (back to check)
```

## Practice: draw flowcharts

### Challenge 1

Draw a flowchart for: "If temperature is above 30°C, turn on fan. Otherwise,
turn off fan."

### Challenge 2

Draw a flowchart for: "Count from 1 to 10, displaying each number. Stop
when you reach 10."

### Challenge 3

Draw a flowchart for: "Read ultrasonic distance. If less than 20 cm, sound
buzzer. If 20-50 cm, light yellow LED. If more than 50 cm, light green LED."

## From flowchart to code

The flowchart translates directly to code:

| Flowchart element | Arduino code |
|---|---|
| Start | `void setup() {` |
| Loop back to top | `void loop() {` |
| Process box | Assignment or function call |
| Decision diamond | `if (...) { } else { }` |
| Input parallelogram | `analogRead()` or `digitalRead()` |
| Output parallelogram | `digitalWrite()` or `Serial.println()` |
| Counted loop | `for (int i = 0; i < n; i++)` |
| Conditional loop | `while (condition)` |

## Key takeaway

Always draw a flowchart before coding complex logic. It saves debugging time
and helps your team understand the design.
