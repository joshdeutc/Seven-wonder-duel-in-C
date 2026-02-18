# Seven Wonders Duel

A C++ implementation of the board game **7 Wonders Duel**, developed as part of the LO21 course at the Universite de Technologie de Compiegne (UTC).

The project includes both a **console** version and a **graphical interface** built with Qt 6.

## Features

- Full implementation of the 3 ages of the game
- 66 building cards across 7 categories (raw materials, manufactured goods, military, civic, scientific, commercial, guilds)
- 12 wonders with unique effects
- 10 progress tokens
- 3 victory conditions: military supremacy, scientific supremacy, civilian victory
- Resource management with production, trading, and chain-building mechanics
- AI opponent (random strategy)
- 3 game modes: Player vs Player, Player vs AI, AI vs AI

## Project structure

```
Seven-wonder-duel-in-C/
├── console/                # Console version (CMake)
│   ├── main.cpp            # Entry point
│   ├── carte_bat_merv.*    # Card class hierarchy (buildings, wonders, tokens)
│   ├── jeu.*               # Game singleton (card database)
│   ├── joueur.*            # Player class (resources, AI)
│   ├── partie.*            # Game session (flow, victory)
│   ├── plateau.*           # Board state (ages, military, tokens)
│   ├── utils.*             # Utilities
│   └── wondersException.*  # Custom exceptions
│
├── 7WondersDuel/           # Qt GUI version
│   ├── 7WondersDuel.pro    # Qt project file
│   ├── main.cpp            # Qt entry point
│   ├── mainwindow.*        # Main window (menu, game modes)
│   ├── batimentwidget.*    # Building card widget
│   ├── merveillewidget.*   # Wonder selection widget
│   ├── jetonprogreswidget.*# Progress token widget
│   ├── a_propos.*          # About dialog
│   ├── resource.qrc        # Qt resource file
│   ├── batiments/          # Building card images (Age 1-3)
│   ├── merveilles/         # Wonder images
│   ├── jetons/             # Progress token images
│   ├── images/             # Logo and misc assets
│   └── formes/             # UI shape templates
│
├── docs/                   # Documentation
│   ├── uml/                # UML diagrams
│   ├── rapports/           # Project reports
│   └── regles/             # Game rules (FR)
│
├── testAffichageCarte/     # Card display test app
├── CMakeLists.txt          # Root CMake config (console)
└── .gitignore
```

## Build

### Console version (CMake)

```bash
cmake -B build
cmake --build build
./build/projet_lo21
```

### GUI version (Qt 6)

Open `7WondersDuel/7WondersDuel.pro` in Qt Creator (requires Qt 6.7+ with MinGW), then build and run from the IDE.

Or from the command line (with Qt and qmake in PATH):

```bash
cd 7WondersDuel
qmake
make
```

## Technologies

- **C++14** (console) / **C++17** (GUI)
- **Qt 6.7** with Qt Widgets
- **CMake 3.27+**

## Game rules

The game follows the official 7 Wonders Duel rules. A French PDF of the rules is available in `docs/regles/`.
