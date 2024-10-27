#include<bits/stdc++.h>
using namespace std;

char petak[100][100];
int poin = 0;
int counter = 0;
bool visited[100][100];


void hancurkan(int r, int c, char nilai) {
    if(visited[r][c]) {
        return;
    }

    if(!visited[r][c]) {
        visited[r][c] = true;
    }

    if(r < 1 || r > 10 || c < 1 || c > 10) {
        return;
    }
    
    if(petak[r][c] == nilai) {
        counter++;
        hancurkan(r+1, c, nilai);
        hancurkan(r-1, c, nilai);
        hancurkan(r, c+1, nilai);
        hancurkan(r, c-1, nilai);
        petak[r][c] = 'X';
    }

}

int main() {
    srand(time(NULL));

    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            petak[i][j] = rand() % 5 + 48;
            cout << petak[i][j] << ' ';
        }
        cout << endl;
    }

    int idx = 1;

    while(idx <= 3) {
        counter = 0;
        memset(visited, 0, sizeof(visited));
        cout << "Pilih petak yang akan kamu hancurkan!" << endl;
        int r, c;
        cin >> r >> c;

        if(r < 1 || r > 10 || c < 1 || c > 10) {
            cout << "Petak tidak valid, pilih petak yang lain!" << endl;
            continue;
        }
        else if(petak[r][c] == 'X') {
            cout << "Petak sudah dihancurkan, pilih petak yang lain!" << endl;
            continue;
        }
        
        hancurkan(r, c, petak[r][c]);
        poin += counter*(counter+1);
        cout << "Anda menghancurkan petak " << r << " " << c << " dan mendapat " << counter*(counter+1) << " poin! Poin total anda sekarang adalah " << poin << " poin" << endl;
        
        idx++;

        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++) {
                cout << petak[i][j] << ' ';
            }
            cout << endl;
        }
    }

    cout << "Selamat! anda mendapatkan " << poin << " poin" << endl;
    cout << "Permainan Selesai!" << endl;
}