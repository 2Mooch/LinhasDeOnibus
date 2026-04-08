#include "../include/RotaOnibus.h"
#include <iostream>
#include <algorithm>
#include <cctype>

No::No(const std::string& n) : nome(n), anterior(nullptr), proximo(nullptr) {}

RotaOnibus::RotaOnibus() : inicio(nullptr), fim(nullptr), quantidade(0) {}

RotaOnibus::~RotaOnibus() {
    while (!estaVazia()) {
        removerPrimeiraParada();
    }
}

bool RotaOnibus::estaVazia() const {
    return inicio == nullptr;
}

std::string RotaOnibus::paraMinusculo(std::string texto) const {
    std::transform(texto.begin(), texto.end(), texto.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return texto;
}

void RotaOnibus::inserirNoInicio(const std::string& nome) {
    No* novo = new No(nome);

    if (estaVazia()) {
        inicio = fim = novo;
    } else {
        novo->proximo = inicio;
        inicio->anterior = novo;
        inicio = novo;
    }

    quantidade++;
}

void RotaOnibus::inserirNoFim(const std::string& nome) {
    No* novo = new No(nome);

    if (estaVazia()) {
        inicio = fim = novo;
    } else {
        fim->proximo = novo;
        novo->anterior = fim;
        fim = novo;
    }

    quantidade++;
}

void RotaOnibus::inserirPorPosicao(const std::string& nome, int posicao) {
    if (posicao < 1 || posicao > quantidade + 1) return;

    if (posicao == 1) {
        inserirNoInicio(nome);
        return;
    }

    if (posicao == quantidade + 1) {
        inserirNoFim(nome);
        return;
    }

    No* novo = new No(nome);
    No* atual = inicio;

    for (int i = 1; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    novo->anterior = atual;
    atual->proximo->anterior = novo;
    atual->proximo = novo;

    quantidade++;
}

void RotaOnibus::removerPrimeiraParada() {
    if (estaVazia()) return;

    No* temp = inicio;

    if (inicio == fim) {
        inicio = fim = nullptr;
    } else {
        inicio = inicio->proximo;
        inicio->anterior = nullptr;
    }

    delete temp;
    quantidade--;
}

void RotaOnibus::removerUltimaParada() {
    if (estaVazia()) return;

    No* temp = fim;

    if (inicio == fim) {
        inicio = fim = nullptr;
    } else {
        fim = fim->anterior;
        fim->proximo = nullptr;
    }

    delete temp;
    quantidade--;
}

void RotaOnibus::buscarPorNome(const std::string& trecho) const {
    std::string busca = paraMinusculo(trecho);
    No* atual = inicio;

    while (atual != nullptr) {
        std::string nomeAtual = paraMinusculo(atual->nome);

        if (nomeAtual.find(busca) != std::string::npos) {
            std::cout << atual->nome << std::endl;
        }

        atual = atual->proximo;
    }
}

void RotaOnibus::listarRotaIda() const {
    No* atual = inicio;
    int i = 1;

    while (atual != nullptr) {
        std::cout << i++ << ". " << atual->nome << std::endl;
        atual = atual->proximo;
    }
}

void RotaOnibus::listarRotaInversa() const {
    No* atual = fim;
    int i = quantidade;

    while (atual != nullptr) {
        std::cout << i-- << ". " << atual->nome << std::endl;
        atual = atual->anterior;
    }
}

int RotaOnibus::contarParadas() const {
    return quantidade;
}
