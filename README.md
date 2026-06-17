<div align="center">

# 🎮 so_long

**A small 2D tile game built from scratch in C with MiniLibX — collect everything, find the exit, count your steps.**

[![Language](https://img.shields.io/badge/C-80.9%25-8E2DE2?style=for-the-badge&logo=c&logoColor=white)](https://github.com/samhq23/so_long)
[![Graphics](https://img.shields.io/badge/MiniLibX-graphics-4A00E0?style=for-the-badge)](https://github.com/42Paris/minilibx-linux)
[![42](https://img.shields.io/badge/42-Project-B57BFF?style=for-the-badge)](https://42.fr)
[![Leaks](https://img.shields.io/badge/Valgrind-0%20leaks-8E2DE2?style=for-the-badge)](#-build--play)

</div>

---

## 📌 What it is

`so_long` is a 2D game from the 42 curriculum, written in C on top of **MiniLibX** — a minimal graphics library that gives you a window, a framebuffer, and raw keyboard/window events, and nothing else. Everything above that (map parsing, rendering, the game loop, collision, win conditions) is hand-built.

The player walks around a tile map, must collect **every** collectible, and can only leave through the exit once the map is clean. Every move is counted and printed.

---

## ✨ Highlights

- 🗺️ **Custom `.ber` map parser** with full validation before anything renders
- 🌊 **Flood-fill reachability check** — guarantees the player can actually reach every collectible and the exit, rejecting impossible maps
- 🎨 Sprite-based **tile renderer** drawing walls, floor, collectibles, player, and exit
- ⌨️ **WASD movement** + `ESC` / window-close to quit, via MiniLibX hooks
- 🔢 Live **move counter** printed to the terminal on every step
- 🧹 Clean teardown — images and the display are freed on exit, **no leaks**

---

## 🕹️ The map format

Maps are plain text with a `.ber` extension, built from five characters:

| Char | Meaning |
|:----:|---------|
| `1` | Wall |
| `0` | Floor (walkable) |
| `P` | Player start (exactly one) |
| `C` | Collectible (one or more) |
| `E` | Exit (exactly one) |

```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

A map is only accepted if it's **rectangular**, **fully walled**, has exactly one `P` and one `E`, at least one `C`, and — crucially — a **valid path** from the player to every collectible and the exit.

---

## 🧠 How it works

The code is split by responsibility:

| File | Job |
|------|-----|
| `map_read.c` | loads the `.ber` file into a 2D grid |
| `map_check.c` / `map_check_utils.c` | shape, wall, and element-count validation |
| `flood_fill.c` / `flood_fill_utils.c` | path-reachability check on a copy of the map |
| `render.c` | draws the tile grid into the MiniLibX window |
| `movement.c` | handles a move, collision, collecting, and the win check |
| `hooks.c` | wires keyboard + window-close events |
| `cleanup.c` | frees images and exits cleanly |

The flood fill is the clever bit: it duplicates the grid and "floods" outward from `P`, marking everything reachable. If any `C` or the `E` is still unreached when the flood finishes, the map is rejected — no game starts on an unwinnable board.

---

## 🚀 Build & play

```bash
git clone https://github.com/samhq23/so_long.git
cd so_long
make

# Launch with any valid map
./so_long maps/map1.ber
```

**Controls:** `W` `A` `S` `D` to move · `ESC` or the window's close button to quit.
Each move prints the running step count to your terminal.

---

## 🗂️ Structure

```
so_long/
├── inc/so_long.h        # structs, key codes, tile size
├── src/                 # parsing, flood fill, render, movement, hooks
├── libft/               # my C standard library
├── ft_printf/           # custom printf
├── textures/            # sprite assets
├── maps/                # sample .ber maps
└── Makefile
```

## 💡 What I took away

MiniLibX hands you almost nothing, which is the point. Building the render loop, event hooks, and a robust map validator on top of a bare framebuffer taught me how a game actually fits together under the hood — and the flood-fill validator was a satisfying reminder that the interesting bugs live in the inputs you didn't expect.

---

<div align="center">

Built by **[Sam](https://github.com/samhq23)** · part of the [42 curriculum](https://github.com/samhq23/42_curriculum)

</div>
