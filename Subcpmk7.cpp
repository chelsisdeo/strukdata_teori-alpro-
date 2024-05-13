#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Struktur data untuk hewan
struct Animal {
    string name;
    int arrivalTime; // Waktu kedatangan
};

class AnimalShelter {
private:
    queue<Animal> dogs; // Antrian anjing
    queue<Animal> cats; // Antrian kucing
    int timestamp; // Waktu saat hewan masuk

public:
    AnimalShelter() {
        timestamp = 0;
    }

    // Menambahkan hewan ke selter
    void enqueue(string name, string type) {
        Animal newAnimal;
        newAnimal.name = name;
        newAnimal.arrivalTime = timestamp++;

        if (type == "dog") {
            dogs.push(newAnimal);
        } else if (type == "cat") {
            cats.push(newAnimal);
        }
    }

    // Mengambil hewan tertua (berdasarkan waktu kedatangan)
    Animal dequeueAny() {
        if (dogs.empty() && cats.empty()) {
            cout << "Selter kosong!" << endl;
            return {"", -1};
        }

        if (dogs.empty()) {
            return dequeueCat();
        } else if (cats.empty()) {
            return dequeueDog();
        }

        if (dogs.front().arrivalTime < cats.front().arrivalTime) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
    }

    // Mengambil anjing tertua
    Animal dequeueDog() {
        if (dogs.empty()) {
            cout << "Tidak ada anjing di selter!" << endl;
            return {"", -1};
        }
        Animal oldestDog = dogs.front();
        dogs.pop();
        return oldestDog;
    }

    // Mengambil kucing tertua
    Animal dequeueCat() {
        if (cats.empty()) {
            cout << "Tidak ada kucing di selter!" << endl;
            return {"", -1};
        }
        Animal oldestCat = cats.front();
        cats.pop();
        return oldestCat;
    }
};

int main() {
    AnimalShelter shelter;

    // Contoh penggunaan
    shelter.enqueue("Buddy", "dog");
    shelter.enqueue("Whiskers", "cat");
    shelter.enqueue("Max", "dog");
    shelter.enqueue("Luna", "cat");

    Animal adoptedPet = shelter.dequeueAny();
    cout << "Hewan yang diadopsi: " << adoptedPet.name << endl;

    Animal adoptedDog = shelter.dequeueDog();
    cout << "Anjing yang diadopsi: " << adoptedDog.name << endl;

    Animal adoptedCat = shelter.dequeueCat();
    cout << "Kucing yang diadopsi: " << adoptedCat.name << endl;

    return 0;
}
