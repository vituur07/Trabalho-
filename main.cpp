#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <cctype>

// Biblioteca necessária para o som no Windows
#ifdef _WIN32
#include <windows.h>
#endif

const int ALTURA = 8;
const int LARGURA = 8;

const std::string RESET = "\033[0m";
const std::string VERMELHO = "\033[1;31m";
const std::string VERDE = "\033[1;32m";
const std::string AZUL = "\033[1;34m";
const std::string AMARELO = "\033[1;33m";
const std::string MAGENTA = "\033[1;35m";
const std::string CIANO = "\033[1;36m";
const std::string BRANCO_BRILHANTE = "\033[1;97m";

const std::vector<std::string> CORES = {AMARELO, VERMELHO, MAGENTA, CIANO, VERDE, AZUL};

const int ALFABETO[26][5][5] = {
    {{0,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1}}, // A
    {{1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}}, // B
    {{0,1,1,1,0}, {1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {0,1,1,1,0}}, // C
    {{1,1,1,0,0}, {1,0,0,1,0}, {1,0,0,1,0}, {1,0,0,1,0}, {1,1,1,0,0}}, // D
    {{1,1,1,1,1}, {1,0,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,1,1,1,1}}, // E
    {{1,1,1,1,1}, {1,0,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,0,0,0,0}}, // F
    {{0,1,1,1,0}, {1,0,0,0,0}, {1,0,1,1,1}, {1,0,0,0,1}, {0,1,1,1,0}}, // G
    {{1,0,0,0,1}, {1,0,0,0,1}, {1,1,1,1,1}, {1,0,0,0,1}, {1,0,0,0,1}}, // H
    {{0,1,1,1,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,1,1,1,0}}, // I
    {{0,0,1,1,1}, {0,0,0,1,0}, {0,0,0,1,0}, {1,0,0,1,0}, {0,1,1,0,0}}, // J
    {{1,0,0,1,0}, {1,0,1,0,0}, {1,1,0,0,0}, {1,0,1,0,0}, {1,0,0,1,0}}, // K
    {{1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {1,0,0,0,0}, {1,1,1,1,1}}, // L
    {{1,0,0,0,1}, {1,1,0,1,1}, {1,0,1,0,1}, {1,0,0,0,1}, {1,0,0,0,1}}, // M
    {{1,0,0,0,1}, {1,1,0,0,1}, {1,0,1,0,1}, {1,0,0,1,1}, {1,0,0,0,1}}, // N
    {{0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}}, // O
    {{1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}, {1,0,0,0,0}, {1,0,0,0,0}}, // P
    {{0,1,1,1,0}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,1,0}, {0,1,1,0,1}}, // Q
    {{1,1,1,1,0}, {1,0,0,0,1}, {1,1,1,1,0}, {1,0,1,0,0}, {1,0,0,1,1}}, // R
    {{0,1,1,1,1}, {1,0,0,0,0}, {0,1,1,1,0}, {0,0,0,0,1}, {1,1,1,1,0}}, // S
    {{1,1,1,1,1}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}}, // T
    {{1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {1,0,0,0,1}, {0,1,1,1,0}}, // U
    {{1,0,0,0,1}, {1,0,0,0,1}, {0,1,0,1,0}, {0,1,0,1,0}, {0,0,1,0,0}}, // V
    {{1,0,0,0,1}, {1,0,0,0,1}, {1,0,1,0,1}, {1,1,0,1,1}, {1,0,0,0,1}}, // W
    {{1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}, {0,1,0,1,0}, {1,0,0,0,1}}, // X
    {{1,0,0,0,1}, {0,1,0,1,0}, {0,0,1,0,0}, {0,0,1,0,0}, {0,0,1,0,0}}, // Y
    {{1,1,1,1,1}, {0,0,0,1,0}, {0,0,1,0,0}, {0,1,0,0,0}, {1,1,1,1,1}}  // Z
};

void limparMatriz(std::vector<std::string>& matriz) {
    for (int i = 0; i < ALTURA; ++i) {
        matriz[i] = std::string(LARGURA, '.'); 
    }
}

void mostrarMatrizDecorada(const std::vector<std::string>& matriz, std::string corAtual, char charLetra) {
    std::cout << RESET << BRANCO_BRILHANTE << "  ==================\n" << RESET;
    for (int i = 0; i < ALTURA; ++i) {
        std::cout << BRANCO_BRILHANTE << "  ||" << RESET;
        for (int j = 0; j < LARGURA; ++j) {
            char c = matriz[i][j];
            std::cout << " "; 
            if (c == '#') {
                std::cout << corAtual << charLetra << RESET;
            } else {
                std::cout << "\033[90m" << "·" << RESET;
            }
        }
        std::cout << BRANCO_BRILHANTE << " ||\n" << RESET;
    }
    std::cout << BRANCO_BRILHANTE << "  ==================\n" << RESET;
}

void carregarLetra(char letra, int padraoDestino[5][5]) {
    letra = toupper(letra);
    int indice = letra - 'A';
    if (indice < 0 || indice > 25) {
        for(int i=0;i<5;i++) for(int j=0;j<5;j++) padraoDestino[i][j] = 0;
        return;
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            padraoDestino[i][j] = ALFABETO[indice][i][j];
        }
    }
}

void desenharPadrao(std::vector<std::string>& matriz, int x, int y, int padrao[5][5]) {
    if (x < 0 || x + 5 > LARGURA || y < 0 || y + 5 > ALTURA) return;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (padrao[i][j] == 1) {
                matriz[y+i].replace(x+j, 1, "#");
            }
        }
    }
}

// === FUNÇÃO DE SOM ===
// Toca um tom "Waka" ou "Waka2" alternando
void tocarSomWaka(int frame) {
    #ifdef _WIN32
        // Beep(Frequencia em Hz, Duração em ms)
        // Alterna entre 250Hz e 400Hz para fazer o efeito "Wa-Ka-Wa-Ka"
        if (frame % 2 == 0) {
            Beep(250, 150); 
        } else {
            Beep(400, 150); 
        }
    #else
        // No Linux, apenas dorme
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        // Tenta fazer um beep simples do sistema
        std::cout << '\a' << std::flush;
    #endif
}

// Som de colisão (quando bate na parede)
void tocarSomColisao() {
    #ifdef _WIN32
        Beep(800, 50); // Som agudo e rápido
        Beep(600, 50); // Som descendo
    #endif
}

void executarFadeIn(std::vector<std::string>& matriz, int pos_x, int pos_y, int padrao[5][5]) {
    std::string niveisFade = ".:oO@"; 
    for (char charFade : niveisFade) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        std::cout << "Inicializando sistema...\n";
        limparMatriz(matriz);
        desenharPadrao(matriz, pos_x, pos_y, padrao);
        mostrarMatrizDecorada(matriz, BRANCO_BRILHANTE, charFade);
        
        #ifdef _WIN32
        Beep(100 + (niveisFade.find(charFade) * 100), 100); // Som subindo no fade in
        #else
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        #endif
    }
}

int main() {
    std::vector<std::string> matriz(ALTURA);
    int padrao[5][5];
    char escolhaLetra;
    int escolhaMovimento;

    std::cout << "=== MATRIZ 8x8 - VERSAO PACMAN (SOM E CORES) ===\n";
    std::cout << "Digite a letra para animar (A-Z): ";
    std::cin >> escolhaLetra;
    
    std::cout << "Escolha o movimento:\n";
    std::cout << "1 - Horizontal\n2 - Vertical\n3 - Diagonal (Bonus)\nOpcao: ";
    std::cin >> escolhaMovimento;

    carregarLetra(escolhaLetra, padrao);

    int pos_x = 0; int pos_y = 0;
    int dir_x = 0; int dir_y = 0;

    if (escolhaMovimento == 1) { dir_x = 1; pos_y = 1; }
    else if (escolhaMovimento == 2) { dir_y = 1; pos_x = 1; }
    else { dir_x = 1; dir_y = 1; }

    executarFadeIn(matriz, pos_x, pos_y, padrao);

    int cor_index = 0;

    for (int frame = 0; frame < 100; ++frame) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        std::cout << "Letra: " << (char)toupper(escolhaLetra) << " | Frame: " << frame << "\n";

        limparMatriz(matriz);
        desenharPadrao(matriz, pos_x, pos_y, padrao);
        mostrarMatrizDecorada(matriz, CORES[cor_index], 'C'); // 'C' parece um pacman aberto

        pos_x += dir_x;
        pos_y += dir_y;

        bool colidiu = false;

        if (dir_x != 0) {
            if (pos_x + 5 >= LARGURA || pos_x < 0) {
                dir_x *= -1;
                pos_x += dir_x;
                colidiu = true;
            }
        }
        if (dir_y != 0) {
            if (pos_y + 5 >= ALTURA || pos_y < 0) {
                dir_y *= -1;
                pos_y += dir_y;
                colidiu = true;
            }
        }

        if (colidiu) {
            cor_index = (cor_index + 1) % CORES.size();
            tocarSomColisao(); // Som extra quando bate
        } else {
            // Se não bateu, toca o som de fundo "Waka Waka"
            // O próprio som serve como delay da animação
            tocarSomWaka(frame);
        }
    }

    std::cout << RESET << "\nFim da animacao!" << std::endl;
    return 0;
}
