// InnoBees STEM Lab - Motor Direction and Speed from Serial
// L298N: ENA -> D5 (PWM), IN1 -> D6, IN2 -> D7
// Commands via Serial Monitor:
//   f = forward, r = reverse, s = stop, b = brake
//   0-9 = set speed (0=stop, 9=full speed)
//   + = increase speed, - = decrease speed

const int ENA = 5;
const int IN1 = 6;
const int IN2 = 7;

int currentSpeed = 0;
char currentDirection = 's';  // s=stopped, f=forward, r=reverse

void applyMotor() {
  analogWrite(ENA, currentSpeed);

  switch (currentDirection) {
    case 'f':
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      break;
    case 'r':
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      break;
    default:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      break;
  }
}

void printStatus() {
  Serial.print("Direction: ");
  switch (currentDirection) {
    case 'f': Serial.print("FORWARD"); break;
    case 'r': Serial.print("REVERSE"); break;
    default:  Serial.print("STOPPED"); break;
  }
  Serial.print(" | Speed: ");
  Serial.print(currentSpeed);
  Serial.print("/255 (");
  Serial.print(map(currentSpeed, 0, 255, 0, 100));
  Serial.println("%)");
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== Motor Serial Control ===");
  Serial.println("Commands:");
  Serial.println("  f = forward");
  Serial.println("  r = reverse");
  Serial.println("  s = stop (coast)");
  Serial.println("  b = brake");
  Serial.println("  0-9 = set speed level");
  Serial.println("  + = faster, - = slower");
  Serial.println("---");

  applyMotor();
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    switch (cmd) {
      case 'f':
      case 'F':
        currentDirection = 'f';
        if (currentSpeed == 0) currentSpeed = 128;
        break;

      case 'r':
      case 'R':
        currentDirection = 'r';
        if (currentSpeed == 0) currentSpeed = 128;
        break;

      case 's':
      case 'S':
        currentDirection = 's';
        currentSpeed = 0;
        break;

      case 'b':
      case 'B':
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, 255);
        Serial.println("BRAKE!");
        delay(500);
        currentDirection = 's';
        currentSpeed = 0;
        break;

      case '+':
        currentSpeed = min(255, currentSpeed + 25);
        break;

      case '-':
        currentSpeed = max(0, currentSpeed - 25);
        break;

      default:
        if (cmd >= '0' && cmd <= '9') {
          currentSpeed = map(cmd - '0', 0, 9, 0, 255);
        }
        break;
    }

    applyMotor();
    printStatus();
  }
}
