//INCLUDING BUILT-IN LIBRARIES...
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class Locacao {
    private: 
        int codigoDoCliente; 
    public: 
        int codigoLocacao;
        int dataDaRetirada;
        int dataDaDevolucao;
        int quantidadeDeOcupantes;
        bool seguro;

        //? Funcção que vai ser chamada de primeira, para registrar todas as variaveis publicas
        Locacao(int codigoDoCliente_, int dataDaRetirada_, int dataDaDevolucao_, int quantidadeDeOcupantes_, bool seguro_) {
            codigoDoCliente = codigoDoCliente_;
            dataDaRetirada = dataDaRetirada_;
            dataDaDevolucao = dataDaDevolucao_;
            quantidadeDeOcupantes = quantidadeDeOcupantes_;
            seguro = seguro_;

            srand(time(0));
            codigoLocacao = rand(); 
        }

        //? Funcção principal que retorna a quantidade de diárias
        int criarLocacao() {
            int horasAtuais;
            cout << "Ola caro cliente, ";
            cout << "quantas horas são? [24h]: ";
            cin >> horasAtuais;

            if (!((horasAtuais > 8) && (horasAtuais < 18))) {
                cout << "Desculpe o encomodo, porém estamos fechados" << endl;
                return 0;
            }

            if (horasAtuais < 12) 
                cout << "Bom dia!" << endl;
            else 
                cout << "Boa tarde!" << endl;

            return 1;
        }

        //?
        void listar() {
            cout << "Codigo da locação -> " << codigoLocacao << endl;
            cout << "Codigo do cliente -> " << codigoDoCliente << endl;
            cout << "Data da retirada -> "<< dataDaRetirada << endl;
            cout << "Data da devolução -> "<< dataDaDevolucao << endl;
            cout << "Quantidade de Ocupantes -> "<< quantidadeDeOcupantes << endl;
            cout << "Seguro -> "<< seguro << endl;
        }
};


int main () {
    Locacao location(3333, 2, 3, 5, true);

    location.criarLocacao();
}


