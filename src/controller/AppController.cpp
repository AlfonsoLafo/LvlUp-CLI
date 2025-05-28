#include "AppController.h"

AppController::AppController() {
    // Aquí se pueden instanciar modelo y vista
}

void AppController::run() {
    // Loop principal: input -> update model -> update view
    bool running = true;
    while (running) {
        int ch = getch(); // Captura de tecla

        switch (ch) {
            case 'q': running = false; break;
            // otros casos: navegación, comandos, etc.
        }

        // Actualizar vista aquí si es necesario
    }
}