# 🕹️ Projeto 3: Animação em Matriz 8x8

**Disciplina:** Lógica de Programação e C++  
**Alunos:** Pedro Henrique, Victor Lima, Letícia Normano, Maria Eduarda Alves e Levi Alves
**Instituição:** IFCE - Técnico em Telecomunicações  
**Semana:** 3 (Arrays Multidimensionais e Manipulação Gráfica)

---

## 📝 Sobre o Projeto
Este projeto é uma implementação avançada do exercício de **Simulação de Matriz de LED 8x8** no console. O programa exibe uma animação contínua onde uma letra escolhida pelo usuário se move pela tela, ricocheteando nas bordas com efeitos visuais.

O objetivo principal foi demonstrar o domínio sobre **Arrays Multidimensionais**, **Loops Aninhados** e **Lógica de Colisão**, além de implementar todos os desafios extras propostos para pontuação máxima.

---

## ✨ Funcionalidades Implementadas

### ✅ Requisitos Básicos
* **Matriz 8x8:** Simulação visual precisa utilizando caracteres ASCII e limpeza de buffer.
* **Animação:** Loop de renderização fluido.
* **Colisão:** A letra detecta as bordas da matriz (X e Y) e inverte a direção automaticamente.

### 🚀 Desafios Extras e Bônus
* **Biblioteca Completa (A-Z):** Uso de um **Array Tridimensional** (`ALFABETO[26][5][5]`) para renderizar qualquer letra do alfabeto.
* **Movimento Diagonal:** Implementação de vetores de direção independentes (`dir_x`, `dir_y`), permitindo movimento livre pela tela.
* **Cores Dinâmicas (ANSI):** A letra muda de cor (Vermelho, Verde, Azul, Amarelo, etc.) a cada colisão com a parede.
* **Efeitos Sonoros (Windows API):**
    * Som de fundo rítmico ("Waka Waka") sincronizado com o frame da animação.
* **Refinamento Visual (Polish):**
    * Bordas decorativas estilo "Monitor Retrô".
    * Efeito de *Fade In* (surgimento gradual) ao iniciar o programa.

---

## 🛠️ Como Compilar e Executar

⚠️ **Atenção:** Devido ao uso da biblioteca `<windows.h>` para a geração de áudio em tempo real, este código deve ser compilado e executado em ambiente **Windows**.

### Pré-requisitos
* Compilador C++ (MinGW/G++).
* Terminal do Windows (CMD ou PowerShell).

### Passo a Passo

1.  **Clone ou baixe** este repositório.
2.  Abra o terminal na pasta do arquivo.
3.  **Compile o código:**
    ```bash
    g++ animacao_pacman.cpp -o animacao
    ```
4.  **Execute o programa:**
    ```bash
    ./animacao.exe
    ```

---

## 🎮 Como Usar

Ao iniciar o programa, siga as instruções interativas:

1.  **Escolha a Letra:** Digite qualquer letra de **A** a **Z** para ser o "personagem" da animação.
2.  **Escolha o Movimento:**
    * `1` - **Horizontal:** A letra vai da esquerda para a direita.
    * `2` - **Vertical:** A letra vai de cima para baixo.
    * `3` - **Diagonal (Bônus):** A letra se move livremente, quicando nos cantos.

---

## 🧠 Destaques Técnicos

### Array Tridimensional
Para evitar dezenas de `if/else`, as letras foram mapeadas em uma estrutura de dados 3D. Isso permite acessar o padrão de bits de qualquer letra usando matemática simples baseada na tabela ASCII:

```cpp
// Acesso direto ao padrão da letra
padraoDestino[i][j] = ALFABETO[letra - 'A'][i][j];
