# Sistema De Gerenciamento De Biblioteca

![Github License](https://img.shields.io/github/license/TiagoDongo/Sistema-De-Gerenciamento-De-Biblioteca?style=for-the-badge&logo=githublicense)
![github actions](https://img.shields.io/badge/Github_Actions-%232088FF?style=for-the-badge&logo=githubactions&logoColor=white)
![GitHub language count](https://img.shields.io/github/languages/count/TiagoDongo/Sistema-De-Gerenciamento-De-Biblioteca?style=for-the-badge)
![ issues](https://img.shields.io/github/issues/TiagoDongo/Sistema-De-Gerenciamento-De-Biblioteca?style=for-the-badge)
![build linux](https://img.shields.io/github/actions/workflow/status/TiagoDongo/Sistema-De-Gerenciamento-De-Biblioteca/build-linux.yml?style=for-the-badge&logo=linux&logoColor=black&label=Build%20Linux&labelColor=%23FCC624)
![build windows](https://img.shields.io/github/actions/workflow/status/TiagoDongo/Sistema-De-Gerenciamento-De-Biblioteca/build-windows.yml?style=for-the-badge&logo=windows&logoColor=white&label=Build%20Windows&labelColor=blue)

Projeto simples para gerenciar informações de uma biblioteca, incluindo cadastro de livros, leitores e controle de empréstimos

> [!IMPORTANT]
> Este projeto foi testado e executado no Windows e no Linux Ubuntu


### Tarefas Pendentes
O projeto ainda está em desenvolvimento, esta faltando:

- [ ] Implementar emprestimo de livros
- [ ] Implementar devolução de livros
- [ ] Escrever testes unitários

## 💻 Pré-requisitos

Antes de começar, verifique se você atendeu aos seguintes requisitos:

- Instalar as extenções de ```C``` e ```Makefile```
- Projeto pode ser executado tanto no **Windows** quanto no **Linux**
- Instalar um compilador de linguagem C na sua maquina:
    - Para Windows: ```MinGW``` 
    - Para Linux: ```gcc```
      
        ```
        sudo apt update
        sudo apt install build-essential
        ```

## 🚀 Instalação do projeto

Para instalar o ```Sistema de Gerenciamento de Biblioteca```, siga estas etapas:

#### Linux e Windows:
1. Clone o repositório para sua máquina local:
    ```
    git clone https://github.com/TiagoDongo/Sistema-De-Gerenciamento-De-Biblioteca.git
    ```

2. Navegue até a pasta do projeto:
    ```
    cd Sistema-De-Gerenciamento-De-Biblioteca
    ```

3. Compile o projeto usando:
    - **Linux:**
        ```
        make
    - **Windows:**
        ```
        mingw32-make
4. Execute o projeto:
    ```
    ./main
    ```

## 📫 Contribuindo para o projeto

Para contribuir com o projeto, siga estas etapas:

1. Bifurque este repositório.
2. Crie um branch: `git checkout -b <nome_branch>`.
3. Faça suas alterações e confirme-as: `git commit -m '<mensagem_commit>'`
4. Envie para o branch original: `git push origin <nome_do_projeto> / <local>`
5. Crie a solicitação de pull.

Como alternativa, consulte a documentação do GitHub em [```como criar uma solicitação pull```](https://help.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request).