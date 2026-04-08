# Sistema de Itinerário de Ônibus

## Descrição
Este projeto implementa um sistema de gerenciamento de rotas de ônibus em C++ utilizando listas encadeadas. O sistema permite cadastrar, remover, buscar e listar paradas, ajudando a manter a ordem correta do itinerário.

---

## Funcionalidades
- Inserir parada no início
- Inserir parada no fim
- Inserir parada por posição
- Remover primeira parada
- Remover última parada
- Buscar parada por nome (parcial)
- Listar rota completa (ida)
- Listar rota em ordem inversa
- Contar paradas

---

## Estrutura de Dados Utilizada

### Lista Duplamente Encadeada
Foi utilizada uma **lista duplamente encadeada**, onde cada nó possui referência para o próximo e para o anterior.

### Justificativa
Essa estrutura foi escolhida porque:

- Permite navegação em duas direções (ida e volta)
- Facilita a listagem inversa da rota
- Permite remover o último elemento sem percorrer toda a lista
- Facilita inserções em posições intermediárias

### Comparação com outras estruturas

- **Lista simplesmente encadeada:**
  - Não permite navegação inversa eficiente
  - Remoção do último elemento é mais custosa

- **Lista circular:**
  - Pode ser útil em rotas contínuas
  - Não é ideal quando há início e fim bem definidos

### Cenário alternativo
Em uma linha de ônibus circular, uma lista circular seria mais adequada, pois o último ponto se conecta novamente ao primeiro.

---

## Requisitos
- GCC/G++ versão 11 ou superior
- Visual Studio Code com extensão C/C++
- Terminal para execução

---

## Estrutura do Projeto
```text
LinhasDeOnibus/
├── include/
├── src/
├── tests/
├── main.cpp
└── README.md
```

---

## Compilação e Execução

### Compilar
```bash
g++ main.cpp src/RotaOnibus.cpp -o programa
```

### Executar
```bash
./programa
```

---

## Testes

### Compilar
```bash
g++ tests/test.cpp src/RotaOnibus.cpp -o teste
```

### Executar
```bash
./teste
```
