#ifndef ROTA_ONIBUS_H
#define ROTA_ONIBUS_H

#include <string>

struct No {
    std::string nome;
    No* anterior;
    No* proximo;

    No(const std::string& n);
};

class RotaOnibus {
private:
    No* inicio;
    No* fim;
    int quantidade;

    std::string paraMinusculo(std::string texto) const;

public:
    RotaOnibus();
    ~RotaOnibus();

    bool estaVazia() const;

    void inserirNoInicio(const std::string& nome);
    void inserirNoFim(const std::string& nome);
    void inserirPorPosicao(const std::string& nome, int posicao);

    void removerPrimeiraParada();
    void removerUltimaParada();

    void buscarPorNome(const std::string& trecho) const;
    void listarRotaIda() const;
    void listarRotaInversa() const;
    int contarParadas() const;
};

#endif
