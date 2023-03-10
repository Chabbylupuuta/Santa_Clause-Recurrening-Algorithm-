# Santa_Clause-Recurrening-Algorithm-
This was a class assignment and I aced it

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void elf(int elf_num) {
    cout << "Elf " << elf_num << " is working" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Elf " << elf_num << " needs help from Santa" << endl;
}

void reindeer(int reindeer_num) {
    cout << "Reindeer " << reindeer_num << " is back" << endl;
}

int main() {
    int num_elves = 6;
    int num_reindeer = 9;

    int elves_helped = 0;
    // Elves need help from Santa
    for (int i = 1; i <= num_elves; i++) {
        elf(i);
        elves_helped++;
        if (elves_helped % 3 == 0) {
            cout << "Santa is helping elves " << i-2 << " to " << i << endl;
            this_thread::sleep_for(chrono::seconds(4));
            elves_helped = 0;
        }
    }

    // Reindeers are back
    int reindeer_back = 0;
    while (reindeer_back < num_reindeer) {
        reindeer_back++;
        reindeer(reindeer_back);
        if (reindeer_back == num_reindeer) {
            cout << "Ho ho ho it is that time of year again!" << endl;
            cout << "Santa is getting in his sleigh!" << endl;
            for (string country : {"China", "America", "Zambia", "Cuba", "Brazil", "Japan", "India", "North Pole"}) {
                cout << "Santa is flying over " << country << "!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
            cout << "Santa is back at the North Pole!" << endl;
        } else if (reindeer_back % 9 == 0) {
            cout << "Santa is preparing his sleigh for the next delivery" << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
    }

    return 0;
}
