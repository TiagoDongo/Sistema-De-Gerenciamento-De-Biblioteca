# Sistema De Gerenciamento De Biblioteca
 
Este é um projeto em **C** que implementa um sistema de gerenciamento de biblioteca com funcionalidades como cadastro de usuários, empréstimos, devoluções e gerenciamento de livros utilizando listas encadeadas. O projeto foi desenvolvido utilizando o **Visual Studio Code** no **Windows**, com o **MinGW** como ferramenta de compilação.

---

## Funcionalidades

- **Usuários**
  - Cadastro de usuários.
  - Listagem de usuários.
  - Registro de empréstimos e devoluções.

- **Livros**
  - Adição de novos livros.
  - Busca de livros por título ou ID.
  - Remoção de livros.
  - Listagem de todos os livros.

- **Persistência**
  - Salvamento e carregamento de dados em arquivos de texto.

---

## Pré-Requisitos

1. **Windows com MinGW instalado**:
   - Certifique-se de ter o compilador MinGW e o `mingw32-make.exe`.
2. **Visual Studio Code**:
   - Recomenda-se usar o VS Code com extensões para C e Makefile.

---

## Compilação e Execução

1. **Clone o repositório**:
    ```bash
    git clone https://github.com/TiagoDongo/Sistema-De-Gerenciamento-De-Biblioteca.git
    cd seu-repositorio

2. **Compile o projeto**:
    -Utilize o comando **mingw32-make** (ou equivalente) para compilar:
    ````bash
    mingw32-make
    ````
    -O executável gerado será main.

3. **Execute o programa**:
    -Após compilar, execute o programa:
    ````bash
    ./main 
    ````

4: **Limpar os arquivos compilados**:
Para limpar os arquivos objeto e o executável, use:
````bash
    mingw32-make clean
````

## Estrutura do Projeto
* main.c: Arquivo principal do programa.
* user_functions.c / .h: Funções relacionadas aos usuários.
* library_functions.c / .h: Funções relacionadas aos livros.
* Biblioteca.h: Estruturas de dados do projeto.
* Makefile: Arquivo para gerenciar a compilação.

## Contribuição
Se você deseja contribuir para o projeto, siga estas etapas:

1. Faça um fork do repositório.
2. Crie um branch para sua feature ou correção de bug:
````bash
    git checkout -b minha-feature
````
3. Faça commit das suas alterações:
````bash
    git commit -m "Adiciona minha feature"
````
4. Envie para o seu repositório fork:
````bash
    git push origin minha-feature
````
5. Abra um Pull Request descrevendo suas alterações.

## Observação
* Este projeto foi testado no Windows com MinGW e no Linux com make. Certifique-se de usar o comando correto de acordo com seu sistema.
* Se encontrar problemas, por favor, abra uma Issue no GitHub.