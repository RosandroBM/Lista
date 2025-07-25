
A lista pode ser manipulada por meio dos seguintes comandos:
```bash
./lista inserir <posicao> <valor>
./lista modificar <posicao> <valor>
./lista obter <posicao>
./lista remover <posicao>
./lista exibir
./lista vazio
./lista cheio
./lista tamanho
```
 Casos de Teste
Inserção e visualização
```bash
./lista inserir 1 10
./lista inserir 2 20
./lista exibir
```
**Saída esperada:**  
Lista: 10 20

Modificação
```bash
./lista modificar 1 99
./lista obter 1
```
**Saída esperada:**  
Valor na posição 1: 99

Remoção
```bash
./lista remover 2
./lista exibir
```
**Saída esperada:**  
Lista: 99

 Verificações
```bash
./lista vazio
./lista cheio
./lista tamanho
```
**Saída esperada:**
Lista vazia: não  
Lista cheia: não  
Tamanho: 1

## 6. Persistência

O estado da lista é salvo automaticamente no arquivo `dados.bin`, garantindo persistência entre execuções.
