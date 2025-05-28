#include <iostream>
#include <exception>
#include <csignal>
#include <unistd.h>
#include <ncurses.h>
#include <fstream>
#include <string>

const std::string runtime_path = "../data/runtime.ini";

struct TerminalSize {
    int width = 0;
    int height = 0;
};

void save_terminal_size(const TerminalSize& ts) {
    std::ofstream file(runtime_path, std::ios::trunc);  // truncar siempre
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo para escritura: " + runtime_path);
    }

    file << "[terminal]\n";
    file << "width=" << ts.width << "\n";
    file << "height=" << ts.height << "\n";
}

TerminalSize load_terminal_size() {
    TerminalSize ts;
    std::ifstream file(runtime_path);

    if (!file.is_open()) { save_terminal_size({0,0}); }
    else {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("width=") != std::string::npos) {
                std::string value = line.substr(line.find('=') + 1);
                if (!value.empty()) save_terminal_size({0,0});
                ts.width = std::stoi(value);
            }
            if (line.find("height=") != std::string::npos) {
                std::string value = line.substr(line.find('=') + 1);
                if (!value.empty()) save_terminal_size({0,0});
                ts.height = std::stoi(value);
            }
        }
    }
    return ts;
}

// Función segura para salir de ncurses
void shutdown_ncurses() {
    curs_set(1);
    nocbreak();
    echo();
    endwin();
    fflush(stdout); // Forzar salida por si hay buffers pendientes
}

int main() {
    try {
        initscr();
        noecho();
        cbreak();
        curs_set(0);
        timeout(100);

        TerminalSize last_saved = load_terminal_size();
        TerminalSize current;

        while (true) {
            getmaxyx(stdscr, current.height, current.width);

            if (current.width != last_saved.width || current.height != last_saved.height) {
                save_terminal_size(current);
                clear();
                mvprintw(0, 0, "Dimensiones actuales: %dx%d", current.width, current.height);
            }

            refresh();
            int ch = getch();
            if (ch == 'q') break;
            usleep(10000);
        }

        shutdown_ncurses();
        return 0;

    } catch (const std::exception& e) {
        shutdown_ncurses();
        std::cerr << "\n[ERROR] " << e.what() << std::endl;
        return 1;
    }
}
