#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

// weapon class
class Weapon
{
public:
    // constructor
    Weapon()
    {
        // seed
        srand(static_cast<unsigned int>(time(0)));

        // weapons
        addWeapon(1, "Plasma Rifle", "A high-energy weapon that fires concentrated plasma bolts.", 45, "Rare");
        addWeapon(2, "Laser Pistol", "A compact, high-precision laser pistol ideal for close combat.", 25, "Common");
        addWeapon(3, "Cryo Grenade", "A grenade that releases a freezing gas upon detonation, freezing enemies.", 35, "Uncommon");
        addWeapon(4, "Sonic Blaster", "Emits sound waves capable of shattering solid objects.", 40, "Rare");
        addWeapon(5, "Electro Blade", "A sword infused with electrical energy, delivering a shock with each strike.", 30, "Uncommon");
        addWeapon(6, "Ion Cannon", "A heavy-duty weapon that fires a massive ion beam, effective against armored targets.", 60, "Epic");
        addWeapon(7, "Pulse Rifle", "Fires rapid bursts of energy pulses, excellent for crowd control.", 38, "Common");
        addWeapon(8, "Nano Sword", "A blade composed of nanobots, able to cut through virtually anything.", 50, "Epic");
        addWeapon(9, "Graviton Hammer", "A weapon that manipulates gravity to deliver devastating blows.", 55, "Legendary");
        addWeapon(10, "Neutron Bomb", "A bomb that releases neutron radiation, lethal to organic life.", 100, "Legendary");
        addWeapon(11, "Crysknife", "A sacred knife made from the tooth of a sandworm. Deadly in close combat.", 50, "Rare");
        addWeapon(12, "Maula Pistol", "A small, easily concealable projectile weapon used by assassins.", 25, "Common");
        addWeapon(13, "Lasgun", "A powerful beam weapon capable of cutting through almost any material.", 60, "Uncommon");
        addWeapon(14, "Spice Grenade", "An explosive that disperses spice particles, causing hallucinations and disorientation.", 50, "Epic");
        addWeapon(15, "Gom Jabbar", "A needle-like weapon that delivers a lethal poison. Used in specific assassination rituals.", 100, "Legendary");
        addWeapon(16, "Hunter-Seeker", "A remote-controlled assassination device that seeks out its target with precision.", 45, "Epic");
        addWeapon(17, "Stunner", "A non-lethal weapon used to incapacitate enemies, commonly used by law enforcement.", 20, "Common");
        addWeapon(18, "Spice-Enhanced Blade", "A blade tempered with the essence of spice, increasing its sharpness and durability.", 55, "Epic");
        addWeapon(19, "Shai-Hulud's Tooth", "A weapon made from a sandworm tooth, infused with the power of the desert.", 70, "Legendary");
        addWeapon(20, "Weirding Module", "A sound-based weapon that amplifies the voice of its user to deliver devastating sonic attacks.", 70, "Legendary");
        addWeapon(21, "Sand Compactor", "A tool-turned-weapon that uses compressed sand to create projectiles.", 30, "Uncommon");
        addWeapon(22, "Fremen Hook", "A specialized tool used by the Fremen to ride sandworms, can also be used as a weapon.", 40, "Rare");
        addWeapon(23, "Injector Dart", "A small dart that can deliver a variety of substances, from tranquilizers to lethal toxins.", 35, "Uncommon");
        addWeapon(24, "Spice Harvester's Wrench", "A large, heavy tool used in spice harvesting, repurposed as a weapon.", 45, "Common");
        addWeapon(25, "Glowglobe Bomb", "A light-emitting device that can be overloaded to explode, blinding enemies temporarily.", 20, "Uncommon");
        addWeapon(26, "Stilgar's Blade", "A unique knife belonging to the legendary Fremen leader Stilgar, revered for its history.", 55, "Epic");
        addWeapon(27, "Sardaukar Blade", "A razor-sharp sword used by the elite Sardaukar troops, feared across the galaxy.", 65, "Rare");
    }

    // give random weapon
    int giveRandWeapon()
    {
        int randomIndex = rand() % weaponIds.size();
        return weaponIds[randomIndex];
    }

    // give weapon based on rarity
    int giveRariWeapon(const std::string &rarity)
    {
        std::vector<int> filteredIds;
        for (const auto &weapon : weapons)
        {
            if (weapon.second.rarity == rarity)
            {
                filteredIds.push_back(weapon.first);
            }
        }
        if (!filteredIds.empty())
        {
            int randomIndex = rand() % filteredIds.size();
            return filteredIds[randomIndex];
        }
        return -1;
    }

    // accessors
    std::string getName(int weaponId)
    {
        return weapons[weaponId].name;
    }

    std::string getDescription(int weaponId)
    {
        return weapons[weaponId].description;
    }

    int getDamage(int weaponId)
    {
        return weapons[weaponId].damage;
    }

    std::string getRarity(int weaponId)
    {
        return weapons[weaponId].rarity;
    }

private:
    struct WeaponData
    {
        std::string name;
        std::string description;
        int damage;
        std::string rarity;
    };

    // dictionary to store weapons
    std::unordered_map<int, WeaponData> weapons;
    std::vector<int> weaponIds;

    // add weapons to the dictionary
    void addWeapon(int id, const std::string &name, const std::string &description, int damage, const std::string &rarity)
    {
        weapons[id] = {name, description, damage, rarity};
        weaponIds.push_back(id);
    }
};

// how to use
int main()
{
    Weapon weaponSystem;

    // get a random weapon
    int randWeaponId = weaponSystem.giveRandWeapon();

    // get a rare weapon
    int rareWeaponId = weaponSystem.giveRariWeapon("Epic");

    return 0;
}
