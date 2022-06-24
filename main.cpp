//INCLUDING BUILT-IN LIBRARIES...
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Newlocacao {
    private:
        int codigoCliente;
        int codigoVeiculo;
    public: 
        int codigoLocacao;
        int dataDaRetirada;
        int dataDaDevolucao;
        bool seguro;
        int quantidadeDeDias;

        //? Funcção que vai ser chamada de primeira, para registrar todas as variaveis publicas
        Newlocacao(int codigoLocacao_, int dataDaRetirada_, int dataDaDevolucao_, bool seguro_, int quantidadeDeDias_) {
            codigoLocacao = codigoLocacao_;
            dataDaRetirada = dataDaRetirada_;
            dataDaDevolucao = dataDaDevolucao_;
            seguro = seguro_;
            quantidadeDeDias = quantidadeDeDias_;
        }

        //? Funções para registrar as variaveis privadas, por segurança
        void registrarCliente(int codigoCliente_) {
            codigoCliente = codigoCliente_;
        }
        void registrarVeiculo(int codigoVeiculo_) {
            codigoVeiculo = codigoVeiculo_;
        }

        //?
        void list() {
            cout << "Codigo do Cliente "<<codigoCliente << endl;
            cout <<"Codigo do veiculo "<< codigoVeiculo << endl;
            cout <<"Codigo da locação "<< codigoLocacao << endl;
            cout <<"Data da devolução "<< dataDaDevolucao << endl;
            cout <<"Data da retirada "<< dataDaRetirada << endl;
            cout <<"Quantidade de Dias "<< quantidadeDeDias << endl;
            cout <<"Seguro "<< seguro << endl;
        }
};


int main () {
    Newlocacao location(1, 2, 3, true, 5);
    location.registrarCliente(12233);
    location.registrarVeiculo(33333);

    location.list();

}