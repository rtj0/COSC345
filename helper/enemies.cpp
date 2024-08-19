#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

// weapon class
class Enemies
{
public:
    // constructor
    Enemies()
    {
        // seed
        srand(static_cast<unsigned int>(time(0)));

        // weapons
        (1, "Plasma Rifle", "A high-energy weapon that fires concentrated plasma bolts.", 45, "Rare", true, false);
        (2, "Laser Pistol", "A compact, high-precision laser pistol ideal for close combat.", 25, "Common", true, false);
        (3, "Icicle", "A grenade that releases a freezing gas upon hit, freezing enemies.", 35, "Uncommon", false, true);
        (4, "Sonic Blaster", "Emits sound waves capable of shattering solid objects.", 40, "Rare", true, true);
        (5, "Electro Blade", "A sword infused with electrical energy, delivering a shock with each strike.", 30, "Uncommon", false, true);
        (6, "Ion Cannon", "A heavy-duty weapon that fires a massive ion beam, effective against armored targets.", 60, "Epic", true, true);
        (7, "Pulse Rifle", "Fires rapid bursts of energy pulses, excellent for crowd control.", 38, "Common", true, true);
        (8, "Nano Sword", "A blade composed of nanobots, able to cut through virtually anything.", 50, "Epic", false, false);
        (9, "Graviton Hammer", "A weapon that manipulates gravity to deliver devastating blows.", 55, "Legendary", false, true);
        (10, "Neutron Bomb", "A bomb that releases neutron radiation, lethal to organic life.", 100, "Legendary", true, false);
        (11, "Crysknife", "A sacred knife made from the tooth of a sandworm. Deadly in close combat.", 50, "Rare", false, false);
        (12, "Maula Pistol", "A small, easily concealable projectile weapon used by assassins.", 25, "Common", false, false);
        (13, "Lasgun", "A powerful beam weapon capable of cutting through almost any material.", 60, "Uncommon", false, false);
        (14, "Spice Grenade", "An explosive that disperses spice particles, causing hallucinations and disorientation.", 50, "Epic", true, true);
        (15, "Gom Jabbar", "A needle-like weapon that delivers a lethal poison. Used in specific assassination rituals.", 100, "Legendary", false, false);
        (16, "Hunter-Seeker", "A remote-controlled assassination device that seeks out its target with precision.", 45, "Epic", true, false);
        (17, "Stunner", "A non-lethal weapon used to incapacitate enemies, commonly used by law enforcement.", 20, "Common", false, true);
        (18, "Spice-Enhanced Blade", "A blade tempered with the essence of spice, increasing its sharpness and durability.", 55, "Epic", false, true);
        (19, "Shai-Hulud's Tooth", "A weapon made from a sandworm tooth, infused with the power of the desert.", 70, "Legendary", false, false);
        (20, "Weirding Module", "A sound-based weapon that amplifies the voice of its user to deliver devastating sonic attacks.", 70, "Legendary", true, true);
        (21, "Sand Compactor", "A tool-turned-weapon that uses compressed sand to create projectiles.", 30, "Uncommon", true, false);
        (22, "Fremen Hook", "A specialized tool used by the Fremen to ride sandworms, can also be used as a weapon.", 40, "Rare", false, true);
        (23, "Injector Dart", "A small dart that can deliver a variety of substances, from tranquilizers to lethal toxins.", 35, "Uncommon", true, true);
        (24, "Spice Harvester's Wrench", "A large, heavy tool used in spice harvesting, repurposed as a weapon.", 45, "Common", true, false);
        (25, "Glowglobe Bomb", "A light-emitting device that can be overloaded to explode, blinding enemies temporarily.", 20, "Uncommon", true, true);
        (26, "Stilgar's Blade", "A unique knife belonging to the legendary Fremen leader Stilgar, revered for its history.", 55, "Epic", false, false);
        (27, "Sardaukar Blade", "A razor-sharp sword used by the elite Sardaukar troops, feared across the galaxy.", 65, "Rare", false, false);
    };
};