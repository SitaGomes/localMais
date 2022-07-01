//INCLUDING BUILT-IN LIBRARIES...
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <stdio.h>

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
        int codigoLocacao;
        time_t dataDaRetirada;
        time_t dataDaDevolucao;
        int quantidadeDeOcupantes;
        bool seguro;
        int totalDeDiarias;

        void setDataDaRetirada();
        void setDataDaDevolucao(time_t dataDaRetirada_);
        void setSeguro();
        void setQuantidadeDeOcupantes();
        void setTotalDeDiarias(time_t dataDaDevolucao_, time_t dataDaRetirada_);
    public: 
        Locacao();
        Locacao(int codigoDoCliente_);

        void criarLocacao();

        int getCodigoLocacao();
        int getCodigoDoCliente();
        int getQuantidadeDeOcupantes();
        time_t getDataDaRetirada();
        time_t getDataDaDevolucao();
        bool getSeguro();
        int getTotalDeDiarias();

};




Locacao::Locacao(int codigoDoCliente_) {
    codigoDoCliente = codigoDoCliente_;

    srand(time(0));
    codigoLocacao = rand(); 
}

Locacao::Locacao() {}

void Locacao::criarLocacao() {
    int horasAtuais;
    
    cout << "Ola caro cliente, ";
    cout << "quantas horas são? [24h]: ";
    cin >> horasAtuais;

    if (!((horasAtuais > 8) && (horasAtuais < 18))) {
        cout << "Desculpe o encomodo, porém estamos fechados" << endl;
        return;
    }

    if (horasAtuais < 12) 
        cout << "Bom dia!" << endl;
    else 
        cout << "Boa tarde!" << endl;
    cout << "Por favor preencha os seguintes dados" << endl;

    setDataDaRetirada();

    time_t dataDaRetirada_ = getDataDaRetirada();

    setDataDaDevolucao(dataDaRetirada_);

    setSeguro();
    
    setQuantidadeDeOcupantes();

    setTotalDeDiarias(dataDaDevolucao, dataDaRetirada);

    cout << "Quantidade de diarias será: ";
    cout << totalDeDiarias << endl;
}


//! Setters
void Locacao::setDataDaRetirada() {
    int dia, mes, ano;

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
    dataDaRetirada = dateToTimeT(dia, mes, ano);
}

void Locacao::setDataDaDevolucao(time_t dataDaRetirada_) {
    int dia, mes, ano;

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

    dataDaDevolucao = dateToTimeT(dia, mes, ano);

    while(dataDaDevolucao <= dataDaRetirada_) {
        cout << " Error! A data de devolução deve ser maior que a data de retirada. " << endl;
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

        dataDaDevolucao = dateToTimeT(dia, mes, ano);
    }
}

void Locacao::setSeguro() {
    cout << "Deseja adicionar um seguro? [SIM 1, NÂO 0] ";
    cin >> seguro;
}

void Locacao::setQuantidadeDeOcupantes() {
    cout << "Qual é a quantidade de ocupantes? ";
    cin >> quantidadeDeOcupantes;
}

void Locacao::setTotalDeDiarias(time_t dataDaDevolucao_, time_t dataDaRetirada_) {

    if ((dataDaRetirada_ == badTime()) || (dataDaDevolucao_ == badTime())) {
        cerr << " Error, estrutura de data inválida! " << endl;
        return;
    }

    double sec = difftime(dataDaDevolucao_, dataDaRetirada_);
    long days = static_cast<long>(sec / (60 * 60 * 24));

    totalDeDiarias = days;
}


//! Geters
int Locacao::getCodigoLocacao() {
    return codigoLocacao;
}

int Locacao::getCodigoDoCliente() {
    return codigoDoCliente;
}

int Locacao::getQuantidadeDeOcupantes() {
    return quantidadeDeOcupantes;
}

time_t Locacao::getDataDaRetirada() {
    return dataDaRetirada;
}

time_t Locacao::getDataDaDevolucao() {
    return dataDaDevolucao;
}

bool Locacao::getSeguro() {
    return seguro;
}

int Locacao::getTotalDeDiarias() {
    return totalDeDiarias;
}

void incluirLocacao(Locacao locacao, FILE *file);
void listarLocacao(FILE *file);


int main () {
    Locacao location(33);
    FILE *file;

    if((file = fopen("locacao.db", "r+b")) == NULL) {
        cout << "Criando um novo arquivo" << endl;
        if((file = fopen("locacao.db", "w+b")) == NULL) {
            cout << "Erro na criação do arquivo" << endl;
        }
    }

    location.criarLocacao();
    incluirLocacao(location, file);
    listarLocacao(file);

}


void incluirLocacao(Locacao locacao, FILE *file) {
    int posicao;

    fseek(file, 0, SEEK_END);
    fwrite(&locacao, sizeof(Locacao), 1, file);
    cout << "Arquivo salvo com sucesso" << endl;
}

void listarLocacao(FILE *f) { 
    Locacao m;

    cout << "--------------------------";
    cout << " Imprimindo as locações ";
    cout << "--------------------------" << endl;

    fseek(f,0,SEEK_SET);
    fread(&m, sizeof(m),1, f);
    while (!feof(f)) { 
        cout << "Codigo do cliente -> " << m.getCodigoDoCliente() << endl;
        cout << "Codigo da locação -> " << m.getCodigoLocacao() << endl;
        cout << "Quantidade de ocupantes -> " << m.getQuantidadeDeOcupantes() << endl;
        cout << "Seguro -> " << m.getSeguro() << endl;  
        cout << "Data da retirada -> " << m.getDataDaRetirada() << endl;
        cout << "Data da devolução -> " << m.getDataDaDevolucao() << endl;
        cout << "Total de diárias -> " << m.getTotalDeDiarias() << endl;  
        cout << endl;      
        fread(&m, sizeof(m),1, f);
    }
}