"""Generate editable SVG teaching diagrams for Foundation Session 1."""

from pathlib import Path
from xml.sax.saxutils import escape


ROOT = Path(__file__).resolve().parents[1]
SESSION = ROOT / "curriculum" / "foundation" / "session-01-technology-around-us"
DIAGRAMS = SESSION / "diagrams"
CIRCUITS = SESSION / "circuits"


COLORS = {
    "ink": "#17324d",
    "muted": "#526d82",
    "paper": "#f7fbfd",
    "board": "#e9f5f8",
    "board_edge": "#287b91",
    "red": "#e53935",
    "black": "#263238",
    "yellow": "#f6a800",
    "green": "#2e9d55",
    "blue": "#2374d8",
    "purple": "#7556d8",
    "orange": "#ef7d19",
    "rail_blue": "#1d70b8",
    "gold": "#e3bd63",
}


def svg_start(title, desc, width=1200, height=720):
    return f"""<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" role="img" aria-labelledby="title desc">
  <title id="title">{escape(title)}</title>
  <desc id="desc">{escape(desc)}</desc>
  <rect width="{width}" height="{height}" fill="{COLORS['paper']}"/>
  <style>
    .title {{ font: 700 30px Arial, sans-serif; fill: {COLORS['ink']}; }}
    .h2 {{ font: 700 21px Arial, sans-serif; fill: {COLORS['ink']}; }}
    .label {{ font: 600 17px Arial, sans-serif; fill: {COLORS['ink']}; }}
    .small {{ font: 15px Arial, sans-serif; fill: {COLORS['muted']}; }}
    .tiny {{ font: 12px Arial, sans-serif; fill: {COLORS['muted']}; }}
    .wire {{ fill: none; stroke-width: 7; stroke-linecap: round; stroke-linejoin: round; }}
    .thin {{ fill: none; stroke: {COLORS['ink']}; stroke-width: 3; }}
    .panel {{ fill: #ffffff; stroke: #a8c0cc; stroke-width: 3; }}
  </style>
  <text x="48" y="48" class="title">{escape(title)}</text>
"""


def svg_end(footer=None):
    footer_svg = ""
    if footer:
        footer_svg = f'<text x="48" y="694" class="small">{escape(footer)}</text>'
    return footer_svg + "\n</svg>\n"


def text(x, y, value, cls="label", anchor="start"):
    return f'<text x="{x}" y="{y}" class="{cls}" text-anchor="{anchor}">{escape(value)}</text>'


def line(points, color, width=7, dash=None):
    coords = " ".join(f"{x},{y}" for x, y in points)
    dash_attr = f' stroke-dasharray="{dash}"' if dash else ""
    return (
        f'<polyline points="{coords}" fill="none" stroke="{color}" '
        f'stroke-width="{width}" stroke-linecap="round" '
        f'stroke-linejoin="round"{dash_attr}/>'
    )


def breadboard(x=260, y=115, w=890, h=500, rows=12):
    parts = [
        f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="24" '
        f'fill="{COLORS["board"]}" stroke="{COLORS["board_edge"]}" stroke-width="4"/>',
        f'<line x1="{x+38}" y1="{y+58}" x2="{x+w-38}" y2="{y+58}" '
        f'stroke="{COLORS["red"]}" stroke-width="4"/>',
        f'<line x1="{x+38}" y1="{y+91}" x2="{x+w-38}" y2="{y+91}" '
        f'stroke="{COLORS["rail_blue"]}" stroke-width="4"/>',
        f'<line x1="{x+38}" y1="{y+h-91}" x2="{x+w-38}" y2="{y+h-91}" '
        f'stroke="{COLORS["red"]}" stroke-width="4"/>',
        f'<line x1="{x+38}" y1="{y+h-58}" x2="{x+w-38}" y2="{y+h-58}" '
        f'stroke="{COLORS["rail_blue"]}" stroke-width="4"/>',
        f'<rect x="{x+38}" y="{y+h/2-18}" width="{w-76}" height="36" fill="#d9e8ed"/>',
    ]
    left = x + 95
    span = w - 190
    for col in range(rows):
        cx = left + col * span / (rows - 1)
        for cy in (y + 74, y + 185, y + 220, y + 280, y + 315, y + h - 74):
            parts.append(
                f'<circle cx="{cx:.1f}" cy="{cy:.1f}" r="5" fill="#fff" '
                f'stroke="#78909c" stroke-width="2"/>'
            )
        parts.append(text(cx, y + h / 2 + 6, str(col + 1), "tiny", "middle"))
    parts.append(text(x + 20, y + 64, "+", "label"))
    parts.append(text(x + 20, y + 98, "-", "label"))
    parts.append(text(x + 20, y + h - 84, "+", "label"))
    parts.append(text(x + 20, y + h - 51, "-", "label"))
    return "\n".join(parts)


def supply(x=42, y=170, label="5 V SOURCE"):
    return f"""
  <rect x="{x}" y="{y}" width="175" height="310" rx="20" fill="#dff0f5" stroke="{COLORS['board_edge']}" stroke-width="4"/>
  {text(x+87, y+45, label, "h2", "middle")}
  <circle cx="{x+145}" cy="{y+105}" r="10" fill="{COLORS['red']}"/>
  {text(x+35, y+112, "5V", "label")}
  <circle cx="{x+145}" cy="{y+295}" r="10" fill="{COLORS['black']}"/>
  {text(x+35, y+302, "GND", "label")}
"""


def arduino(x=40, y=120, w=200, h=480):
    pins = [("D4", 220), ("D5~", 265), ("D6~", 310), ("D7", 355),
            ("D8", 400), ("D9~", 445), ("5V", 500), ("GND", 545)]
    parts = [
        f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="22" '
        f'fill="#d7f0f4" stroke="#167187" stroke-width="4"/>',
        text(x + w / 2, y + 42, "Arduino Uno", "h2", "middle"),
        f'<rect x="{x+24}" y="{y+72}" width="82" height="125" rx="12" '
        f'fill="#255f70" stroke="{COLORS["ink"]}" stroke-width="3"/>',
        text(x + 65, y + 125, "ATmega", "tiny", "middle"),
        text(x + 65, y + 145, "328P", "tiny", "middle"),
    ]
    for label, py in pins:
        parts.append(f'<circle cx="{x+w-5}" cy="{py}" r="9" fill="#fff" stroke="{COLORS["ink"]}" stroke-width="3"/>')
        parts.append(text(x + 122, py + 6, label, "label"))
    return "\n".join(parts)


def resistor(x, y, label="330 ohm", horizontal=True):
    if horizontal:
        return f"""
  <line x1="{x-42}" y1="{y}" x2="{x}" y2="{y}" stroke="{COLORS['ink']}" stroke-width="4"/>
  <rect x="{x}" y="{y-17}" width="120" height="34" rx="8" fill="#f2dda1" stroke="#795f22" stroke-width="3"/>
  <line x1="{x+120}" y1="{y}" x2="{x+162}" y2="{y}" stroke="{COLORS['ink']}" stroke-width="4"/>
  {text(x+60, y-28, label, "small", "middle")}
"""
    return f"""
  <line x1="{x}" y1="{y-42}" x2="{x}" y2="{y}" stroke="{COLORS['ink']}" stroke-width="4"/>
  <rect x="{x-17}" y="{y}" width="34" height="120" rx="8" fill="#f2dda1" stroke="#795f22" stroke-width="3"/>
  <line x1="{x}" y1="{y+120}" x2="{x}" y2="{y+162}" stroke="{COLORS['ink']}" stroke-width="4"/>
  {text(x+30, y+65, label, "small")}
"""


def led(x, y, color="#ef5350", label="LED"):
    return f"""
  <path d="M{x-30},{y+5} Q{x},{y-50} {x+30},{y+5} Z" fill="{color}" stroke="{COLORS['ink']}" stroke-width="4"/>
  <line x1="{x-30}" y1="{y+5}" x2="{x-30}" y2="{y+68}" stroke="{COLORS['ink']}" stroke-width="5"/>
  <line x1="{x+30}" y1="{y+5}" x2="{x+30}" y2="{y+68}" stroke="{COLORS['ink']}" stroke-width="5"/>
  {text(x, y-60, label, "label", "middle")}
  {text(x-30, y+90, "A +", "tiny", "middle")}
  {text(x+30, y+90, "K -", "tiny", "middle")}
"""


def button(x, y, pressed=False):
    lever_y = y + 35 if pressed else y + 5
    return f"""
  <rect x="{x-55}" y="{y+45}" width="110" height="55" rx="8" fill="#dce7eb" stroke="{COLORS['ink']}" stroke-width="3"/>
  <line x1="{x}" y1="{lever_y}" x2="{x}" y2="{y+45}" stroke="{COLORS['ink']}" stroke-width="8"/>
  <rect x="{x-28}" y="{y-5}" width="56" height="28" rx="9" fill="#efefef" stroke="{COLORS['ink']}" stroke-width="3"/>
  {text(x, y-22, "BUTTON", "small", "middle")}
"""


def buzzer(x, y):
    return f"""
  <circle cx="{x}" cy="{y}" r="55" fill="#dcd5fa" stroke="#4d3aa3" stroke-width="4"/>
  <circle cx="{x}" cy="{y}" r="20" fill="#4d3aa3"/>
  {text(x, y-72, "ACTIVE BUZZER", "small", "middle")}
  {text(x-58, y+7, "+", "label", "middle")}
  {text(x+58, y+7, "-", "label", "middle")}
"""


def callout(x, y, w, h, heading, lines):
    body = [
        f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="16" class="panel"/>',
        text(x + 20, y + 32, heading, "h2"),
    ]
    for i, value in enumerate(lines):
        body.append(text(x + 20, y + 66 + i * 28, value, "small"))
    return "\n".join(body)


def write_svg(path, content):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content, encoding="utf-8")


def concept_breadboard():
    s = svg_start(
        "How a Breadboard Is Connected Internally",
        "Power rails run horizontally. Groups of five terminal holes are connected vertically, with the center channel separating both sides.",
    )
    s += breadboard(85, 100, 1030, 500, 14)
    s += line([(180, 174), (465, 174)], COLORS["red"], 12)
    s += line([(180, 191), (465, 191)], COLORS["rail_blue"], 12)
    for x in (250, 390, 530):
        s += line([(x, 285), (x, 320)], COLORS["green"], 12)
        s += line([(x, 380), (x, 415)], COLORS["purple"], 12)
    s += callout(780, 205, 290, 215, "What the colors show", [
        "Red/blue: long power rails",
        "Green: one connected group",
        "Purple: separate group",
        "Center gap: no connection",
        "Test real boards for split rails",
    ])
    s += svg_end("Use continuity mode only when the breadboard is not powered.")
    write_svg(DIAGRAMS / "breadboard-internal-connections.svg", s)


def concept_led_rgb():
    s = svg_start(
        "LED and RGB LED Polarity",
        "A standard LED has an anode and cathode. A common-cathode RGB LED has three color anodes and one shared cathode, with a resistor for each color.",
    )
    s += led(190, 260, "#ef5350", "STANDARD LED")
    s += callout(55, 440, 285, 150, "Polarity clues", [
        "Long leg: usually anode (+)",
        "Short leg: usually cathode (-)",
        "Flat rim: usually cathode",
    ])
    s += '<rect x="420" y="110" width="710" height="500" rx="22" class="panel"/>'
    s += text(775, 150, "COMMON-CATHODE RGB LED", "h2", "middle")
    s += '<circle cx="770" cy="310" r="90" fill="#f5f5f5" stroke="#17324d" stroke-width="4"/>'
    for cx, c, label in ((720, "#ef5350", "R"), (770, "#43a047", "G"), (820, "#2979ff", "B")):
        s += f'<circle cx="{cx}" cy="300" r="25" fill="{c}" opacity="0.85"/>'
        s += text(cx, 306, label, "label", "middle")
    for x, c, lab in ((530, COLORS["red"], "RED + resistor"), (690, COLORS["green"], "GREEN + resistor"), (850, COLORS["blue"], "BLUE + resistor")):
        s += resistor(x, 470, "330 ohm")
        s += line([(x + 162, 470), (x + 190, 470), (x + 190, 385)], c)
        s += text(x + 60, 535, lab, "small", "middle")
    s += line([(770, 400), (770, 430), (960, 430), (960, 565)], COLORS["black"])
    s += text(960, 590, "COMMON CATHODE -> GND", "small", "middle")
    s += svg_end("Each RGB color is a separate LED and needs its own current-limiting resistor.")
    write_svg(DIAGRAMS / "led-and-rgb-led.svg", s)


def mini_circuit_panel(x, y, title_value, state, parallel=False):
    panel_height = 290 if parallel else 260
    out = [f'<rect x="{x}" y="{y}" width="530" height="{panel_height}" rx="18" class="panel"/>',
           text(x + 265, y + 34, title_value, "h2", "middle")]
    if parallel:
        out.append(line([(x + 45, y + 120), (x + 105, y + 120), (x + 105, y + 215)], COLORS["red"], 5))
        for branch_y, col, lab in ((y + 120, "#ef5350", "LED 1"), (y + 215, "#43a047", "LED 2")):
            out.append(resistor(x + 155, branch_y, "330"))
            out.append(led(x + 390, branch_y + 5, col, ""))
            out.append(line([(x + 105, branch_y), (x + 113, branch_y)], COLORS["red"], 5))
            out.append(line([(x + 317, branch_y), (x + 360, branch_y), (x + 360, branch_y + 10)], COLORS["orange"], 5))
            out.append(line([(x + 420, branch_y + 73), (x + 470, branch_y + 73)], COLORS["black"], 5))
        out.append(line([(x + 470, y + 193), (x + 470, y + 288), (x + 45, y + 288)], COLORS["black"], 5))
    else:
        out.append(line([(x + 45, y + 135), (x + 125, y + 135)], COLORS["red"], 5))
        if state == "open":
            out.append(line([(x + 125, y + 135), (x + 185, y + 90)], COLORS["ink"], 5))
            out.append(line([(x + 205, y + 135), (x + 250, y + 135)], COLORS["ink"], 5))
        else:
            out.append(line([(x + 125, y + 135), (x + 250, y + 135)], COLORS["green"], 5))
        out.append(resistor(x + 250, y + 135, "330"))
        out.append(led(x + 445, y + 140, "#ef5350", "LED"))
        out.append(line([(x + 475, y + 208), (x + 475, y + 230), (x + 45, y + 230)], COLORS["black"], 5))
    return "\n".join(out)


def concept_circuit_types():
    s = svg_start(
        "Open, Closed, Series and Parallel Circuits",
        "Four panels compare an open switch, closed path, two LEDs in one series path, and two LED branches in parallel.",
        1200, 720,
    )
    s += mini_circuit_panel(45, 85, "OPEN CIRCUIT", "open")
    s += mini_circuit_panel(625, 85, "CLOSED CIRCUIT", "closed")
    s += '<rect x="45" y="375" width="530" height="260" rx="18" class="panel"/>'
    s += text(310, 409, "SERIES: ONE PATH", "h2", "middle")
    s += line([(85, 500), (145, 500)], COLORS["red"], 5)
    s += resistor(145, 500, "150")
    s += led(345, 505, "#ef5350", "LED 1")
    s += line([(375, 573), (415, 573), (415, 500)], COLORS["ink"], 5)
    s += led(475, 505, "#ef5350", "LED 2")
    s += line([(505, 573), (505, 610), (85, 610)], COLORS["black"], 5)
    s += mini_circuit_panel(625, 375, "PARALLEL: TWO PATHS", "closed", True)
    s += svg_end("Series: same current. Parallel: same voltage across each branch.")
    write_svg(DIAGRAMS / "circuit-types.svg", s)


def concept_multimeter():
    s = svg_start(
        "Digital Multimeter Connections",
        "Resistance and continuity are measured on an unpowered component, voltage is measured in parallel, and current is measured by opening the circuit and inserting the meter in series.",
    )
    panels = [(45, "RESISTANCE / CONTINUITY", "Power OFF", "Across component"),
              (420, "DC VOLTAGE", "Power ON", "Meter in parallel"),
              (795, "DC CURRENT", "Power OFF to insert", "Meter in series")]
    for x, heading, note1, note2 in panels:
        s += f'<rect x="{x}" y="90" width="330" height="530" rx="18" class="panel"/>'
        s += text(x + 165, 126, heading, "h2", "middle")
        s += f'<circle cx="{x+165}" cy="260" r="92" fill="#30373d" stroke="#111" stroke-width="4"/>'
        s += f'<rect x="{x+105}" y="190" width="120" height="55" rx="5" fill="#cfe7c7"/>'
        s += text(x + 165, 225, "0.00", "h2", "middle")
        s += f'<circle cx="{x+165}" cy="295" r="35" fill="#777" stroke="#111" stroke-width="3"/>'
        s += line([(x + 120, 350), (x + 90, 500)], COLORS["black"], 4)
        s += line([(x + 210, 350), (x + 240, 500)], COLORS["red"], 4)
        s += text(x + 165, 405, note1, "label", "middle")
        s += text(x + 165, 440, note2, "small", "middle")
    s += text(210, 570, "COM + V/ohm socket", "small", "middle")
    s += text(585, 570, "Probe across two nodes", "small", "middle")
    s += text(960, 570, "Never bridge 5 V to GND", "small", "middle")
    s += svg_end("Always check the selected mode and probe socket before touching the circuit.")
    write_svg(DIAGRAMS / "multimeter-guide.svg", s)


def concept_arduino_pin_map():
    s = svg_start(
        "Arduino Uno R3 External Pin Map",
        "Educational map of power, digital, PWM, serial, analog, I2C, SPI, reset, USB, and main controller connections.",
    )
    s += '<rect x="235" y="90" width="730" height="550" rx="35" fill="#d8f1f4" stroke="#167187" stroke-width="5"/>'
    s += '<rect x="265" y="160" width="180" height="160" rx="18" fill="#b7c9d0" stroke="#17324d" stroke-width="4"/>'
    s += text(355, 245, "USB-B", "h2", "middle")
    s += '<rect x="490" y="250" width="240" height="150" rx="16" fill="#255f70" stroke="#17324d" stroke-width="4"/>'
    s += text(610, 332, "ATmega328P", "h2", "middle")
    s += '<circle cx="845" cy="255" r="55" fill="#263238"/>'
    s += text(845, 260, "POWER", "small", "middle")
    groups = [
        (260, 115, 430, "POWER: IOREF RESET 3.3V 5V GND GND VIN", COLORS["red"]),
        (485, 115, 450, "ANALOG: A0 A1 A2 A3 A4/SDA A5/SCL", COLORS["green"]),
        (250, 605, 690, "DIGITAL: D0/RX D1/TX D2 D3~ D4 D5~ D6~ D7 D8 D9~ D10~ D11~ D12 D13", COLORS["blue"]),
    ]
    for x, y, w, label, col in groups:
        s += f'<rect x="{x}" y="{y}" width="{w}" height="38" rx="8" fill="#fff" stroke="{col}" stroke-width="4"/>'
        s += text(x + w / 2, y + 25, label, "tiny", "middle")
    s += callout(770, 360, 160, 190, "Key marks", [
        "~ = PWM",
        "D0/D1 = serial",
        "D13 = built-in LED",
        "A4/A5 = I2C",
        "GND = common return",
    ])
    s += svg_end("Educational top-view map. Consult the official Arduino Uno R3 pinout before advanced wiring.")
    write_svg(DIAGRAMS / "arduino-uno-pin-map.svg", s)


def concept_arduino_blocks():
    s = svg_start(
        "Arduino Uno R3 Internal Functional Blocks",
        "Functional block diagram showing USB, USB-to-serial controller, ATmega328P, memory, clock, digital input output, analog conversion, timers, power regulation, and external connectors.",
    )
    boxes = {
        "usb": (60, 150, 180, 90, "USB-B\\nPower + data"),
        "bridge": (300, 150, 220, 90, "ATmega16U2\\nUSB to serial"),
        "cpu": (610, 250, 250, 130, "ATmega328P\\nMicrocontroller"),
        "memory": (920, 120, 220, 110, "Memory\\nFlash / SRAM / EEPROM"),
        "clock": (920, 270, 220, 90, "16 MHz clock"),
        "digital": (300, 470, 220, 100, "Digital I/O\\nD0-D13"),
        "analog": (610, 470, 220, 100, "ADC\\nA0-A5"),
        "timers": (920, 440, 220, 130, "Timers + PWM\\nTiming and brightness"),
        "power": (60, 430, 180, 140, "Power section\\nUSB / jack / VIN\\nregulation"),
    }
    for key, (x, y, w, h, label) in boxes.items():
        fill = "#dff1f5" if key != "cpu" else "#b9e1e8"
        s += f'<rect x="{x}" y="{y}" width="{w}" height="{h}" rx="16" fill="{fill}" stroke="{COLORS["board_edge"]}" stroke-width="4"/>'
        lines = label.split("\\n")
        for i, value in enumerate(lines):
            s += text(x + w / 2, y + h / 2 - 8 + i * 25, value, "label", "middle")
    for pts, col in [
        ([(240, 195), (300, 195)], COLORS["purple"]),
        ([(520, 195), (610, 195), (610, 275)], COLORS["purple"]),
        ([(240, 500), (300, 500)], COLORS["red"]),
        ([(735, 250), (735, 195), (920, 195)], COLORS["blue"]),
        ([(860, 315), (920, 315)], COLORS["blue"]),
        ([(660, 380), (410, 380), (410, 470)], COLORS["green"]),
        ([(735, 380), (735, 470)], COLORS["green"]),
        ([(810, 380), (1030, 380), (1030, 440)], COLORS["orange"]),
    ]:
        s += line(pts, col, 6)
    s += svg_end("This is a learning diagram, not the complete electrical schematic.")
    write_svg(DIAGRAMS / "arduino-internal-blocks.svg", s)


def circuit_base(title_value, desc, with_arduino=False):
    s = svg_start(title_value, desc)
    if with_arduino:
        s += arduino()
        s += breadboard(285, 110, 855, 500, 12)
    else:
        s += supply()
        s += breadboard()
    return s


def c1():
    s = circuit_base("Circuit 1 - Single LED Closed Circuit", "A 5 volt supply connects through a 330 ohm resistor and red LED to ground on a breadboard.")
    s += resistor(520, 250)
    s += led(770, 300, "#ef5350", "RED LED")
    s += line([(187, 275), (400, 275), (400, 250), (478, 250)], COLORS["red"])
    s += line([(682, 250), (740, 250), (740, 305)], COLORS["orange"])
    s += line([(800, 368), (800, 465), (187, 465)], COLORS["black"])
    s += callout(875, 235, 225, 190, "Current path", ["5 V", "330 ohm resistor", "LED anode to cathode", "GND", "Expected: about 9 mA"])
    s += svg_end("Disconnect power before reversing or moving the LED.")
    write_svg(CIRCUITS / "01-single-led-closed.svg", s)


def c2():
    s = circuit_base("Circuit 2 - Button Creates Open and Closed Paths", "A normally open push button controls a resistor and red LED on a breadboard.")
    s += button(480, 225, False)
    s += resistor(610, 315)
    s += led(855, 340, "#ef5350", "LED")
    s += line([(187, 275), (425, 275), (425, 270)], COLORS["red"])
    s += line([(535, 270), (535, 315), (568, 315)], COLORS["green"])
    s += line([(772, 315), (825, 315), (825, 345)], COLORS["orange"])
    s += line([(885, 408), (885, 465), (187, 465)], COLORS["black"])
    s += callout(930, 215, 190, 180, "Two states", ["Released = open", "Current = 0", "Pressed = closed", "LED turns on"])
    s += svg_end("A closed path allows current; an open path stops current.")
    write_svg(CIRCUITS / "02-button-open-closed.svg", s)


def c3():
    s = circuit_base("Circuit 3 - Two Red LEDs in Series", "Two red LEDs share the same current in one path with a 150 ohm resistor.")
    s += resistor(440, 250, "150 ohm")
    s += led(660, 300, "#ef5350", "LED 1")
    s += led(865, 300, "#ef5350", "LED 2")
    s += line([(187, 275), (360, 275), (360, 250), (398, 250)], COLORS["red"])
    s += line([(602, 250), (630, 250), (630, 305)], COLORS["orange"])
    s += line([(690, 368), (690, 405), (835, 405), (835, 305)], COLORS["orange"])
    s += line([(895, 368), (895, 465), (187, 465)], COLORS["black"])
    s += callout(950, 215, 170, 180, "Calculation", ["Vf total = 4 V", "R = 125 ohm", "Choose 150 ohm", "One open stops both"])
    s += svg_end("Use two red LEDs; two blue LEDs normally need more than a 5 V supply in series.")
    write_svg(CIRCUITS / "03-two-led-series.svg", s)


def c4():
    s = circuit_base("Circuit 4 - Two LED Branches in Parallel", "Two LEDs connect across the same supply, and each branch has its own 330 ohm resistor.")
    for y, col, label in ((245, "#ef5350", "RED LED"), (405, "#43a047", "GREEN LED")):
        s += resistor(450, y)
        s += led(745, y + 35, col, label)
        s += line([(187, 275), (360, 275), (360, y), (408, y)], COLORS["red"])
        s += line([(612, y), (715, y), (715, y + 40)], COLORS["orange"])
        s += line([(775, y + 103), (840, y + 103), (840, 465), (187, 465)], COLORS["black"])
    s += callout(900, 215, 210, 190, "Parallel rules", ["Same branch voltage", "Currents add", "One resistor per LED", "One branch can open", "Other branch stays on"])
    s += svg_end("Each LED branch is calculated separately.")
    write_svg(CIRCUITS / "04-two-led-parallel.svg", s)


def c5():
    s = circuit_base("Circuit 5 - Series Resistors Reduce LED Current", "A 220 ohm and 330 ohm resistor are placed in series with one red LED.")
    s += resistor(400, 250, "220 ohm")
    s += resistor(610, 250, "330 ohm")
    s += led(880, 300, "#ef5350", "LED")
    s += line([(187, 275), (330, 275), (330, 250), (358, 250)], COLORS["red"])
    s += line([(562, 250), (568, 250)], COLORS["orange"])
    s += line([(772, 250), (850, 250), (850, 305)], COLORS["orange"])
    s += line([(910, 368), (910, 465), (187, 465)], COLORS["black"])
    s += callout(925, 205, 195, 200, "Result", ["R total = 550 ohm", "Current about 5.5 mA", "LED is dimmer", "Series values add"])
    s += svg_end("Compare measured resistor voltage and LED brightness with Circuit 1.")
    write_svg(CIRCUITS / "05-series-resistors-led.svg", s)


def c6():
    s = circuit_base("Circuit 6 - Button-Controlled Active Buzzer", "A normally open button applies 5 volts to a low-current active buzzer on a breadboard.")
    s += button(500, 230, False)
    s += buzzer(760, 350)
    s += line([(187, 275), (445, 275)], COLORS["red"])
    s += line([(555, 275), (625, 275), (625, 350), (705, 350)], COLORS["purple"])
    s += line([(815, 350), (890, 350), (890, 465), (187, 465)], COLORS["black"])
    s += callout(925, 215, 190, 210, "Check first", ["Rated for 5 V", "Observe + and -", "Current below 20 mA", "Released: silent", "Pressed: sounds"])
    s += svg_end("Use a transistor driver for a buzzer that exceeds the controller or switch current limit.")
    write_svg(CIRCUITS / "06-button-active-buzzer.svg", s)


def c7():
    s = circuit_base("Circuit 7 - Button Controls LED and Buzzer in Parallel", "One button feeds two parallel branches: a resistor and LED branch, and a low-current active buzzer branch.")
    s += button(420, 210, False)
    s += resistor(580, 285)
    s += led(805, 315, "#ef5350", "LED")
    s += buzzer(760, 490)
    s += line([(187, 275), (365, 275), (365, 255)], COLORS["red"])
    s += line([(475, 255), (520, 255), (520, 440)], COLORS["green"])
    s += line([(520, 285), (538, 285)], COLORS["orange"])
    s += line([(742, 285), (775, 285), (775, 320)], COLORS["orange"])
    s += line([(835, 383), (900, 383), (900, 465), (187, 465)], COLORS["black"])
    s += line([(520, 440), (705, 440), (705, 490)], COLORS["purple"])
    s += line([(815, 490), (900, 490)], COLORS["black"])
    s += callout(930, 180, 185, 190, "Branches", ["Branch 1: LED + R", "Branch 2: buzzer", "Same supply voltage", "Branch currents add"])
    s += svg_end("The button carries the combined branch current.")
    write_svg(CIRCUITS / "07-button-led-buzzer-parallel.svg", s)


def c8():
    s = circuit_base("Circuit 8 - Common-Cathode RGB Color Mixer", "Three current-limited color channels connect to a common-cathode RGB LED on a breadboard.")
    for y, col, label in ((220, COLORS["red"], "RED"), (310, COLORS["green"], "GREEN"), (400, COLORS["blue"], "BLUE")):
        s += resistor(410, y)
        s += line([(187, 275), (340, 275), (340, y), (368, y)], COLORS["red"])
        s += line([(572, y), (710, y)], col)
        s += text(625, y - 12, label, "small", "middle")
    s += '<circle cx="790" cy="315" r="86" fill="#f1f1f1" stroke="#17324d" stroke-width="4"/>'
    for cx, cy, color in ((760, 295, "#ef5350"), (800, 295, "#43a047"), (780, 335, "#2979ff")):
        s += f'<circle cx="{cx}" cy="{cy}" r="24" fill="{color}" opacity="0.9"/>'
    s += text(790, 205, "RGB LED", "label", "middle")
    s += line([(790, 400), (790, 465), (187, 465)], COLORS["black"])
    s += callout(920, 205, 190, 220, "Color mixing", ["R + G = yellow", "R + B = magenta", "G + B = cyan", "R + G + B = white-ish", "One resistor per color"])
    s += svg_end("Confirm the RGB LED pin order from its datasheet; packages are not all identical.")
    write_svg(CIRCUITS / "08-rgb-color-mixer.svg", s)


def c9():
    s = circuit_base("Circuit 9 - Arduino Controls One External LED", "Arduino digital pin 8 drives a red LED through a 330 ohm resistor to common ground.", True)
    s += resistor(550, 290)
    s += led(840, 330, "#ef5350", "EXTERNAL LED")
    s += line([(235, 400), (410, 400), (410, 290), (508, 290)], COLORS["orange"])
    s += text(340, 385, "D8", "small", "middle")
    s += line([(712, 290), (810, 290), (810, 335)], COLORS["orange"])
    s += line([(870, 398), (930, 398), (930, 545), (235, 545)], COLORS["black"])
    s += callout(940, 180, 170, 180, "Program", ["D8 = OUTPUT", "HIGH: LED on", "LOW: LED off", "delay sets timing"])
    s += svg_end("Use a common GND between Arduino and every external component.")
    write_svg(CIRCUITS / "09-arduino-external-led.svg", s)


def c10():
    s = circuit_base("Circuit 10 - Arduino Four-LED Sequential Light", "Arduino pins 4 through 7 independently drive four LEDs, each through a 330 ohm resistor to common ground.", True)
    xs = [430, 590, 750, 910]
    cols = ["#ef5350", "#ffb300", "#43a047", "#2979ff"]
    pins = [220, 265, 310, 355]
    for i, (x, col, pin_y) in enumerate(zip(xs, cols, pins)):
        s += resistor(x - 45, 300, "330")
        s += led(x + 115, 350, col, f"LED {i+1}")
        s += line([(235, pin_y), (300 + i * 18, pin_y), (300 + i * 18, 300), (x - 87, 300)], col, 5)
        s += line([(x + 145, 418), (x + 145, 520)], COLORS["black"], 5)
    s += line([(545, 520), (1055, 520), (1055, 545), (235, 545)], COLORS["black"], 6)
    s += callout(955, 145, 165, 150, "Pins", ["D4 -> LED 1", "D5 -> LED 2", "D6 -> LED 3", "D7 -> LED 4"])
    s += svg_end("The LEDs are separate parallel output branches; software creates the running-light sequence.")
    write_svg(CIRCUITS / "10-arduino-four-led-chaser.svg", s)


def circuits_readme():
    lines = [
        "# Session 1 Circuit Diagram Index",
        "",
        "All circuit images are editable SVG files. Wiring tables and calculations",
        "are in [Ten Practical Breadboard Circuits](../04-ten-practical-circuits.md).",
        "",
    ]
    files = [
        ("01-single-led-closed.svg", "Single LED closed circuit"),
        ("02-button-open-closed.svg", "Button open/closed circuit"),
        ("03-two-led-series.svg", "Two LEDs in series"),
        ("04-two-led-parallel.svg", "Two LED branches in parallel"),
        ("05-series-resistors-led.svg", "Series resistors with LED"),
        ("06-button-active-buzzer.svg", "Button-controlled active buzzer"),
        ("07-button-led-buzzer-parallel.svg", "LED and buzzer in parallel"),
        ("08-rgb-color-mixer.svg", "RGB color mixer"),
        ("09-arduino-external-led.svg", "Arduino external LED"),
        ("10-arduino-four-led-chaser.svg", "Arduino four-LED chaser"),
    ]
    for filename, caption in files:
        lines.extend([f"## {caption}", "", f"![{caption}]({filename})", ""])
    (CIRCUITS / "README.md").write_text("\n".join(lines), encoding="utf-8")


def main():
    DIAGRAMS.mkdir(parents=True, exist_ok=True)
    CIRCUITS.mkdir(parents=True, exist_ok=True)
    concept_breadboard()
    concept_led_rgb()
    concept_circuit_types()
    concept_multimeter()
    concept_arduino_pin_map()
    concept_arduino_blocks()
    for make in (c1, c2, c3, c4, c5, c6, c7, c8, c9, c10):
        make()
    circuits_readme()
    print(f"Generated 6 concept diagrams and 10 circuit diagrams in {SESSION}")


if __name__ == "__main__":
    main()
