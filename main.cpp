//INCLUDING BUILT-IN LIBRARIES...
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <ctime>

using namespace std;

time_t dateToTimeT(int day, int month, int year) {
  // january 5, 2000 is passed as (1, 5, 2000)
  tm tmp = tm();
  tmp.tm_mday = day;
  tmp.tm_mon = month - 1;
  tmp.tm_year = year - 1900;
  return mktime(&tmp);
}

time_t badTime() {
  return time_t(-1);
}

time_t now() {
  return time(0);
}


class Locacao {
    private: 
        int codigoDoCliente; 
    public: 
        int codigoLocacao;
        time_t dataDaRetirada;
        time_t dataDaDevolucao;
        int quantidadeDeOcupantes;
        bool seguro;

        //? Funcção que vai ser chamada de primeira, para registrar as variaveis obrigatórias
        Locacao(int codigoDoCliente_, int quantidadeDeOcupantes_, bool seguro_) {
            codigoDoCliente = codigoDoCliente_;
            quantidadeDeOcupantes = quantidadeDeOcupantes_;
            seguro = seguro_;

            srand(time(0));
            codigoLocacao = rand(); 
        }

        //? Funcção principal que retorna a quantidade de diárias
        int criarLocacao() {
            int horasAtuais;
            int dia, mes, ano;
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
            cout << "Por favor preencha os seguintes dados" << endl;

            cout << "-------------------";
            cout << " Data de Retirada ";
            cout << "-------------------" << endl;

            do {
                cout << "Dia da retirada: ";
                cin >> dia; 
            } while (!((dia > 0) && (dia <= 31)));

            do {
                cout << "Mes da retirada: ";
                cin >> mes;
            } while (!((mes >= 1) && (mes <= 12)));
            
            do {
                cout << "Ano da retirada: ";
                cin >> ano;
            } while (ano < 2022);
            
            //? Criando variavel do tipo time_t(tempo) para data de retirada do veiculo
            time_t dataDaRetirada = dateToTimeT(dia, mes, ano);

            cout << "-------------------";
            cout << " Data de Devolução ";
            cout << "-------------------" << endl;

            do {
                cout << "Dia da devolução: ";
                cin >> dia; 
            } while (!((dia > 0) && (dia <= 31)));

            do {
                cout << "Mes da devolução: ";
                cin >> mes;
            } while (!((mes >= 1) && (mes <= 12)));
            
            do {
                cout << "Ano da devolução: ";
                cin >> ano;
            } while (ano < 2022);

            time_t dataDaDevolucao = dateToTimeT(dia, mes, ano);

            if ((dataDaRetirada == badTime()) || (dataDaDevolucao == badTime())) {
                cerr << " Error estrutura de data inválida! " << endl;
                return -1;
            }

            double sec = difftime(dataDaDevolucao, dataDaRetirada);
            long days = static_cast<long>(sec / (60 * 60 * 24));
            cout << "Quantidade de diarias será: ";
            cout << days << endl;

            return days;
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
    Locacao location(3333, 5, true);

    location.criarLocacao();
}


