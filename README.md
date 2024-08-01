
# performanceEvaluation
Avaliação de desempenho em diferentes PCs

Este guia fornece instruções passo a passo para configurar e executar o código de teste de desempenho em um ambiente Windows utilizando o Windows Subsystem for Linux (WSL). Siga os passos abaixo para garantir uma execução bem-sucedida.

## Passo 1: Clonar o Repositório Git

Primeiramente, você precisa clonar o repositório Git onde o código está armazenado. Abra o PowerShell ou o Prompt de Comando como Administrador e execute o seguinte comando:

```sh
git clone https://github.com/IuriDkill/performanceEvaluation.git
```


```sh
cd performanceEvaluation
```


## Passo 2: Instalar o WSL

Você precisa instalar o WSL no seu sistema Windows. Abra o PowerShell ou o Prompt de Comando como Administrador e execute o seguinte comando:

```sh
wsl --install
```

Após a execução bem-sucedida do comando, reinicie o computador para que as alterações tenham efeito.

## Passo 3: Atualizar o Sistema e Instalar Dependências

Depois de reiniciar o computador, abra o terminal do WSL (pode ser Ubuntu, por exemplo) e execute os seguintes comandos para instalar as ferramentas necessárias:

1. **Instalar o make**:

```sh
sudo apt install make
```

2. **Atualizar o sistema**:

```sh
sudo apt update
```

3. **Instalar o pacote build-essential**:

```sh
sudo apt install build-essential
```

## Passo 4: Compilar o Código

Navegue até o diretório onde o código fonte está localizado e compile o código usando o `make`. No terminal do WSL, execute:

```sh
make
```

## Passo 5: Preparar o Script para Execução

Dê permissão de execução ao script `run.sh`:

```sh
chmod +x run.sh
```

## Passo 6: Executar o Script

Finalmente, execute o script `run.sh`:

```sh
./run.sh
```

O script `run.sh` irá gerar 10 arquivos CSV contendo os resultados dos testes de desempenho, que serão armazenados na pasta `results`.

---