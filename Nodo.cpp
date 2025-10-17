#include "Nodo.h"

Nodo::Nodo(int x, int y, int value) {
    this->x = x;
    this->y = y;
    this->value = value;
    this->next = nullptr;
}
