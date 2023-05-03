#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void elf(int elf_num) { 
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Elf " << elf_num << " is working on some toys" << endl;
    this_thread::sleep_for(chrono::seconds(4));
    cout << "Elf " << elf_num << " needs help from Santa" << endl;
}

void reindeer(int reindeer_num) { 
    string vacations[] = {"Cape Verde", "Bahamas", "Mexico", "Zanzibar", "Cape Town", "Livingstone", "California", "Samfya Beach", "Madagasca"};
    int vacation_idx = reindeer_num - 1;
    cout << "Reindeer " << reindeer_num << " is back from " << vacations[vacation_idx] << endl;
    this_thread::sleep_for(chrono::seconds(4));
}

int main() {
    int num_elves = 6;
    int num_reindeer = 9;

    int elves_helped = 0;
    int reindeer_back = 0;
    bool all_reindeer_back = false;

    while (!all_reindeer_back) {
        // Elves need help from Santa
        for (int i = 1; i <= num_elves; i++) {
            elf(i);
            elves_helped++;
            if (elves_helped % 3 == 0) {
                cout << "Santa is helping elves " << i-2 << " to " << i << endl;
                cout << "Santa has gone back to sleep" << endl;
                this_thread::sleep_for(chrono::seconds(6));
                reindeer_back++;
                if (reindeer_back <= num_reindeer) {
                    reindeer(reindeer_back);
                }
                else {
                    all_reindeer_back = true;
                    break;
                }
            }
        }

        if (all_reindeer_back) {
            cout << "Jolly good show, all my 9 reindeers are back from their vacations" << endl;
              this_thread::sleep_for(chrono::seconds(2));
            cout << "Ho ho ho it is that time of year again!" << endl;
              this_thread::sleep_for(chrono::seconds(2));
              cout << "Santas Elves have placed all 9 reindeers on the sleigh!" << endl;
              this_thread::sleep_for(chrono::seconds(2));
            cout << "Santa is getting in his sleigh!" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            for (string country : {"China", "America", "Zambia", "Cuba", "Brazil", "Japan", "India", "Jamaica "}) {
                cout << "Santa is flying over " << country << "!" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
            cout << "Santa is back at the North Pole!" << endl;
            cout << "Santa has gone back to his year long sleep" << endl;

        }
    }

    return 0;
}

