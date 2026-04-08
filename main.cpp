#include <iostream>
#include <limits>
#include "include/RotaOnibus.h"

using namespace std;

void menu() {
    cout << "\n1. Inserir início\n2. Inserir fim\n3. Inserir posição\n";
    cout << "4. Remover início\n5. Remover fim\n";
    cout << "6. Buscar\n7. Listar ida\n8. Listar inversa\n9. Contar\n0. Sair\n";
}

int main() {
    RotaOnibus rota;
    int op;
    string nome;
    int pos;

    do {
        menu();
        cin >> op;
        cin.ignore();

        switch (op) {
            case 1:
                getline(cin, nome);
                rota.inserirNoInicio(nome);
                break;
            case 2:
                getline(cin, nome);
                rota.inserirNoFim(nome);
                break;
            case 3:
                getline(cin, nome);
                cin >> pos;
                rota.inserirPorPosicao(nome, pos);
                break;
            case 4:
                rota.removerPrimeiraParada();
                break;
            case 5:
                rota.removerUltimaParada();
                break;
            case 6:
                getline(cin, nome);
                rota.buscarPorNome(nome);
                break;
            case 7:
                rota.listarRotaIda();
                break;
            case 8:
                rota.listarRotaInversa();
                break;
            case 9:
                cout << rota.contarParadas() << endl;
                break;
        }
    } while (op != 0);

    return 0;
}
