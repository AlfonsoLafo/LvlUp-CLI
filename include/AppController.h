#pragma once

#include <curses.h>

class AppController {
public:
    AppController();  // Cargar modelo, preparar vista
    void run();       // Loop principal
};