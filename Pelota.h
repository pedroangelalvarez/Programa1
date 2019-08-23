//
// Created by pedro on 23/08/19.
//

#ifndef PROGRAMA1_PELOTA_H
#define PROGRAMA1_PELOTA_H


class Pelota {
private:
    int x;
    int y;
    int radio;
    char color;
    int vx;
    int vy;
    int direccion;

public:
    Pelota(int px, int py, int radio, char color, int vx, int vy, int direccion):x{px},y{py};
    void moverse();
    void rebotar();
};


#endif //PROGRAMA1_PELOTA_H
