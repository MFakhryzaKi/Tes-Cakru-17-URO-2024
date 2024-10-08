#include<bits/stdc++.h>
using namespace std;

class Robot {
    public:
    string name;
    int HP;
    int Attack;

    virtual void melee_attack(Robot &enemy) {
        int damage = Attack / 2.5;
        cout << name << " Memberikan " << damage << " damage kepada " << enemy.getname() << endl;
        enemy.takedamage(damage);
    }

    virtual void range_attack(Robot &enemy) {
        int damage = rand() % Attack + 1;
        cout << name << " Memberikan " << damage << " damage kepada " << enemy.getname() << endl;
        enemy.takedamage(damage);
    }

    int takedamage(int x) {
        HP -= x;
        if (HP < 0) {
            HP = 0;
        } 
    }

    bool alive() {
        return HP > 0; 
    }

    int currentHP () {
        return HP;
    }

    string getname() {
        return name;
    }
};

class Player1 : public Robot {
    public :

    void showstatus() {
        cout << name << ": " << HP << endl;
    }
};

class Player2 : public Robot {
    public :

    void showstatus() {
        cout << name << ": " << HP << endl;
    }
};

class Battle {
    private :
    Player1 player1;
    Player2 player2;

    public :

    Battle(Player1 p1, Player2 p2) : player1(p1), player2(p2) {}

    void start_fight() {
        int metode_serangan;
        cout << "Pertandingan dimulai" << endl;

        while(player1.alive() && player2.alive()) {
            cout << "HP tersisa: " << endl;
            player1.showstatus();
            player2.showstatus();

            while(true) {
                cout << "Giliran Player 1" << endl;
                cout << "Pilih metode serangan: " << endl << "1. melee attack" << endl << "2. ranged attack" << endl;
                cin >> metode_serangan;
                if(metode_serangan == 1) {
                    player1.melee_attack(player2);
                    break;
                }
                else if(metode_serangan == 2) {
                    player1.range_attack(player2);
                    break;
                }
                else {
                    cout << "METODE SERANGAN TIDAK TERSEDIA" << endl;
                }
            }

            if(player2.currentHP() == 0) {
                cout << player2.getname() << " telah dikalahkan" << endl;
                cout << "Pemenangnya adalah " << player1.getname() << endl;
                break;
            }

            while(true) {
                cout << "Giliran Player 2" << endl;
                cout << "Pilih metode serangan: " << endl << "1. melee attack" << endl << "2. ranged attack" << endl;
                cin >> metode_serangan;
                if(metode_serangan == 1) {
                    player2.melee_attack(player1);
                    break;
                }
                else if(metode_serangan == 2) {
                    player2.range_attack(player1);
                    break;
                }
                else {
                    cout << "METODE SERANGAN TIDAK TERSEDIA" << endl;
                }
            }

            if(player1.currentHP() == 0) {
                cout << player1.getname() << " telah dikalahkan" << endl;
                cout << "Pemenangnya adalah " << player2.getname() << endl;
                break;
            }

            cout << endl << "__________________________" << endl;
        }
    }
};


int main () {
    srand(time(NULL));
    Robot robo1, robo2, robo3, robo4;
    Player1 player1;
    Player2 player2;

    robo1.name = "C_Bot";
    robo1.Attack = 45;
    robo1.HP = 100;

    robo2.name = "Python_Bot";
    robo2.Attack = 70;
    robo2.HP = 75;

    robo3.name = "Java_Bot";
    robo3.Attack = 40;
    robo3.HP = 110;

    robo4.name = "Pascal_Bot";
    robo4.Attack = 30;
    robo4.HP = 135;

    string jawaban;
    cout << "Apakah Kamu Ingin Bermain?" << endl << "1. YA" << endl << "2. TIDAK" << endl;
    cin >> jawaban;
    if(jawaban != "1") {
        cout << "Baiklah, mungkin lain kali :(" << endl;
        return 0;
    }

    cout << endl;
    cout << "Silakan Pilih Robot Anda" << endl << endl;
    cout << "1. " << robo1.name << endl << "Attack: " << robo1.Attack << endl << "HP: " << robo1.HP << endl << endl;
    cout << "2. " << robo2.name << endl << "Attack: " << robo2.Attack << endl << "HP: " << robo2.HP << endl << endl;
    cout << "3. " << robo3.name << endl << "Attack: " << robo3.Attack << endl << "HP: " << robo3.HP << endl << endl;
    cout << "4. " << robo4.name << endl << "Attack: " << robo4.Attack << endl << "HP: " << robo4.HP << endl << endl;
    cout << "Player 1: ";
    cin >> jawaban;
    if(jawaban == "1") {
        player1.name = robo1.name;
        player1.Attack = robo1.Attack;
        player1.HP = robo1.HP;
    }
    else if(jawaban == "2") {
        player1.name = robo2.name;
        player1.Attack = robo2.Attack;
        player1.HP = robo2.HP;
    }
    else if(jawaban == "3") {
        player1.name = robo3.name;
        player1.Attack = robo3.Attack;
        player1.HP = robo3.HP;
    }
    else {
        player1.name = robo4.name;
        player1.Attack = robo4.Attack;
        player1.HP = robo4.HP;
    }
    cout << endl;

    cout << "Player 2: ";
    cin >> jawaban;
    if(jawaban == "1") {
        player2.name = robo1.name;
        player2.Attack = robo1.Attack;
        player2.HP = robo1.HP;
    }
    else if(jawaban == "2") {
        player2.name = robo2.name;
        player2.Attack = robo2.Attack;
        player2.HP = robo2.HP;
    }
    else if(jawaban == "3") {
        player2.name = robo3.name;
        player2.Attack = robo3.Attack;
        player2.HP = robo3.HP;
    }
    else {
        player2.name = robo4.name;
        player2.Attack = robo4.Attack;
        player2.HP = robo4.HP;
    }

    Battle battle(player1, player2);
    battle.start_fight();
}





// Robot robo1, robo2;
    // cout << "Player 1" << endl;
    // cout << "Create a name for your robot: ";
    // cin >> robo1.name;
    // cout << "Insert your robot's HP: ";
    // cin >> robo1.HP;
    // cout << "Insert your robot's damage: ";
    // cin >> robo1.damage;

    // cout << "Player 2" << endl;
    // cout << "Create a name for your robot: ";
    // cin >> robo2.name;
    // cout << "Insert your robot's HP: ";
    // cin >> robo2.HP;
    // cout << "Insert your robot's damage: ";
    // cin >> robo2.damage;

    // cout << endl;

    // cout << "Robot inherited successfully" << endl << endl;
    // cout << "Player 1" << endl;
    // cout << "Robot Name: " << robo1.name << endl;
    // cout << "HP: " << robo1.HP << endl;
    // cout << "damage: " << robo1.damage << endl;

    // cout << endl;

    // cout << "Robot inherited successfully" << endl;
    // cout << "Player 2" << endl;
    // cout << "Robot Name: " << robo2.name << endl;
    // cout << "HP: " << robo2.HP << endl;
    // cout << "damage: " << robo2.damage << endl;