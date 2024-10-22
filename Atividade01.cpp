#include <iostream>
#include <string>
using namespace std;

// A classe Client representa um cliente do banco, armazenando seu nome e CPF.
// Essa estrutura é importante para vincular um titular às contas bancárias.
class Client {
private:
    string name;  // Nome do cliente
    string cpf;   // CPF do cliente (identificação única)

public:
    // Construtor que inicializa o nome e o CPF do cliente.
    Client(string name, string cpf) : name(name), cpf(cpf) {}

    // Getters que retornam o nome e CPF do cliente.
    string getName() const { return name; }
    string getCpf() const { return cpf; }
};

// A classe BankAccount representa uma conta bancária associada a um cliente.
// Cada conta tem um número único, um saldo e um titular.
class BankAccount {
private:
    int accountNumber;   // Número da conta bancária
    double balance;      // Saldo disponível na conta
    Client accountHolder; // Titular da conta (objeto da classe Client)

public:
    // Construtor que inicializa o número da conta, o titular e, opcionalmente, o saldo inicial.
    // Caso nenhum saldo seja informado, o valor padrão será 0.
    BankAccount(int accountNumber, Client accountHolder, double balance = 0.0) 
        : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance) {}

    // Método que permite adicionar um valor ao saldo da conta.
    void deposit(double amount) {
        balance += amount;
        cout << "Depositado: R$ " << amount << " na conta " << accountNumber << endl;
    }

    // Método para realizar um saque. Ele verifica se há saldo suficiente antes de descontar o valor.
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Saldo insuficiente para saque na conta " << accountNumber << endl;
        } else {
            balance -= amount;
            cout << "Sacado: R$ " << amount << " da conta " << accountNumber << endl;
        }
    }

    // Este método transfere um valor para outra conta. 
    // Ele verifica se há saldo suficiente antes de realizar a transferência.
    void transfer(double amount, BankAccount &destination) {
        if (amount > balance) {
            cout << "Saldo insuficiente para transferência na conta " << accountNumber << endl;
        } else {
            balance -= amount;
            destination.deposit(amount);
            cout << "Transferido: R$ " << amount << " da conta " << accountNumber
                 << " para a conta " << destination.accountNumber << endl;
        }
    }

    // Sobrecarga do método de transferência. 
    // Aqui, o valor é dividido em duas partes iguais e enviado para duas contas diferentes.
    void transfer(double amount, BankAccount &destination1, BankAccount &destination2) {
        double half = amount / 2;
        if (amount > balance) {
            cout << "Saldo insuficiente para transferência na conta " << accountNumber << endl;
        } else {
            balance -= amount;
            destination1.deposit(half);
            destination2.deposit(half);
            cout << "Transferido: R$ " << half << " para cada conta ("
                 << destination1.accountNumber << " e " << destination2.accountNumber << ") da conta " << accountNumber << endl;
        }
    }

    // Exibe o saldo atual da conta de maneira simples e direta.
    void showBalance() const {
        cout << "Saldo atual da conta " << accountNumber << ": R$ " << balance << endl;
    }

    // Exibe as informações do titular da conta e o saldo, ajudando na visualização geral da conta.
    void showInfo() const {
        cout << "Titular: " << accountHolder.getName() << ", CPF: " << accountHolder.getCpf() << endl;
        cout << "Número da Conta: " << accountNumber << ", Saldo: R$ " << balance << endl;
    }
};

// Função principal onde criamos os clientes e contas, realizamos operações e exibimos os resultados.
// É aqui que as funcionalidades são demonstradas na prática.
int main() {
    // Criação de três clientes com nomes e CPFs diferentes.
    Client client1("Ana", "111.111.111-11");
    Client client2("Bruno", "222.222.222-22");
    Client client3("Carla", "333.333.333-33");

    // Criação de três contas bancárias associadas aos clientes.
    // A conta de Ana tem saldo inicial de R$ 1000, enquanto as demais começam com saldo zero.
    BankAccount account1(1001, client1, 1000.0);
    BankAccount account2(1002, client2);
    BankAccount account3(1003, client3);

    // Exibindo o saldo inicial da conta de Ana.
    account1.showBalance();

    // Ana transfere R$200 para Bruno.
    account1.transfer(200.0, account2);

    // Ana transfere R$300, dividindo o valor entre Bruno e Carla.
    account1.transfer(300.0, account2, account3);

    // Exibe as informações finais de todas as contas após as operações realizadas.
    cout << endl;
    account1.showInfo();
    account2.showInfo();
    account3.showInfo();

    return 0;
}
