# Teacher Answer Key: Session 6 Workbook

## Part A

1. A step-by-step set of clear, ordered instructions to solve a problem
   or complete a task.

2. Making a phone call (example): Unlock phone → Open contacts → Find
   friend's name → Tap call button → Wait for answer → Talk → Tap end call.

3. Automatic door (example): Measure distance → If person within 50cm →
   Open door (servo to 90°) → Wait 5 seconds → If no one near → Close door.

4. Clear, ordered, finishes (or loops intentionally), each step doable.
   NOT "uses fancy words."

## Part B

1. Oval=Start/End. Rectangle=Process/Action. Diamond=Decision.
   Parallelogram=Input/Output. Arrow=Flow direction.

2. Flowchart should show: Start → Read button → Diamond "Pressed?" →
   Yes: LED ON / No: LED OFF → Loop back to Read button.

3. Flowchart should show: Read temp → Diamond ">35?" → Yes: RED →
   No: Diamond ">25?" → Yes: GREEN → No: BLUE → Loop back.

## Part C

1. A named container that stores a value in memory that can change during
   program execution.

2. Button presses=int. Temperature=float. LED on?=bool. Command=char.
   Name=String. Pin number=int (or const int).

3. `3rdPlace`: starts with number. `my speed`: has a space. `for`: reserved
   word. `ledState = "true"`: bool needs true/false without quotes.

4. x = 5, 8, 16, 17, 13.

## Part D

1. `if (lightLevel < 300)`. `if (digitalRead(BUTTON_PIN) == LOW)`.
   `if (distance < 20)`. `if (temp >= 20 && temp <= 30)`.
   `if (motorSpeed == 0)`.

2. Output: "B" (75 ≥ 70 is true, so second branch executes).

3. `if (light < 200)` ... `else if (light < 600)` ... `else`.

## Part E

1. Output: 0, 1, 2, 3, 4 (prints numbers 0 through 4).

2. Runs 5 times. Values: 1, 3, 5, 7, 9.

3. ```cpp
   for (int i = 0; i < 7; i++) {
     digitalWrite(8, HIGH);
     delay(200);
     digitalWrite(8, LOW);
     delay(200);
   }
   ```

4. `for`: use when you know how many times to repeat.
   `while`: use when you repeat until a condition becomes false (unknown count).

## Part F

1. (1) Reuse code without rewriting. (2) Organize code into readable,
   testable pieces. (Also accept: readability, debugging ease.)

2. Return type: float. Name: getDistance. Parameters: none (empty).
   Returns: distance in cm as a float.

3. ```cpp
   void beep(int times) {
     for (int i = 0; i < times; i++) {
       digitalWrite(7, HIGH);
       delay(200);
       digitalWrite(7, LOW);
       delay(200);
     }
   }
   ```

## Part G

1. Bug 1: Line 2 — missing semicolon after `BUTTON_PIN = 2`.
   Bug 2: Line 6 — should be `INPUT_PULLUP` (or INPUT), not `OUTPUT`.
   Bug 3: Line 10 — should be `==` (comparison), not `=` (assignment).

2. The condition is wrong: `light > 300` turns on when bright. For dark
   conditions, light value is LOW, so it should be `light < 300`.

3. `Serial.println()` — print variable values to Serial Monitor to observe
   what the program is actually doing.

## Part H

1. `a / b` = 3 (integer division truncates). `a % b` = 1 (remainder).

2. Algorithm: Set counter to 10 → While counter ≥ 0: print counter, blink
   LED, decrement counter, wait 1 second → When 0: turn on buzzer for
   2 seconds → Stop.

   Accept any reasonable code implementing this logic with a for/while loop,
   Serial.println, LED blink, and buzzer at end.
