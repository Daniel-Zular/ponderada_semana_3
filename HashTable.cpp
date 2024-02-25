#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class Produto {
public:
    int codigo;
    string nome;
    Produto() : codigo(-1), nome("") {} // Construtor padrão
    Produto(int c, string n) : codigo(c), nome(n) {} // Construtor com parâmetros
};

class HashTable {
private:
    Produto items[MAX_ITEMS];
    int length;

    int getHash(int codigo) const { // Função hash
        return codigo % MAX_ITEMS;
    }

public:
    HashTable() : length(0) { // Construtor
        for (int i = 0; i < MAX_ITEMS; i++) {
            items[i] = Produto();
        }
    }

    void insertItem(Produto produto) { // Insere um produto
        if (length >= MAX_ITEMS) {
            cout << "Tabela cheia, não pode inserir novo item." << endl;
            return; // Evita a inserção se a tabela já está cheia
        }
        int location = getHash(produto.codigo);
        while (items[location].codigo > 0) {
            location = (location + 1) % MAX_ITEMS;
        }
        items[location] = produto;
        length++;
    }

    void retrieveItem(Produto& produto, bool& found) { // Busca um produto
        int location = getHash(produto.codigo);
        found = false;
        while (items[location].codigo != -1 && !found) {
            if (items[location].codigo == produto.codigo) {
                found = true;
                produto = items[location];
            } else {
                location = (location + 1) % MAX_ITEMS;
            }
        }
    }

    void deleteItem(Produto produto) { // Deleta um produto
        int location = getHash(produto.codigo);
        bool found = false;
        while (items[location].codigo != -1 && !found) {
            if (items[location].codigo == produto.codigo) {
                found = true;
                items[location] = Produto(); // Marca como removido
            } else {
                location = (location + 1) % MAX_ITEMS;
            }
        }
        if (found) {
            length--;
        }
    }

    int getLength() const { // Retorna o número de itens na tabela
        return length;
    }

    void print() const { // Imprime todos os produtos na tabela
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i].codigo != -1) {
                cout << "Posição " << i << ": " << items[i].nome << " (Código: " << items[i].codigo << ")" << endl;
            }
        }
    }
};

int main() {
    HashTable tabela;
    bool encontrado;

    // Caso de teste 1: Inserir itens sem colisões
    cout << "Caso de teste 1: Inserir itens sem colisões" << endl;
    tabela.insertItem(Produto(101, "Caneta BIC"));
    cout << "Esperado: 1, Real: " << tabela.getLength() << endl;
    tabela.insertItem(Produto(102, "Papel Sulfite"));
    cout << "Esperado: 2, Real: " << tabela.getLength() << endl;

    // Caso de teste 2: Inserir itens com colisões
    cout << "\nCaso de teste 2: Inserir itens com colisões" << endl;
    tabela.insertItem(Produto(201, "Lápis"));
    tabela.insertItem(Produto(301, "Borracha"));
    cout << "Esperado: 4 (ou mais, se colidir), Real: " << tabela.getLength() << endl;

    // Caso de teste 3: Buscar itens
    cout << "\nCaso de teste 3: Buscar itens" << endl;
    Produto p = Produto(101, "");
    tabela.retrieveItem(p, encontrado);
    if (encontrado) {
        cout << "Caneta BIC encontrado." << endl;
    } else {
        cout << "Caneta BIC não encontrado." << endl;
    }

    // Caso de teste 4: Deletar itens
    cout << "\nCaso de teste 4: Deletar itens" << endl;
    tabela.deleteItem(Produto(101, "Caneta BIC"));
    tabela.retrieveItem(p, encontrado);
    cout << "Após deletar, esperado: não encontrado, Real: ";
    if (!encontrado) {
        cout << "Produto não encontrado." << endl;
    } else {
        cout << "Produto ainda encontrado." << endl;
    }
    cout << "Esperado: 3 (ou menos, se não houver colisões), Real: " << tabela.getLength() << endl;

  // Caso de teste 5: Tentativa de inserção em uma tabela cheia
  cout << "\nCaso de teste 5: Tentativa de inserção em uma tabela cheia" << endl;
  // Preenchendo a tabela até ficar cheia
  while (tabela.getLength() < MAX_ITEMS) {
      tabela.insertItem(Produto(tabela.getLength() + 500, "Produto Extra " + to_string(tabela.getLength())));
  }
  cout << "Tabela cheia com " << tabela.getLength() << " itens." << endl;
  // Tentando adicionar outro item
  Produto overflowProduto(1001, ""); // Cria uma variável para o produto
  tabela.insertItem(overflowProduto); // Tenta inserir o produto na tabela cheia
  tabela.retrieveItem(overflowProduto, encontrado); // Tenta recuperar o produto da tabela
  if (!encontrado) {
      cout << "Não foi possível inserir novo item, tabela cheia." << endl;
  } else {
      cout << "Erro: Foi possível inserir um item em uma tabela cheia." << endl;
  }

    return 0;
}
