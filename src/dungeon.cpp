#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <queue>
#include <set>
#include <map>

class Room
{
public:
    // Each direction
    Room *north;
    Room *south;
    Room *west;
    Room *east;
    std::string content; // Should be converted to RoomType after that is created

    Room() : north(nullptr), south(nullptr), west(nullptr), east(nullptr), content("Empty room") {}
};

class Dungeon
{
private:
    std::vector<Room *> rooms;
    std::mt19937 rng; // allow for seeds (if we want later on)

    Room *generateRoom()
    {
        Room *newRoom = new Room();
        rooms.push_back(newRoom);
        return newRoom;
    }

    void linkRooms(Room *room1, Room *room2, int direction)
    {
        switch (direction)
        {
        case 0: // North
            room1->north = room2;
            room2->south = room1;
            break;
        case 1: // South
            room1->south = room2;
            room2->north = room1;
            break;
        case 2: // West
            room1->west = room2;
            room2->east = room1;
            break;
        case 3: // East
            room1->east = room2;
            room2->west = room1;
            break;
        }
    }

public:
    Dungeon() : rng(std::time(0)) {}

    ~Dungeon()
    { // Deconstructor
        for (Room *room : rooms)
        {
            delete room;
        }
    }

    Room *generateFloor(int numRooms)
    {
        if (numRooms <= 0)
        {
            return nullptr;
        }

        Room *startRoom = generateRoom();

        for (int i = 1; i < numRooms; ++i)
        {
            Room *existingRoom;
            int direction;

            do
            {
                existingRoom = rooms[std::uniform_int_distribution<>(0, rooms.size() - 1)(rng)];
                direction = std::uniform_int_distribution<>(0, 3)(rng);
            } while (
                (direction == 0 && existingRoom->north != nullptr) ||
                (direction == 1 && existingRoom->south != nullptr) ||
                (direction == 2 && existingRoom->west != nullptr) ||
                (direction == 3 && existingRoom->east != nullptr)); // Making sure it is not overwriting

            Room *newRoom = generateRoom();
            linkRooms(existingRoom, newRoom, direction); // linking rooms
        }
        return rooms[std::uniform_int_distribution<>(0, rooms.size() - 1)(rng)];
    }

    void traverseAndPrint(Room *startRoom)
    { // Traverse the floor (used for testing or can create floor maps)
        if (startRoom == nullptr)
            return;

        std::queue<std::pair<Room *, std::pair<int, int>>> q;
        std::map<std::pair<int, int>, Room *> visited;

        q.push({startRoom, {0, 0}});
        visited[{0, 0}] = startRoom;

        while (!q.empty()){
            auto [currentRoom, coords] = q.front();
            q.pop();

            int x = coords.first;
            int y = coords.second;
            std::cout << "Room at (" << x << ", " << y << "): " << currentRoom->content << std::endl;

            if (currentRoom->north && visited.find({x, y + 1}) == visited.end())
            {
                q.push({currentRoom->north, {x, y + 1}});
                visited[{x, y + 1}] = currentRoom->north;
            }
            if (currentRoom->south && visited.find({x, y - 1}) == visited.end())
            {
                q.push({currentRoom->south, {x, y - 1}});
                visited[{x, y - 1}] = currentRoom->south;
            }
            if (currentRoom->east && visited.find({x + 1, y}) == visited.end())
            {
                q.push({currentRoom->east, {x + 1, y}});
                visited[{x + 1, y}] = currentRoom->east;
            }
            if (currentRoom->west && visited.find({x - 1, y}) == visited.end())
            {
                q.push({currentRoom->west, {x - 1, y}});
                visited[{x - 1, y}] = currentRoom->west;
            }
        }
    }
};

int main()
{ // Example how to use
    Dungeon dungeon;
    int numRooms = 20;
    Room *startRoom = dungeon.generateFloor(numRooms);

    std::cout << "Dungeon generated with 20 rooms." << std::endl;

    dungeon.traverseAndPrint(startRoom); // layout checking

    return 0;
}