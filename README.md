# Card Wars
---
Um simples jogo de cartas utilizando a biblioteca curses, compatível com Micrsoft Windows e Linux.

## Compilação
### Windows
#### Dependências
Você precisará dos seguintes programas:
+ GCC
+ `make`
+ Instalar a biblioteca PDCurses no projeto

##### Instalando a biblioteca PDCurses:
Na raiz do diretório do projeto, crie duas pastas, uma com o nome de `include` e outra com o nome de `lib`
Vá para o (site oficial do PDCUrses)[https://pdcurses.org/] e baixe a versão estável.

Extraia a versão estável em algum lugar e copie os arquivos `curses.h`, `curspriv.h` e `panel.h` para a pasta `include` criada anteriormente.

Dentro da biblioteca, navegue para a pasta `wincon` pelo terminal.
Dentro da pasta, rode o make para compilar a biblioteca:
```
make
```

Depois de compilar a biblioteca, mova o arquivo `pdcwin.h` para a pasta `include` criada anteriormente e o arquivo `pdcurses.a` para a pasta `lib` criada anteriormente.

Renomeie o arquivo `lib\pdcurses.a` para `lib\libpdcurses.a`

##### Compilando o projeto
Dentro da pasta do projeto, execute o make:
```
make
```

### Linux
#### Dependências
+ `gcc`
+ `make`
+ `ncurses`

##### Compilando o projeto
Dentro da pasta do projeto, execute o make da seguinte forma:
```sh
make LINUX=true
```
O argumento `LINUX=true` informa que será utilizada a biblioteca `ncurses` ao invés de `PDCurses`.
