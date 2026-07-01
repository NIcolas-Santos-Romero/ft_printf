*This project has been created as part of the 42 curriculum by nicsanto.*

## Descrição

O **ft_printf** é um projeto que tem como objetivo recriar a famosa função `printf` da biblioteca padrão do C (`libc`). O intuito principal é introduzir o conceito de funções variádicas (funções que aceitam um número indefinido de argumentos) e aprofundar o entendimento sobre como a formatação de strings e a conversão de bases matemáticas funcionam por baixo dos panos no computador.

Esta implementação lida com as seguintes conversões obrigatórias:

| Conversor | Descrição |
| :--- | :--- |
| `%c` | Imprime um único caractere. |
| `%s` | Imprime uma string. |
| `%p` | Imprime um endereço de memória (ponteiro) em formato hexadecimal (prefixado com `0x`). |
| `%d` e `%i` | Imprimem números decimais (base 10). |
| `%u` | Imprime um número decimal sem sinal (*unsigned*). |
| `%x` e `%X` | Imprimem números em formato hexadecimal (base 16), em minúsculas ou maiúsculas. |
| `%%` | Imprime o sinal de porcentagem. |

## Instruções

Para compilar e utilizar a biblioteca `libftprintf.a` nos seus projetos, siga os passos abaixo.

### Compilação

O projeto inclui um `Makefile` configurado de acordo com as regras da 42. Para compilar, basta rodar na raiz do repositório:

    make

Isso irá compilar os arquivos fontes e gerar o arquivo estático `libftprintf.a`.

Outros comandos úteis do `Makefile`:
* `make clean`: Remove os arquivos objetos (`.o`).
* `make fclean`: Remove os arquivos objetos e a biblioteca compilada.
* `make re`: Refaz a compilação do zero.

### Utilização

Inclua o cabeçalho no seu código C:

    #include "ft_printf.h"

Na hora de compilar o seu programa (`main.c`), referencie a biblioteca:

    cc main.c -L. -lftprintf -o meu_programa

### Exemplos de Uso

Abaixo estão exemplos práticos isolados demonstrando como chamar cada um dos conversores da `ft_printf` e qual será a impressão no terminal:

**1. Caractere (`%c`)**

    ft_printf("Caractere: %c\n", 'A');

**Saída:** `Caractere: A`


**2. String (`%s`)**

    ft_printf("String: %s\n", "Hello World");

**Saída:** `String: Hello World`


**3. Ponteiro / Endereço de Memória (`%p`)**

    ft_printf("Endereço de memória: %p\n", ptr);

**Saída:** `Endereço de memória: 0x7ffe5a9b8c4c` *(O valor exato varia)*


**4. Inteiros Base 10 (`%d` e `%i`)**

    ft_printf("Inteiros: %d e %i\n", 42, -42);

**Saída:** `Inteiros: 42 e -42`


**5. Inteiro sem sinal / Unsigned (`%u`)**

    ft_printf("Unsigned: %u\n", 4294967295);

**Saída:** `Unsigned: 4294967295`


**6. Hexadecimal Base 16 (`%x` e `%X`)**

    ft_printf("Hexadecimal: %x e %X\n", 255, 255);

**Saída:** `Hexadecimal: ff e FF`


**7. Porcentagem (`%%`)**

    ft_printf("Porcentagem: 100%%\n");

**Saída:** `Porcentagem: 100%`


## Algoritmo e Estrutura de Dados

### Estrutura de Dados

Para gerenciar o número variável de argumentos, o projeto faz uso da estrutura fundamental `va_list` (provida pela macro `<stdarg.h>`). Diferente de projetos de listas encadeadas, o `ft_printf` não armazena os dados do usuário, ele atua como um fluxo direto contínuo (*stream*). O `va_list` é utilizado como uma "mochila" onde os argumentos são iterados com `va_arg` e imediatamente convertidos e despachados para a tela usando a função `write`.

### Algoritmo: Roteamento e Recursividade

A arquitetura do código foi dividida para respeitar a Norminette (limite máximo de 5 funções por arquivo) e é baseada em dois pilares:

1. **O Roteador (Parser):** A função principal itera sobre a string original. Ao encontrar o caractere de escape `%`, ela aciona uma função roteadora (`ft_con`). Essa função atua como um "Switch/Case" modular: analisa o formato subsequente (o *type*) e aciona o especialista correspondente para aquele tipo de dado, mantendo o controle contínuo dos caracteres impressos para retornar o tamanho exato final.
2. **Empilhamento de Recursão (Conversão de Bases):** A conversão de números (`%d`, `%i`, `%u`, `%x`, `%X`) dispensa loops pesados (como `while`) ou alocação estática de strings invertidas. Em vez disso, utiliza um algoritmo altamente recursivo. A função divide o número continuamente por sua base (10 ou 16) chamando a si mesma até alcançar o primeiro dígito. Ao atingir a condição de parada, o retorno desempilha a execução (*Call Stack*), aplicando a operação de módulo (`% 10` ou `% 16`) e utilizando mapeamento ASCII direto (somando `'0'` para decimais) ou indexação em uma string base (`"0123456789abcdef"`) para imprimir do primeiro ao último caractere sequencialmente.

Para o ponteiro (`%p`), o algoritmo foi otimizado para reaproveitar a função hexadecimal de `%x`. O ponteiro bruto (`void *`) sofre um *casting* de segurança para `unsigned long` (8 bytes em arquiteturas 64-bits), evitando perda de precisão de memória, e é injetado no motor hexadecimal já existente.

## Recursos

**Referências Clássicas e Materiais de Estudo:**
* [Man page do printf](https://man7.org/linux/man-pages/man3/printf.3.html) - `man 3 printf`
* [Man page do stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html) - `man 3 stdarg`
* [Vídeo de apoio sobre o ft_printf (YouTube)](https://www.youtube.com/watch?v=Hb2m7htiKWM)
* [Artigo "Estudos de um leigo em ft_printf" (Medium)](https://medium.com/@thiagoschaves61/estudos-de-um-leigo-em-ft-printf-07294484a8e1)
* [Parâmetros interessantes do scanf e do printf em C (Viva o Linux)](https://www.vivaolinux.com.br/artigo/Parametros-interessantes-do-scanf-e-do-printf-em-C/)
* [Fórum: Como criar minha própria função printf (Viva o Linux)](https://www.vivaolinux.com.br/topico/C-C++/Como-criar-minha-propria-funcao-printf-1/)

**Uso de Inteligência Artificial:**
Este projeto utilizou IA (Gemini) como um assistente ativo de tutoria durante o processo de aprendizagem para os seguintes fins específicos:
* Compreensão aprofundada das macros variádicas (`va_start`, `va_arg`, `va_copy`, `va_end`) e como funcionam por baixo dos panos na memória do C com a regra do "*Default Argument Promotions*".
* Criação de testes de mesa explicativos para dominar a visualização e o conceito de desempilhamento das funções recursivas aplicadas à base 10 e base 16.
* Auxílio pontual no planejamento arquitetural para reduzir funções redundantes (como unificar a conversão do endereço físico `%p` com `%x` via *casting* para `unsigned long`), garantindo que o código se adequasse à regra estrita de 5 funções por arquivo da Norminette, sem a geração direta de código pronto.
