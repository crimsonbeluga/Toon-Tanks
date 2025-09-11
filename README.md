# 🪖 Toon Tanks

A fast-paced survival arena game where you control a tank and battle endless waves of enemy tanks, turrets, and other deadly opponents. Collect power-ups and survive as long as possible.

---

## 📦 Installation / Setup

**Requirements:**
- Unreal Engine 5.5
- No additional dependencies required

**Setup Steps:**
1. Clone or download this repository.
2. Open the `.uproject` file in Unreal Engine via the Epic Games Launcher or Unreal Project Browser.
3. Let Unreal build any missing files if prompted.

---

## ▶️ How to Play

1. Open the main level in the Unreal Editor.
2. Press **Play** to start the game.
3. **Controls:**
   - **WASD** – Move the tank
   - **Mouse** – Aim the turret
   - **Left Mouse Button** – Fire

Your goal is to survive as many waves of enemies as possible while collecting power-ups.

---

## ⚙️ Features

- **Player Tank System**
  - Player-controlled tank pawn with mouse-based turret aiming
  - Smooth movement and rotation using delta time
  - Camera spring arm with follow camera and camera lag

- **Combat & Projectiles**
  - Projectile system with mesh, movement, collision, trail, and hit logic
  - Sound effects and camera shake on firing and impact
  - Damage applied to enemies on collision

- **Health & Death System**
  - Modular health component that tracks damage and calls death logic on zero HP
  - Shared base class for tanks and turrets that handles firing, turret rotation, and death visuals (particles, sound, camera shake)

- **Enemy AI & Towers**
  - AI-controlled turrets that automatically detect and fire at the player
  - Timed fire loop and distance-based targeting behavior
  - Game ends when all towers are destroyed

- **Game Loop & Win Conditions**
  - GameMode class tracks remaining towers, handles win/loss conditions, and controls player input states
  - Disables player input on death and shows win/loss state

- **Hazards**
  - Moving hazard actor (SawTooth) with configurable movement distance and speed on X/Y/Z axes

- **Polish**
  - Projectile trails, hit particles, and death explosions
  - Camera lag on follow camera
  - Sound effects for firing, hits, and destruction
  - Camera shake feedback on weapon fire and impacts

---

## 🧩 Architecture Notes

**Core Classes:**
- `ATank` — Player-controlled tank pawn. Handles input, aiming, movement, and firing.
- `ATower` — AI-controlled turret enemy. Automatically tracks and fires at player.
- `ABasePawn` — Shared base class for tanks and towers. Provides firing, turret rotation, and death logic.
- `AProjectile` — Projectile actor. Applies damage, spawns VFX/SFX, and destroys itself on impact.
- `UHealthComponent` — Modular health component that tracks damage and calls `ActorDied` on zero HP.
- `AToonTanksGameMode` — Central game manager. Tracks remaining towers, handles win/loss conditions, and controls player input states.
- `AToonTanksPlayerController` — Custom controller class to enable/disable player input during game start/end.
- `ASawTooth` — Moving hazard actor with back-and-forth interpolation movement.

This modular class setup makes the project easy to expand with new enemies, hazards, or gameplay systems.

---

## 🤝 Contributing

If collaborating on this project, follow these guidelines:

- **Branch naming:**  
  - `feature/<feature-name>` for new features  
  - `fix/<bug-name>` for bug fixes

- **Commit messages:**  
  - Use [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)  
    - Examples: `feat: add turret AI`, `fix: resolve projectile collision bug`

- **Workflow:**  
  - Create a branch → commit changes → open a pull request → request review

---

## 👥 Credits

- **Logan Green** — Programmer / Designer  
- **Tools Used:** Unreal Engine 5.5, Premiere Pro

---

## 📄 License

All rights reserved.  
This project and its content may not be used, copied, or distributed without explicit permission.

---

## 📎 Download

A downloadable build will be added here once the game reaches a stable state.
